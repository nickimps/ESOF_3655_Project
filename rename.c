/*

ESOF 3655 Project

Nicholas Imperius
Jimmy Tsang
Jarrod Graseley

*/

#include <stdio.h>
#include <unistd.h>

void renameFile() {
	FILE *file;
	int name;
	char before[1024];
	char after[1024];
	
	printf("What is the existing file name: ");
	scanf("%s", before);
	
	if (access(before, F_OK)) {
		printf("Enter a new name: ");
		scanf("%s", after);
		
		if (access(after, F_OK)) {
			
			if (rename(before, after) == 0) {
				printf("Name succesfully changed");
			}
			else {
				printf("Name could not be changed");
			}
		}
		else {
			printf("Error: File name %s already exists, after");
		}
	} 
	else {
		printf("Error: No such file with name %s exists", before);
	}
}
