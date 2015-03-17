HOAX-Firmware-Installation
==========================

Bitte beachten Sie die ausführliche Anleitung auf http://wiki.keyboardpartner.de!

HEX-Files zum Upload per AVRdude. Zu jedem HEX-File gehört eine EEPROM-Datei mit Endung .EEP!

<b>Flash-Dateien:</b>
HOAX_main.hex             HX3 Standard, ggf. mit Preset24 oder 1 bis 2 Preset16-Panel 
HOAX_main_latching.hex	  Latching Presets (einrastende Tasten) mit alter Preset12 MPX Platine
HOAX_main_tabvib.hex      wie Standard, jedoch drei Schalter (V1,V2,CH - V3=V1+V2) statt Drehschalter an PL5
HOAX_main_buttonvib.hex   wie Standard, jedoch Vibrato-Einstellung über die vier Common-Preset-Taster von Panel16 statt Drehschalter
HOAX_main_xb2.hex         Spezialversion für XB2-Einbausatz, nutzt vorhandene Bedienelemente und Display
HOAX_main_xb2_panel16.hex Spezialversion für alten XB2-Einbausatz mit Panel16
Preset24.hex              Firmware für ATmega8 auf Preset24-Platine

<b>in FPGACORES:</b>
main_midi.bit             FPGA-Konfiguration zum Upload mit TeraTerm-Makro
*.dat                     PicoBlaze Keyscan-Routinen, zum Upload mit TeraTerm-Makro
*.bin                     SPIN-1 externe I2C Rerverb Programme, zum Upload mit TeraTerm-Makro

hoaxflash.bat             Batch-Datei, ruft AVRdude mit allen Parametern zum Flashen des Controllers mit "HOAX_main.hex" auf.
                          Parameter COM-Schnittstellennummer, z.B. "C:\HOAX>hoaxflash 14" for COM14 (für Windows)
hoaxflasheeprom.bat       Batch-Datei, wie vor, programmier jedoch zusätzlich mit EEPROM-Datei "HOAX_main.eep" (für Windows)
                          Batch-Dateien sind ggf. für das gewünschte Flash-File anzupassen!

avrdude.exe               AVRdude-Programm zum Firmware-Update über serielle Schnittstelle (für Windows)
libusb0.dll               Wird von manchen Windows-Systemen benötigt, um AVRdude auszuführen
ATmegaBOOT_xx8.c          Nur für Neukompilierung des Bootloaders mit WinAVR nötig
Makefile                  Nur für Neukompilierung des Bootloaders mit WinAVR nötig

<b>Verzeichnisse:</b>
BETA                    enthält allerletzte Firmware und FPGA-Konfiguration
DOCS_PDF                Syntax-Tabelle zur Kommunikation und weitere Unterlagen
FPGACORES               FPGA-Konfiguration, Hallprogramme und Scan-Cores
PLATINEN                Schaltpläne, Bestückungspläne und weitere Unterlagen
TERATERM_MACRO          Update-Makros für empfohlenes Terminal-Programm TeraTerm 4.7x (für Windows)
giveio                  Wird benötigt, um AVRdude auszuführen
FOR_OEM                 enthält alle dateien für AVR-Erstprogrammierung, wie oben, jedoch mit eingebautem Bootloader
                        (Arduino/AVRdude-kompatibel) für Programmierung eines fabrikneuen AVR-Controllers


HOAX-Firmware-Installation (english)
====================================

Please note installation instructions on http://wiki.keyboardpartner.de!

Flash files for serial upload via AVRdude. Please also program the appropiate EEPROM file (ending .EEP).

<b>Flash files:</b>
HOAX_main.hex             standard version with rotary vibrato switch, optional Preset24 or Preset16-Panel
HOAX_main_latching.hex	  version for latching preset keys with old Preset12 MPX board
HOAX_main_tabvib.hex      as standard, but 3 switches (V1,V2,CH - V3=V1+V2) instead of rotary vibrato switch at PL5
HOAX_main_buttonvib.hex   as standard, but vibrato setting (V1..V3, CH) by four Common Preset buttons on Panel16
HOAX_main_xb2.hex         special version for XB2 retrofit kit, uses XB2's buttons and display
HOAX_main_xb2_panel16.hex special version for XB2 retrofit kit, uses installed Panel16

<b>in FPGACORES:</b>
main_midi.bit           FPGA configuration, to be uploaded by TeraTerm macro
*.dat                   PicoBlaze Key scanning routines, to be uploaded by TeraTerm macro
*.bin                   SPIN-1 external I2C Rerverb programs, to be uploaded by TeraTerm macro

hoaxflash.bat           Batch file, invokes AVRdude with all parameters to flah controllers with "HOAX_main.hex"
                        Parameter COM interface number, for example "C:\HOAX>hoaxflash 14" for COM14
hoaxflasheeprom.bat     Batch file, like above, but also with EEPROM-Datei "HOAX_main.eep"

Directories:
BETA                    last firmware revisions and FPGA configurations, testing only
DOCS_PDF                Syntax table for HX3 COM port, MIDI tables etc. 
FPGACORES               FPGA configuration, reverb firmware and keyboard scan cores for upload with TeraTerm macro
PLATINEN                schematics, mechanical drawings, board and componentlayouts
TERATERM_MACRO          FPGA and scan core pdate macros for terminal emulator TeraTerm 4.7x (Windows)
giveio                  used by AVRdude flash tool
FOR_OEM                 contains all flash files as above, but with built-in bootloader (Arduino/AVRdude compatible).

AdaBoot by Adafruit, modified for ATmega644P(A)06/2012 by Carsten Meyer, cm@ct.de

