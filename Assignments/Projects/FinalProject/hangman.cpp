#include "hangman.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<std::string> readWordsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::string> words;
    std::string word;

    if (file.is_open()) {
        while (file >> word) {
            words.push_back(word);
        }
        file.close();
    } else {
        std::cerr << "Error: Unable to open file.\n";
    }

    return words;
}

std::string getRandomWord(const std::vector<std::string>& words) {
    int index = rand() % words.size();
    return words[index];
}

void displayHangman(int wrongGuesses) {

    #ifdef _WIN32
        system("cls"); // For Windows
    #else
        system("clear"); // For Unix/Linux
    #endif
    

    // ASCII art representation of Hangman. Added case 7 and 8 for higher difficulties
    switch (wrongGuesses) {
    case 0: //intial
        std::cout << "       -------\n";
        std::cout << "      |     |\n";
        std::cout << "      |     \n";
        std::cout << "      |    \n";
        std::cout << "      |     \n";
        std::cout << "      |    \n";
        std::cout << " _____|__________\n";
        std::cout << "/     |         /|\n";
        std::cout << "______________ / /\n";
        std::cout << "              | /\n";
        std::cout << "______________|/ \n";
        break;
    case 1: //head
        std::cout << "       -------\n";
        std::cout << "      |     |\n";
        std::cout << "      |     @\n";
        std::cout << "      |    \n";
        std::cout << "      |     \n";
        std::cout << "      |    \n";
        std::cout << " _____|__________\n";
        std::cout << "/     |         /|\n";
        std::cout << "______________ / /\n";
        std::cout << "              | /\n";
        std::cout << "______________|/ \n";
        break;
    case 2: //neck
        std::cout << "       -------\n";
        std::cout << "      |     |\n";
        std::cout << "      |     @\n";
        std::cout << "      |     |\n";
        std::cout << "      |     |\n";
        std::cout << "      |    \n";
        std::cout << " _____|__________\n";
        std::cout << "/     |         /|\n";
        std::cout << "______________ / /\n";
        std::cout << "              | /\n";
        std::cout << "______________|/ \n";
        break;
    case 3: //first arm
        std::cout << "       -------\n";
        std::cout << "      |     |\n";
        std::cout << "      |     @\n";
        std::cout << "      |    /| \n";
        std::cout << "      |     |\n";
        std::cout << "      |    \n";
        std::cout << " _____|__________\n";
        std::cout << "/     |         /|\n";
        std::cout << "______________ / /\n";
        std::cout << "              | /\n";
        std::cout << "______________|/ \n";
        break;
    case 4: //second arm (dead on hard)
        std::cout << "       -------\n";
        std::cout << "      |     |\n";
        std::cout << "      |     @\n";
        std::cout << "      |    /|\\\n";
        std::cout << "      |     |\n";
        std::cout << "      |    \n";
        std::cout << " _____|__________\n";
        std::cout << "/     |         /|\n";
        std::cout << "______________ / /\n";
        std::cout << "              | /\n";
        std::cout << "______________|/ \n";
        break;
    case 5://first leg
        std::cout << "       -------\n";
        std::cout << "      |     |\n";
        std::cout << "      |     @\n";
        std::cout << "      |    /|\\\n";
        std::cout << "      |     |\n";
        std::cout << "      |    /  \n";
        std::cout << " _____|__________\n";
        std::cout << "/     |         /|\n";
        std::cout << "______________ / /\n";
        std::cout << "              | /\n";
        std::cout << "______________|/ \n";
        break;
    case 6://last leg (dead on normal mode)
        std::cout << "       -------\n";
        std::cout << "      |     |  \n";
        std::cout << "      |     X  \n";
        std::cout << "      |    /|\\ \n";
        std::cout << "      |     |   \n";
        std::cout << "      |    / \\ \n";
        std::cout << " _____|__________\n";
        std::cout << "/     |         /|\n";
        std::cout << "______________ / /\n";
        std::cout << "              | /\n";
        std::cout << "______________|/ \n";
        break;

        case 7:// stars for difficulties below medium
        std::cout << "       -------\n";
        std::cout << "      |     |\n";
        std::cout << "      | *   X  \n";
        std::cout << "      |    /|\\ \n";
        std::cout << "      |     | \n";
        std::cout << "      |    / \\ \n";
        std::cout << " _____|_________\n";
        std::cout << "/     |         /|\n";
        std::cout << "______________ / /\n";
        std::cout << "              | /\n";
        std::cout << "______________|/ \n";
        break;

        case 8://extra stars
    std::cout << "       -------\n";
    std::cout << "      |     |\n";
    std::cout << "      | **  X\n";
    std::cout << "      |    /|\\\n";
    std::cout << "      |     |\n";
    std::cout << "      |    / \\\n";
    std::cout << " _____|_________\n";
    std::cout << "/     |         / |\n";
    std::cout << "______________ / /\n";
    std::cout << "              | /\n";
    std::cout << "______________|/ \n";
    break;
}
}


void displayWord(const std::string& word) {
    std::cout << "Word: " << word << std::endl;
}

bool updateWord(const std::string& selectedWord, std::string& hiddenWord, char letter) {
    bool letterFound = false;
    for (size_t i = 0; i < selectedWord.length(); ++i) {
        if (selectedWord[i] == letter) {
            hiddenWord[i] = letter;
            letterFound = true;
        }
    }
    return letterFound;
}