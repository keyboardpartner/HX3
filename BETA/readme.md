HX3 Beta Firmware
=================

### Update Packages FOR BETA TESTERS ONLY

These packages are not intended for customer installation. May contain serious 
bugs. Use at your own risk. Do only use files contained in self-contained ZIP 
package.

### Last Build

* HX3 Remote: #4.10  .exe for Windows XP and up
* HX3 Flash: #3.925g   .exe for Windows XP and up
* HX3 Tapering	    .exe for Windows XP and up
* AVR:  #4.22      .hex and .eep files, latest firmware for AVR controller
* FPGA: #10102016   .bit configuration file for FPGA update
* SCAN: #33         .dat ScanCore files for MIDI and FATAR

### Changelog

03/13/2017 FatarScan #33

* Hardware inputs on PL16 for Sostenuto/Sustain pedal connection
* Sostenuto working with MIDI #64 and hardware inputs

Otherwise empty PL16 on mainboard was only used to output an auxiliary
MIDI signal for Neo Ventilator speed control on pin 7 and some internal
test signals. It now uses separate input pins 4 (for lower manual) and 6
(upper) for sustain and 3 (lower) and 5 (upper) for sostenuto. Switch
pins to ground (pin 10) to activate sustain or sostenuto on particular
manual. An additional 10-pin header is needed, solder in PL16 position.

If you don't need separate sutain/sostenuto inputs for upper and lower
manuals, just connect both inputs for each function, i.e. 4 and 6 for
sustain and 3 and 5 for sostenuto. Do not bridge all 4 inputs.

Both are controllable by MIDI CC #64 also (wired by "MIDI CC set" menu
to either sustain or sostenuto). These functions work even on splitted
manuals, so if you have lower on left part of manual, pin 3 affects only
sostenuto on left side. I think this should fit all needs.

03/13/2017 FatarScan #32

* DO NOT USE #31!
* improved key velocity on MIDI out
* improved click evaluation

(moved finalized files to LATEST directory)
