/*

ESOF 3655 Project

Nicholas Imperius
Jimmy Tsang
Jarrod Grasley

This file removes text from a .txt file

*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

void removeText() {
	//Initialize file variable and char arrays
	char fileName[800];
	
	//Get file name from the user
	printf("Enter the textFile's name: ");
	scanf("%s", fileName);
	
	int fileNameLength = strlen(fileName);
	const char *fileType = &fileName[fileNameLength-4];
	char txtType[] = ".txt";
	
	if (strcmp(txtType, fileType) == 0) {
		if (access(fileName, F_OK) == 0) {
			fopen(fileName, "w");
			printf("Text file has been cleared.\n");
		} 
		else
			printf("Error: Text file could not be found.\n");
	}
	else
		printf("Error: Not a text file.\n");
}