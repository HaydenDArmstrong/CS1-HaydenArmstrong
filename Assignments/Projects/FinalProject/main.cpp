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
#include "hangman.h"

using namespace std;

void startGame(Difficulty difficulty, const vector<string>& words) {
    // Adjust game parameters based on difficulty
    int maxTries;
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
    bool playAgain = true;

    srand(time(0));

    while (playAgain) {
        
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

            cout << "Enter a letter: ";
            cin >> letter;

            // Check if the letter has already been guessed
            if (guessedLetters.find(letter) != string::npos) {
                cout << "You've already guessed that letter. Try again.\n";
                continue;
            }

            // Check if the letter is in the word
            if (updateWord(selectedWord, hiddenWord, letter)) {
                cout << "Correct!\n";
            } else {
                cout << "Incorrect guess.\n";
                ++wrongGuesses;
            }

            // Add guessed letter to list
            guessedLetters += letter;

            // Check if the word has been guessed
            if (selectedWord == hiddenWord) {
                guessedWord = true;
                break;
            }
        }

        // Display outcome of game
        if (guessedWord) {
            cout << "Congratulations! You guessed the word: " << selectedWord << endl;
        } else {
            cout << "Ouch! You ran out of tries. The word was: " << selectedWord << endl;
        }

            // Ask player if they want to play again
        char choice;
        cout << "Do you want to play again? (y/n): ";
        cin >> choice;

        if (choice != 'y' && choice != 'Y') {
            playAgain = false;
        }

        // Reset variables for new game
        guessedWord = false;
        guessedLetters.clear();
        }

        

    }

int main() {
    // Read words from file into vector
    vector<string> words;
    
    // Main game loop
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
                cout << "When all parts of the stick figure are hung, the game is over.\n";
                cout << "There are usually 6 incorrect guesses (head, body, 2 arms, 2 legs), but this will change with difficulty.\n";
                cout << "Easy: Short words, more common letters. 8 tries before ending\n";
                cout << "Medium: Moderate length words, some common letters. 6 tries before ending\n";
                cout << "Hard: Longer words, fewer common letters. 4 tries before ending \n";
                break; // Don't start the game, let the loop repeat
            default:
                cout << "Invalid choice. Defaulting to Medium difficulty.\n";
                difficulty = Difficulty::MEDIUM;
                words = readWordsFromFile("words.txt");
                break;
        }

        startGame(difficulty, words);

    return 0;

}
