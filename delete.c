/*

ESOF 3655 Project

Nicholas Imperius
Jimmy Tsang
Jarrod Graseley

This file deletes a file in the same directory as where the program is being run

*/

#include <stdio.h>
#include <unistd.h>

void delete() {
	//Initialize file variable and char arrays
	char fileName[800];
	
	//Get file name from the user
	printf("Enter the file's name: ");
	scanf("%s", fileName);
	
	//if the file exists, then we try to create it
	// else, let user know it exists already
	if(remove(fileName) == 0)
		printf("File has been deleted.\n");
	else
		printf("Error: Unable to delete the file.\n");
}