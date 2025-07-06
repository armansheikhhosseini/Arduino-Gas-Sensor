# Arduino Gas Sensor Security System

A comprehensive Arduino-based gas detection and security system that combines gas sensing capabilities with password protection. This project uses an MQ-2 gas sensor to detect various gases and includes a keypad authentication system for secure access.

## 🚀 Features

- **Multi-Gas Detection**: Detects LPG, i-butane, propane, methane, alcohol, hydrogen, and smoke
- **Password Protection**: Secure 4x4 keypad authentication system
- **Visual Alerts**: LED indicators for system status and gas detection
- **Audio Alerts**: Buzzer alarms for gas detection and system feedback
- **LCD Display**: 16x2 LCD for real-time sensor readings and system status
- **Adjustable Sensitivity**: Configurable threshold values for gas detection
- **Real-time Monitoring**: Continuous sensor monitoring with serial output

## 🛠️ Hardware Requirements

### Components
- **Arduino Uno/Nano** (or compatible)
- **MQ-2 Gas Sensor Module**
- **16x2 LCD Display**
- **4x4 Matrix Keypad**
- **Buzzer** (Active or Passive)
- **LED** (Red for alerts)
- **Resistors** (220Ω for LED, 10kΩ for LCD contrast)
- **Breadboard and Jumper Wires**
- **Power Supply** (9V or USB)

### Libraries Required
- `LiquidCrystal.h` (built-in)
- `Keypad.h` ([Download here](https://github.com/Chris--A/Keypad))

## 📋 Circuit Connections

### LCD Display (16x2)
- **RS** → Analog Pin A0
- **Enable** → Analog Pin A1
- **D4** → Analog Pin A2
- **D5** → Analog Pin A3
- **D6** → Analog Pin A4
- **D7** → Analog Pin A5
- **VSS** → GND
- **VDD** → 5V
- **V0** → Potentiometer (contrast adjustment)

### 4x4 Matrix Keypad
- **ROW1** → Digital Pin 9
- **ROW2** → Digital Pin 8
- **ROW3** → Digital Pin 7
- **ROW4** → Digital Pin 6
- **COL1** → Digital Pin 5
- **COL2** → Digital Pin 4
- **COL3** → Digital Pin 3
- **COL4** → Digital Pin 2

### MQ-2 Gas Sensor
- **VCC** → 5V
- **GND** → GND
- **A0** → Analog Pin A5
- **D0** → Not used (optional digital output)

### Alert System
- **Red LED** → Digital Pin 12 (with 220Ω resistor)
- **Buzzer** → Digital Pin 13

## ⚙️ Installation & Setup

1. **Install Arduino IDE**: Download from [arduino.cc](https://www.arduino.cc/en/software)

2. **Install Required Libraries**:
   ```
   Sketch → Include Library → Manage Libraries
   Search for "Keypad" and install the library by Mark Stanley and Alexander Brevig
   ```

3. **Circuit Assembly**: Connect components according to the wiring diagram above

4. **Upload Code**: 
   - Open `GasSensor.ino` in Arduino IDE
   - Select your board and port
   - Upload the code to your Arduino

5. **Calibration**:
   - Let the sensor warm up for 2-3 minutes
   - Adjust the threshold value in code if needed (default: 500)
   - Test with different gases to fine-tune sensitivity

## 🔧 Configuration

### Default Settings
- **Password**: `1373` (can be changed in code)
- **Gas Threshold**: `500` (adjustable based on your needs)
- **Buzzer Frequency**: `700Hz` for gas detection, `4000Hz` for login success

### Customization Options
```cpp
// Change default password (max 4 characters)
char Master[Password_Lenght] = "1373";

// Adjust gas detection sensitivity
int sensorThres = 500;

// Modify buzzer tones
tone(buzzer, 700, 50);  // Gas detection alarm
tone(buzzer, 4000, 1000);  // Login success
```

## 🎮 Usage

1. **Power On**: Connect Arduino to power source
2. **Authentication**: Enter the 4-digit password using the keypad (default: 1373)
3. **Monitoring**: After successful login, the system displays real-time gas sensor readings
4. **Alert Response**: When gas levels exceed the threshold:
   - Red LED lights up
   - Buzzer sounds alarm
   - Continue monitoring until levels return to normal

### Keypad Layout
```
[ 1 ] [ 2 ] [ 3 ] [ F ]
[ 4 ] [ 5 ] [ 6 ] [ F ]
[ 7 ] [ 8 ] [ 9 ] [ F ]
[ # ] [ 0 ] [ = ] [ F ]
```

## 🔬 Technical Specifications

- **Operating Voltage**: 5V DC
- **Gas Detection Range**: 200-10000 ppm
- **Response Time**: < 10 seconds
- **Recovery Time**: < 30 seconds
- **Operating Temperature**: -10°C to 50°C
- **Operating Humidity**: < 95% RH

## 🐛 Troubleshooting

### Common Issues

**LCD not displaying properly**
- Check wiring connections
- Adjust contrast using potentiometer
- Verify 5V power supply

**Keypad not responding**
- Check row/column pin connections
- Ensure proper library installation
- Test individual keys

**Gas sensor not detecting**
- Allow 2-3 minutes warm-up time
- Check analog pin connection (A5)
- Adjust threshold value in code

**False alarms**
- Increase threshold value
- Ensure proper ventilation during testing
- Check for electrical interference

## 🛡️ Safety Considerations

- **Ventilation**: Always test in well-ventilated areas
- **Calibration**: Regular calibration recommended for accurate readings
- **Power**: Use stable power supply to avoid false readings
- **Placement**: Mount sensor away from heat sources and direct airflow

## 🔄 Future Enhancements

- WiFi connectivity for remote monitoring
- Data logging to SD card or cloud
- Multiple sensor support
- SMS/Email alerts
- Mobile app integration
- Web dashboard for monitoring

## 📊 Circuit Simulation

[View Interactive Circuit Simulation](https://circuits.io/circuits/4967518-gas-sensor-with-login-password/embed#breadboard)

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 👨‍💻 Author

**Arman Sheikhhosseini**
- Email: arman.sheikhhosseini@gmail.com
- GitHub: [@armansheikhhosseini](https://github.com/armansheikhhosseini)

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## ⭐ Support

If you found this project helpful, please give it a star on GitHub!
