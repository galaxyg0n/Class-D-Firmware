# Firmware for an Class D amplifier
This is the firmware for an extended project of an Class D amplifier made in an SMD soldering course on SDU Odense

### Specs
- ATmega328P MCU
- 0.91" OLED Display
- Bluetooth audio in
- AUX (3.5mm jack) audio in
- 6.35mm jack audio in
- 2 channel RCA audio in
-------------------------------------------
- 2x25W channels
- 2 channel RCA audio out


### Vscode project setup
- Download AVRDUDE for compilation
- Change the "C:\\WinAVR-20100110\\avr\\include" path in c_cpp_properties.json to fit with wherever your avr libraries are
- Test MakeFile (should work universally)

### TODO
- Finish README.md
