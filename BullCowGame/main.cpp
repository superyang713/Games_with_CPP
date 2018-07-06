/*
This is the console executable, that makes use of the BullCow class.
This acts as the view in a MVC pattern, and is responsible for all
user interaction, for game logic see the FBullCowGame class.
*/


#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game.

// The entry point for our application.
int main()
{
	BCGame.Reset();
	PrintIntro();
	do
	{
		PlayGame();
	} while (AskToPlayAgain());

	return 0;
}


void PrintIntro()
{
	// introduce the game
	constexpr int32 WORLD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORLD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	return;
}


void PlayGame()
{
	int32 MaxTries = BCGame.GetMaxTries();

	// loop for the number of turns asking for guesses
	// TODO: change from FOR to WHILE loop once we are validating tries
	for (int32 i = 0; i < MaxTries; i++)
	{
		FText Guess = GetGuess(); // TODO: make loop checking valid.
		
		// submit valid guess to the game
		FBullCowCount BullCowCout = BCGame.SubmitGuess(Guess);
		// print number of bulls and cows
		std::cout << "Bulls = " << BullCowCout.Bulls;
		std::cout << ". Cows = " << BullCowCout.Cows << std::endl;

		std::cout << std::endl;
	}
	// TODO: add a game summary
}


FText GetGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();

	// get a guess from the player
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	FText Guess;
	getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n) ";
	FText Response;
	getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}