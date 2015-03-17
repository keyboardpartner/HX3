echo off
echo Batch for DIAMEX PROG-S ISP programmer on COM port #
echo Example usage: flash_diamex 4
echo with 4 = port number (1..31) of FTDI cable (see Windows device manager do determine #)

echo Place 10-pin ribbon connector of ISP programmer on PL1, pin 1 facing towards XTAL
echo Insert CONF_DIS jumper JP5 on HX3 board before continuing
pause

avrdude -C "avrdude.conf" -pm644p -cstk500v2 -B8 -P COM%1 -U lfuse:w:0xf7:m -U hfuse:w:0xd2:m -U efuse:w:0xff:m -U flash:w:"HX3mk3_boot_std.hex":i -U eeprom:w:"HX3mk3_boot_std.eep":i

echo Remove CONF_DIS jumper JP5
echo Use HX3 Remote to update to appropriate firmware!
pause
