#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// all values initialized 0
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	OK,
	NOT_Isogram,
	Wrong_Length,
	Not_Lowercase,
};

class FBullCowGame
{
public:
	FBullCowGame(); // constructor
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;

	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString);

	void Reset(); // TODO: make a more rich return value;
	FBullCowCount SubmitGuess(FString);


// Try ignore this and focus on the interface above 
private:
	// see constructor for initialization
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};