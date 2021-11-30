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
	printf("Enter the file you would like to change: ");
	scanf("%s", source);
	
	//check if file exists
	if (access(source, F_OK) != -1) {
		//open the file in append mode
		FILE* sourceFile = fopen(source, "a");
		
		//get data to append
		char newData[800];
		printf("Enter the text you would like to append: ");
		scanf("%s", newData);
		
		//send that data to the file
		if (fputs(newData, sourceFile) != EOF)
			printf("Text appended successfully.");
		else
			printf("Error: Append unsuccessful.");
			
		fclose(sourceFile);
	}
	else
		printf("Error: Text file could not be found.\n");
}