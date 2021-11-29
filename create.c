/*

ESOF 3655 Project

Nicholas Imperius
Jimmy Tsang
Jarrod Graseley

*/

#include <stdio.h>
#include <unistd.h>

void create() {
	//Initialize file variable and char arrays
	FILE *file;
	char fileName[800];
	
	//Get file name from the user
	printf("Enter the new file's name: ");
	scanf("%s", fileName);
	
	//if the file exists, then we try to create it
	// else, let user know it exists already
	if(access(fname, F_OK) == 0)
		if (fopen(fileName, "w"))
			printf("File has been created.");
		else
			printf("Error: unable to create the file.");
	else
		printf("Error: the file you want to create already exists.");
}
	