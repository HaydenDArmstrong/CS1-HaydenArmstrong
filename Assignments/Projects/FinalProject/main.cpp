/*
Made by Hayden Armstrong
Due Date: 5/10/24
Program: This program is a hangman program. I designed it to function in three difficulties; easy, medium, and hard.

Each difficulty has corresponding words text file, and limits the amount of guesses given as difficulty scales.

hangman.h is the file where functions are declared, hangman.cpp are the implemntation of those functions,
main.cpp is where the main logic is for the game. 

*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "hangman.h"


using namespace std;

void startGame(Difficulty difficulty, const vector<string>& words, int& wins, int& games, double& wlratio) {
    // Adjust game based on difficulty
    int maxTries = 0; // Initialization of maxTries
    switch (difficulty) {
        case Difficulty::EASY:
            maxTries = 8;
            break;
        case Difficulty::MEDIUM:
            maxTries = 6;
            break;
        case Difficulty::HARD:
            maxTries = 4;
            break;
        case Difficulty::HELP:
            break;
    }

    // Initialize variables
    char letter;
    bool guessedWord = false;

    srand(time(0));

    // Select a random word from vector
    string selectedWord = getRandomWord(words);

    // Initialize
    int wrongGuesses = 0;
    string guessedLetters;
    string hiddenWord(selectedWord.length(), '_');

    cout << "Welcome to Hangman! Try to guess the word.\n";

    // Main game loop
    while (wrongGuesses < maxTries && !guessedWord) {
        displayHangman(wrongGuesses);
        displayWord(hiddenWord);
        cout << "Incorrect letters guessed: ";
        for (int i = 0; i < guessedLetters.size(); ++i) {
            cout << guessedLetters[i];
            // Print comma and space if it's not the last character
            if (i < guessedLetters.size() - 1) {
                cout << ", ";
            }
        }
cout << endl;
        cout << "Guesses remaining: " << maxTries - wrongGuesses << endl;

        cout << "Enter a letter: ";
        cin >> letter;

        // Check if the input is an alphabetic character
    if (!isalpha(letter)) {
        cout << "Invalid input! Please enter an alphabetic character.\n";
       continue; // Restart the loop to prompt for a valid input
    }

    // Convert input to lowercase to match the word files
    letter = tolower(letter);

        // Check if the letter has already been guessed. doesnt currently working because of the hangman screen refresh loop
        //if (guessedLetters.find(letter) != string::npos) {
        //    cout << "You've already guessed that letter. Try again.\n";
        //    continue;
        //}

        // Check if the letter is in the word
        if (updateWord(selectedWord, hiddenWord, letter)) {
            cout << "Correct!\n";
        } else {

            ++wrongGuesses;
            guessedLetters += letter; // Add incorrect letter to list
        }

        // Check if the word has been guessed
        if (selectedWord == hiddenWord) {
            guessedWord = true;
            break;
        }
    }

    // Display outcome of game
    if (guessedWord) {
        cout << "Congratulations! You guessed the word: " << selectedWord << endl;
        ++wins;
    } else {
        displayHangman(wrongGuesses);
        cout << "Ouch! You ran out of tries. The word was: " << selectedWord << endl;
    }
    ++games;
    if (games > 0) {
        wlratio = static_cast<double>(wins) / games;
    } else {
        wlratio = 0.0; // Avoid division by zero
    }
}

int main() {
    // Read words from file into vector
    vector<string> words;

    //initalize external ints that we use to track wins and total games player
    int wins = 0;
    int games = 0;
    double wlratio = 0.0;



    char playAgainChoice = 'y'; // Initialize playAgainChoice

    while (playAgainChoice == 'y' || playAgainChoice == 'Y') {
        // Display menu to select difficulty
        cout << "Select difficulty:\n";
        cout << "1. Easy\n";
        cout << "2. Medium\n";
        cout << "3. Hard\n";
        cout << "4. Explanation\n";
        int choice;
        cin >> choice;

        Difficulty difficulty;
        switch (choice) {
            //chooses which word file and difficulty to activate based on user answer
            case 1:
                difficulty = Difficulty::EASY;
                words = readWordsFromFile("words_easy.txt");
                break;
            case 2:
                difficulty = Difficulty::MEDIUM;
                words = readWordsFromFile("words.txt");
                break;
            case 3:
                difficulty = Difficulty::HARD;
                words = readWordsFromFile("words_hard.txt");
                break;
            case 4:
                difficulty = Difficulty::HELP;
                cout << "Explanation:\n";
                cout << "The objective of hangman is to guess the secret word before the stick figure is hung.\n";
                cout << "When all parts of the stick figure are hung, the game is over.\n\n";
                cout << "There are usually 6 incorrect guesses (head, body, 2 arms, 2 legs), but this will change with difficulty.\n\n";
                cout << "Easy: Short words, more common letters. 8 tries before ending\n";
                cout << "Medium: Moderate length words, some common letters. 6 tries before ending\n";
                cout << "Hard: Longer words, fewer common letters. 4 tries before ending \n\n";
                break;

            default:
                cout << "Invalid choice. Defaulting to Medium difficulty.\n";
                difficulty = Difficulty::MEDIUM;
                words = readWordsFromFile("words.txt");
                break;
        }

        if (choice != 4) { 
            // Start the game only if not showing explanation
            startGame(difficulty, words, wins, games, wlratio);
        }

        // Display total number of wins
        cout << "Total wins: " << wins << endl;
        cout << "Total Games Played: " << games << endl;

        cout << setprecision(2) << "Win/Loss Ratio: " << wlratio << endl;

        //once game is over, ask if want to play again

        cout << "Do you wish to play again? (y/n): ";
        cin >> playAgainChoice;
    }

    return 0;
}
