# Bill of Materials (BOM) - Arduino Gas Sensor Security System

## Core Components

| Item # | Component | Quantity | Description | Approximate Cost (USD) |
|--------|-----------|----------|-------------|------------------------|
| 1 | Arduino Uno R3 | 1 | Main microcontroller board | $25.00 |
| 2 | MQ-2 Gas Sensor Module | 1 | Multi-gas detection sensor | $8.00 |
| 3 | 16x2 LCD Display (HD44780) | 1 | Character display with backlight | $12.00 |
| 4 | 4x4 Matrix Keypad | 1 | Membrane keypad for input | $6.00 |
| 5 | Active Buzzer | 1 | 5V piezo buzzer | $2.00 |
| 6 | Red LED (5mm) | 1 | Visual indicator | $0.50 |
| 7 | 220Ω Resistor | 1 | Current limiting for LED | $0.10 |
| 8 | 10kΩ Potentiometer | 1 | LCD contrast adjustment | $1.00 |
| 9 | Breadboard (830 points) | 1 | Circuit prototyping | $8.00 |
| 10 | USB Cable (A to B) | 1 | Programming and power | $5.00 |

**Subtotal Core Components: $67.60**

## Connection Components

| Item # | Component | Quantity | Description | Approximate Cost (USD) |
|--------|-----------|----------|-------------|------------------------|
| 11 | Male-to-Male Jumper Wires | 20 | Breadboard connections | $3.00 |
| 12 | Male-to-Female Jumper Wires | 10 | Component connections | $3.00 |
| 13 | Female-to-Female Jumper Wires | 5 | Optional connections | $2.00 |

**Subtotal Connection Components: $8.00**

## Optional Enhancements

| Item # | Component | Quantity | Description | Approximate Cost (USD) |
|--------|-----------|----------|-------------|------------------------|
| 14 | Project Enclosure | 1 | Plastic case for protection | $15.00 |
| 15 | 9V Battery + Connector | 1 | Portable power option | $8.00 |
| 16 | Power Jack | 1 | External power input | $2.00 |
| 17 | On/Off Switch | 1 | Power control | $2.00 |
| 18 | Heat Shrink Tubing | 1m | Wire protection | $3.00 |
| 19 | Perfboard | 1 | Permanent circuit board | $5.00 |
| 20 | IC Sockets | 2 | Component protection | $2.00 |

**Subtotal Optional Components: $37.00**

## Tools and Supplies

| Item # | Tool/Supply | Quantity | Description | Approximate Cost (USD) |
|--------|-------------|----------|-------------|------------------------|
| 21 | Wire Strippers | 1 | For preparing wires | $10.00 |
| 22 | Diagonal Cutters | 1 | Wire cutting | $8.00 |
| 23 | Multimeter | 1 | Testing and debugging | $25.00 |
| 24 | Soldering Iron Kit | 1 | For permanent connections | $30.00 |
| 25 | Solder (60/40) | 1 roll | Electronic solder | $8.00 |
| 26 | Flux | 1 | Soldering aid | $5.00 |
| 27 | Desoldering Braid | 1 | Error correction | $3.00 |
| 28 | Anti-static Wrist Strap | 1 | Component protection | $5.00 |

**Subtotal Tools and Supplies: $94.00**

## Software Requirements

| Item | Description | Cost |
|------|-------------|------|
| Arduino IDE | Free development environment | Free |
| Keypad Library | Arduino keypad library | Free |
| USB Drivers | Arduino board drivers | Free |

**Total Software Cost: $0.00**

## Component Specifications

### Arduino Uno R3
- **Microcontroller**: ATmega328P
- **Operating Voltage**: 5V
- **Input Voltage**: 7-12V (recommended)
- **Digital I/O Pins**: 14 (6 PWM outputs)
- **Analog Input Pins**: 6
- **Flash Memory**: 32KB
- **SRAM**: 2KB
- **EEPROM**: 1KB
- **Clock Speed**: 16MHz

