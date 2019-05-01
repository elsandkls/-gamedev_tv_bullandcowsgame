#pragma once
#include <string> 

using FString = std::string; // compatibility with UnrealEngine
using int32 = int; // compatibility with UnrealEngine

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	GuessIsNull,
	NotIsogram,
	NotLowerCase,
	IncorrectCharLength,
	OK
};

class FBullsAndCowsGame
{
public:   //get and set members/actions	
	FBullsAndCowsGame(); // constructor

	int32 GetMaxTries() const;
	int32 GetMaxWordLength() const;
	int32 GetCurrentTry() const; 

	void Reset(); // TODO: change the return value later.
	EGuessStatus CheckGuessValidity(FString);  // TODO: change the return value later.
	bool IsIsogram(FString);
	bool IsLowerCase(FString);
	void SetCurrentTry();
	bool IsGameWon(FString);
	FBullCowCount ProcessGuess(FString);

private:
	// see initialization section for starting values
	int32 MyCurrentTry; // private member variables
	int32 MyMaxTries; // private member variables
	int32 MaxWordLength; // private member variables
	FString MyHiddenWord; 
};