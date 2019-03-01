#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio4.h>
#define MAXCHARS 100
// Gavin Anderson , 20116948, 17gka2
//Arsh Kochhar, 20104779, 17AK126
//Shiyan Boxer, 20106887, 17sb79
int main(int argc, char **argv)
{

	//declare variables
	FILE*infile;
	char anArray[MAXCHARS];
	char userInput[MAXCHARS];
	int position;
	int errors;
	int wordAmount;
	int wordPerminute;
	long startMsec;
	long endMsec;
	float totalTime;


//Gives a directory to the file
	infile = fopen("../typingTest.txt","r");



//Returns null if file is not found and displays a message that the file can't be found
	if(infile == NULL) {
		printf("Could not be opened");
		exit(1);
	}
	//Records the intial time in miliseconds
	startMsec = getmSecs();
	//value of errors is initalized
	errors = 0;
	//Reads the file line by line and inserts the data into a char array
	while(fgets(anArray,MAXCHARS,infile)) {
		//Counts the amount of words on the file. This way allows for multiple different files of various lengths can be used
		wordAmount = wordAmount +1;
// prints the current term being added into the array
		printf("%s",anArray);
		//Adds the usersinput into a char array
		fgets(userInput,MAXCHARS,stdin);
		//compares the two current values in the char arrays
		while(strcmp(userInput,anArray) != 0) {
			//allows for a new input to be added
			printf("Error Please type: %s\n", anArray);
			//adds one to the error counter
			errors = errors + 1;
			//adds the new input to the userInput array
			fgets(userInput,MAXCHARS,stdin);

		}
	}
	//Takes a second time in miliseconds
	endMsec = getmSecs();
	//Substracts the two times
	totalTime = endMsec - startMsec;
	//converts the miliseconds into seconds for a better frame of reference
	totalTime = totalTime / 1000;
	// divides the amount of words by the total time to calculate the words per minute being typed
	wordPerminute = wordAmount / totalTime * 60;
// final print statements
	printf("Test Complete: %.2f\n", totalTime);
	printf("Errors: %d\n", errors);
	printf("Words per Minute %d",wordPerminute);




}
