/*
	This is a console excuteable. 
	See FBullsAndCowsGame for details.
*/
// Simple Game: Bulls and Cows
// Udemy Unreal Course
#include <iostream> 
#include <string> 
#include "FBullsAndCowsGame.h" 

using FText = std::string; // compatibility with UnrealEngine
using int32 = int; // compatibility with UnrealEngine

void PrintIntro();
void PlayGame();
FText UserInput(); 
void GameOutput();
bool AskToPlayAgain();
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
	std::cout << "Welcome to Bulls and Cows, a fun word game\n";
	std::cout << "Can you guess the " << word_length;
	std::cout << " letter isogram I'm thinkng of?\n";
	std::cout << std::endl;
}

FText GetUserInput()
{
	int32 Try = BCGame.GetCurrentTry();
	FText Guess = "";
	// get a guess fron the user 
	std::cout << "Try: " << Try << "   \n What is your guess? ";
	std::getline(std::cin, Guess);
	std::cout << std::endl; 
	return Guess;
}

void GameOutput(FText Guess)
{	 
	// repeat the guess back to them
	std::cout << "Your guess was: " << Guess;
	std::cout << std::endl;
}

void PlayGame()
{
	BCGame.Reset();

	int32 limit = BCGame.GetMaxTries();
	//std::cout << limit << std::endl;
	FText Guess = "";
	// loop for the number of user guesses -- lesson 53
	for (int32 count = 1; count <= limit; count++)
	{
		Guess = GetUserInput(); 
		EGuessStatus Status = BCGame.CheckGuessValidity(Guess);
		// repeat the guess back to them
		GameOutput(Guess);
		//submit guess to game
		FBullCowCount BullCowCount = BCGame.ProcessGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls << std::endl;
		std::cout << "Cows = " << BullCowCount.Cows << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;
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