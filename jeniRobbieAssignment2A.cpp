/**
****************************************************************************************************
File: jeniRobbieAssignment2A.cpp
Author : <Jeni Robbie>
Assignment 2- Question 1

C++ program using functions which produces a series of triangles pointing to the
right, drawn with a * character, which, when the program runs, will
imitate 'waves'.The program allows the user to specify the size of the waves to be
drawnand how many waves are to be drawn altogether.
The user should also be able to specify if the wave size stays the same or gets biggerand
bigger.

Assumptions made are as followed :
1. what size means - size means height of peak
2. what the user defines the first wave peak size not min max peak size of wave sequence
	if min peak in sequence was > or < length of sequence, complications of choosing initial peak size.
	if max peak size < sequence length it contradicts the "get bigger options"
3. minimum size of first wave must be 2 (minimum size is logical assumption otherwise you cannot create a triangle)
4. Maximum wave size is 5
5.max num of waves - user cant enter 1000 Waves would get too big(not triangles) given previous assumption that we are defining first peak
6. minimum number of waves is 2 other wise will contradict get bigger option
7. How many times programme can run ? User can repeat program infitely until deciding to stop
Other Descisions :
Created const ariables defining restrictions discussed about so that if I wanted to change the limits, I would only need to change the const variables
Allowed user to specify special characer that draws wave

Date Created : 3 / 10 / 19
Last Modified 30 / 10 / 19
* ***************************************************************************************************
*/
#include <iostream>
#include <time.h>
#include "waveFunctionDeclaration.h"
using namespace std;

int main()
{	
	char specialChar;	//  Defining the character to be printed to create wave
	char characterInput;	//Variable for getting wave size increase response
	int numOfWaves = 0;		// Variable for number of waves to be printed
	char exitCondition;		//The user input deciding to start program again or exit
	int waveSize = 0;			// The size of first wave to be defined 
	bool increaseWaveSize = false;	// Condition depending on user input of "does wave size get bigger?" response
	const int maxWaveSize = 5;			//set maximum limit of first wave peak
	const int minWaveSize = 2;		//set minimum limit of first wave peak 
	const int maxNumOfWaves = 10;	//set maximum limit number of waves
	const int minNumofWaves = 2;	//set minimum limit of number of waves
	do
	{
		// Give instructions to the user
		userInstructions( maxWaveSize, minWaveSize, maxNumOfWaves, minNumofWaves);

		//Get character that prints wave from user
		cout << "Please enter the symbol or character you wish to draw the waves with. For example - '*'" << endl;
		cin >> specialChar;

		//Get valid first wave size from user 
		waveSize = getUserNumInput("size", maxWaveSize, minWaveSize);

		//Get and validate the number of waves the user wants to print
		numOfWaves = getUserNumInput("number", maxNumOfWaves, minNumofWaves);

		// Let user decide if waves should get bigger or not
		increaseWaveSize = getWaveIncreaseResponse();

		//Prints wave pattern and prints wave pattern differently dependin on user choice
		wavePattern(numOfWaves, increaseWaveSize, waveSize, specialChar);

		// Exit condition prompt and input
		exitCondition = exitOrContinue();

	} while (exitCondition == 'y');
	return 0;
}
