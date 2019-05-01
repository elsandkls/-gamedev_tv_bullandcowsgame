/*
The game logic(no view code or direct user interaction)
The game is a simple gues the word game.
*/
#pragma once
#include <string> 

// compatibility with UnrealEngine
using FString = std::string;  
using int32 = int;  

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
	bool IsIsogramHashTable(FString);
	bool IsLowerCase(FString);
	void SetCurrentTry();
	bool IsGameWon(FString); 
	FBullCowCount ProcessGuess(FString);
	int32 GameLoop = 0;

private:
	// see initialization section for starting values
	int32 MyCurrentTry; // private member variables
	int32 MyMaxTries; // private member variables
	int32 MaxWordLength; // private member variables 
	FString MyHiddenWord; 
	FString MyHiddenWordList[25] = { "plants","fruity","shovel","bucket","garden","planet", "orgasmic", "gasiform", "origamis", "algorism", "organism", "isograms", "gouramis", "isogram", "gambirs", "gisarme", "imagers", "imagoes", "mirages", "armings", "margins", "morgans", "origans", "roaming", "signora" };

};