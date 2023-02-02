/* Small program to implement a random number generator 
   and play a guessing game against the computer
*/

#include <iostream>
#include <experimental/random>

int random_num();
void message();

void game()
{
	int guess_count = 0;
	std::string answer = "";
	int guess = 0;
	int num = random_num();
	std::cout << "Enter a number between 1 and 100: ";
	while (std::cin >> guess)
	{
		guess_count++;
		if (guess > 100 || guess < 0)
		{
			std::cout << "Don't be a smartass!!!" << std::endl;
			std::cout << "Enter a valid number: ";
		}
		else if (guess < num)
		{
			std::cout << "Your guess was too low!" << std::endl;
			std::cout << "Enter a higher number: ";
		}	
		else if (guess > num)
		{
			std::cout << "Your guess was too high!" << std::endl;
			std::cout << "Enter a lower number: ";
		}
		else
		{
			std::cout << "You guessed the number!!!" << std::endl;
			std::cout << "It took you " << guess_count << " guesses." << std::endl;
			std::cout << "Would you like to play again? (y or n): ";
			std::cin >> answer;
			if (answer == "y")
			{
				// setting up the next game if the user chose 'yes'
				guess_count = 0;
				num = random_num();
				std::cout << "Enter a number between 1-100: ";
				guess = 0;
			}
			else
			{
				std::cout << "Thankyou for playing! Goodbye." << std::endl;
				break;
			}
		}
	}
}
int main()
{
	message();
	game();
	return 0;
}

int random_num()
{
	// random number generator for the game
	std::experimental::reseed();
	return std::experimental::randint(1, 100);
}

void message()
{
	std::cout << "Welcome to the game! The object of the game "
	"is to guess the number the computer \nis thinking of "
	"and it will tell you if your guess is too high or "
	"too low." << std::endl;
}