### MQ-2 Gas Sensor
- **Operating Voltage**: 5V ±0.1V
- **Current Consumption**: 150mA
- **Detection Range**: 200-10,000ppm
- **Response Time**: <10s
- **Recovery Time**: <30s
- **Detected Gases**: LPG, Propane, Hydrogen, Methane, Alcohol, Smoke
- **Operating Temperature**: -10°C to 50°C
- **Operating Humidity**: <95%RH

### 16x2 LCD Display
- **Controller**: HD44780 or compatible
- **Display**: 16 characters × 2 lines
- **Character Size**: 5×8 dots
- **Operating Voltage**: 5V
- **Interface**: 4-bit or 8-bit parallel
- **Backlight**: Blue/Green LED
- **Viewing Angle**: 6 o'clock
- **Operating Temperature**: 0°C to 50°C

### 4x4 Matrix Keypad
- **Type**: Membrane keypad
- **Layout**: 4 rows × 4 columns
- **Operating Voltage**: 3.3V - 5V
- **Contact Resistance**: <100Ω
- **Insulation Resistance**: >100MΩ
- **Operating Force**: 100-300g
- **Life Expectancy**: >1 million actuations
- **Operating Temperature**: -20°C to 70°C

## Recommended Suppliers

### Online Retailers
1. **Arduino Official Store** - Genuine Arduino boards
2. **Adafruit** - Quality components and tutorials
3. **SparkFun** - Educational electronics
4. **Amazon** - Wide selection, fast shipping
5. **AliExpress** - Budget options (longer shipping)
6. **Digi-Key** - Professional electronic components
7. **Mouser Electronics** - Industrial grade components

### Local Suppliers
- Electronics hobby stores
- University bookstores
- Maker spaces
- Radio Shack (where available)

## Cost Analysis

| Category | Minimum Cost | Recommended Cost | Premium Cost |
|----------|--------------|------------------|--------------|
| Core Components | $67.60 | $67.60 | $90.00 |
| Connections | $8.00 | $8.00 | $15.00 |
| Optional Items | $0.00 | $20.00 | $37.00 |
| Tools (if needed) | $0.00 | $50.00 | $94.00 |
| **Total** | **$75.60** | **$145.60** | **$236.00** |

## Budget Alternatives

### Ultra-Budget Version ($45)
- Arduino Nano (clone) - $8
- MQ-2 Sensor Module - $5
- 16x2 LCD - $8
- 4x4 Keypad - $4
- Basic components - $10
- Breadboard and wires - $10

### Educational Kit Version ($120)
- All basic components
- Project enclosure
- Comprehensive documentation
- Additional sensors for experiments
- Soldering practice kit

### Professional Version ($300+)
- Genuine Arduino components
- Industrial-grade sensors
- Professional enclosure
- PCB fabrication
- Comprehensive tool kit

## Ordering Checklist

### Before Ordering
- [ ] Verify Arduino IDE compatibility
- [ ] Check local voltage requirements
- [ ] Consider shipping costs and times
- [ ] Read component reviews
- [ ] Verify seller reputation

### When Ordering
- [ ] Order 10% extra small components (resistors, wires)
- [ ] Include basic tools if not owned
- [ ] Consider buying component variety packs
- [ ] Check for bundle deals
- [ ] Verify return policy

### After Receiving
- [ ] Inspect all components for damage
- [ ] Test Arduino board before assembly
- [ ] Verify LCD display functionality
- [ ] Check keypad key response
- [ ] Test gas sensor output

## Storage and Organization

### Component Storage
- Anti-static bags for ICs
- Small parts organizer for resistors/LEDs
- Protective case for Arduino board
- Dry storage for sensors

### Workspace Setup
- Good lighting
- Anti-static work surface
- Organized tool arrangement
- Adequate ventilation
- Fire extinguisher nearby (for soldering)

## Maintenance Schedule

### Weekly (During Active Use)
- Visual inspection of connections
- Clean LCD display
- Check for loose wires

### Monthly
- Test all system functions
- Calibrate gas sensor if needed
- Check power supply stability
- Update software if needed

### Annually
- Replace gas sensor (if used frequently)
- Deep clean all components
- Inspect for component aging
- Update documentation

---

**Note**: Prices are approximate and may vary based on location, supplier, and market conditions. Always compare prices from multiple sources before purchasing.
