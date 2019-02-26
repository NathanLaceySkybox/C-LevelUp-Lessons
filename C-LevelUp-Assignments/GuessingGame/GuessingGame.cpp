#include "GuessingGame.hpp"
#include <iostream>
#include <tuple>

GuessingGame::GuessingGame(const std::string& gameTitle, const std::string& wordToGuess, uint32_t guessesAllowed)
	: mGameTitle(gameTitle)
	, mWordToGuess(wordToGuess)
	, mGuessesAllowed(guessesAllowed)
{
}

GuessingGame::GuessingGame(const char* gameTitle, const char* wordToGuess, uint32_t guessesAllowed)
	: mGameTitle(gameTitle)
	, mWordToGuess(wordToGuess)
	, mGuessesAllowed(guessesAllowed)
{
}

void GuessingGame::StartGame()
{
	DisplayStart();
}

bool GuessingGame::PlayLoop()
{
	return DisplayGuess();
}

void GuessingGame::DisplayStart()
{
	std::cout << "Welcome to " << mGameTitle << "\n";
	std::cout << "Can you guess my " << mWordToGuess.size() << " letter word?\n";
}

bool GuessingGame::DisplayGuess()
{
	std::string guess;
	std::cin >> guess;

	auto[correctGuess, correctSymbols, correctPlaces]{ Guess(guess) };

	return correctGuess || mGuessesMade >= mGuessesAllowed;
}

std::tuple<bool, uint32_t, uint32_t> GuessingGame::Guess(const std::string& guess)
{
	++mGuessesMade;
	uint32_t correctSymbols{ 0u };
	uint32_t correctPlaces{ 0u };
	const uint32_t smallerStringSize = guess.size() < mWordToGuess.size() ? guess.size() : mWordToGuess.size();

	for (uint32_t i{ 0u }; i < smallerStringSize; ++i)
	{
		if (guess[i] == mWordToGuess[i])
		{
			++correctPlaces;
		}
	}

	if (correctPlaces == mWordToGuess.size() && mWordToGuess.size() == guess.size())
	{
		return { true, correctSymbols, correctPlaces };
	}
	else
	{
		return { false, correctSymbols, correctPlaces };
	}
}
