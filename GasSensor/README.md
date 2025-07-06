# Gas Sensor Security System

A sophisticated Arduino-based security system that combines gas detection with password authentication for enhanced safety and security.

## 🔥 Project Overview

This project implements a comprehensive safety monitoring system using an MQ-2 gas sensor that can detect multiple types of gases including LPG, propane, methane, alcohol, hydrogen, and smoke. The system features password-protected access and provides both visual and audio alerts when dangerous gas levels are detected.

## 🎯 Key Features

### Security Features
- **Password Protection**: 4-digit keypad authentication system
- **User Authentication**: Secure login with configurable password
- **System Lock**: Ability to lock the system and return to password mode
- **Access Control**: Prevents unauthorized access to monitoring functions

### Gas Detection Capabilities
- **Multi-Gas Detection**: Detects LPG, i-butane, propane, methane, alcohol, hydrogen, and smoke
- **Adjustable Sensitivity**: Configurable threshold for different environments
- **Real-time Monitoring**: Continuous sensor readings with 100ms update intervals
- **Automatic Calibration**: Self-adjusting sensor baseline

### Alert System
- **Visual Alerts**: Red LED indicator for gas detection
- **Audio Alerts**: Buzzer with different tones for various system states
- **LCD Display**: Real-time sensor readings and system status
- **Serial Monitoring**: Debug output for troubleshooting

### User Interface
- **16x2 LCD Display**: Clear status messages and sensor readings
- **4x4 Matrix Keypad**: Easy password input and system control
- **Intuitive Controls**: Simple navigation with visual feedback
- **Status Indicators**: Clear system state communication

## 🛠️ Hardware Components

| Component | Quantity | Purpose |
|-----------|----------|---------|
| Arduino Uno/Nano | 1 | Main microcontroller |
| MQ-2 Gas Sensor | 1 | Gas detection |
| 16x2 LCD Display | 1 | User interface |
| 4x4 Matrix Keypad | 1 | Password input |
| Buzzer | 1 | Audio alerts |
| Red LED | 1 | Visual alerts |
| 220Ω Resistor | 1 | LED current limiting |
| 10kΩ Potentiometer | 1 | LCD contrast adjustment |
| Breadboard | 1 | Circuit assembly |
| Jumper Wires | 20+ | Connections |

## 📐 Detailed Wiring Diagram

### LCD Display Connections
```
LCD Pin    →  Arduino Pin    →  Function
VSS        →  GND           →  Ground
VDD        →  5V            →  Power
V0         →  Potentiometer →  Contrast
RS         →  A0            →  Register Select
Enable     →  A1            →  Enable Signal
D4         →  A2            →  Data Bit 4
D5         →  A3            →  Data Bit 5
D6         →  A4            →  Data Bit 6
D7         →  A5            →  Data Bit 7
A          →  5V            →  Backlight Anode
K          →  GND           →  Backlight Cathode
```

### 4x4 Keypad Connections
```
Keypad Pin →  Arduino Pin  →  Function
ROW1       →  9           →  Row 1 (1,2,3,F)
ROW2       →  8           →  Row 2 (4,5,6,F)
ROW3       →  7           →  Row 3 (7,8,9,F)
ROW4       →  6           →  Row 4 (#,0,=,F)
COL1       →  5           →  Column 1 (1,4,7,#)
COL2       →  4           →  Column 2 (2,5,8,0)
COL3       →  3           →  Column 3 (3,6,9,=)
COL4       →  2           →  Column 4 (F,F,F,F)
```

### MQ-2 Gas Sensor Connections
```
Sensor Pin →  Arduino Pin  →  Function
VCC        →  5V           →  Power Supply
GND        →  GND          →  Ground
A0         →  A5           →  Analog Output
D0         →  Not Used     →  Digital Output (Optional)
```

### Alert System Connections
```
Component     →  Arduino Pin  →  Additional Components
Red LED (+)   →  12          →  220Ω Resistor to GND
Red LED (-)   →  GND         →  Direct connection
Buzzer (+)    →  13          →  Direct connection
Buzzer (-)    →  GND         →  Direct connection
```

## ⚡ Power Requirements

- **Operating Voltage**: 5V DC (via USB or external adapter)
- **Current Consumption**: ~200mA (including all components)
- **Recommended Power**: 9V DC adapter or USB power bank
- **Sensor Warm-up**: Allow 2-3 minutes for stable readings

## 🔧 Software Configuration

### Default Settings
```cpp
const char masterPassword[PASSWORD_LENGTH] = "1373";  // Default password
const int GAS_THRESHOLD = 500;                        // Detection threshold
const int LOGIN_SUCCESS_TONE = 4000;                  // Success beep frequency
const int GAS_ALARM_TONE = 700;                       // Alert beep frequency
```

### Customization Options

**Change Password:**
```cpp
const char masterPassword[PASSWORD_LENGTH] = "YOUR_PASSWORD";
```

**Adjust Sensitivity:**
```cpp
const int GAS_THRESHOLD = 400;  // Lower = more sensitive
```

**Modify Alert Tones:**
```cpp
const int LOGIN_SUCCESS_TONE = 3000;    // Hz
const int GAS_ALARM_TONE = 800;         // Hz
```

## 🎮 Operation Guide

### System Startup
1. Power on the Arduino
2. Wait for "Gas Security Sys" welcome message
3. System will prompt for password entry

### Authentication Process
1. Use the keypad to enter the 4-digit password (default: 1373)
2. **#** key resets current password entry
3. **=** key acts as backspace
4. System validates password and grants/denies access

