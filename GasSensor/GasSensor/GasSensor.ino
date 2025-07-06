/*
  Arduino Gas Sensor Security System
  
  This project implements a comprehensive gas detection and security system using:
  - MQ-2 Gas Sensor for detecting LPG, propane, methane, alcohol, hydrogen, and smoke
  - 4x4 Matrix Keypad for password authentication
  - 16x2 LCD Display for user interface and sensor readings
  - LED and Buzzer for visual and audio alerts
  
  Circuit Connections:
  ==================
  
  LCD Display (16x2):
  * RS pin → Analog pin A0
  * Enable pin → Analog pin A1
  * D4 pin → Analog pin A2
  * D5 pin → Analog pin A3
  * D6 pin → Analog pin A4
  * D7 pin → Analog pin A5
  * VSS → GND, VDD → 5V, V0 → Potentiometer for contrast
  
  4x4 Matrix Keypad:
  * ROW1 → Digital pin 9
  * ROW2 → Digital pin 8
  * ROW3 → Digital pin 7
  * ROW4 → Digital pin 6
  * COL1 → Digital pin 5
  * COL2 → Digital pin 4
  * COL3 → Digital pin 3
  * COL4 → Digital pin 2
  
  MQ-2 Gas Sensor:
  * VCC → 5V
  * GND → GND
  * A0 → Analog pin A5
  
  Alert System:
  * Red LED → Digital pin 12 (with 220Ω resistor)
  * Buzzer → Digital pin 13
  
  Author: Arman Sheikhhosseini
  Email: arman.sheikhhosseini@gmail.com
  Date: May 2017 (Updated: July 2025)
  Version: V2.0
  License: MIT
*/

// ======================== LIBRARY INCLUDES ========================
#include <LiquidCrystal.h>
#include <Keypad.h>

// ======================== PIN DEFINITIONS ========================
// LCD Pins
const int LCD_RS = 10;
const int LCD_ENABLE = A0;
const int LCD_D4 = A1;
const int LCD_D5 = A2;
const int LCD_D6 = A3;
const int LCD_D7 = A4;

// Alert System Pins
const int RED_LED_PIN = 12;
const int BUZZER_PIN = 13;
const int GAS_SENSOR_PIN = A5;

// Keypad Pins
const byte KEYPAD_ROWS = 4;
const byte KEYPAD_COLS = 4;
byte rowPins[KEYPAD_ROWS] = {9, 8, 7, 6};
byte colPins[KEYPAD_COLS] = {5, 4, 3, 2};

// ======================== CONFIGURATION CONSTANTS ========================
const int PASSWORD_LENGTH = 5;  // 4 digits + null terminator
const int GAS_THRESHOLD = 500;   // Adjustable gas detection threshold
const int LOGIN_SUCCESS_TONE = 4000;
const int LOGIN_SUCCESS_DURATION = 1000;
const int GAS_ALARM_TONE = 700;
const int GAS_ALARM_DURATION = 50;
const int WRONG_PASSWORD_TONE = 500;
const int WRONG_PASSWORD_DURATION = 500;

// ======================== GLOBAL VARIABLES ========================
// LCD and Keypad objects
LiquidCrystal lcd(LCD_RS, LCD_ENABLE, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

// Keypad configuration
char keypadLayout[KEYPAD_ROWS][KEYPAD_COLS] = {
  {'1', '2', '3', 'F'},
  {'4', '5', '6', 'F'},
  {'7', '8', '9', 'F'},
  {'#', '0', '=', 'F'}
};
Keypad keypad = Keypad(makeKeymap(keypadLayout), rowPins, colPins, KEYPAD_ROWS, KEYPAD_COLS);

// Password system variables
char enteredPassword[PASSWORD_LENGTH];
const char masterPassword[PASSWORD_LENGTH] = "1373";  // Default password
byte passwordIndex = 0;
bool isPasswordMode = true;
bool isSystemLocked = false;

// System state variables
unsigned long lastSensorRead = 0;
const unsigned long SENSOR_READ_INTERVAL = 100;  // Read sensor every 100ms
unsigned long lastDisplayUpdate = 0;
const unsigned long DISPLAY_UPDATE_INTERVAL = 500;  // Update display every 500ms

// ======================== SETUP FUNCTION ========================
void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  Serial.println(F("=== Arduino Gas Sensor Security System ==="));
  Serial.println(F("Initializing system..."));
  
  // Initialize LCD
  lcd.begin(16, 2);
  lcd.clear();
  
  // Configure pin modes
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(GAS_SENSOR_PIN, INPUT);
  
  // Initialize system state
  digitalWrite(RED_LED_PIN, LOW);
  isPasswordMode = true;
  passwordIndex = 0;
  
  // Display welcome message
  displayWelcomeMessage();
  
  Serial.println(F("System initialized successfully!"));
  Serial.println(F("Default password: 1373"));
}

// ======================== MAIN LOOP ========================
void loop() {
  if (isPasswordMode) {
    handlePasswordInput();
  } else {
    handleGasMonitoring();
  }
}

