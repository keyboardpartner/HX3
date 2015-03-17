program MEM2DAT;

(* MEM2DAT Converter für PicoBlaze-Cores, LongWord-DATs    *)
(* für Borland Pascal 7 or Delphi, von C. Meyer 2/2009 (!) *)

{$R-} (* Array-Bereichs-Check ausschalten! *)

uses  sysutils;

const signon = ^m^j'Mem2Dat Converter 4 Bytes/Line LSB first'^m^j;

var   hexfilename,datfilename,filext : string;

(* Untersuchen eines Dateinamens auf Angabe einer extension,   *)
(* gefundene extension wird (Upcase) in FILEXT gespeichert.    *)

function hasextension(s:string):boolean;
var i,j : integer;
begin
  hasextension:=false;
  filext:='';
  for i:=length(s) downto 2 do begin
    if s[i]='.' then begin
      hasextension:=true;
      filext:=copy(s,succ(i),255);
      for j:=1 to length(filext) do
        filext[j]:=upcase(filext[j]);
      exit;
      end;
    end;
  end;

function extractfilename(s:string):string;
var j : integer;
begin
  j:=pos('.',s);
  extractfilename:=copy(s,0,j-1);
end;

procedure gethexfile;
var hexfil          : text;
    binfil: file of LongInt; {ggf. ändern auf Word oder Byte}
    s               : string;
    i,n : byte;
    zeile       : word;
    wert	    : longint; {ggf. ändern auf Word oder Byte}

  function gethex(ziffern:byte):longint;
  var st  : string;
      x : longint;
      converr: Integer;
  begin
    st:='$'+copy(s,0,ziffern);
    val(st,x,converr);
    gethex:=x;
    if converr <> 0 then
    begin
      writeln('Error at line ',zeile);
      halt;
    end;
  end;

begin
  assign(hexfil,hexfilename);
  {$I-} reset(hexfil); {$I+}
  if ioresult<>0 then begin
    writeln('Error opening ',hexfilename);
    halt;
  end;
  assign(binfil,datfilename);
  rewrite(binfil);
  zeile:=0;
  while not eof(hexfil) do begin
    readln(hexfil,s);
    if s[1] <> '@' then
    begin
      n:=length(s);
      inc(zeile);
      wert:=gethex(n);
      write(binfil,wert);
    end;
  end;
  close(hexfil);
  close(binfil);
  write(zeile);
  writeln(' lines read');
  write(zeile*4);
  writeln(' Bytes written to file ', datfilename);
end;


(*---------------------------- MAIN ---------------------------*)

begin
  writeln(signon);
  if paramcount>0 then hexfilename:=paramstr(1) else begin
    write('MEM-Filename: ');
    readln(hexfilename);
    if hexfilename='' then halt;
    end;
  if hasextension(hexfilename) then
    begin
      datfilename:=extractfilename(hexfilename)+'.DAT';
      gethexfile;
    end
  else
  begin
    datfilename:=hexfilename+'.DAT';
    hexfilename:=hexfilename+'.MEM';
    gethexfile;
  end;
end.

