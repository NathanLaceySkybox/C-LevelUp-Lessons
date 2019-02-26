#pragma once
#include <string>

class GuessingGame
{
public:
	GuessingGame() = default;
	GuessingGame(const std::string& gameTitle, const std::string& wordToGuess, uint32_t guessesAllowed);
	GuessingGame(const char* gameTitle, const char* wordToGuess, uint32_t guessesAllowed);

	void StartGame();
	bool PlayLoop();

private:
	void DisplayStart();
	bool DisplayGuess();
	std::tuple<bool, uint32_t, uint32_t> Guess(const std::string& guess);

private:
	const std::string mGameTitle{ "GuessingGame" };
	const uint32_t mGuessesAllowed{ 2u };
	uint32_t mGuessesMade{ 0u };
	const std::string mWordToGuess{ "Word" };
};