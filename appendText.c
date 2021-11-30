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
	
	int fileNameLength = strlen(source);
	const char *fileType = &source[fileNameLength-4];
	char txtType[] = ".txt";
	
	if (strcmp(txtType, fileType) == 0) {
		//Check if file exists
		if (access(source, F_OK) != -1) {
			//Open the file in append mode
			FILE* sourceFile = fopen(source, "a");
			
			//Get data to append and loop through each char to add text with spaces
			char newData[800];
			char ch;
			int index = 0;
			printf("Enter the text you would like to append: ");
			
			//This removes the newline we just created from clicking enter on the previous prompt
			scanf("%c", &ch);
			
			//Loop through remaining characters until we get a newline character
			while (scanf("%c", &ch)) {
				if (ch == '\n')
					break;
				newData[index++] = ch;
			}
			
			//Lets us know we are at end of the string
			newData[index] = '\0';
			
			//Send that data to the file
			if (fputs(newData, sourceFile) != EOF)
				printf("Text appended successfully.\n");
			else
				printf("Error: Append unsuccessful.\n");
			
			//Close the file
			fclose(sourceFile);
		}
		else
			printf("Error: Text file could not be found.\n");
	}
	else
		printf("Error: Not a text file.\n");
}