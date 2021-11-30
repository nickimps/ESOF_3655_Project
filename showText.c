/*

ESOF 3655 Project

Nicholas Imperius
Jimmy Tsang
Jarrod Grasley

This file shows the text of a .txt file

*/

#include <stdio.h>
#include <unistd.h>

void show() {
	//Get name of file to access
	char source[800];
	printf("Enter the file you would like to show: ");
	scanf("%s", source);
	
	//check if the file exists
	if (access(source, F_OK) != -1) {
		//open the file with read access
		FILE* sourceFile = fopen(source, "r");
		
		if (sourceFile) {
			//create temp variable
			char temp;
			
			//read file until end of file (EOF)
			while ((temp = fgetc(sourceFile)) != EOF) {
				//send individual char to line until it reaches the end
				putchar(temp);
			}
			printf("\n");
		}
		//close the file
		fclose(sourceFile);
	}
	else
		printf("Error: Text file could not be found.\n");
}