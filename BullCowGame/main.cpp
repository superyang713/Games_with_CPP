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
FText GetValidGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game.

// The entry point for our application.
int main()
{
	do
	{
        BCGame.Reset();
        PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());

	return 0;
}


void PrintIntro()
{
	// introduce the game
	std::cout << "\n\nWelcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	return;
}


void PlayGame()
{
	int32 MaxTries = BCGame.GetMaxTries();

    // is NOT won and loop asking for guesses while the game
    // and there are still tries remaining
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)  // TODO: change from FOR to WHILE loop once we are validating tries
	{
		FText Guess = GetValidGuess(); // TODO: make loop checking valid.

		// submit valid guess to the game
		FBullCowCount BullCowCout = BCGame.SubmitValidGuess(Guess);

		// print number of bulls and cows
		std::cout << "Bulls = " << BullCowCout.Bulls;
		std::cout << ". Cows = " << BullCowCout.Cows << "\n\n";
	}
	// TODO: add a game summary
}


// loop continually until the user gives a valid guess
FText GetValidGuess()  // TODO: change to valid guess
{
	// get a guess from the player
    EGuessStatus Status = EGuessStatus::Invalid_Status;
    FText Guess;
    do {
        int32 CurrentTry = BCGame.GetCurrentTry();
        std::cout << "Try " << CurrentTry << ". Enter your guess: ";
        getline(std::cin, Guess);

        Status = BCGame.CheckGuessValidity(Guess);
        switch (Status)
        {
            case EGuessStatus::NOT_Isogram:
                std::cout << "Please enter a word without repeating letters.\n";
                break;
            case EGuessStatus::Wrong_Length:
                std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
                break;
            case EGuessStatus::Not_Lowercase:
                std::cout << "Please enter all lowercase letters.\n";
                break;
            default:
                break;
        }
        std::cout << std::endl;
    } while (Status != EGuessStatus::OK);  //Keep looping until we get no errors.
    return Guess;
}


bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n) ";
	FText Response;
	getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}
