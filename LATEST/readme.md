HX3 Latest Firmware
===================

#### Working releases for update with HX3 Remote application

### Update Packages for Customers

New: Complete update packages for most common HX3 instruments for a hassle-free update to newest version. 
The ZIPs Flash_XXX.zip contain only the files needed for your instrument. You don't need the other HX3 stuff offered here.
For example, if you own a **HX3 MIDI Expander Plexi**, download 
**[Flash_Expander_mk3_4.zip] (https://github.com/keyboardpartner/HX3/blob/master/LATEST/Flash_Expander_mk3_4.zip?raw=true)** and unzip folder to local hard disk.
It countains the new <b>HX3 Flash utility</b> which will run a complete update free of doubt. 
See wiki page **[HX3_Update_Application] (http://wiki.keyboardpartner.de/index.php?title=HX3_Update_Application)** for description.

Following update packages are available:

* **[Flash_DrawbarExpander.zip] (https://github.com/keyboardpartner/HX3/blob/master/LATEST/Flash_DrawbarExpander.zip?raw=true)** - for new HX3 DrawbarExpander
* **[Flash_Expander_mk2.zip] (https://github.com/keyboardpartner/HX3/blob/master/LATEST/Flash_ExpanderPlexi_mk2.zip?raw=true)** - for HX3 MIDI Expander Plexi, older mk2 version
* **[Flash_Expander_mk3_4.zip] (https://github.com/keyboardpartner/HX3/blob/master/LATEST/Flash_ExpanderPlexi_mk3_4.zip?raw=true)** - for HX3 MIDI Expander Plexi USB, current mk3/mk4 versions
* **[Flash_OrganMag.zip] (https://github.com/keyboardpartner/HX3/blob/master/LATEST/Flash_OrganMag.zip?raw=true)** - for MAG custom organs. Has different drawbar tapering
* **[Flash_OrganStandard_mk2.zip] (https://github.com/keyboardpartner/HX3/blob/master/LATEST/Flash_OrganStandard_mk2.zip?raw=true)** - for HX3 standard organ installations, older mk2 board
* **[Flash_OrganStandard_mk3_4.zip] (https://github.com/keyboardpartner/HX3/blob/master/LATEST/Flash_OrganStandard_mk3_4.zip?raw=true)** - for HX3 standard organ installations, current mk3/mk4 versions
* **[Flash_OrganUhl.zip] (https://github.com/keyboardpartner/HX3/blob/master/LATEST/Flash_OrganUhl.zip?raw=true)** - for Uhl Instruments X-2 and X-3 organs
* **[Flash_XB2_mk3.zip] (https://github.com/keyboardpartner/HX3/blob/master/LATEST/Flash_XB2_mk3.zip?raw=true)** - for newer XB2 kits (stereo rotary sim) with mk3/mk4 boards


### Update Packages for OEM/Developers/Technicians

Copy and unzip single ZIP files or whole contents of this repo (full download link: 
https://github.com/heise/HOAX/archive/master.zip) to a new folder on your hard disk, for example E:\HX3\LATEST\. See 
http://wiki.keyboardpartner.de/index.php?title=HX3_Update_Application for details on update procedure. From
03/2015, ZIP files will contain all necessary files (including FPGA, AVR and ScanCores) plus appropriate HX3 Remote/Update for 
mk2 as well as mk3/mk4 boards. Scroll to bottom of page for file usage.


### Last Build

* HX3 Remote: #3.9  .exe for Windows XP and up
* HX3 Flash: #3.9   .exe for Windows XP and up
* HX3 Tapering	    .exe for Windows XP and up
* AVR:  #3.90       .hex and .eep files, latest firmware for AVR controller
* FPGA: #20122015   .bit configuration file for FPGA update
* SCAN: #17         .dat ScanCore files, #20 for MIDI input and #19 for XB2


### Changelog

<b>12/23/2015</b> Firmware #3.90, FPGA 20122015, HX3 Remote #3.9, HX3 Flash #3.9

* Moved older firmwares to ARCHIVED_FIRMW directory
* Complete update ZIPs for most common HX3 instruments
* Last minor changes to Firmware #3.9
* Fixed several minor bugs in HX3 Remote and HX3 Flash
* Added "Reset File Info" in HX3 Remote to prevent missing files error
* OEM only: HX3 Flash now uses configuration file "hx3_flash_config.ini" which describes files and parameters to change/update. This text file may be customized by OEMs for their instruments and given to customers as complete package.
* OEM only: Added personal serial number file handling for production
* Leslie(R) default file name changed to "_rotary"


<b>12/20/2015</b> Firmware #3.90 PRELIMINARY, FPGA 20122015, MIDI IN ScanCore #20

* "Master Volume" menu entry, affects all 4 output signals. Available by pressing encoder knob twice.
* MIDI ScanCore #20 provides +1 and +2 octave up of lower manual in upper manual split mode. Will be implemented in other scan cores soon.
* Emphasised "throb" in rotary horn simulation with FPGA #20122015
* Refined rotary modulation parameters. Those in FW #3.85 were a little low, resulting in a somewhat "flat" modulation.
* Less artefacts (see note below)
* Support for HX3 Drawbar Expander. In this firmware TONE pot analog input is mapped to MASTER VOLUME, otherwise it is compatible with HX3 standard firmware for board installations. TONE pot parameter is available as menu entry only.
* Deleted obsolete menu entries for standard firmware
* Rotary stops on front center position for both rotor and horn (phew! That was hard work...)
* "freewheel taper-off" effect when rotary stopped from slow or fast run
* Sostenuto/Sustain selection moved to MIDI CC set entries to make it available through menu system. 6 additional entries with "." will have sostenuto on MIDI CC #64 instead of sustain.

<b>12/04/2015</b> Firmware #3.851, FPGA 27112015, MIDI IN ScanCore #19

* Added "Sustain", "Sostenuto" and "All Notes Off" accepted MIDI commands, MIDI ScanCore #19 only!
* adjustable vibrato scanner gearing, param 488 in HX3 remote (located just before "Vib1 LC age")
* fixed unwanted "feature" in MIDI IN ScanCore #18. Sostenuto CC #66 robbed PERC ON in NI B4 CC set 
* instead, Sustain on CC #64 may be switched to Sostenuto functionality by HX3 Remote param 489 
* new MIDI ScanCore #19 compatible with older FW
* new HX3 Remote organ defaults file
* new FPGA 27112015, uses 16x oversampling
* improved overflow behaviour in busbar adders, somewhat louder bass pedal
* less prone to overflow distortions on loud tapering settings
* higher audio output level on rotary simulation
* rotary simluation delay lines now with 16x oversampling rate, should result in less modulation artefacts
* revised rotary params in firmware
* Simplified "Leslie" default parameters in HX3 Remote
* fixed minor "no VibKnob save on preset 0" bug in MIDI Expander firmware

<b>10/23/2015</b> ScanCore #18 for XB2

* Fixed Split bug, split did not work on #17. Just replace XB2 ScanCore in HX3 Remote.

<b>10/16/2015</b> Firmware #3.841, FPGA #16102015

* Fixed annoying "ticker noise when keys released" bug in vibrato
* Changed reverb algorithm, improved level adjustment
* Reduced granular switching noise in new vibrato
* Reduced Dry/Mix amount
* Raised Bass pedal level by 50%, slightly reduced harmonic content

<b>10/09/2015</b> Firmware #3.84, FPGA #09102015

* Completely re-written scanner vibrato and scanner capacitor blending
* May need some Chorus Dry/Wet and Age param tweaking to your taste
* Bugfix in HX3_tapering.exe concerning "Save All" function, will regard individual level scaling now
* Updated XB2 firmware (HX3 mk3/mk4 only)
* Please update AVR firmware <b>and</b> FPGA

<b>09/04/2015</b> Firmware #3.83c, new tapering

* updated HX3 Remote and HX3 Flash to Windows 8/10 compatility
* new rotary horn FIR filter coeffs for less peaks
* corrected taper_levels files, old tapering tends to overflow distortion
* adjusted output levels for each taperlevels file

<b>08/28/2015</b> Firmware #3.83c

* backup for licence numbers if corrupted EEPROM
* added a warning if HX3 is not finalized, for more reliable update with HX3 Flash on HX3 board installations
* HX3 will not work if not finalized to prevent incomplete updates
* refined lower manual drawbar log curve
* fixed bug in MAG organs firmware (pedal output)
* new optimized tapering files - more punch, less peaks
* more volume on pedal bass 16'
* improvements for HX3 Remote and HX3 Flash
* removed unneccessary messages from HX3 Remote
* Alternate  drawbar set select signal for particular preset number, Parameter 483 in Organ Defaults. HX3 will switch to alternate drawbar set when prset number in parameter 483 is active.
* Single Preset16 is not splitted to 8/8 configuration for upper/lower manual if parameter 484 is "on". All 16 presets are available for upper manual.
* OEMs only: Added production programming for DIAMEX ISP programmer ("Advanced" tab) in HX3 Remote

<b>07/24/2015</b> Firmware #3.822, HX3 Remote #3.82

* Fixed a bug in HX3 Remote, lost licences when updating firmware
* HX3 Flash minor changes for reliability

<b>07/09/2015</b> Firmware #3.822, FPGA #05072015, ScanCores #17

From firmware 3.82 and up, HX3 will not send own MIDI CCs on MIDI OUT when MIDI Option = 3 (RcvSndMgNoCC). 
MIDI Option = 3 is now default on all firmwares except HX3 Expander (which has to accept MIDI CCs). 
This change has been made since the MIDI CCs HX3 sends out may disturb connected MIDI workstations/arrangers.
Note: If send/receive of MIDI CCs is enabled (Option = 1 or 2), 
HX3 will transmit its own CCs (drawbars etc.) always according to NI B4 set, 
independent from selected MIDI CC interpreter. 

Independent from MIDI option selected, HX3 will always send a 3.3V TTL level MIDI signal on 
PL16 pin 8 for controlling Ventilator/Minivent DSP board with synced stop/slow/fast.
Pin 34 of Vent DSP board is MIDI TTL input. Also wire digital ground (PL16 pin 10). 
Ventilator DSP accepts MIDI CC #21 values 0 (stop), 1 (slow), 2 (fast) on channel 1.

* New HX3 Flash application - simple no-hassle updater for mk3 and mk4 boards (public beta)
* Fixed bass pedal drawbar bug on some MIDI CC sets due to flaw in ScanCores
* Fixed erraneous display/saving of AudioJ Conf A/B
* Fixed Percussion mute bug on presets 1..15
* Modified MIDI Option = RcvSndMgNoCC behaviour (see above)
* HX3 now sends MIDI CC #1 and #44 for rotary footswitch when MIDI Option = 1 or 2
* RcvSndMgNoCC option is now default on HX3 firmwares except for HX3 Expander
* Added MIDI CCs for Hamichord/Mojo CC set:
* > #1 = Rotary Slow/Stop/Fast (modulation wheel),
* > #91 = TG Leakage (is "Crosstalk" knob on Mojo), 
* > #92 = TG Cap set (is "Keyclick Length" knob on Mojo), 
* > #95 = Swell Trim Cap (is "Percussion Volume" knob on Mojo)
* Additional TTL MIDI output for controlling Ventilator/Minivent DSP board (see above)

<b>06/29/2015</b> Firmware #3.812, FPGA #29062015

* Linear display mapping (MIDI as well as analog drawbar input) to better match the drawbar numbering
* Drawbar loudness logarithmisation to fit B3 drawbar curve
* Potentiometer/drawbar input hysteresis changed
* Improved V2/V3 vibrato and LC line box "Age" parameter range

<b>06/24/2015</b> Firmware #3.81

* fixed distortions when playing full chord in upper octave (please update FPGA also, use fpga_25042015.bit, installs new TG tapering files)
* fixed missing percussion bug after common preset save
* improved potentiometer/drawbar hysteresis for noise-free operation
* minor changes to HX3 Remote to prevent loss of licence numbers

<b>04/27/2015</b> Firmware #3.806, FPGA #25042015

* Improved reproduction of upper notes leakage
* Pedal added to rotary simulation instead of plain output on "+B" audio configs

<b>03/10/2015</b> Firmware #3.74, FPGA #1003015, HX3 Remote #3.74, ScanCores #16

* Working copy for evaluation - not final!
* Common Presets save current keyboard split mode and split point
* Binary combinations of Common Presets allowed (pressing two or more preset buttons at one time)
* 4 TG capacitor sets from 1955 to 1972 plus "Recapped" (more aggressive)

* Not fixed yet: Display of output configurations A/B may be erraneous

<b>01/10/2015</b> Firmware #3.72, FPGA #09012015, HX3 Remote #3.7, ScanCores #14

* Some changes in Hammond MIDI CC set for XK3c (relocated reverb and lower vibrato ON buttons), see HX3 Expander User Manual (directory DOCS_PDF) for details.
* Fixed Bug in ScanCores OrganScan61 and Strip16, Bass Split was not working
* Fixed small bug in percussion drawbar muting (#3.721)
* Fixed bug in common presets assignment
* Fixed bug in single drawbar versions which prevented pots AmpVol and TonePot from working
* Several menu entries no longer skipped on non-Expander versions
* FPGA #09012015 with appropriate level adjustment for Bass on Leslie signal
* Streamlined firmware to fit into 60 kByte; firmware 3.63 update did not work due to memory overlap
* Auto-Restore feature for Licence numbers in HX3 Remote 3.7
* Common Presets save Percussion/Vibrato/Efx tab settings and Upper/Lower Preset numbers (default 1..4)
* Manual presets only save drawbar settings on HX3 standard firmware; Expander and single drawbar versions save tabs on presets
* Added repair program (ZIP archive) to recover non-working HX3 to usable condition

<b>10/22/2014</b> Firmware #3.62

* Please Note: #3.6x update procedure did not work due to memory overlap
* Changed directory structure on Github repo, all files available as packed ZIP for easy download 
* Revised swell curve with more accurate frequency response on FW 3.63
* Adjustable minimal swell volume down to zero by menu or parameter 482 (see HX3 Remote). Needs FPGA configuration #22102014 and, if applicable, HX3 Remote 3.63 
* AO28 amplifier noise without digital artefacts

<b>06/13/2014</b> Firmware #3.55 

* New HX3 Remote with improved MIDI CC assignment. In conjunction with firmware 3.55, it will display and select received MIDI CCs for easier assignment of custom MIDI CC sets.
* MIDI Route-Thru to HX3 Remote. Small bug fixed in Voce MIDI CC setup, added controllers 87 (Treble Equ/Tone) and 88 (Bass Equ).

<b>06/04/2014</b> 

* Fixed small bug in ScanCores which would have shown up later
* Added FIR Upload to HX Remote
* Added ScanCore for Scan16, 61 Keys

<b>05/28/2014</b>

* Added FPGA #28052014 with better treble response on Leslie sim
* HX3 Remote had a small bug in "Write Basics" function that transmitted "1" instead of "255" value with Booleans (Enables etc.) of value "true".  Fixed with version 1.09 (online).
* Fixed small bug in HX3 firmware that prevented saving of Amp122 resp. Leslie Volume Pot Enable by MenuPanel.

<b>05/20/2014</b>

* Bugfix on HX_remote.exe, organ param list, last parameter Amp122 Volume Enable was missing

<b>05/19/2014</b>

* Bugfix on HX_remote.exe, EEPROM programming was faulty
* Bugfix on FPGA configuration, fixed sporadic crackling noise on right Leslie channel
* Experimental custom MIDI CC set, editor added to HX3_remote

<b>05/01/2014</b>

* Stereo Leslie simulation with improved modulation
* New vibrato algorithm with delay line "aging" parameter
* Pedal is fully polyphonic with "dry" original sound or "Trek II string bass". Last note played fades out
* Output jacks are mono on new board, but configurable by menu parameter, i.e. you may get organ, amp122 sim, pedal or leslie L/R on any jack. Separate jack extension board (or plug "rings" on HX3 mk2) carries "other" signals
* Lower octave foldback is configurable by menu parameter: Foldback with full level, foldback with muted level, no foldback ("all way down") with full level or muted level
* Reverb amount may be adjusted for each of three tab settings separately
* Bass and Treble tone controls have wider range 
* Virtual key contacts have "mutual resistance" now which yields a more "decent" click response
* New remote parameters 400..481 directly access 81 params like menu selection by MenuPanel
* Deleted obsolete remote params 500..563 despite some for compatibility (519..524)

### Files

Flash files for serial upload via AVRdude or HX3 Remote. Each .HEX file has a corresponding .EEP file. Versions for mk2 
and mk3 version boards are in separate ZIP archives. Please update only the file appropriate for your product. 
<b>Note:</b> For operation with firmware 3.5 and up, remove jumpers JP7 and JP8 which may still sit on your board from 
factory programming. These jumpers are only required for updating the reverb DSP (no need to update unless noted).

<b>HX3mkX_std.hex</b> Standard version, mainboard with button presets, Preset12 or Preset16<br>
<b>HX3mkX_expander.hex</b> MIDI expander box version<br>
<b>HX3mkX_latching.hex</b> Mainboard with latching presets on Preset12<br>
<b>HX3mkX_preset24.hex</b> Mainboard with presets on external Preset24<br>
<b>HX3mkX_mag.hex</b> Special version for MAG custom organs<br>
<b>HX3mkX_single.hex</b> Mainboard with button presets or Preset16, single manual drawbar assignment<br>
<b>HX3mkX_single_bv.hex</b> Mainboard with button presets or Preset16, single manual drawbar assignment, button vibrato on Panel16<br>
<b>HX3mk3_xb2.hex</b> HX3 Retrofit Kit for XB2 (mk3 only)<br>

<b>HX_xxx.dat</b>  Scan cores for different scan boards or MIDI input<br>
<b>fpga_DDMMYYY.bit</b>  FPGA configuration (Sound Engine), creation date (version) encoded DDMMYYYY<br>
<b>dsp_rev.bin</b>  Spin-FV1 Reverb DSP program<br>

<b>HX3_avr_repair.ZIP</b>  Repair tool (command line batch) to restore corrupted firmware - see README in archive<br>

Please also regard installation instructions on http://wiki.keyboardpartner.de!

AdaBoot by Adafruit, modified for ATmega644P(A)06/2012 by Carsten Meyer, cm@ct.de
