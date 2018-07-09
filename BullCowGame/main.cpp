#include <iostream>
#include <string>
#include "FBullCowGame.h"


// to make syntax Unreal friendly
using FText = std::string;
using int32 = int;


void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();


FBullCowGame BCGame;    // instantiate a new game


int main()
{
    bool bPlayAgain = false;
    do
    {
        BCGame.Reset();
        PrintIntro();
        PlayGame();
        bPlayAgain = AskToPlayAgain();
    } while (bPlayAgain);
    return 0;
}


void PrintIntro()
{
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << std::endl;
	std::cout << "          }   {         ___ " << std::endl;
	std::cout << "          (o o)        (o o) " << std::endl;
	std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
	std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
	std::cout << " *  |-,--- |              |------|  * " << std::endl;
	std::cout << "    ^      ^              ^      ^ " << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}


// plays a single game to completion
void PlayGame()
{
    int32 MaxTries = BCGame.GetMaxTries();

    while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
    {
        FText Guess = GetValidGuess();
        FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
    }

    PrintGameSummary();
    return;
}


// loop continually until the user gives a valid guess
FText GetValidGuess()
{
    FText Guess = "";
    EGuessStatus Status = EGuessStatus::INVALID_STATUS;
    do
    {
        // get a guess from the player
        int32 CurrentTry = BCGame.GetCurrentTry();
        std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries();
        std::cout << ". Enter your Guess: ";
        std::getline(std::cin, Guess);

        // validate the guess to make sure input word pass all requirements.
        Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
        {
            case EGuessStatus::WRONG_LENGTH:
                std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
                break;
            case EGuessStatus::NOT_ISOGRAM:
                std::cout << "Please enter a word witout repeating letters.\n\n";
                break;
            case EGuessStatus::NOT_LOWERCASE:
                std::cout << "Please enter all lowercase letters.\n\n";
                break;
            default:
                // assume the guess is valid
                break;
        }

    } while (Status != EGuessStatus::OK);
    return Guess;
}


bool AskToPlayAgain()
{
    std::cout << "Do  you wnat to play again (y/n)? ";
    FText Response = "";
    std::getline(std::cin, Response);
    return (tolower(Response[0]) == 'y');
}


void PrintGameSummary()
{
    if (BCGame.IsGameWon())
    {
        std::cout << "WELL DONE - YOU WIN!" << std::endl;
    }
    else
    {
        std::cout << "Better luck next time!" << std::endl;
    }
}
