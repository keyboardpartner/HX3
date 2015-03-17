HX3 Scan Source
===============

Sample scan routine for Fatar matrix keyboards and FatarScan2 scan board. To be assembled with free Mediatronix PicoBlaze IDE on:

http://www.mediatronix.com/pages/pBlazIDE

You might want to write your own scan routine for the embedded PicoBlaze controller. Use tool mem2dat.exe to create an uploadable xxx.DAT ScanCore file. Tool mem2dat.exe is called by the pBlaze IDE assembler through line

 EXEC  "mem2dat HX_fatar"

at assembly time (press F12 or click "assemble/simulate" button in pBlaze IDE). Resulting HX_fatar.DAT (or your own ScanCore) may be uploaded to HX3 with HX3 Remote software.

(c) by Carsten Meyer, cm@ct.de and KeyboardPartner UG, 2/2011, 5/2014.
