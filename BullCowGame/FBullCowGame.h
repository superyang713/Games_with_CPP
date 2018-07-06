#pragma once
#include <string>

class FBullCowGame
{
public:
	void Reset(); // TODO: make a more rich return value;
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValidity(std::string); // TODO: make a more rich return value;


// Try ignore this and focus on the interface above 
private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;
	bool IsIsogram(std::string);
};