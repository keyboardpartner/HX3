HX3 Beta Firmware
=================

### Update Packages FOR BETA TESTERS ONLY

These packages are not intended for customer installation. May contain serious 
bugs. Use at your own risk. Do only use files contained in self-contained ZIP 
package.

### Last Build

* HX3 Remote: #4.11  .exe for Windows XP and up
* HX3 Flash: #3.925g   .exe for Windows XP and up
* HX3 Tapering	    .exe for Windows XP and up
* AVR:  #4.20      .hex and .eep files, latest firmware for AVR controller
* FPGA: #10102016   .bit configuration file for FPGA update
* SCAN: #30         .dat ScanCore files for MIDI and FATAR

### Changelog

<b>10/27/2016</b> Firmware #4.20, FPGA #26102016 (both in Remote_for_all.zip)

*  New menu "ContEarlyActn" and HX3 Remote Parameter 491, Contact Early Action ON/OFF:
** If set to ON, organ will close key contacts on 1st FATAR rubber contact and send MIDI ON without velocity.
** If set to OFF ("George Fleury" mode), organ will close key contacts on 2nd FATAR rubber contact and send MIDI ON with velocity.
*  New menu "TG Gears Tune" and HX3 Remote Parameter 488, TG Tuning will fine tune the organ plusminus 100 cent. 
Note: To accomplish this, all TG gears must be changed which may take around 100 ms.
* Audio output config initialisation bug fixed


<b>09/27/2016</b> Firmware #4.1c, FPGA #25092016 (both in Remote_for_all.zip)

(moved finalized files to LATEST directory)
