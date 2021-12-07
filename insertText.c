/*

ESOF 3655 Project

Nicholas Imperius
Jimmy Tsang
Jarrod Grasley

This file inserts text to a .txt file

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void insert() {
	//Initialize for loop variable
	int i;
	
	//Get the file to insert to
	char fileName[1000];
	printf("Enter the file name you want to insert in: ");
	scanf("%s", fileName);
	
	int fileNameLength = strlen(fileName);
	const char *fileType = &fileName[fileNameLength-4];
	char txtType[] = ".txt";
	
	if (strcmp(txtType, fileType) == 0) {
		if (access(fileName, F_OK) != -1) {
			//Open the file in read mode
			FILE *fptr = fopen(fileName, "r");
			
			//Initialize storage string
			char originalString[8000];
			
			if (fptr) {
				//Store the contents of the file
				int index = 0;
				char chr = fgetc(fptr);
				while (chr != EOF) {
					originalString[index++] = chr;
					chr = fgetc(fptr);
				}
				
				//Get the text to insert
				char inputText[8000];
				char temp;
				printf("Enter the text you want to insert: ");
				scanf("%c", &temp); // clears buffer
				scanf("%[^\n]s", inputText);
				
				//Get length of original text
				int lengthOfFile = strlen(originalString);
				
				//Get where they want the text inserted
				int pos;
				printf("Enter where you want to insert: ");
				scanf("%d", &pos);
				
				//Check for valid position
				if (pos >= 0 || pos <= lengthOfFile) {
					//Get the substrings of before the position to insert to
					char *firstPart;
					firstPart = malloc(pos - 1);
					
					for (i = 0; i < (pos - 1); i++)
						*(firstPart + i) = *(originalString + i);
					*(firstPart + i) = '\0';
					
					//Get the substring for after the position
					char *lastPart;
					lastPart = malloc(lengthOfFile - pos + 1);
					
					for (i = 0; i < (lengthOfFile - pos + 1); i++)
						*(lastPart + i) = *((originalString + pos - 1) + i);
					*(lastPart + i) = '\0';
					
					//Clear the original string, and then add the firstpart + insertpart + lastpart
					strcpy(originalString, "");
					strcat(originalString, firstPart);
					strcat(originalString, inputText);
					strcat(originalString, lastPart);
					
					//free memory
					free(firstPart);
					free(lastPart);
					
					//Create the file with the new text
					FILE *insertedFile = fopen(fileName, "w");
					fprintf(insertedFile, "%s", originalString);
					fclose(insertedFile);
					
					//Print success message
					printf("Text has been inserted.\n");
				}
				else
					printf("Error: Position Invalid.\n");
			}
			else
				printf("Error: Unable to read file.\n");
			
			//Close file
			fclose(fptr);
		}
		else
			printf("Error: Unable to find file.\n");
	}
	else
		printf("Error: Not a text file.\n");
}