#include <iostream>
#include <string.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

typedef unsigned int u_int;

const char* words[] = {"apple", "orange", "month", "vehicle", "bookmarks",
						"insert", "history", "scientist", "meaningless",
						"wheelchair", "engineering", "mysterious", "stream",
						"question", "eigenvectors", "scared", "challenge",
						"crash", "dinosaurs", "extinct", "reverse", "infusion",
						"sometimes", "elevated", "partnership", "freedom", "finally",
						"religion", "happened", "extraordinary", "yesterday", "issues",
						"programming", "language", "right", "ready", "easier", "way",
						"always", "morning", "someone", "child", "season"};
const u_int wordsCount = 44;
const u_int historyLetters = 26;
u_int maxMistakes = 5;

bool isGuessWord(char historyArray[], u_int indexWord, u_int letters) {
	u_int guessedLetters = 0;
	u_int i = 0;
	while(words[indexWord][i]) {
		u_int j = 0;
		while(historyArray[j]) {
			if(words[indexWord][i] == historyArray[j++]) {
				++guessedLetters;
			}
		}
		i++;
	}

	return (guessedLetters == letters);
}

void print(char historyArray[], u_int indexWord, u_int mistakes, u_int letters) {
		cout << '[' << mistakes << '/' << maxMistakes << "] ";
		for(u_int j = 0; j < letters; j++) {
			u_int index = 0;
			bool noSuchLetter = true;
			while(historyArray[index]) {
				if(words[indexWord][j] == historyArray[index]) {
					cout << historyArray[index] << ' ';
					noSuchLetter = false;
					break;
				}
				index++;
			}
			if (noSuchLetter) {
				cout << "_ ";
			}
		}
		cout << "History: ";
		u_int i = 0;
		while(historyArray[i])
			cout << historyArray[i++] << ' ';

		cout << endl;
}

void checkLetterExistInWord(u_int indexWord, u_int& mistakes, char letter) {
	u_int j = 0;
	bool noSuchLetter = true;
	while(words[indexWord][j]) {
		if(words[indexWord][j] == letter) {
			noSuchLetter = false;
			cout << "OK" << endl;
			break;
		}
		j++;
	}
	if(noSuchLetter) {
		mistakes++;
		cout << "No such letter" << endl;	
	}
}

char enterLetter(u_int indexWord, u_int& mistakes) {
	cout << "Choose a letter: ";
	char letter;
	cin >> letter;

	checkLetterExistInWord(indexWord, mistakes, letter);
	return letter;
}

char generateLetter(u_int indexWord, u_int& mistakes, char historyArray[]) {
	char letter;
	letter = 'a' + rand() % 26;
	cout << letter << endl;
	checkLetterExistInWord(indexWord, mistakes, letter);
	return letter;
}

void play(bool isAI) {
	u_int indexInHistoryArray;
	u_int mistakes;
	u_int indexWord;	
	srand(time(NULL));	
	
	while(true) {
		indexInHistoryArray = 0;
		mistakes = 0;
		char historyArray[historyLetters] = {0};
		indexWord = rand()%wordsCount;
		
		while(mistakes < maxMistakes) {
			u_int lettersInWord = strlen(words[indexWord]);
			print(historyArray, indexWord, mistakes, lettersInWord);	
			char letter;
			if (isAI) {
				letter = generateLetter(indexWord, mistakes, historyArray);
			} else	
				letter = enterLetter(indexWord, mistakes);	
			
			historyArray[indexInHistoryArray++] = letter;
			
			if(isGuessWord(historyArray, indexWord, lettersInWord)) {
				cout << "Congratulations, you guessed the word!!!" << endl;
				break;
			}
		}
		if(mistakes == maxMistakes)
			cout << "Sorry, game over ;( The word was: " << words[indexWord] << endl;

		char choice;
		do {
			cout << "One more word? [Y/N]" << endl;
			cin >> choice;
		} while(!(tolower(choice) == 'y' || tolower(choice) == 'n'));
		
		if(tolower(choice) == 'y') {
			continue;
		} else if(tolower(choice) == 'n') {
			return;
		}
	}
}
int main() {
	cout << "Welcome to new Ubisoft game!" << endl
		 << "How do you prefer to play this game?" << endl;
	do {
		 cout << "Player Vs Computer[p] OR Computer Vs Computer[c]" << endl <<
		 	 "Change max mistake[m]. Now is: " << maxMistakes << endl <<
		 	 "Exit[e]" << endl
		 << "Choose option: ";
		char option;
		cin >> option;
		if(tolower(option) == 'p')
			play(false);
		else if(tolower(option) == 'c')
			play(true);
		else if(tolower(option) == 'm') {
			cout << "Set max mistakes: ";
			cin >> maxMistakes;
		}
		else if(tolower(option) == 'e') {
			cout << "Bye, bye :)" << endl;
			break;
		}
	} while(true);
	return 0;
}
