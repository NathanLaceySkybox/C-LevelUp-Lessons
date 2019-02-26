#include "GuessingGame.hpp"

int main(int argc, char** argv)
{
	GuessingGame guessingGame("Nathan's Guessing Game", "Test", 2u);

	guessingGame.StartGame();
	
	while (!guessingGame.PlayLoop());

	return 0;
}