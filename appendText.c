/*

ESOF 3655 Project

Nicholas Imperius
Jimmy Tsang
Jarrod Grasley

This file appends text to a .txt file

*/

#include <stdio.h>
#include <unistd.h>

void append() {
	//Get name of file to access
	char source[800];
	printf("Enter the file you would like to show: \n");
	scanf("%s", source);
	
	//check if file exists
	if (access(source, F_OK) != -1) {
		//open the file in append mode
		FILE* sourceFile = fopen(source, "a");
		
		//get data to append
		char newData[800];
		printf("Enter the text you would like to append: \n");
		scanf("%s", newData);
		
		//send that data to the file
		fputs(newData, sourceFile);
		
		fclose(sourceFile);
	}
}