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
	
	int fileNameLength = strlen(source);
	const char *fileType = &source[fileNameLength-4];
	char txtType[] = ".txt";
	
	if (strcmp(txtType, fileType) == 0) {
		//check if the file exists
		if (access(source, F_OK) != -1) {
			//open the file with read access
			FILE* sourceFile = fopen(source, "r");
			
			if (sourceFile) {
				//Get the size of a line
				int lineSize;
				printf("Enter the number of chars per line: ");
				scanf("%d", &lineSize);
				
				//Get the number of lines per page
				int numOfLines;
				printf("Enter the number of lines per page: ");
				scanf("%d", &numOfLines);
				
				//Instruction for user
				printf("-- Hit [enter] to load next page --\n ");
				char temp[1];
				scanf("%c", temp);
				
				//Make sure valid line number
				if (numOfLines > 0 && lineSize > 0) {
					char line[lineSize];
					int linesInFile = 0;
					
					//Get the total number of lines in the textfile
					while(fgets(line, sizeof(line), sourceFile))
						linesInFile += 1;
					
					//close the file
					fclose(sourceFile);
					
					//Initialize variables
					int start = 0;
					int end = 0;
					int lineNum = 1;
					
					//Loop until we have nothing left in the text file
					while(1) {
						//Check to make sure that there are lines left
						if ((linesInFile - 1) > end) {
							
							//Increment where the end is
							end += numOfLines;
							
							//Reset line number
							lineNum = 1;
							
							//Open the file each time
							FILE* file = fopen(source, "r");
							
							//Print out each line that needs to be printed
							while (fgets(line, sizeof(line), sourceFile)) {
								if (start <= lineNum && end >= lineNum)
									printf("%s", line);
								lineNum += 1;
							}
							
							//Close the file
							fclose(file);
							
							//Make the end line + 1 the next start line
							start = end + 1;
						}
						else
							break;
						
						//Wait for enter press from user
						scanf("%c", temp);
					}
				}
				else
					printf("Error: Not a valid number.\n");
			}
			else
				printf("Error: Unable to open file.");
	
			//close the file
			fclose(sourceFile);
		}
		else
			printf("Error: Text file could not be found.\n");
	}
	else
		printf("Error: Not a text file.\n");
}