#include <iostream>
#include <random>
#include <limits> // Required for numeric_limits

int main() {
    // Use modern C++ random number generation
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 100); // Range 1 to 100 inclusive
    int secretNumber = distrib(gen);

    int guess;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!\n";
    std::cout << "I've chosen a number between 1 and 100. Try to guess it.\n";

    while (true) {
        std::cout << "Enter your guess: ";

        // Input validation using a more robust approach
         if (!(std::cin >> guess)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue; // Skip the rest of the loop and ask for input again
        }


        attempts++;

        if (guess < secretNumber) {
            std::cout << "Too low!\n";
        } else if (guess > secretNumber) {
            std::cout << "Too high!\n";
        } else {
            std::cout << "Congratulations! You guessed the number in " << attempts << " attempts.\n";
            break; // Exit the loop when the guess is correct
        }
    }

    return 0;
}