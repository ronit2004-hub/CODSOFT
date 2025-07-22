#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int main() {
    // Initialize random seed
    srand(time(0));
    
    // Generate random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;
    
    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I've selected a number between 1 and 100. Can you guess it?" << endl;
    
    while (true) {
        cout << "Enter your guess: ";
        
        // Check for valid input
        while (!(cin >> guess)) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            cout << "Please enter a valid number: ";
        }
        
        attempts++;
        
        if (guess == secretNumber) {
            cout << "Congratulations! You guessed the correct number in " 
                 << attempts << " attempts!" << endl;
            break;
        } else if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Too high! Try again." << endl;
        }
    }
    
    return 0;
}