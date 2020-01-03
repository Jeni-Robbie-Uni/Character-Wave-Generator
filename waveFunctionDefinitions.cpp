/***************************************************************************************************
File: waveFunctionDefinitions.cpp
Author : <Jeni Robbie>
Assignment 2- Question 1
Description: Function definitions
Date Created: 31/10/19
Last Modified: 31/10/19
***************************************************************************************************/

#include <string>
#include "waveFunctionDeclaration.h" 
#include <iostream>
#include <time.h>

// Give instructions to the user
void userInstructions( int maxSize, int minSize, int maxNum, int minNum)
{
	// Uses global variables defining wave limits to give flexible instructions
	cout << "This program produces a series of triangles drawn with a user defined character such as * to imitate waves." << endl;
	cout << "You(the user) can define the first waves maximum size(peak), how many waves will be produced and if these waves will get gradually bigger or stay the same." << endl;
	cout << "The first wave's maximum peak is " <<maxSize << "* high and the maximum occurence of the waves is " << maxNum << endl;
	cout << "The minimum first wave's peak must be " << minSize << " in order to form triangular waves" << endl;
	cout << "The minimum wave length must be " << minNum << endl;
}

//Get and validate wave characteristic i.e size limits or datatype
int getUserNumInput(string waveCharacteristic, int maxNum, int minNum)
{
	bool inputValid = false;
	int userInput = 0; //Stores wave number or size
	while (inputValid == false)
	{
		cout << "Please enter the " << waveCharacteristic << " of waves to occur. Max: " << maxNum << " Min: " << minNum << endl;
		cin >> userInput;
		// Validates wave input and gives feedback on type of invalid input entered
		inputValid = integerRangeInputValidation(userInput, minNum, maxNum);
	}
	return userInput;
}


// Validates input and give+s feedback on invalid input entered
bool integerRangeInputValidation(int userinput, int minNum, int maxNum)
{
	//cin.fail=true if user input is not an integer
	if (cin.fail())
	{
		//Clear buffer of error state
		cin.clear();
		//ignore next 1000 input characters after first error found and move on to next line
		cin.ignore(1000, '\n');
		cout << "Invalid input- input must be a number." << endl;
		return false;
	}
	//Checks userinput is within set range of integers defined by parameters minNum and maxNum
	else if (userinput < minNum || userinput > maxNum)
	{
		cout << "Invalid input- number is out of range." << endl;
		return  false;
	}
	else
		return true;
}

//Validate 2 character yes or no response to user input
bool characterValidation(char userinput)
{

	if (userinput != 'y' && userinput != 'n')
	{
		//Prompt user
		cout << "Input invalid. \nPlease enter \"y\" for yes and  \"n\" for no." << endl;
		return false;
	}
	else
	{
		return true;
	}
}
bool getWaveIncreaseResponse()
{
	// Give user instruction
	cout << "Would you like the waves to  get bigger type character \"y\" for yes and \"n\" for no (y/n)." << endl;
	bool responseValid = false;
	char characterInput;
	{
		cin >> characterInput;
		// Return boolean value from validating user response
		responseValid = characterValidation(characterInput);
	}while (responseValid == false)
	// returns wave increase boolean value
	if (characterInput == 'y')
		return true;
	else
		return false;
}
//Print wave pattern differently depending on userinput
void wavePattern(int length, bool increase, int size, char symbolCharacter)
{
	//loop for the number of waves
	for (int y = 0; y < length; y++)
	{
		//Prints increasing triangle
		triangleIncrement(size, symbolCharacter);
		//Prints decreasing triangle
		triangleDecrement(size, symbolCharacter);
		// if user has selected waves to get bigger, waves size will increase by 1 everytime goes through loop
		if (increase == true)
			size = size + 1;
	}
}
// Prints triangle in increment pattern
void triangleIncrement(int maxSize, char symbol)
{
	const int millisecond = 100;	// Time delay in seconds
	//loops for hieght of wave
	for (int i = 1; i <= maxSize; i++)
	{
		
		clock_t goal = millisecond + clock();	//Time delay for printing
		while (goal > clock());
		{
			//loops to print 1 or more symbols depending on position of first loop
			for (int x = 1; x <= i; x++)
			{
				cout << symbol;
			}
			cout << endl;
		}

	}
}

//Print charachter in descending triangle pattern based on wave size
void triangleDecrement(int maxSize, char symbol)
{
	//starts count at maximum size -1 to get first position in decrement triangle
	for (int i = (maxSize - 1); i >= 1; i--)
	{
		const int millisecond = 100;	// Time delay in seconds
		clock_t goal = millisecond + clock(); //Time delay for printing
		while (goal > clock());
		{
			//loops to print 1 or more symbols depending on position of first loop
			for (int x = 1; x <= i; x++)
			{
				cout << symbol;
			}
			cout << endl;
		}

	}
}

//Asks user whether to repeat program again and gets input
char exitOrContinue()
{
	char exit;		//character user inputs to exit loop or continue program
	cout << "Do you want to start again? Enter y for yes or any other key to exit." << endl;
	cin >> exit;
	return exit;
}


