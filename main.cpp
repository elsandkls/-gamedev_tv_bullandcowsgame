/*
	This is a console excuteable.  
*/
// Simple Game: Bulls and Cows
// Udemy Unreal Course
#pragma once
#include <iostream> 
#include <string> 
#include "FBullsAndCowsGame.h" 

// compatibility with UnrealEngine
using FText = std::string;  
using int32 = int;  

// function prototypes
void PrintIntro();
void PlayGame();
FText UserInput(); 
void GameOutput(FText);
bool AskToPlayAgain(); 
void PrintGameSummary(FText);
bool Answer = true;

FBullsAndCowsGame BCGame; //instantiate a new game

int main()
{
	while (Answer == true)
	{
		PrintIntro();
		PlayGame();
		Answer = AskToPlayAgain();
	}
	return 0;
}

void PrintIntro()
{
	// introduce the game    
	int32 word_length = BCGame.GetMaxWordLength();
	std::cout << ".:*~*: ._. : *~*: ._. : *~*: ._. : *~*: ._. : *~*:." << std::endl; 
	std::cout << "Welcome to Bulls and Cows, a fun word game. \n";
	std::cout << ".:*~*: ._. : *~*: ._. : *~*: ._. : *~*: ._. : *~*:." << std::endl;
	std::cout << "Can you guess the " << word_length << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
}

FText GetUserInput()
{
	int32 Try = BCGame.GetCurrentTry();
	int32 maxTry = BCGame.GetMaxTries();
	FText Guess = "";
	// get a guess fron the user 
	std::cout << "Try: " << Try << " of "<< maxTry << "  \n What is your guess? ";
	std::getline(std::cin, Guess);
	std::cout << std::endl; 
	return Guess;
}

void GameOutput(FText Guess)
{	 
	// repeat the guess back to the user
	std::cout << "Your guess was: " << Guess;
	std::cout << std::endl;
}

void PlayGame()
{
	BCGame.Reset();

	int32 limit = BCGame.GetMaxTries();
	//std::cout << limit << std::endl;
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::GuessIsNull; //intialize

	// loop for the number of user guesses -- lesson 53
	for (int32 count = 1; count <= limit; count++)
	{
		while (Status != EGuessStatus::OK)
		{
			Guess = GetUserInput();
			Status = BCGame.CheckGuessValidity(Guess);
			switch (Status)
			{
				case EGuessStatus::IncorrectCharLength:
					std::cout << "Please enter a " << BCGame.GetMaxWordLength() << " letter word. \n"; 
					break;
				case EGuessStatus::NotIsogram:
					std::cout << "Please enter an Isogram. An Isogram has no duplicate letters. \n";
					break;
				case EGuessStatus::NotLowerCase:
					std::cout << "Please enter all lower case characters. \n";
					break;
				case EGuessStatus::GuessIsNull:
					std::cout << "Please enter a word. \n";
					break;
				default:
					break;
			}
		}
		// repeat the guess back to them
		GameOutput(Guess);
		//submit guess to game
		FBullCowCount BullCowCount = BCGame.ProcessGuess(Guess);
		if (BullCowCount.Cows == 0 || BCGame.IsGameWon(Guess) == true)
		{
			// end game
			BCGame.GameLoop++;
			PrintGameSummary(Guess);
			return;
		}
		else
		{
			std::cout << "Bulls = " << BullCowCount.Bulls <<  "\t Cows = " << BullCowCount.Cows << std::endl;
			std::cout << std::endl;
			Status = EGuessStatus::GuessIsNull; // reset to default to prepare for next user input round.
		}
	}
	PrintGameSummary(Guess);
	std::cout << std::endl;
	BCGame.GameLoop++;
	// TODO summarize the game
}

bool AskToPlayAgain()
{
	bool UASSwitch;
	std::cout << "Do you want to play again?";
	FText Response = "";
	std::getline(std::cin, Response);
	if (Response[0] == 'y' || Response[0] == 'Y')
	{
		UASSwitch = true;
	}
	else
	{
		UASSwitch = false;
	}
	return UASSwitch;
}

void PrintGameSummary(FText Guess)
{
	// introduce the game    
	if (BCGame.IsGameWon(Guess) == true)
	{
		std::cout << "Well done! You win.\n";
	}
	else
	{
		std::cout << "Better luck next time.\n"; 
	}
	std::cout << ".:*~*: ._. : *~*: ._. : *~*: ._. : *~*: ._. : *~*:." << std::endl;
	std::cout << std::endl;
}