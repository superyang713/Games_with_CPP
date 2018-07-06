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

class FBullCowGame
{
public:
	FBullCowGame(); // constructor
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO: make a more rich return value;
	bool CheckGuessValidity(FString); // TODO: make a more rich return value;
	// counts bulls & cows, and increasing turn # assuming valid guess
	FBullCowCount SubmitGuess(FString);


// Try ignore this and focus on the interface above 
private:
	// see constructor for initialization
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};