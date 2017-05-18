/*

   Demonstrates the use a 16x2 LCD display and
  4x4 LCD display.  T

   The  Arduino circuit connection for LCD:

   * LCD RS  pin to analog pin A0

   * LCD  Enable pin to analog pin A1

   * LCD D4  pin to analog pin A2

   * LCD D5  pin to analog pin A3

   * LCD D6  pin to analog pin A4

   * LCD D7  pin to analog pin A5

   The  Arduino circuit connection for MAtrix Key Pad:

   * ROW1 pin  to digital pin 9

   * ROW2 pin  to digital pin 8

   * ROW3 pin  to digital pin 7

   * ROW4 pin  to digital pin 6

   * COLUMN1  pin to digital pin 5

   * COLUMN2  pin to digital pin 4

   * COLUMN3  pin to digital pin 3

   * COLUMN4  pin to digital pin 2

   Name:-  Arman Sheikh Hosseini

   Date:-   may2017

   Version:-  V0.1

   e-mail:-  arman.sheikhhosseini@gmail.com

   */

  // include the library code:

 #include <LiquidCrystal.h>
 
 #include <Keypad.h>

  LiquidCrystal lcd(10,A0,A1,A2,A3,A4);

  //4x4 Matrix key pad

  const byte ROWS = 4; // Four rows

  const byte COLS = 4; // Four columns

  // Define the Keymap

  char keys[ROWS][COLS] = 

  {

   
  {'1','2','3','F'},

   
  {'4','5','6','F'},

   
  {'7','8','9','F'},

   
  {'#','0','=','F'}

  };

  // Connect keypad ROW0, ROW1, ROW2 and ROW3 to  Arduino pins.

  byte rowPins[ROWS] = { 9, 8, 7, 6 };

  // Connect keypad COL0, COL1, COL2 and COL3 to  Arduino pins.

  byte colPins[COLS] = { 5, 4, 3, 2 }; 

  // Create the Keypad
  Keypad kpd = Keypad( makeKeymap(keys), rowPins,
  colPins, ROWS, COLS );


//password configuration

#define Password_Lenght 5 // Give enough room for six chars + NULL char
 
char Data[Password_Lenght]; // 6 is the number of chars it can hold + the null char = 7
char Master[Password_Lenght] = "1373"; 
byte data_count = 0,newCodeCount=0;
bool Pass_is_good;
char customKey;

bool PasswordMode ;



/////////////////////////



int redLed = 12;
int buzzer = 13;
int smokeA0 = A5;
// Your threshold value
int sensorThres = 500;




 ///////////////////////

  void setup() 

  {
PasswordMode=true;

     

    // set up the LCD's number of columns and rows:

   
  lcd.begin(16, 2);

    // Print  a message to the LCD.

   
//////////////////
  pinMode(redLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);

///////
  }

  void loop()
{
  if(PasswordMode==true){
   getPassword();
  }

  if(PasswordMode==false){
    getSensor();
  
    lcd.setCursor(0, 0);
       lcd.print("sensor Thresh:");
        lcd.setCursor(0, 1);
        
       
          lcd.print(getSensor());
     
        delay(100);

  }
}


int getSensor(){
  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    digitalWrite(redLed, HIGH);
    tone(buzzer, 700, 50);

  }
  else
  {
    digitalWrite(redLed, LOW);
    noTone(buzzer);
  }
  return analogSensor;
  delay(100);
}


void getPassword(){


  
   lcd.setCursor(0,0);
  lcd.print("Enter Password:");
  



  customKey = kpd.getKey();

  
  
  if (customKey && PasswordMode==true ) // makes sure a key is actually pressed, equal to (customKey != NO_KEY)
  {
    Data[data_count] = customKey; // store char into data array
    lcd.setCursor(data_count,1); // move cursor to show each new char
    lcd.print(Data[data_count]); // print char at said cursor
    data_count++; // increment data array by 1 to store new char, also keep track of the number of chars entered
  }

  if(data_count == Password_Lenght-1 && PasswordMode==true) // if the array index is equal to the number of expected chars, compare data to master
  {
     
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Password is ");

    if(!strcmp(Data, Master)){ // equal to (strcmp(Data, Master) == 0)
       tone(buzzer, 4000, 1000);
      lcd.print("Good");

       lcd.setCursor(0, 1);
       lcd.print("Loging in");
      PasswordMode=false;
    
    }
    else{
      lcd.print("Bad");
      tone(buzzer, 500, 500);
    }
    delay(1000);// added 1 second delay to make sure the password is completely shown on screen before it gets cleared.
    lcd.clear();
    clearData();  
   
  }
}

void clearData()
{
  while(data_count !=0)
  {   // This can be used for any array size, 
    Data[data_count--] = 0; //clear array for new data
  }
  return;
}

