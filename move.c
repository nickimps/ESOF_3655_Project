/*

ESOF 3655 Project

Nicholas Imperius
Jimmy Tsang
Jarrod Grasley

This file moves a file to another directory

*/

void move() {
	//Get name of the file they want to move
	char source[800];
	printf("Enter the file you would like to move: ");
	scanf("%s", source);
	
	//Check if the file exists
	if (access(source, F_OK) != -1) {
		//Open the file with read access
		FILE *sourceFile = fopen(source, "r");
		
		if (sourceFile) {
			//Get the destination
			char dest[800];
			printf("Enter the destination file's name and path: ");
			scanf("%s", dest);
			
			if (access(dest, F_OK) == -1) {
				//Create the destination file
				FILE *destFile = fopen(dest, "wb");
				
				if (destFile) {
					//Copy the contents of the file
					char chr = fgetc(sourceFile);
					while (chr != EOF) {
						fputc(chr, destFile);
						chr = fgetc(sourceFile);
					}
					
					printf("File successfully moved.\n");
				}
				else
					printf("Error: Unable to create file.\n");
				
				//Close the file
				fclose(sourceFile);
				fclose(destFile);
				
				//Remove the original file
				remove(source);
			}
			else
				printf("Error: File exists already.\n");
		}
		else
			printf("Error: Unable to read file.\n");
		
		//Close the file
		fclose(sourceFile);
	}
	else
		printf("Error: File does not exist.\n");
	
	
}