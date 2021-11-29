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
	
	//if the file exists, then we try to create it
	// else, let user know it exists already
	if(remove(fileName) == 0)
		printf("File has been copied.\n")
	else
		printf("Error: Unable to copy the file.\n");
}