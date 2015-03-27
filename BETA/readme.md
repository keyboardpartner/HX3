HX3 Beta Test Firmware
======================

<b>Beta test copy for evaluation with HX3 Remote application</b>

<b>Please note: These files are intended for Beta testers only and may contain undocumented features as well as unknown bugs.</b>

Copy and unzip single ZIP files or whole contents of this repo (full download link: 
https://github.com/heise/HOAX/archive/master.zip) to a new folder on your hard disk, for example E:\HX3\LATEST\. See 
http://wiki.keyboardpartner.de/index.php?title=HX3_Remote/Update_Application for details un update procedure. From
03/2015, ZIP files will contain all necessary files (including FPGA, AVR and ScanCores) plus appropriate HX3 Remote for 
mk2 as well as mk3 boards. Some beta releases will be mk3 only at first publishing.

### Update Procedure

* Download ZIP #3.80, unzip to new folder. Use only files/applications contained.
* Start HX3 Remote and connect. 
* Click "Update AVR" and select appropriate HEX file. After "Refresh Info" new AVR Version should be displayed.
* Click "Update FPGA" and select new FPGA_xxxxxx.bit file. This also uploads all scan cores and TG taper_level files.
* Set appropiate scan core and options near "Write Basics" button.
* Click "Write Basics".
* Check serials/licences, user and FW information after "Refresh Info". Done.

### Last Build

* HX3 Remote: #3.80 .exe for Windows XP and up
* HX3 Tapering	    .exe for Windows XP and up
* AVR:  #3.802      .hex and .eep files, latest firmware for AVR controller
* FPGA: #24032015   .bit configuration file for FPGA update
* SCAN: #$16        .dat ScanCore files


### Changelog

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

