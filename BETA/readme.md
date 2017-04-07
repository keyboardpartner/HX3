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

<b>12/20/2016</b> Firmware #4.25, FPGA #03042017

* Glitches in filter assignment and leakage generation fixed
* internal signal processing 18 bits wide (was 16)
* Tuning capability, parameter "TG Gears Tune" on display, A = 433 to 447 Hz
* phase and amplitude noise/leakage improved
* Sustain/sostenuto hardware inputs on MIDI and FatarScan Core, see below
* Sostenuto CC #64 works also on FatarScan if enabled by MIDI CC menu
* Lowered distortion on TG notes 48 and up, less interference

Completely revised my old generator design, dating from 2012. There might have been a 
glitch in my old code that assigned wrong LC filter numbers (i.e. their 
simulation) to some generator notes, so some notes were to weak or too loud even 
with "new" tapering. New generator has a smooth response with "new caps" 
selected in menu. Please revise your own tapering files if needed. Also FM/phase 
noise revised, may need readjustment of TG Flutter param to get that "blowing a 
bottle whoosh" (can't describe it better) on each note.

<b>03/13/2017</b> FatarScan #33

* Hardware inputs on PL16 for Sostenuto/Sustain pedal connection
* Sostenuto working with MIDI #64 and hardware inputs
* improved key velocity on MIDI out, FatarScan #33
* improved click evaluation

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


(moved finalized files to LATEST directory)
