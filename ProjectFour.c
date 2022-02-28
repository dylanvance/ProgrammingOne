/*
* Program Name: Project 4
*
* Description: Opens an input file, copies the contents,
*			   and prints the copied content along with
*			   some calculated averages.
*
* Author: Dylan Vance n01450847
*
* Date: 12/4/20
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* GetFileName(char [80]);
int FileFunc(char [80], char [60][10]);
int PrintTable(char [60][10]);


int main(void) {

	char arry[60][10];
	char fileName[80];

	GetFileName(fileName);

	FileFunc(fileName, arry);

	PrintTable(arry);

	return 0;
}


/*
* Function Name: GetFileName
*
* Input Parameters: input[80] - an 80 character array 
*					that holds the file name.
*
* Description: Prompts the user for a file name and attempts
*			   to open the file: if unsuccessful, the user 
*			   is alerted and the program is exited. Also 
*			   checks to see if 'q' (the quit command) is 
*			   entered.
*
* Return Value: input - the file name.
*/
char* GetFileName(char input[80]) {

	char quit[80] = "q";

	printf("Enter The File Name: ");
	scanf("%s", input);

	if (strcmp(input, quit) == 0) {
		printf("Quitting Program\n");
		exit(0);
	}

	FILE* inputFile;

	inputFile = fopen(input, "r");

	if (inputFile == NULL) {
		printf("ERROR: File Does Not Exist\n");
		exit(0);
	}

	fclose(inputFile);

	return input;
}


/*
* Function Name: FileFunc
*
* Input Parameters: input[80] - the file name.
*					inputArray[60][10] - the 2d array that
*					the file's contents will be copied to.
*
* Description: Opens the input file and scans the contents of
*			   the file to an array then closes the file.
*
* Return Value: Nothing.
*/
int FileFunc(char input[80], char inputArray[60][10]) {

	FILE* inputFile;

	printf("Opening File\n");
	inputFile = fopen(input, "r");

	printf("Copying File\n");
	for (int i = 0; i < 60; i++) {
		fscanf(inputFile, "%s", inputArray[i]);
	}

	printf("Closing File\n");
	fclose(inputFile);

	return 0;
}


/*
* Function Name: PrintTable
*
* Input Parameters: outputArray[60][10] - the 2d array of the 
*					file's contents.
*
* Description: Prints a table of the file's contents as well
*			   as the averages of the 4 quiz scores.
*
* Return Value: Nothing.
*/
int PrintTable(char outputArray[60][10]) {

	int newLineCtr = 0;
	int quizScoreCtr = 0;
	float sum = 0;
	float avg = 0;
	char* pend;
	char header[7][6] = 
	{"Name", "ID", "Quiz1", "Quiz2", "Quiz3", "Quiz4", "Avg"};
	
	printf("Printing Table\n");

	for (int i = 0; i < 7; i++) {
		printf("%10s|", header[i]);
	}

	printf("\n");

	for (int i = 0; i < 60; i++) {

		printf("%10s|", outputArray[i]);
		newLineCtr++;
		quizScoreCtr++;

		if (quizScoreCtr > 2) {
			sum += strtof(outputArray[i], &pend);
		}

		if (newLineCtr == 6) {
			avg = sum / 4;
			printf("%10.2f|", avg);
			printf("\n");
			sum = 0;
			avg = 0;
			newLineCtr = 0;
			quizScoreCtr = 0;
		}
	}

	return 0;
}