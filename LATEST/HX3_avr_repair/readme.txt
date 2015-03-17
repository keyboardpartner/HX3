Using the HX3 repair tool
=========================

If HX3 is no longer accessible by HX3 Remote due to corrupted firmware, please try the following procedure:

Even when firmware is dead, red LED on HX3 should blink when powering up for a moment. 
This indicates the Arduino bootloader is OK and will accept re-programming.

Insert CONF_DIS jumper JP5 and RESET jumper on PL1 position "R". 

Attach FTDI cable and determine COM port number issued by HX3 Remote or by Windows device manager.

Power up HX3.

Open Command Prompt and type (here "4" is the com port number):

hx3_repair 4

Follow instructions issued by hx3_repair batch window.

-cm