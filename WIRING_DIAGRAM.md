# Wiring Diagram - Arduino Gas Sensor Security System

## Complete Circuit Connections

### Arduino Uno Pin Assignment

```
Digital Pins:
D2  ← COL4 (Keypad)
D3  ← COL3 (Keypad)  
D4  ← COL2 (Keypad)
D5  ← COL1 (Keypad)
D6  ← ROW4 (Keypad)
D7  ← ROW3 (Keypad)
D8  ← ROW2 (Keypad)
D9  ← ROW1 (Keypad)
D10 ← RS (LCD)
D11 ← Not Used
D12 ← Red LED (+ terminal, with 220Ω resistor to GND)
D13 ← Buzzer (+ terminal)

Analog Pins:
A0  ← Enable (LCD)
A1  ← D4 (LCD)
A2  ← D5 (LCD)
A3  ← D6 (LCD)
A4  ← D7 (LCD)
A5  ← A0 (MQ-2 Gas Sensor)

Power Connections:
5V  ← VCC (MQ-2), VDD (LCD), + (LED via resistor)
GND ← GND (MQ-2), VSS (LCD), K (LCD), - (LED), - (Buzzer)
```

## Component-Specific Wiring

### 16x2 LCD Display
```
LCD Pin | Arduino Pin | Description
--------|-------------|------------
1 (VSS) | GND        | Ground
2 (VDD) | 5V         | Power +5V
3 (V0)  | Wiper of   | Contrast adjustment
        | 10kΩ Pot   | (Pot between 5V and GND)
4 (RS)  | D10        | Register Select
5 (E)   | A0         | Enable
6 (D0)  | Not Used   | Data Bit 0 (4-bit mode)
7 (D1)  | Not Used   | Data Bit 1 (4-bit mode)
8 (D2)  | Not Used   | Data Bit 2 (4-bit mode)
9 (D3)  | Not Used   | Data Bit 3 (4-bit mode)
10(D4)  | A1         | Data Bit 4
11(D5)  | A2         | Data Bit 5
12(D6)  | A3         | Data Bit 6
13(D7)  | A4         | Data Bit 7
14(A)   | 5V         | Backlight Anode
15(K)   | GND        | Backlight Cathode
```

### 4x4 Matrix Keypad
```
Keypad Pin | Arduino Pin | Row/Column | Keys
-----------|-------------|------------|-------------
1          | D9         | ROW1       | 1, 2, 3, F
2          | D8         | ROW2       | 4, 5, 6, F
3          | D7         | ROW3       | 7, 8, 9, F
4          | D6         | ROW4       | #, 0, =, F
5          | D5         | COL1       | 1, 4, 7, #
6          | D4         | COL2       | 2, 5, 8, 0
7          | D3         | COL3       | 3, 6, 9, =
8          | D2         | COL4       | F, F, F, F
```

### MQ-2 Gas Sensor Module
```
Sensor Pin | Arduino Pin | Description
-----------|-------------|------------
VCC        | 5V         | Power Supply
GND        | GND        | Ground
A0         | A5         | Analog Output
D0         | Not Used   | Digital Output (Optional)
```

### Alert System Components
```
Component | Pin | Arduino Pin | Additional Components
----------|-----|-------------|---------------------
Red LED   | +   | D12        | 220Ω resistor in series
Red LED   | -   | GND        | Direct connection
Buzzer    | +   | D13        | Direct connection
Buzzer    | -   | GND        | Direct connection
```

## Assembly Instructions

### Step 1: Prepare the Breadboard
1. Place Arduino Uno near the breadboard
2. Connect power rails: Red rail to 5V, Blue rail to GND
3. Use jumper wires to extend power connections

### Step 2: Install LCD Display
1. Place LCD on breadboard or use I2C backpack for easier wiring
2. Connect power (VDD to 5V, VSS to GND)
3. Install 10kΩ potentiometer for contrast control
4. Wire data and control pins as per table above
5. Connect backlight (A to 5V, K to GND)

### Step 3: Install Keypad
1. Connect 8 wires from keypad to Arduino digital pins
2. Use the pin mapping table above
3. Ensure solid connections to prevent input errors
4. Test each key after connection

### Step 4: Install Gas Sensor
1. Connect VCC to 5V power rail
2. Connect GND to ground rail
3. Connect A0 (analog output) to Arduino A5
4. Allow 2-3 minutes warm-up time after power-on

### Step 5: Install Alert Components
1. Connect LED with 220Ω current-limiting resistor
2. Connect buzzer directly to digital pin and ground
3. Test alert components before final assembly

### Step 6: Final Assembly
1. Double-check all connections
2. Ensure no short circuits
3. Secure all components
4. Upload code to Arduino
5. Test complete system

## Power Distribution

```
5V Rail Connections:
├── LCD VDD (Pin 2)
├── LCD Backlight Anode (Pin 14)
├── MQ-2 VCC
├── Potentiometer (one end)
└── Arduino 5V Pin

GND Rail Connections:
├── LCD VSS (Pin 1)
├── LCD Backlight Cathode (Pin 15)
├── MQ-2 GND
├── LED Cathode (via 220Ω resistor)
├── Buzzer Negative
├── Potentiometer (one end)
└── Arduino GND Pin
```

## Wire Color Recommendations

```
Connection Type | Recommended Color
----------------|------------------
Power (+5V)     | Red
Ground (GND)    | Black
Data Lines      | Various (Yellow, Green, Blue, etc.)
Analog Signals  | Orange
Digital I/O     | Various bright colors
```

## Testing Connections

### Continuity Testing
1. Use multimeter to check all connections
2. Verify no short circuits between power and ground
3. Test each data line for proper connection

### Component Testing
1. **LCD**: Should display startup message
2. **Keypad**: Each key should register in serial monitor
3. **Gas Sensor**: Should show readings in serial monitor
4. **LED**: Should light when gas threshold exceeded
5. **Buzzer**: Should sound during alerts and login

## Common Wiring Mistakes

### LCD Issues
- Reversed power connections (VDD/VSS)
- Missing contrast potentiometer
- Incorrect data pin mapping
- Missing backlight connections

### Keypad Issues
- Row/column pins swapped
- Missing or loose connections
- Incorrect pin mapping in code
- Multiple keys registering from one press

### Sensor Issues
- No power to sensor
- Analog pin not connected
- Sensor not warmed up
- Threshold set incorrectly

## Troubleshooting Guide

| Problem | Possible Cause | Solution |
|---------|----------------|----------|
| Blank LCD | No power/contrast | Check power, adjust potentiometer |
| Garbled LCD | Wrong connections | Verify data pin wiring |
| No keypad response | Loose wires | Check all 8 connections |
| Multiple key presses | Cross-talk | Check for shorts between pins |
| No gas readings | Sensor issue | Verify power and analog connection |
| Constant alerts | Wrong threshold | Adjust threshold in code |

## Safety Considerations

⚠️ **Important Safety Notes:**
- Double-check all connections before powering on
- Use appropriate wire gauge for current requirements
- Secure all connections to prevent intermittent failures
- Test in safe environment before deployment
- This is a learning project, not certified safety equipment

## Tools Required

- Breadboard (830 tie points recommended)
- Jumper wires (Male-to-Male, Male-to-Female)
- Wire strippers
- Multimeter (for testing)
- Small screwdriver (for potentiometer)
- Arduino IDE (for programming)

---

*Always verify connections twice before applying power to prevent component damage.*
