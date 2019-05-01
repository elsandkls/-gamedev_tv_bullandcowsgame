#include "FBullsAndCowsGame.h"

FBullsAndCowsGame::FBullsAndCowsGame()
{
	// initialization code 
	Reset();
}

void FBullsAndCowsGame::Reset()
{
	// constants defintions
	constexpr int32 MAX_TRIES = 5;
	//constexpr int32 MAX_WORDLENGTH = 9;
	const FString HIDDEN_WORD = "planet";
	int32 MAX_WORDLENGTH = HIDDEN_WORD.length();

	// Variables used in program
	MaxWordLength = MAX_WORDLENGTH;
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1; // varies during programs lifecycle
	MyHiddenWord = HIDDEN_WORD;

	return;
}

int32 FBullsAndCowsGame::GetMaxTries() const
{
	return MyMaxTries;
}

int32 FBullsAndCowsGame::GetMaxWordLength() const
{
	return MaxWordLength;
}

int32 FBullsAndCowsGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

void FBullsAndCowsGame::SetCurrentTry()
{
	MyCurrentTry++;
	return;
}

bool FBullsAndCowsGame::IsGameWon(FString Guess)
{
	if (Guess == MyHiddenWord)
	{
		return true;
	}
	else
	{
		return false;
	}
}

EGuessStatus FBullsAndCowsGame::CheckGuessValidity(FString Guess)
{
	if (IsIsogram(Guess) == false) // if the guess isn't an isogram
	{	// return error
		return EGuessStatus::NotIsogram;
	}
	else if (IsLowerCase(Guess) == false) // if the guess isn't all lowercase
	{	// return error
		return EGuessStatus::NotLowerCase;
	}
	else if (GetMaxWordLength() != Guess.length()) // if the guess length is wrong
	{	// return error
		return EGuessStatus::IncorrectCharLength;
	}
	else if (Guess == "") // if the guess is emtpy or null
	{	// return error
		return EGuessStatus::GuessIsNull;
	}
	else // otherwise
	{	// return ok
		return EGuessStatus::OK;
	} 
}

bool FBullsAndCowsGame::IsIsogram(FString Guess)
{
	int32 charMatchsFound = 0;
	int32 outercharcount = 0;
	int32 innercharcount = 0;
	for (outercharcount = 0; outercharcount < Guess.length(); outercharcount++)
	{
		for (innercharcount = 0; innercharcount < Guess.length(); innercharcount++)
		{
			if (Guess[outercharcount] == Guess[innercharcount] && outercharcount != innercharcount)
			{
				charMatchsFound++;
			}
		}
	}
	if(charMatchsFound > 0)
	{ 
		return false;
	}
	else
	{ 
		return true;
	}
}

bool FBullsAndCowsGame::IsLowerCase(FString Guess)
{
	int32 charcheck = 0;
	int32 charcount = 0;

	for (charcount = 0; charcount < Guess.length(); charcount++)
	{
		charcheck += islower(Guess[charcount]);
	}

	// look up islower to see what the return values are. just guessing
	if( charcheck > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// recieves a valid guess, increments turn, and returns count
FBullCowCount FBullsAndCowsGame::ProcessGuess(FString Guess)
{
	// increment the turn number
	SetCurrentTry();

	// setup a return variable
	FBullCowCount BullCowCount;
	
	// loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	int32 GuessWordLength = Guess.length();

	for (int32 HiddenWordChar = 0; HiddenWordChar < HiddenWordLength; HiddenWordChar++)
	{
		for (int32 GuessWordChar = 0; GuessWordChar < GuessWordLength; GuessWordChar++)
		{
			// compare letters against the hidden word
			if (HiddenWordChar == GuessWordChar)
			{
				if (MyHiddenWord[HiddenWordChar] == Guess[GuessWordChar])
				{	// if they match increment bulls (location matters)
					BullCowCount.Bulls++;
				}
				else
				{	// else increment cows
					BullCowCount.Cows++;
				}
			} 
		}
	}
	return BullCowCount;
}