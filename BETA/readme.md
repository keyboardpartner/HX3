HX3 Beta Test Firmware
======================

<b>Beta test copy for evaluation with HX3 Remote application</b>

<b>Please note: These files are intended for Beta testers only and may contain undocumented features as well as unknown bugs.
If no ZIP is present, firmware has become final. See LATEST directory.</b>


Copy and unzip single ZIP files or whole contents of this repo (full download link: 
https://github.com/heise/HOAX/archive/master.zip) to a new folder on your hard disk, for example E:\HX3\LATEST\. See 
http://wiki.keyboardpartner.de/index.php?title=HX3_Remote/Update_Application for details un update procedure. From
03/2015, ZIP files will contain all necessary files (including FPGA, AVR and ScanCores) plus appropriate HX3 Remote for 
mk2 as well as mk3 boards. Some beta releases will be mk3 only at first publishing.

### Update Procedure

* Download latest ZIP, unzip to new folder. Use only files/applications contained.
* Plug in USB and power supply cable, start HX3 Remote and connect. 
* Click "Update FW" and select appropriate HEX file (for example "xxx_std" for HX3 board installations, "xxx_expander" for MIDI expander module). 
* Procedure takes about one minute, AVRdude progress shown in separate command window.
* Click "Update FPGA" and select new FPGA_xxxxxx.bit file. This also uploads all scan cores and TG taper_level files.
* Set appropiate scan core and options near "Write Basics" button.
* If your HX3 already has Licences installed, check "Auto Restore Licences" and "Use previous HX3 board info". 
* Otherwise, enter your Licence numbers in "Finalize Settings".
* Click "Finalize". This transfers licences and also creates a factory reset record on HX3 board.
* Check serials/licences, user and FW information after "Refresh Info". Done.

### Last Build

Note: If no ZIP present, firmware has become final. See LATEST directory.

* HX3 Remote: #3.80 .exe for Windows XP and up
* HX3 Tapering	    .exe for Windows XP and up
* AVR:  #3.806      .hex and .eep files, latest firmware for AVR controller
* FPGA: #25042015   .bit configuration file for FPGA update
* SCAN: #$16        .dat ScanCore files


### Changelog


<b>04/27/2015</b> FPGA #25042015

* Improved reproduction of upper notes leakage
* Pedal added to rotary simulation instead of plain output on "+B" audio configs

<b>03/29/2015</b> Firmware #3.806, FPGA #29032015, HX3 Remote #3.80, Scan Rev. #16

* Updated presets to Emil's "Hammond Theater Presets" - thanks to Emil for his help
* Cleaned up HX3 Remote user interface, moved some buttons to "Advaced" page
* Fixed some minor bugs in HX3 Remote preset file handling
* Re-work of firmware, FIR coefficients in flash memory instead of EEPROM, frees 512 EEPROM bytes for future use
* Cleaned up MIDI CC interpreters, making room for additional CC set
* Added MIDI CC support for both Hamichord and KeyB Duo (i.e. now 6 MIDI CC sets)
* Fixed "saved to upper" display bug

<b>03/27/2015</b> Firmware #3.802, FPGA #24032015, HX3 Remote #3.80, Scan Rev. #16

* Updated HX3_tapering.exe with better user interface
* Slightly changed bass pedal tapering
* Fixed Tone pot overflow bug
* Deleted obsolete Swell TrimCap param 483 in HX3 Remote


<b>03/17/2015</b> Firmware #3.801, FPGA #24032015, HX3 Remote #3.80, Scan Rev. #16

* Working copy for evaluation - not final!
* Complete rework of AO28 amp and tapering
* Editor for capacitor sets and tapering schemes (HX3_tapering.exe)
* Loadable capacitor sets (taper_levelsX.dat), upload by HX3 Remote
* Common Presets save current keyboard split mode and split point
* Binary combinations of Common Presets allowed (pressing two or more preset buttons at one time)
* 4 TG capacitor sets from 1955 to 1972 plus "Recapped" (more aggressive)
* Scan Cores "SysEx" and "MIDI Timing" bugs fixed
* Pedal foldback bug fixed, new pedal sound mix

