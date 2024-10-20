// The purpose for this program is to guessed the number that the user is thinking of.
//Author: David Kesselman
//Last Modified: 10/19/2024

#include <iostream>
#include <cstdlib> //For rand and srand
#include <ctime>   // For the time function
using namespace std;

const int MAX_TRIES = 10; //Maximum number of attempts allowed

// Step 1: Initialize Game Setup
// Function to output game instructions
void output_game_instructions() 
{
    cout << "\n\n########################################################" << endl;
    cout << "#    Welcome to the GUESS THE NUMBER game !!!          #" << endl;
    cout << "#    You have 10 attempts to guess a number            #" << endl;
    cout << "#    between 100 and 999! Your score will go           #" << endl;
    cout << "#    up by 1 every time you win, and down by 1 every   #" << endl;
    cout << "#    time you lose. Ready! Set! Go!                    #" << endl;
    cout << "########################################################\n\n" << endl;
}

// Step 2: Main Game Setup
// Function to generate a random number between 100 and 999
int generate_rand_num() 
{
    return (rand() % 900) + 100;
}

// Step 3: Setup for a New Game
// Function to read and validate the user's guess
int read_and_validate() 
{
    int guess;
    cout << "Please enter your guess: "; // Prompt for input
    while (true) 
    {
        cin >> guess;
        if (guess >= 100 && guess <= 999) 
        {
            return guess; //Return Valid Guess
        }
        cout << "Invalid input. Input must be between 100 and 999.\n Please re-enter: ";
    }
}

// Step 4: Player Guess Loop
// Function to ask the user if they want to play again
bool play_again() 
{
    char response;
    cout << "\nWould you like to play again (type y for yes and n for no): "; 
    cin >> response; // Read the reponse
    while (true) 
    {
        if (response == 'y' || response == 'Y' || response == 'n' || response == 'N') 
        {
            return response == 'y' || response == 'Y'; //return true if yes, false if no
        }
        cout << "Invalid input. Please type y for yes and n for no: "; 
        cin >> response; // Read the input again after the error message
    }
}

// Step 5: Display Final Score
int main() 
{
    srand(time(0)); // Seed random number generator

    do 
    {
        int random_number = generate_rand_num(); //Generate a random number
        int tries_left = MAX_TRIES; // Initialize number of tries
        int score = 0; //Initialize score
        bool guessed_correctly = false; //Initialize flag for correct guess

        output_game_instructions(); // Output game instructions

        do 
        {
            cout << "You have " << tries_left << " tries" << endl;
            int guess = read_and_validate(); //Get and validate user's guess
            tries_left--; // Decrement number of tries left

            if (guess == random_number) 
            {
                cout << "Congratulations! You guessed correctly!" << endl;
                score++; // Increase score for correct guess
                guessed_correctly = true; // Set flag to true
            }
            else if (tries_left == 0) 
            {
                cout << "\nSorry, you ran out of tries. The number was " << random_number << "." << endl;
                score--; // Decrease score for running out of tries
            }
            else if (guess < random_number) 
            {
                cout << " Please guess higher.\n" << endl;
            }
            else 
            {
                cout << " Please guess lower.\n" << endl;
            }

        }
            while (!guessed_correctly && tries_left > 0);

        cout << "\nYOUR SCORE is NOW " << score << endl; // Display final score

        // Step 6: Ask to Play Again
    }
        while (play_again()); //Repeat the game iif the user wants to play again

    return 0;
}
