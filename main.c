#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "iwaddefs.h"

#ifdef _WIN32
#include "config.win.h"
#else
#include "config.h"
#endif

int main()
{
	DIR* WadPathFolder = opendir(CDL_WADPath);
	struct dirent* entry;
	int x = 0;
	int files = 1;
	int KnownWADsLength = sizeof(CDL_KnownWADs)/sizeof(CDL_KnownWADs[0]);
	char ExecutableLine[100];
	
	if (strcat(CDL_WADPath, "") == 0)
	{
		printf("WAD path is not configured\n");
		#ifdef _WIN32
		printf("You must edit config.win.h\n");
		#else
		printf("You must edit config.h\n");
		#endif
		return 1;
	}
	else if (strcat(CDL_ExecutablePath, "") == 0)
	{
		printf("Executable path is not configured\n");
		#ifdef _WIN32
		printf("You must edit config.win.h\n");
		#else
		printf("You must edit config.h\n");
		#endif
		return 1;
	}

	printf("Using ");
	printf(CDL_WADPath);
	#ifdef _WIN32
	printf(" as WAD path (edit config.win.h and recompile to change)\n\n");
	#else
	printf(" as WAD path (edit config.h and recompile to change)\n\n");
	#endif

	if (WadPathFolder == NULL)
	{
		printf("Directory does not exist -- make sure that ");
		printf(CDL_WADPath);
		printf(" is correct\n");
		return 1;
	}

	printf("Listing WADs:\n");
	
	while ((entry=readdir(WadPathFolder)))
	{
		char* entryName = entry->d_name;
		if (entryName[0] != '.')
		{
			for (x = 0; x < KnownWADsLength; x++)
			{
				if (strcmp(entryName, CDL_KnownWADs[x]) == 0)
				{
					files++;
					/*
					Yes, I know this is bad practice.
					I literally couldn't think of anything better.
					*/
					if (strcmp(entryName, "DOOM.WAD") == 0)
					{
						printf("1 - The Ultimate DOOM");
						DEF_DOOM1 = 1;
					}
					else if (strcmp(entryName, "DOOM2.WAD") == 0)
					{
						printf("2 - DOOM 2: Hell on Earth");
						DEF_DOOM2 = 1;
					}
					else if (strcmp(entryName, "DOOM1.WAD") == 0)
					{
						printf("3 - DOOM Shareware");
						DEF_DOOMS = 1;
					}
					else if (strcmp(entryName, "PLUTONIA.WAD") == 0)
					{
						printf("4 - The Plutonia Experiment");
						DEF_PLUTO = 1;
					}
					else if (strcmp(entryName, "TNT.WAD") == 0)
					{
						printf("5 - TNT: Evilution");
						DEF_TNTEV = 1;
					}
					else if (strcmp(entryName, "FREEDOOM1.WAD") == 0)
					{
						printf("6 - Freedoom: Phase 1");
						DEF_FREE1 = 1;
					}
					else if (strcmp(entryName, "FREEDOOM2.WAD") == 0)
					{
						printf("7 - Freedoom: Phase 2");
						DEF_FREE2 = 1;
					}
					else if (strcmp(entryName, "FREEDM.WAD") == 0)
					{
						printf("8 - FreeDM");
						DEF_FREDM = 1;
					}
					printf("\n");
				}
			}
		}
	}

	if (files < 1)
	{
		printf("No WADs found\n");
		return 1;
	}

	int c;
	
	printf("Type the number of the IWAD you want to launch\nType anything else to cancel\n> ");
	c = getchar();
	printf("%i\n", c);

	switch (c)
	{
		case 49:
			if (DEF_DOOM1)
			{
				strcat(ExecutableLine, CDL_ExecutablePath);
				strcat(ExecutableLine, " -iwad ");
				strcat(ExecutableLine, CDL_WADPath);
				strcat(ExecutableLine, "/DOOM2.WAD");
			}
			break;
		case 50:
			if (DEF_DOOM2)
			{
				strcat(ExecutableLine, CDL_ExecutablePath);
				strcat(ExecutableLine, " -iwad ");
				strcat(ExecutableLine, CDL_WADPath);
				strcat(ExecutableLine, "/DOOM2.WAD");
			}
			break;
		case 51:
			if (DEF_DOOMS)
			{
				strcat(ExecutableLine, CDL_ExecutablePath);
				strcat(ExecutableLine, " -iwad ");
				strcat(ExecutableLine, CDL_WADPath);
				strcat(ExecutableLine, "/DOOM1.WAD");
			}
			break;
		case 52:
			if (DEF_PLUTO)
			{
				strcat(ExecutableLine, CDL_ExecutablePath);
				strcat(ExecutableLine, " -iwad ");
				strcat(ExecutableLine, CDL_WADPath);
				strcat(ExecutableLine, "/PLUTONIA.WAD");
			}
			break;
		case 53:
			if (DEF_TNTEV)
			{
				strcat(ExecutableLine, CDL_ExecutablePath);
				strcat(ExecutableLine, " -iwad ");
				strcat(ExecutableLine, CDL_WADPath);
				strcat(ExecutableLine, "/TNT.WAD");
			}
			break;
		case 54:
			if (DEF_FREE1)
			{
				strcat(ExecutableLine, CDL_ExecutablePath);
				strcat(ExecutableLine, " -iwad ");
				strcat(ExecutableLine, CDL_WADPath);
				strcat(ExecutableLine, "/FREEDOOM1.WAD");
			}
			break;
		case 55:
			if (DEF_FREE2)
			{
				strcat(ExecutableLine, CDL_ExecutablePath);
				strcat(ExecutableLine, " -iwad ");
				strcat(ExecutableLine, CDL_WADPath);
				strcat(ExecutableLine, "/TNT.WAD");
			}
			break;
		case 56:
			if (DEF_FREDM)
			{
				strcat(ExecutableLine, CDL_ExecutablePath);
				strcat(ExecutableLine, " -iwad ");
				strcat(ExecutableLine, CDL_WADPath);
				strcat(ExecutableLine, "/FREEDOOM1.WAD");
			}
			break;
		default:
			return 0;
	}
	printf(ExecutableLine);
	system(ExecutableLine);
}
