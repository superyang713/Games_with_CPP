#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();


// The entry point for our application.
int main()
{
	PrintIntro();
	do
	{
		std::cout << std::endl;
		PlayGame();
	} while (AskToPlayAgain());

	return 0;
}


void PrintIntro()
{
	// introduce the game
	constexpr int WORLD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORLD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	return;
}


void PlayGame()
{
	FBullCowGame BCGame; // instantiate a new game.
	int MaxTries = BCGame.GetMaxTries();

	std::cout << MaxTries << std::endl;
	// loop for the number of turns asking for guesses
	for (int i = 0; i < MaxTries; i++)
	{
		std::string Guess = GetGuess();
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}
}


std::string GetGuess()
{
	// get a guess from the player
	std::cout << "Enter your guess: ";
	std::string Guess;
	getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n) ";
	std::string Response;
	getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}