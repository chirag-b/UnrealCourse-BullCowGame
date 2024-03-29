/*
	The game logic (no view code or direct user interaction)
	The game is a simple guess the word game based on Mastermind.
*/

#pragma once
#include <string>

// to make syntax Unreal friendly
using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;

};

enum class EGuessStatus
{
	Invalid_State,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame
{
// public interface
public:
	FBullCowGame();

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	int GetHiddenWordLength() const;
	EGuessStatus CheckGuessValidity(FString) const;
	
	void Reset();
	FBullCowCount SubmitValidGuess(FString);

private:
	// see constructor for initialisation
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameWon;
	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;
};