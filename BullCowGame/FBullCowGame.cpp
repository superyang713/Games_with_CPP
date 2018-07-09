#include "FBullCowGame.h"
#include <map>


// to make syntax Unreal friendly
#define TMap std::map
using int32 = int;


// constructor
FBullCowGame::FBullCowGame() { Reset(); }   //default constructor


// getter functions
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }


int32 FBullCowGame::GetMaxTries() const
{
    TMap<int32, int32> WordLengthToMaxTries{
        {3, 4}, {4, 7}, {5, 10}, {6, 16}, {7, 20}
    };
    return WordLengthToMaxTries[MyHiddenWord.length()];
}


void FBullCowGame::Reset()
{
    const int32 NumberOfHiddenWords = 4;
    const FString HIDDEN_WORDS[NumberOfHiddenWords] = {
        "cat", "dog", "planet", "earth"
    };
    int32 RandomIndex = rand() % NumberOfHiddenWords;
    MyHiddenWord = HIDDEN_WORDS[RandomIndex];

    MyCurrentTry = 1;
    bGameIsWon = false;
    return;
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
    if (!IsIsogram(Guess))
    {
        return EGuessStatus::NOT_ISOGRAM;
    }
    else if (!IsLowercase(Guess))
    {
        return EGuessStatus::NOT_LOWERCASE;
    }
    else if (Guess.length() != (unsigned)GetHiddenWordLength())
    {
        return EGuessStatus::WRONG_LENGTH;
    }
    else
    {
        return EGuessStatus::OK;
    }
}


// valid if the game is won, increments turn, and returns count
// The variable "Guess" has already been validated by CheckGuessValidity func.
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
    MyCurrentTry++;
    FBullCowCount BullCowCount;
    int32 WordLength = MyHiddenWord.length();

    for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++)
    {
        for (int32 GChar = 0; GChar < WordLength; GChar++)
        {
            if (Guess[GChar] == MyHiddenWord[MHWChar])
            {
                if (MHWChar == GChar)
                {
                    BullCowCount.Bulls++;
                }
                else
                {
                    BullCowCount.Cows++;
                }
            }
        }
    }
    if (BullCowCount.Bulls == WordLength)
    {
        bGameIsWon = true;
    }
    else
    {
        bGameIsWon = false;
    }
    return BullCowCount;
}


bool FBullCowGame::IsIsogram(FString Word) const
{
    // treat 0 and 1 letter words as isograms
    if (Word.length() <= 1) { return true; }

    TMap<char, bool> LetterSeen;
    for (auto Letter : Word)
    {
        Letter = tolower(Letter);
        if (LetterSeen[Letter])
        {
            return false;
        }
        else
        {
            LetterSeen[Letter] = true;
        }
    }
    return true;
}


bool FBullCowGame::IsLowercase(FString Word) const
{
    for (auto Letter : Word)
    {
        if (!islower(Letter))
        {
            return false;
        }
    }
    return true;
}
