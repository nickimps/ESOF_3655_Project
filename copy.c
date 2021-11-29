/*

ESOF 3655 Project

Nicholas Imperius
Jimmy Tsang
Jarrod Graseley

This file copies a file in the same directory as where the program is being run

*/

#include <stdio.h>
#include <unistd.h>

void copy() {
	//Initialize file variable and char arrays
	char fileName[800];
	
	//Get file name from the user
	printf("Enter the file name you want to copy: ");
	scanf("%s", fileName);

	//Create the file pointer for the source file we want to copy
	FILE *fptrSource = fopen(fileName, "r");
	
	//If the file was able to opened, then get the destination file
	// else, let the user know
	if (fptrSource) {
		//Get file name from the user
		printf("Enter the file name you want to copy it to: ");
		scanf("%s", fileName);
		
		FILE *fptrDest = fopen(fileName, "wb");
		
		//If the file was able to be opened, copy the file char by char
		// else, let the user know
		if (fptrDest) {
			char chr = fgetc(fptrSource);
			while (chr != EOF) {
				fputc(chr, fptrDest);
				chr = fgetc(fptrSource);
			}
			
			printf("Copy Successful.");
		}
		else
			printf("Error: Cannot open file '%s'\n", fileName);
		
		//Close pointer
		fclose(fptrDest);
	}
	else
		printf("Error: Cannot open file '%s'\n", fileName);
	
	//Close pointer
	fclose(fptrSource);
}