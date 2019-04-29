// Simple Game: Bulls and Cows
// Udemy Unreal Course
#include <iostream> 
#include <string> 
#include "FBullsAndCowsGame.h" 

void PrintIntro();
void PlayGame();
std::string UserInput();
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
	int WORLD_LENGTH = BCGame.GetMaxWordLength();
	std::cout << "Welcome to Bulls and Cows, a fun word game\n";
	std::cout << "Can you guess the " << WORLD_LENGTH;
	std::cout << " letter isogram I'm thinkng of?\n";
	std::cout << std::endl;
}

std::string UserInput()
{
	std::string Guess = "";
	// get a guess fron the user 
	std::cout << "What is your guess?\n";
	std::getline(std::cin, Guess);
	std::cout << std::endl;

	return Guess;
}

void GameOutput(std::string Guess)
{
	// repeat the guess back to them
	std::cout << "Your guess was: " << Guess;
	std::cout << std::endl;
}

void PlayGame()
{
	int limit = BCGame.GetMaxTries();
	std::cout << limit << std::endl;

	std::string Guess = "";
	// loop for the number of user guesses
	for (int count = 1; count <= limit; count++)
	{
		Guess = UserInput();
		// repeat the guess back to them
		GameOutput(Guess);
	}

}

bool AskToPlayAgain()
{
	bool UASSwitch;
	std::cout << "Do you want to play again?";
	std::string Response = "";
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