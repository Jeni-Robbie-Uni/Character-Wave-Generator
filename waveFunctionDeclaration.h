/***************************************************************************************************
File: waveFunctionDeclaration.h
Author : <Jeni Robbie>
Assignment 2- Question 1
Description: Function declaration
Date Created: 31/10/19
Last Modified: 31/10/19

/***************************************************************************************************/
#ifndef waveFunctionDeclaration
#include <string>
using namespace std;

//Gives user Program instruction
void userInstructions(int maxSize, int minSize, int maxNum, int minNum);


//Gets the user integer input for each wave characteristic
int getUserNumInput(string waveCharacteristic, int maxNum, int minNum);

// Validate integer range (min to max) defined by user
bool integerRangeInputValidation(int userinput, int min, int max);

//Validates user input of character y or n
bool characterValidation(char userinput);

// Prints increasing triangle of characters 
void triangleIncrement(int maxSize, char symbol);
//Print charachter in descending triangle pattern
void triangleDecrement(int maxSize,char symbol);

// Prints both increment and decrement triangle to form wave pattern
void wavePattern(int length, bool increase, int size, char symbolChar);

// Gets the exit response from user to continue program or exit
char exitOrContinue();



// Gets user input to "waves get bigger?" prompt and validates
bool getWaveIncreaseResponse();
#endif
