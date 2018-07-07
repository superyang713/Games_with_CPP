#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon () const { return bGameWon; }


void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planes";
	MyHiddenWord = HIDDEN_WORD;

    bGameWon = false;
	MyCurrentTry = 1;
	return;
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
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;

	// loop through all letters in the hidden word
	int32 WordLength = MyHiddenWord.length();  // assuming same length as guess
	for (int32 GWChar = 0; GWChar < WordLength; GWChar++)
	{
		for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++)
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

    if (BullCowCount.Bulls == MyHiddenWord.length())
    {
        bGameWon = true;
    }
    else {
        bGameWon = false;
    }
	return BullCowCount;
}
