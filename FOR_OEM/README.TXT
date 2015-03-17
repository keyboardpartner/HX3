HOAX_BOOT FOR OEM
=================

AdaBoot by Adafruit modified for ATmega644P(A)
by Carsten Meyer, cm@ct.de

Nur für OEM:
Dieses ReadMe ist nur für Hersteller/Lizenznehmer der HOAX-Platine relevant.


Vorbereitung:
-------------

- Diesen gesamten Ordner auf Laufwerk C: kopieren und in "\HOAX" umbenennen
- Pfad dieser Datei also "C:\HOAX\FOR_OEM\README.TXT"


Vorbereiten des FTDI-Treibers:
------------------------------

Nur falls noch nicht installiert - wird aber für die folgenden Aktionen gebraucht!

- für das FTDI-Kabel TTL-232 5V:
  VCP-Treiber von http://www.ftdichip.com/Drivers/VCP.htm herunterladen,
  entpacken, Kabel an USB anschließen,
  VCP-Treiber für das neu erkannte USB-Device auswählen
- Geräte-Manager öffnen, zugewiesenen COM-Port des FTDI-Kabels notieren
  und mit Text-Editor in Batch-Datei "hoaxflash.bat"
  unter "-P COMx" mit x=COM-Port-Nummer eintragen (wichtig! - voreingestellt ist 6)



Flashen des Bootloaders und des Main-Programms:
-----------------------------------------------

Dieser Vorgang programmiert den Bootloader und Version 3.40 der Firmware als Basisversion
gleichzeitig in den völlig fabrikneuen Controller

- JP5 setzen, Platine mit Strom versorgen (5V/250mA)
- ATmega644P per ISP-Programmer an PL1 mit HEX-Files "HOAX_boot_main.hex"
  und "HOAX_boot_main.eep" programmieren,
  Fuse Setting: SPIEN, EESAVE, BOOTSZ1, BOOTRST, CKSEL3, BODLEVEL0, BODLEVEL1, BOOTLOCK11 (BLB11)



Aufspielen der FPGA-Konfiguration:
==================================

Für Updates/Änderungen der FPGA-Konfiguration (HOAX-Sound-Engine)

- Ggf. aktuelle "main_midi.bit", "HX_*.dat" und "hoax3rev.bin" in Unterverzeichnis "FPGACORES" kopieren
- Terminal-Programm TeraTerm von http://www.heise.de/download/teraterm-pro.html
  downloaden und istallieren (falls nicht schon vorhanden)
- In der Makro-Datei "HOAX_UPLOAD.TTL" in "\TERATERM_MACRO"
  Pfade "mypath=..." konrollieren (mehrfach vorhanden, mit Texeditor zu öffnen)
  und ggf. auf aktuellen Pfad zu "<drive>:\HOAX\FPGACORES" setzen (Default C:\HOAX\FPGACORES)
- TeraTerm starten
- Unter "Setup/Serial Port..." oben notierten COM-Port des FTDI-Kabels eintragen, sowie
  Baud rate 57600, Data 8 bit, Parity none, Stop 1 bit,
  Flow control none (falls nicht schon geschehen)
- Unter "Setup/Terminal..." einstellen: Receive CR, Transmit CRLF, Local echo (falls nicht schon geschehen)
- ggf. mit ALT-N neue Verbindung, wenn DISCONNECTED
- Für spätere Updates Einstellungen unter "Setup/Save setup" Teraterm-Setup in TERATERM.INI sichern
- Makro "HOAX_UPLOAD.TTL" mit "Control/Macro..." öffnen/ausführen, Anweisungen folgen
- Bei Frage nach Scan Core folgende Ziffern eingeben:
	Core 0 = Chained OrganScan61 (alt, von Projekt Klangcomputer), mit ein bis drei Platinen in Reihe
	Core 1 = MIDI receive only
	Core 2 = ScanFatar2 mit ein oder zwei Manualen
	Core 3 = Scan4014-16/Bass parallel 2x 44 Tasten, 2x 3 Platinen
	Core 4 = Scan4014-16/Bass parallel 2x 49 Tasten, 2x 3 Platinen
	Core 5 = Scan4014-16/Bass parallel 2x 61 Tasten, 2x 4 Platinen
	         oder ein bis drei Scan4014-61 parallel

        für Produktion und Test Core 6 wählen:

 	Core 6 = TEST core, liefert Test-Akkord am Audio-Ausgang
	         und Testpulse an Scan-Anschluss

	Core 7 = OptoScan von B.A.S.S.


Inbetriebnahme
==============

Nach dem Flashen des Controllers und Aufspielen der FPGA-Konfiguration mit Scan-Core 6 liefert die Platine
einen Test-Akkord C-Dur an den Audio-Ausgängen, ein einzelnes C auf Audio-Bass-Ausgang
und Testimpulse ("Schieberegister") an PL14 und PL15.

An jedem der Pins 1..8 von PL14 und PL15 müssen saubere Impulse von ca. 8 µs Länge
und 3,3V Höhe anliegen. Zwei Pulse gleich nebeneinander mit 4µs Abstand und nur
halbem Pegel deuten auf einen Kurzschluss hin, ein fehlender Impuls auf eine Unterbrechung.

PL16 führt einige Digital-Audio-Signale (für zukünftige Erweiterungen).

Nach erfolgreichem Test Scan-Core mit den Befehlen

WEN=1
519=xxx

auf den vom Kunden gewünschten Scan-Core "xxx" (0..7) umstellen.

Damit AVRdude wieder auf das FTDI-Kabel zugreifen kann, muss TeraTerm beendet
oder die Verbindung mit ALT-I unterbrochen werden!


Erstellen des Bootloaders:
--------------------------

Nur falls Bootloader selbst geändert wurde, nur für Sonderfälle nach Absprache.

- ggf. WinAVR (open source) installieren
- Command Prompt aufrufen
- "make hoaxboot" ausführen


Flashen des Bootloaders:
------------------------

Bootloader allein ohne Main-Programm, nur für Sonderfälle nach Absprache.

- JP5 setzen, Platine mit Strom versorgen (5V/250mA)
- ATmega644P per ISP-Programmer an PL1 mit HEX-File "HOAX_boot.hex"
  (oder "HOAX_boot_main.hex" gleichzeitig mit Hauptprogramm, siehe oben) programmieren,
  Fuse Setting: SPIEN, BOOTSZ1, BOOTRST, CKSEL3, BODLEVEL0, BODLEVEL1, BOOTLOCK11 (BLB11)

