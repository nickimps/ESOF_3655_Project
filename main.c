/*

ESOF 3655 Project

Nicholas Imperius
Jimmy Tsang
Jarrod Grasley

Main driver program

*/

#include <stdio.h>
#include <stdlib.h>

#include "create.c"
#include "rename.c"
#include "delete.c"
#include "copy.c"
#include "move.c"
#include "insertText.c"
#include "appendText.c"
#include "removeText.c"
#include "showText.c"

int main() {

	char command[800];
	
	printf("Commands: \nCreateFile\nDeleteFile\nRenameFile\nCopyFile\nMoveFile\nInsertText\nAppendText\nRemoveText\nShowText\nExit\n");

	//Program runs as long as exit is not called
	while(strcmp("Exit", command) != 0) {
		printf("\nEnter a Command: ");
		scanf("%s", command);
		
		if (strcmp("CreateFile", command) == 0) {
			create();
		}
		else if (strcmp("CreateFile/h", command) == 0) {
			printf("CreateFile allows you to create a new file. Once you use the command, just enter the new file's name.");
		}
		
		else if (strcmp("DeleteFile", command) == 0) {
			delete();
		}
		else if (strcmp("DeleteFile/h", command) == 0) {
			printf("DeleteFile allows you to delete an existing file. Once you use the command, enter the file's name you want to delete.");
		}
		
		else if (strcmp("RenameFile", command) == 0) {
			renameFile();
		}
		else if (strcmp("RenameFile/h", command) == 0) {
			printf("RenameFile allows you to rename a file. Once you use the command, enter the name of the file and then the new name for it.");
		}
		
		else if (strcmp("CopyFile", command) == 0) {
			copy();
		}
		else if (strcmp("CopyFile/h", command) == 0) {
			printf("CopyFile allows you to take an existing file and duplicate it. Once you use the command, enter the file you want to copy and then the path with the new file name.");
		}
		
		else if (strcmp("MoveFile", command) == 0) {
			move();
		}
		else if (strcmp("MoveFile/h", command) == 0) {
			printf("MoveFile allows you to move an existing file to a different folder. \nOnce you use the command,enter 'full path'\'new file name'.");
		}
		
		else if (strcmp("InsertText", command) == 0) {
			insert();
		}
		else if (strcmp("InsertText/h", command) == 0) {
			printf("InsertText allows you to add text to the end of a text file. Once you use the command, enter the file's name, the text you want to insert, and where you want to insert it.");
		}
		
		else if (strcmp("AppendText", command) == 0) {
			append();
		}
		else if (strcmp("AppendText/h", command) == 0) {
			printf("AppendText allows you to append text to anywhere in a text file. Once you use the command, enter the file's name and the text you would like to add to the end of the file.");
		}
		
		else if (strcmp("RemoveText", command) == 0) {
			removeText();
		}
		else if (strcmp("RemoveText/h", command) == 0) {
			printf("RemoveText allows you to remove all text in a text file. Once you use the command, enter the file's name that you want to clear.");
		}
		
		else if (strcmp("ShowText", command) == 0) {
			show();
		}
		else if (strcmp("ShowText/h", command) == 0) {
			printf("ShowText allows you to show the content of a text file. Once you use the command, enter the file's name that has the text you want to show.");
		}
		
		else if (strcmp("Exit", command) == 0) {
			printf("");
		}
		else {
			printf("Error: Not a valid command.\n");
		}
	}
}
