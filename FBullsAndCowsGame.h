#pragma once
#include <string> 

class FBullsAndCowsGame
{
public:   //get and set members/actions
	void Reset(); // TODO: change the return value later.
	int GetMaxTries();
	int GetMaxWordLength();
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValidity(std::string);  // TODO: change the return value later.

private:
	int MyCurrentTry = 1; // private member variables
	int MyMaxTries = 5; // private member variables
	int MaxWordLength = 9; // private member variables
};