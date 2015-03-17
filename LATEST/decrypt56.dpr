program decrypt56;
// Seriennummer-Generator für HX3
// Usage: decrypt56 <number>
// Returns: O:<OrganLicence> L:<LeslieLicence>

{$APPTYPE CONSOLE}

uses
  SysUtils;

const
  organ_a= $A97E14;
  organ_b= $8B74A5;
  leslie_a= $7D8623;
  leslie_b= $28BFAC;

var SerialNumber, OrganLicence, LeslieLicence, Shifter: LongInt;
  byte_0, byte_1, byte_2, byte_3: Byte;
  xor_0, xor_1, xor_2, xor_3, xor_organ, xor_leslie: Byte;
  i: Integer;
  bit_array: Array[0..23] of byte;
  select_ab: boolean;
(*---------------------------- MAIN ---------------------------*)

begin
  if paramcount>0 then begin
    SerialNumber:= StrToInt(trim(paramstr(1)));
    byte_0:= byte(SerialNumber and $FF);
    byte_1:= byte((SerialNumber shr 8) and $FF);
    byte_2:= byte((SerialNumber shr 16) and $FF);

    Shifter:= SerialNumber;
    for i:= 0 to 23 do begin
      bit_array[i]:=byte(Shifter and 1);
      Shifter:=Shifter shr 1;
    end;

    xor_3:= bit_array[20] xor bit_array[21] xor bit_array[22] xor bit_array[23];
    xor_2:= bit_array[16] xor bit_array[17] xor bit_array[18] xor bit_array[19] xor xor_3;
    xor_1:= bit_array[8] xor bit_array[9] xor bit_array[10] xor bit_array[11] xor xor_2;
    xor_0:= bit_array[0] xor bit_array[1] xor bit_array[2] xor bit_array[3] xor xor_1;
    select_ab:= xor_0 <> 0;
    xor_2:= (byte_1 shl 1) or ((byte_1 shr 7) and 1);
    xor_1:= byte_2 xor byte_1;
    xor_0:= (byte_0 shl 2) or ((byte_0 shr 6) and 3);

    Shifter:= LongInt(xor_2);
    Shifter:= (Shifter shl 8) or (LongInt(xor_1));
    Shifter:= (Shifter shl 8) or (LongInt(xor_0));

    if select_ab then OrganLicence:= Shifter xor organ_a
      else OrganLicence:= Shifter xor organ_b;
    if select_ab then LeslieLicence:= Shifter xor leslie_a
      else LeslieLicence:= Shifter xor leslie_b;

    writeln('O:'+IntToStr(OrganLicence)+' L:'+IntToStr(LeslieLicence));
  end else writeln('0');
end.


