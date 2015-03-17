HX3 Remote Sources
==================

HX3 Remote Sources to be compiled with Borland Delphi 2005 Personal Edition (and up) for those interested in improving it. This is more or less a quick & dirty (but working) approach, so be forgiving. Borland Delphi 2005 Personal Edition was downloadable for free some time ago, also included on some computer magazine CDs/DVDs. It still works fine on Windows 7 if you add the new string value "$(BDS)\Bin\delphicoreide90.bpl" = "Delphi Core IDE"  to the "HKEY_CURRENT_USER\Software\Borland\BDS\3.0\Known IDE Packages" registry key. Otherwise you'll get an access violation error on rtl90.bpl on exit of IDE. 

You might have to install the TColorButton component to Delphi (used as a simple LED indicator). See

http://www.swissdelphicenter.com/de/showcode.php?id=1100

for details.

HX3 Remote uses ftdiclass component from Michael "Zipplet" Nixon.

(c) by Carsten Meyer, cm@ct.de and KeyboardPartner UG, 5/2014.
