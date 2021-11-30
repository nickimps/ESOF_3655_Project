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

void remove() {
		//Initialize file variable and char arrays
	char textName[800];
	
	//Get file name from the user
	printf("Enter the textFile's name: ");
	scanf("%s", textName);
	
	//Add comparison for .txt
	
	if (access(textName, F_OK) == 0) {
		fopen(textName, "w");
		printf("Text file has been cleared");
	} 
	else {
		printf("Text file could not be found");
	}
}