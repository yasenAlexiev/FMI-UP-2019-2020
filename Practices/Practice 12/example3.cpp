#include <iostream>
#include <string.h>

int main() {
	const char* words[] = { "programirane", "alkoholik", "zadachi", "grupa", "lampa",
							"student", "uchitel", "izpit", "sesuq", "alkohol",
							"8 dekemvri", "nov laptop" };

	const size_t words_count = 12;

	const char* myFavoriteWord = "alkohol";

	for(int i = 0; i < words_count; ++i) {
		if(strcmp(words[i], myFavoriteWord) == 0) {
			char str[30];
			strcpy(str, "Yes, baby! ");
			strcat(str, words[i]);
			std::cout << str << std::endl;
		}

		if(strstr(words[i], myFavoriteWord) != nullptr) {
			std::cout << "\"" << myFavoriteWord << "\" is substring in \"" << words[i] << std::endl;
		}
	}

	return 0;
}