### Gas Monitoring Mode
1. After successful login, system displays real-time gas levels
2. **SAFE** status shows normal operation
3. **ALERT** status indicates gas detection above threshold
4. Press **#** to lock system and return to password mode

### Keypad Layout and Functions
```
[ 1 ] [ 2 ] [ 3 ] [ F ]
[ 4 ] [ 5 ] [ 6 ] [ F ]
[ 7 ] [ 8 ] [ 9 ] [ F ]
[ # ] [ 0 ] [ = ] [ F ]

# = Reset password entry / Lock system
= = Backspace function
0-9 = Number input
F = Not used (reserved for future features)
```

## 📊 Sensor Specifications

### MQ-2 Technical Details
- **Detection Range**: 200-10000 ppm
- **Sensitivity**: Adjustable via onboard potentiometer
- **Response Time**: < 10 seconds
- **Recovery Time**: < 30 seconds
- **Operating Temperature**: -10°C to 50°C
- **Operating Humidity**: < 95% RH (non-condensing)

### Detected Gases
| Gas Type | Typical Range | Applications |
|----------|---------------|--------------|
| LPG | 200-5000 ppm | Kitchen gas leaks |
| Propane | 200-5000 ppm | Outdoor grills, heaters |
| Methane | 300-10000 ppm | Natural gas leaks |
| Alcohol | 25-500 ppm | Breath analyzer applications |
| Hydrogen | 300-5000 ppm | Industrial applications |
| Smoke | Variable | Fire detection |

## 🛡️ Safety Guidelines

### Installation Safety
- ⚠️ **Never install near ignition sources**
- ⚠️ **Ensure proper ventilation during testing**
- ⚠️ **Use in dry environments only**
- ⚠️ **Regular calibration recommended**

### Operational Safety
- 🔥 **This is NOT a certified safety device**
- 🔥 **Use as a supplementary monitoring tool only**
- 🔥 **Professional gas detection equipment recommended for critical applications**
- 🔥 **Regular maintenance and calibration required**

## 🔍 Troubleshooting

### Common Issues and Solutions

**Problem**: LCD shows garbled text
- **Solution**: Check wiring connections, adjust contrast potentiometer

**Problem**: Keypad not responding
- **Solution**: Verify row/column connections, check library installation

**Problem**: Gas sensor always shows high readings
- **Solution**: Allow 2-3 minute warm-up, check if sensor needs replacement

**Problem**: No gas detection
- **Solution**: Test threshold settings, verify analog pin connection

**Problem**: System keeps asking for password
- **Solution**: Check password in code, verify keypad connections

**Problem**: False alarms
- **Solution**: Increase threshold value, check for electrical interference

### Diagnostic Commands
Monitor the Serial output (9600 baud) for debugging information:
- Gas sensor raw values
- Password entry attempts
- System state changes
- Threshold comparisons

## 🚀 Future Enhancements

### Planned Features
- [ ] WiFi connectivity for remote monitoring
- [ ] Data logging to SD card
- [ ] Multiple user support with different access levels
- [ ] SMS/Email alerts via GSM module
- [ ] Web interface for configuration
- [ ] Mobile app for remote monitoring

### Hardware Upgrades
- [ ] Battery backup system
- [ ] Multiple sensor support (CO, CO2, etc.)
- [ ] Outdoor weatherproof enclosure
- [ ] Solar power option
- [ ] Wireless sensor nodes

## 📋 Testing Procedure

### Initial Setup Testing
1. **Power Test**: Verify all components power on correctly
2. **Display Test**: Check LCD shows clear text
3. **Keypad Test**: Test all keys respond correctly
4. **Audio Test**: Verify buzzer produces different tones

### Sensor Calibration
1. **Baseline Reading**: Record sensor value in clean air
2. **Threshold Setting**: Adjust based on environment
3. **Response Test**: Test with safe gas source (alcohol swab)
4. **Recovery Test**: Verify sensor returns to baseline

### Security Testing
1. **Password Test**: Verify correct password grants access
2. **Wrong Password**: Confirm incorrect password is rejected
3. **Lock Function**: Test system lock functionality
4. **Reset Test**: Verify password reset works correctly

## 📞 Support

If you encounter issues or have questions:

1. **Check Wiring**: Verify all connections match the diagram
2. **Serial Monitor**: Check debug output for error messages
3. **Library Version**: Ensure you have the latest Keypad library
4. **Power Supply**: Verify stable 5V power supply

## 🎯 Project Applications

- **Home Safety**: Kitchen gas leak detection
- **Industrial Monitoring**: Workplace gas safety
- **Educational Projects**: Learning about sensors and security
- **Prototype Development**: Base for commercial gas detectors
- **Research Projects**: Environmental monitoring studies

## 📈 Performance Metrics

- **Response Time**: < 10 seconds for gas detection
- **Update Rate**: Display updates every 500ms
- **Sensor Reading**: Every 100ms for real-time monitoring
- **Password Processing**: Immediate keypress response
- **System Stability**: Continuous operation capability

## 🏆 Interactive Demo

Experience the project in action: [Circuit Simulator](https://circuits.io/circuits/4967518-gas-sensor-with-login-password/embed#breadboard)

**Default Login Credentials**: `1373`

---

*This project demonstrates the integration of multiple Arduino components to create a functional safety monitoring system. While suitable for educational and prototype purposes, professional-grade equipment should be used for critical safety applications.*
