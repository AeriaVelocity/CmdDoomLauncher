#include <stdio.h>
#include <string.h>
#include <dirent.h>

#ifdef _WIN32
#include "config.win.h"
#else
#include "config.h"
#endif

int main()
{
	DIR* WadPathFolder = opendir(CDL_WADPath);
	struct dirent* entry;
	int x, y = 0;
	int files = 1;
	int KnownWADsLength = sizeof(CDL_KnownWADs)/sizeof(CDL_KnownWADs[0]);
	char* WADEntries[KnownWADsLength];
	
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
					if (entryName == "DOOM.WAD")
					{
						printf("The Ultimate DOOM");
					}
				}
			}
		}
	}

	if (files < 1)
	{
		printf("No WADs found\n");
		return 1;
	}

	int c = 0;
	
	printf("Type the number of the IWAD you want to launch\nType anything else to cancel\n> ");
	c = getchar();
}
