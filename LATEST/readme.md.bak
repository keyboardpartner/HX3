HX3 Latest Firmware
===================

<b>Working releases for update with HX3 Remote application</b>

Copy and unzip whole contents of this directory to a new folder on your hard disk, for example E:\HX3\LATEST\. 
See http://wiki.keyboardpartner.de/index.php?title=HX3_Remote/Update_Application for details un update procedure. 

### Last Build

* HX3 Remote: #3.72	.exe for Windows XP and up
* AVR:  #3.721      .hex and .eep files, latest firmware for AVR controller
* FPGA: #09012015   .bit configuration file for FPGA update
* SCAN: #$14        .dat ScanCore files

### Files

Flash files for serial upload via AVRdude or HX3 Remote. Each .HEX file has a corresponding .EEP file. Versions for mk2 
and mk3 version boards are in separate ZIP archives. Please update only the file appropriate for your product. 
<b>Note:</b> For operation with firmware 3.5 and up, remove jumpers JP7 and JP8 which may still sit on your board from 
factory programming. These jumpers are only required for updating the reverb DSP (no need to update unless noted).

<b>HX3mkX_std.hex</b> Standard version, mainboard with button presets or Preset16<br>
<b>HX3mkX_expander.hex</b> MIDI expander box version<br>
<b>HX3mkX_latching.hex</b> Mainboard with latching presets on Preset12<br>
<b>HX3mkX_preset24.hex</b> Mainboard with presets on external Preset24<br>
<b>HX3mkX_single.hex</b> Mainboard with button presets or Preset16, single manual drawbar assignment<br>
<b>HX3mkX_single_bv.hex</b> Mainboard with button presets or Preset16, single manual drawbar assignment, button vibrato on Panel16<br>
<b>HX3mk3_xb2.hex</b> HX3 Retrofit Kit for XB2 (mk3 only)<br>

<b>HX_xxx.dat</b>  Scan cores for different scan boards or MIDI input<br>
<b>fpga_DDMMYYY.bit</b>  FPGA configuration (Sound Engine), creation date (version) encoded DDMMYYYY<br>
<b>dsp_rev.bin</b>  Spin-FV1 Reverb DSP program<br>

<b>HX3_avr_repair.ZIP</b>  Repair tool (command line batch) to restore corrupted firmware - see README in archive<br>


### Changelog

<b>01/10/2015</b> Firmware #3.72, FPGA #09012015, HX3 Remote #3.7, Scan Rev. #14

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

Please also regard installation instructions on http://wiki.keyboardpartner.de!

AdaBoot by Adafruit, modified for ATmega644P(A)06/2012 by Carsten Meyer, cm@ct.de
