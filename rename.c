/*

ESOF 3655 Project

Nicholas Imperius
Jimmy Tsang
Jarrod Grasley

*/

#include <stdio.h>
#include <unistd.h>

void renameFile() {
	//Initialize Variables
	int name;
	char before[800];
	char after[800];
	
	//Get the file name from the user
	printf("What is the existing file name: ");
	scanf("%s", before);
	
	//If the file exists then prompt for new name and change it
	// else, let user know the file does not exist
	if (access(before, F_OK) == 0) {
		printf("Enter a new name: ");
		scanf("%s", after);
		
		if (access(after, F_OK))
			if (rename(before, after) == 0)
				printf("Name succesfully changed.\n");
			else
				printf("Name could not be changed.\n");
		else
			printf("Error: File '%s' already exists.\n", after);
	} 
	else {
		printf("Error: '%s' does not exist.\n", before);
	}
}
