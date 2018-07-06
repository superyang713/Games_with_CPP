#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }


void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "adfasfsajifjefjas";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}


bool FBullCowGame::IsGameWon () const
{
	return false;
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess)
{
	if (false)	// if the guess isn't an isogram 
	{
		return EGuessStatus::NOT_Isogram;
	}
	else if (false)  // if the guess isn't all lowercase
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength())  // if the guess length is wrong
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

// receives a VALID guess, increments turns, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//increment the turn number
	MyCurrentTry++;

	// setup a return variable
	FBullCowCount BullCowCount;

	// loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 GWChar = 0; GWChar < HiddenWordLength; GWChar++)
	{
		for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++)
		{
			// compare letters against the hidden word
			// if they match then and in the same place
			if (Guess[GWChar] == MyHiddenWord[MHWChar] && GWChar == MHWChar)
			{
				BullCowCount.Bulls++;	// increment bulls
			}
			// if they match but not in the same place
			else if (Guess[GWChar] == MyHiddenWord[MHWChar] && GWChar != MHWChar)
			{
				BullCowCount.Cows++;	// increment cows
			}
		}
	}
	return BullCowCount;
}