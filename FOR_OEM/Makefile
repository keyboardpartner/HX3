# Makefile for ATmegaBOOT
# E.Lins, 18.7.2005
# $Id: Makefile,v 1.4 2008/10/05 17:41:43 cvs Exp $
#
# Instructions
#
# To build the HOAX  bootloader for the 644p:  - by cm
# make hoaxboot
#

# program name should not be changed...
PROGRAM    = ATmegaBOOT_xx8


OBJ        = $(PROGRAM).o
OPTIMIZE   = -O2

DEFS       =
LIBS       =

CC         = avr-gcc

OBJCOPY        = avr-objcopy
OBJDUMP        = avr-objdump

all:

hoaxboot:TARGET = hoaxboot
hoaxboot:CFLAGS += '-DMAX_TIME_COUNT=F_CPU>>2' '-DNUM_LED_FLASHES=5'  '-DWATCHDOG_MODS'
hoaxboot:$ HOAX_boot.hex
hoaxboot:AVR_FREQ = 16000000L
hoaxboot:MCU_TARGET = atmega644p
hoaxboot:LDSECTION  = --section-start=.text=0xF800


# Override is only needed by avr-lib build system.

override CFLAGS        = -g -Wall $(OPTIMIZE) -mmcu=$(MCU_TARGET) -DF_CPU=$(AVR_FREQ) $(DEFS)
override LDFLAGS       = -Wl,$(LDSECTION)
#override LDFLAGS       = -Wl,-Map,$(PROGRAM).map,$(LDSECTION)


%.elf: $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -rf *.o *.elf *.lst *.map *.sym *.lss *.eep *.srec *.bin *.hex

%.lst: %.elf
	$(OBJDUMP) -h -S $< > $@

%.hex: %.elf
	$(OBJCOPY) -j .text -j .data -O ihex $< $@

%.srec: %.elf
	$(OBJCOPY) -j .text -j .data -O srec $< $@

%.bin: %.elf
	$(OBJCOPY) -j .text -j .data -O binary $< $@