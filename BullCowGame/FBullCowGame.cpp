#include "FBullCowGame.h"
#include <map>
#define TMap std::map

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon () const { return bGameWon; }


void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 3;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

    bGameWon = false;
	MyCurrentTry = 1;
	return;
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess)
{
	if (!IsIsogram(Guess))	// if the guess isn't an isogram
	{
		return EGuessStatus::NOT_Isogram;
	}
	else if (!IsLowercase(Guess))  // if the guess isn't all lowercase
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != (unsigned)GetHiddenWordLength())  // if the guess length is wrong
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

    if ((unsigned)BullCowCount.Bulls == MyHiddenWord.length())
    {
        bGameWon = true;
    }
    else {
        bGameWon = false;
    }
	return BullCowCount;
}


bool FBullCowGame::IsIsogram(FString Word) const
{
    // treat 0 and 1 letter words as isograms.
    if (Word.length() <= 1){ return true;}

    TMap<char, bool> LetterSeen;     // set up our map
    for (auto Letter : Word)         // for all letters of the word
    {
        Letter = tolower(Letter);    // handle mixed case
        if (LetterSeen[Letter])      // if the letter is in the map
        {
            return false;
        }
        else {
            LetterSeen[Letter] = true;   // add the letter to the map as seen
        }
    }

    return true;
}


bool FBullCowGame::IsLowercase(FString Word) const
{
    for (auto Letter : Word)
    {
        if (!islower(Letter))   // if not a lowercase letter
            return false;
    }
    return true;
}
