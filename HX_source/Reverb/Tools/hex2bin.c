/*
    hex2bin converts an Intel hex file to binary.
    Copyright (C) 1998,1999  Jacques Pelletier

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* size in bytes */
#define MEMORY_SIZE 1024*1024

/* This mask is for mapping the target binary inside our
binary buffer. If for example, we are generating a binary
file with records starting at FFF00000, the bytes will be
stored at the beginning of the memory buffer. */
#define ADDRESS_MASK 0x000F0000

/* We use buffer to speed disk access. */
#ifdef USE_FILE_BUFFERS
#define BUFFSZ 4096
#endif

#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif

/* FIXME how to get it from the system/OS? */
#define MAX_FILE_NAME_SIZE 81

#ifdef DOS
#define MAX_EXTENSION_SIZE 4
#else
#define MAX_EXTENSION_SIZE 16
#endif

/* The data records can contain 255 bytes: this means 512 characters. */
#define MAX_LINE_SIZE 1024

#define NO_ADDRESS_TYPE_SELECTED 0
#define LINEAR_ADDRESS 1
#define SEGMENTED_ADDRESS 2

typedef char filetype[MAX_FILE_NAME_SIZE];
typedef int boolean;
typedef unsigned char byte;

filetype    Filename;           /* string for opening files */
char        Extension[MAX_EXTENSION_SIZE];       /* filename extension for output files */

FILE        *Filin,             /* input files */
*Filout;            /* output files */

#ifdef USE_FILE_BUFFERS
char		*FilinBuf,          /* text buffer for file input */
*FiloutBuf;         /* text buffer for file output */
#endif

void usage(void);

void *NoFailMalloc (size_t size);
void NoFailOpenInputFile (char *Flnm);
void NoFailOpenOutputFile (char *Flnm);
void PutExtension(char *Flnm, char *Extension);

void usage(void)
{
	fprintf (stderr,
		"\nusage: hex2bin [-s xxxx] [-e extension] [-c] filename\n"
		"-s xxxx\tStarting address in hex\n"
		"-e extension\toutput filename extension\n"
		"-c enable checksum verification\n\n");

	exit(1);
} /* procedure USAGE */

void *NoFailMalloc (size_t size)
{
	void *result;

	if ((result = malloc (size)) == NULL)
	{
		fprintf (stderr,"Can't allocate memory.\n");
		exit(1);
	}
	return (result);
}

/* Open the input file, with error checking */
void NoFailOpenInputFile (char *Flnm)
{
	while ((Filin = fopen(Flnm,"r")) == NULL)
	{
		fprintf (stderr,"Input file %s cannot be opened. Enter new filename: ",Flnm);
		fgets (Flnm,MAX_FILE_NAME_SIZE,stdin);
		if (Flnm[0] == '\0') exit(1);
	}

#ifdef USE_FILE_BUFFERS
	FilinBuf = (char *) NoFailMalloc (BUFFSZ);
	setvbuf(Filin, FilinBuf, _IOFBF, BUFFSZ);
#endif
} /* procedure OPENFILIN */

/* Open the output file, with error checking */
void NoFailOpenOutputFile (char *Flnm)
{
	while ((Filout = fopen(Flnm,"w")) == NULL)
	{
		/* Failure to open the output file may be
		simply due to an insufficiant permission setting. */

		fprintf(stderr,"Output file %s cannot be opened. Enter new file name: ", Flnm);
		fgets(Flnm,MAX_FILE_NAME_SIZE,stdin);
		if (Flnm[0] == '\0') exit(1);
	}
#ifdef USE_FILE_BUFFERS
	FiloutBuf = (char *) NoFailMalloc (BUFFSZ);
	setvbuf(Filout, FiloutBuf, _IOFBF, BUFFSZ);
#endif

} /* procedure OPENFILOUT */

/* Adds an extension to a file name */
void PutExtension(char *Flnm, char *Extension)
{
	char        *Period;        /* location of period in file name */
	boolean     Samename;

	/* This assumes DOS like file names */
	/* Don't use strchr(): consider the following filename:
		../my.dir/file.hex
	*/
	if ((Period = strrchr(Flnm,'.')) != NULL)
		*(Period) = '\0';

	Samename = FALSE;
	if (strcmp(Extension, Period+1)== 0)
		Samename = TRUE;

	strcat(Flnm,".");
	strcat(Flnm, Extension);
	if (Samename)
	{
		fprintf (stderr,"Input and output filenames (%s) are the same.", Flnm);
		exit(1);
	}
}

