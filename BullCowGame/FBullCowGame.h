/* The game logic (no view code or direct user interaction)
 * The game is a simple guess the word game based on Mastermind.
*/

#pragma once
#include <string>


// to make syntax Unreal friendly
using FString = std::string;
using int32 = int;


/*! \struct FBullCowCount
 *  \brief Brief struct description
 *  contains the feedback of correct number of words
 */
struct FBullCowCount
{
    int32 Bulls = 0; /*!< number of correct words at the correct position */
    int32 Cows  = 0; /*!< number of correct words at the wrong position */
};


/*! \enum class EGuessStatus
 *
 *  brief description
 *  used in switch statement to catch user input error.
 */
enum class EGuessStatus
{
    INVALID_STATUS,
    OK,
    NOT_ISOGRAM,
    WRONG_LENGTH,
    NOT_LOWERCASE
};


/*! \class FBullCowGame
 *  \brief Brief class description
 *
 *  Detailed description
 */
class FBullCowGame
{
public:
    FBullCowGame();     //constructor

    // getter functions
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    int32 GetHiddenWordLength() const;
    bool IsGameWon() const;
    EGuessStatus CheckGuessValidity(FString) const;

    void Reset();
    FBullCowCount SubmitValidGuess(FString);

protected:
    int32 MyCurrentTry;
    FString MyHiddenWord;
    bool bGameIsWon;

    bool IsIsogram(FString) const;
    bool IsLowercase(FString) const;
};
