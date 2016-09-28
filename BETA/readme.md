HX3 Beta Firmware
=================

### Update Packages FOR BETA TESTERS ONLY

These packages are not intended for customer installation. May contain serious 
bugs. Use at your own risk. Do only use files contained in self-contained ZIP 
package.

### Last Build

* HX3 Remote: #4.01  .exe for Windows XP and up
* HX3 Flash: #3.925g   .exe for Windows XP and up
* HX3 Tapering	    .exe for Windows XP and up
* AVR:  #4.10      .hex and .eep files, latest firmware for AVR controller
* FPGA: #25092016   .bit configuration file for FPGA update
* SCAN: #30         .dat ScanCore files for MIDI and FATAR

### Changelog

<b>09/27/2016</b> Firmware #4.1, FPGA #25092016 (both in Remote_for_all.zip)

* New Chorus Vibrato Routing, new parameters in menu and HX3 Remote:
* Scanner Gears: Vibrato modulation frequency
* Scanner Leak: Leakage of unmodulated signal on V1/V2/V3
* VibCh AmplMod: Modulation of upper frequency limit of LC linebox
* VibCh Preemphasis: Treble enhancement on Vib/Ch
* VibCh Reflect: Reflections on LC linebox due to aged capacitors
* VibCh Response: upper frequency limit of LC linebox
* Ch LineboxLvl: Vibrato mix on Chorus C1/C2/C3
* Ch BypassLvl: Dry mix on Chorus C1/C2/C3
* V1 ModAmount: Modulation depth on V1
* ...
* C3 ModAmount: Modulation depth on C3
* Adjustable busbar levels for each drawbar (by HX3 Remote only)


<b>06/27/2016</b> FATAR ScanCore #25, MIDI ScanCore #30

* Added separate update package for FATAR/MIDI, will update ScanCore only
* Changed MIDI velocity scaling to triple squared curve in FATAR ScanCore 
* "Missing notes" bug in FATAR ScanCore fixed
* New MIDI ScanCore #30 with 88 key support, full transpose 24 notes, upper manual split +1 and +2 octaves on lower part

(moved finalized files to LATEST directory)
