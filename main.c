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

int main() {

	char command[1024];
	
	printf("Commands: \nCreateFile\nDeleteFile\nRenameFile\nCopyFile\nMoveFile\nAddText\nAppendText\nRemoveText\nShowText\nExit\n");

	//Program runs as long as exit is not called
	while(strcmp("Exit", command) != 0) {
		printf("\nEnter a Command: ");
		scanf("%s", command);
		
		if (strcmp("CreateFile", command) == 0) {
			create();
		}
		else if (strcmp("CreateFile/h", command) == 0) {
			printf("Create File allows you to create a new file");
		}
		
		else if (strcmp("DeleteFile", command) == 0) {
			delete();
		}
		else if (strcmp("DeleteFile/h", command) == 0) {
			printf("Delete File allows you to delete an existing file");
		}
		
		else if (strcmp("RenameFile", command) == 0) {
			renameFile();
		}
		else if (strcmp("RenameFile/h", command) == 0) {
			printf("Rename File allows you to rename a file");
		}
		
		else if (strcmp("CopyFile", command) == 0) {
			copy();
		}
		else if (strcmp("CopyFile/h", command) == 0) {
			printf("Copy File allows you to take an existing file and duplicate it");
		}
		
		else if (strcmp("MoveFile", command) == 0) {
			//move();
		}
		else if (strcmp("MoveFile/h", command) == 0) {
			printf("Move File allows you to move an existing file");
		}
		
		else if (strcmp("AddText", command) == 0) {
			//add();
		}
		else if (strcmp("AddText/h", command) == 0) {
			printf("Add Text allows you to add text to the end of a text file");
		}
		
		else if (strcmp("AppendText", command) == 0) {
			//append();
		}
		else if (strcmp("AppendText/h", command) == 0) {
			printf("Append Text allows you to append text to anywhere in a text file");
		}
		
		else if (strcmp("RemoveText", command) == 0) {
			//r/emove();
		}
		else if (strcmp("RemoveText/h", command) == 0) {
			printf("Remove Text allows you to remove all text in a text file");
		}
		
		else if (strcmp("ShowText", command) == 0) {
			//show();
		}
		else if (strcmp("ShowText/h", command) == 0) {
			printf("Show Text allows you to show the content of a text file");
		}
	}
}