int main (int argc, char *argv[])
{
/* line inputted from file */
	char Line[MAX_LINE_SIZE];

/* flag that a file was read */
	boolean Fileread;
	boolean Enable_Checksum_Error = FALSE;
	boolean Status_Checksum_Error = FALSE;

/* cmd-line parameter # */
	char *c,*p;

	unsigned int Param;
	unsigned int i;

/* Application specific */

	unsigned int 	Nb_Bytes;
	unsigned int 	First_Word, Address, Segment, Upper_Address;
	unsigned int    Lowest_Address, Highest_Address, Starting_Address;
	unsigned int 	Phys_Addr, Type;
	unsigned int 	temp;

	/* We will assume that when one type of addressing is selected, it will be valid for all the
	current file. Records for the other type will be ignored. */
	unsigned int	Seg_Lin_Select = NO_ADDRESS_TYPE_SELECTED;

	boolean Starting_Address_Setted = FALSE;

	int temp2;

	byte	Data_Str[MAX_LINE_SIZE];
	byte 	Checksum;

/* This will hold binary codes translated from hex file. */
	byte *Memory_Block;

	fprintf (stdout,"hex2bin v1.0.1, Copyright (C) 1999 Jacques Pelletier\n");

	if (argc == 1)
		usage();

	strcpy(Extension, "bin"); /* default is for binary file extension */

	/* read file */
	Param = 1;

	for (Param = 1; Param < argc; Param++)
	{
		c = p = argv[Param];
#ifdef __linux__
		/* We don't accept an option beginning with a '/' because it could be a file name. */
		if(*c == '-')
#else
			if((*c == '-') || (*c == '/'))
#endif
			{
				p = c + 2;
			/* Parameter may follow immediately after option */
			/* Skips after parameter to next option */
				if (*p == '\0')
					p = argv[++Param];

				switch(tolower (*(++c)))
				{
					case 'e':
					/* Last parameter was -E, so this parameter is the filename extension. */
						if (strlen(p) > MAX_EXTENSION_SIZE)
							usage();

					/* Check to see if the user put a period in the filename extension */
						if (strchr(p, '.') == NULL)
							strcpy(Extension, p);
						else
							strcpy(Extension, p+1);
						break;

					case 'c':
						Enable_Checksum_Error = TRUE;
						break;
					case 's':
						sscanf(p,"%x",&Starting_Address);
						Starting_Address_Setted = TRUE;
						break;
					case 'h':
						usage();
						break;
					default:
						usage();
				} /* switch */
			} else
				break;
		/* if option */

	} /* for Param */

	/* when user enters input file name */

	/* Assume last parameter is filename */
	strcpy(Filename,argv[argc -1]);

	/* Just a normal file name */
	NoFailOpenInputFile (Filename);
	PutExtension(Filename, Extension);
	NoFailOpenOutputFile(Filename);
	Fileread = TRUE;

	/* allocate a buffer */
	Memory_Block = (byte *) NoFailMalloc(MEMORY_SIZE);

	/* For EPROM or FLASH memory types, fill unused bytes with FF */
	memset (Memory_Block,0xFF,MEMORY_SIZE);

	/* To begin, assume the lowest address is at the end of the memory.
	subsequent addresses will lower this number. At the end of the input
	file, this value will be the lowest address. */
	Segment = 0;
	Upper_Address = 0;
	Lowest_Address = MEMORY_SIZE - 1;
	Highest_Address = 0;

	/* Now read the file & process the lines. */
	do /* repeat until EOF(Filin) */
	{
		/* Read a line from input file. */
		fgets(Line,MAX_LINE_SIZE,Filin);

		/* Remove carriage return/line feed at the end of line. */
		i = strlen(Line)-1;

		if (Line[i] == '\n') Line[i] = '\0';

		/* Scan the first two bytes and nb of bytes.
		The two bytes are read in First_Word since it's use depend on the
		record type: if it's an extended address record or a data record.
		*/
		sscanf (Line, ":%2x%4x%2x%s",&Nb_Bytes,&First_Word,&Type,Data_Str);

		Checksum = Nb_Bytes + (First_Word >> 8) + (First_Word & 0xFF) + Type;

		p = Data_Str;

		/* If we're reading the last record, ignore it. */
		switch (Type)
		{
			/* Data record */
			case 0:
				Address = First_Word;

				if (Seg_Lin_Select == SEGMENTED_ADDRESS)
					Phys_Addr = ((Segment << 4) & ADDRESS_MASK) + Address;
				else
				/* LINEAR_ADDRESS or NO_ADDRESS_TYPE_SELECTED
				Upper_Address = 0 as specified in the Intel spec. until an extended address
				record is read. */
					Phys_Addr = ((Upper_Address << 16) & ADDRESS_MASK) + Address;

				/* Check that the physical address stays in the buffer's range. */
				if ((Phys_Addr + Nb_Bytes) <= MEMORY_SIZE -1)
				{
					/* Set the lowest address as base pointer. */
					if (Phys_Addr < Lowest_Address)
						Lowest_Address = Phys_Addr;

					/* Same for the top address. */
					temp = Phys_Addr + Nb_Bytes -1;

					if (temp > Highest_Address)
						Highest_Address = temp;

					/* Read the Data bytes. */
					/* Bytes are written in the Memory block even if checksum is wrong. */
					for (i= Nb_Bytes; i > 0; i--)
					{
						sscanf (p, "%2x",&temp2);
						p += 2;
						Memory_Block[Phys_Addr++] = temp2;
						Checksum = (Checksum + temp2) & 0xFF;
					};

					/* Read the Checksum value. */
					sscanf (p, "%2x",&temp2);

					/* Verify Checksum value. */
					Checksum = (Checksum + temp2) & 0xFF;

					if ((Checksum != 0) && Enable_Checksum_Error)
					{
						Status_Checksum_Error = TRUE;
					}
				}
				else
				{
					if (Seg_Lin_Select == SEGMENTED_ADDRESS)
						fprintf(stderr,"Data record skipped at %4X:%4X\n",Segment,Address);
					else
						fprintf(stderr,"Data record skipped at %8X\n",Phys_Addr);
				}

				break;

			/* End of file record */
			case 1:
				/* Simply ignore checksum errors in this line. */
				break;

			/* Extended segment address record */
			case 2:
				/* First_Word contains the offset. It's supposed to be 0000 so
				we ignore it. */

				/* First extended segment address record ? */
				if (Seg_Lin_Select == NO_ADDRESS_TYPE_SELECTED)
					Seg_Lin_Select = SEGMENTED_ADDRESS;

				/* Then ignore subsequent extended linear address records */
				if (Seg_Lin_Select == SEGMENTED_ADDRESS)
				{
					sscanf (p, "%4x%2x",&Segment,&temp2);

					/* Update the current address. */
					Phys_Addr = (Segment << 4) & ADDRESS_MASK;

					/* Verify Checksum value. */
					Checksum = (Checksum + (Segment >> 8) + (Segment & 0xFF) + temp2) & 0xFF;

					if ((Checksum != 0) && Enable_Checksum_Error)
						Status_Checksum_Error = TRUE;
				}
				break;

			/* Start segment address record */
			case 3:
				/* Nothing to be done since it's for specifying the starting address for
				execution of the binary code */
				break;

			/* Extended linear address record */
			case 4:
				/* First_Word contains the offset. It's supposed to be 0000 so
				we ignore it. */

				/* First extended linear address record ? */
				if (Seg_Lin_Select == NO_ADDRESS_TYPE_SELECTED)
					Seg_Lin_Select = LINEAR_ADDRESS;

				/* Then ignore subsequent extended segment address records */
				if (Seg_Lin_Select == LINEAR_ADDRESS)
				{
					sscanf (p, "%4x%2x",&Upper_Address,&temp2);

					/* Update the current address. */
					Phys_Addr = (Upper_Address << 16) & ADDRESS_MASK;

					/* Verify Checksum value. */
					Checksum = (Checksum + (Upper_Address >> 8) + (Upper_Address & 0xFF) + temp2)
						& 0xFF;

					if ((Checksum != 0) && Enable_Checksum_Error)
						Status_Checksum_Error = TRUE;
				}
				break;

			/* Start linear address record */
			case 5:
				/* Nothing to be done since it's for specifying the starting address for
				execution of the binary code */
				break;
			default:
		}
	} while (!feof (Filin));
/*-----------------------------------------------------------------------------*/

	fprintf(stdout,"Lowest address = %08X\n",Lowest_Address);
	fprintf(stdout,"Highest address = %08X\n",Highest_Address);

	/* This starting address is for the binary file,

	ex.: if the first record is :nn010000ddddd...
	the data supposed to be stored at 0100 will start at 0000 in the binary file.

	Specifying this starting address will put FF bytes in the binary file so that
	the data supposed to be stored at 0100 will start at the same address in the
	binary file.
	*/

	if(Starting_Address_Setted)
	{
		Lowest_Address = Starting_Address;
	}

	/* write binary file */
	fwrite (&Memory_Block[Lowest_Address],
		1,
		Highest_Address - Lowest_Address +1,
		Filout);

	free (Memory_Block);

#ifdef USE_FILE_BUFFERS
	free (FilinBuf);
	free (FiloutBuf);
#endif

	fclose (Filin);
	fclose (Filout);

	if (Status_Checksum_Error & Enable_Checksum_Error)
	{
		fprintf(stderr,"Checksum error detected.\n");
		return 1;
	}

	if (!Fileread)
		usage();
	return 0;
}
