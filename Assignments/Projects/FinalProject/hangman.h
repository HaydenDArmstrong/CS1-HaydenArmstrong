#ifndef HANGMAN_H
#define HANGMAN_H

#include <string>
#include <vector>

enum class Difficulty { EASY, MEDIUM, HARD, HELP };

//external variables to track wins, number of games, and win/loss ratio (wins divided by total number of games)
extern int wins;
extern int games;
extern double wlratio;


std::vector<std::string> readWordsFromFile(const std::string& filename);
std::string getRandomWord(const std::vector<std::string>& words);
void displayHangman(int wrongGuesses);
void displayWord(const std::string& word);
bool updateWord(const std::string& selectedWord, std::string& hiddenWord, char letter);


#endif 