// ======================== PASSWORD FUNCTIONS ========================
void handlePasswordInput() {
  char key = keypad.getKey();
  
  if (key && isPasswordMode) {
    if (key == '#') {
      // Reset password entry
      clearPasswordData();
      displayPasswordPrompt();
      Serial.println(F("Password entry reset"));
    } 
    else if (key == '=' && passwordIndex > 0) {
      // Backspace functionality
      passwordIndex--;
      enteredPassword[passwordIndex] = '\0';
      updatePasswordDisplay();
      Serial.println(F("Character deleted"));
    }
    else if (isdigit(key) && passwordIndex < (PASSWORD_LENGTH - 1)) {
      // Add digit to password
      enteredPassword[passwordIndex] = key;
      passwordIndex++;
      updatePasswordDisplay();
      Serial.print(F("Key pressed: "));
      Serial.println(key);
      
      // Check if password is complete
      if (passwordIndex == (PASSWORD_LENGTH - 1)) {
        enteredPassword[passwordIndex] = '\0';  // Null terminate
        validatePassword();
      }
    }
  }
}

void validatePassword() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("Checking..."));
  
  delay(500);  // Brief delay for user feedback
  
  lcd.clear();
  lcd.setCursor(0, 0);
  
  if (strcmp(enteredPassword, masterPassword) == 0) {
    // Password correct
    lcd.print(F("Access Granted!"));
    lcd.setCursor(0, 1);
    lcd.print(F("Welcome User"));
    
    tone(BUZZER_PIN, LOGIN_SUCCESS_TONE, LOGIN_SUCCESS_DURATION);
    
    isPasswordMode = false;
    Serial.println(F("LOGIN SUCCESS: Access granted"));
    
    delay(2000);
    lcd.clear();
    displayGasMonitoringUI();
  } else {
    // Password incorrect
    lcd.print(F("Access Denied!"));
    lcd.setCursor(0, 1);
    lcd.print(F("Try Again"));
    
    tone(BUZZER_PIN, WRONG_PASSWORD_TONE, WRONG_PASSWORD_DURATION);
    
    Serial.println(F("LOGIN FAILED: Incorrect password"));
    
    delay(2000);
    clearPasswordData();
    displayPasswordPrompt();
  }
}

void clearPasswordData() {
  passwordIndex = 0;
  for (int i = 0; i < PASSWORD_LENGTH; i++) {
    enteredPassword[i] = '\0';
  }
}

void displayWelcomeMessage() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("Gas Security Sys"));
  lcd.setCursor(0, 1);
  lcd.print(F("Initializing..."));
  delay(2000);
  
  displayPasswordPrompt();
}

void displayPasswordPrompt() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("Enter Password:"));
  lcd.setCursor(0, 1);
  lcd.print(F("____"));
  Serial.println(F("Waiting for password input..."));
}

void updatePasswordDisplay() {
  lcd.setCursor(0, 1);
  
  // Display asterisks for entered digits
  for (int i = 0; i < 4; i++) {
    if (i < passwordIndex) {
      lcd.print(F("*"));
    } else {
      lcd.print(F("_"));
    }
  }
}

// ======================== GAS MONITORING FUNCTIONS ========================
void handleGasMonitoring() {
  unsigned long currentTime = millis();
  
  // Read sensor at regular intervals
  if (currentTime - lastSensorRead >= SENSOR_READ_INTERVAL) {
    int gasLevel = readGasSensor();
    checkGasAlert(gasLevel);
    lastSensorRead = currentTime;
  }
  
  // Update display at regular intervals
  if (currentTime - lastDisplayUpdate >= DISPLAY_UPDATE_INTERVAL) {
    updateGasDisplay();
    lastDisplayUpdate = currentTime;
  }
  
  // Check for system lock command (press # to return to password mode)
  char key = keypad.getKey();
  if (key == '#') {
    lockSystem();
  }
}

int readGasSensor() {
  int rawValue = analogRead(GAS_SENSOR_PIN);
  
  // Print sensor data to serial for debugging
  Serial.print(F("Gas Sensor Raw Value: "));
  Serial.print(rawValue);
  Serial.print(F(" | Threshold: "));
  Serial.print(GAS_THRESHOLD);
  Serial.print(F(" | Status: "));
  Serial.println(rawValue > GAS_THRESHOLD ? F("ALERT") : F("SAFE"));
  
  return rawValue;
}

void checkGasAlert(int gasLevel) {
  if (gasLevel > GAS_THRESHOLD) {
    // Gas detected - activate alerts
    digitalWrite(RED_LED_PIN, HIGH);
    tone(BUZZER_PIN, GAS_ALARM_TONE, GAS_ALARM_DURATION);
  } else {
    // No gas detected - deactivate alerts
    digitalWrite(RED_LED_PIN, LOW);
    noTone(BUZZER_PIN);
  }
}

void updateGasDisplay() {
  int gasLevel = analogRead(GAS_SENSOR_PIN);
  
  lcd.setCursor(0, 0);
  lcd.print(F("Gas Level:      "));
  lcd.setCursor(0, 1);
  
  // Display gas level with status
  if (gasLevel > GAS_THRESHOLD) {
    lcd.print(F("ALERT! "));
    lcd.print(gasLevel);
    lcd.print(F("   "));
  } else {
    lcd.print(F("SAFE  "));
    lcd.print(gasLevel);
    lcd.print(F("   "));
  }
}

void displayGasMonitoringUI() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("Monitoring Gas"));
  lcd.setCursor(0, 1);
  lcd.print(F("Press # to lock"));
  delay(2000);
}

void lockSystem() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("System Locked"));
  lcd.setCursor(0, 1);
  lcd.print(F("Goodbye!"));
  
  // Turn off all alerts
  digitalWrite(RED_LED_PIN, LOW);
  noTone(BUZZER_PIN);
  
  Serial.println(F("SYSTEM LOCKED: Returning to password mode"));
  
  delay(2000);
  
  // Reset to password mode
  isPasswordMode = true;
  clearPasswordData();
  displayPasswordPrompt();
}

