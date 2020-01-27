#include <iostream>
#include <string.h>
#define MAX_BUFFER_SIZE (1000)

/*
Напишете програма, която въвежда от потребителя произволен текст с дължина до 1000 символа и го съхранява в масив от тип char с подходящ размер. Текстът може да съдържа произволни символи. След това програмата ви трябва да изведе на екрана, на отделни редове, всички думи, които се срещат в текста, като срещу всяка дума се посочи броят на нейните срещания. При извеждането, за всяка дума трябва да има точно един ред (т.е. една дума не трябва да се извежда по няколко пъти).



За целите на задачата считаме, че думите в текста са последователности от произволни непразни (non-whitespace) символи, които са отделени една от друга с един или повече празни символи. Например: 
Примерно изпълнение 1: 
Enter a text: One Two Three   Four    One Two One   Two One – 3 time(s) Two – 3 time(s) Three – 1 time(s) Fout – 1 time(s) 
	Примерно изпълнение 2: 
	Enter a text: 8u8  abc123+_+_     *     &yy&a__,bc  8u8 8u8 – 2 time(s) abc123+_+_ - 1 time(s) * - 1  time(s) &yy&a__,bc – 1 time(s) 
	Примерно изпълнение 3: 
	Enter a text: JustOneLongWord JustOneLongWord – 1 time(s) 
	 
	Примерно изпълнение 4: 
	Enter a text:  No words (empty string)
*/

void deleteDictionary(char** dictionary, size_t size) {
	for(int i = 0; i < size; ++i) {
		delete[] dictionary[i];
	}
	delete[] dictionary;
}

void fillWithZero(unsigned* arr, size_t capacity) {
	for(int i = 0; i < capacity; ++i) {
		arr[i] = 0;
	}
}

void printDictionary(char** dictionary, unsigned* countArray, size_t size) {
	for(int i = 0; i < size; ++i) {
		std::cout << dictionary[i] << " - " << countArray[i] << " time(s)" << std::endl;
	}
}

bool resize(char**& dictionary, unsigned*& countArray, size_t& capacity) {
	size_t newCapacity = capacity*2;
	char** newDictionary = new(std::nothrow) char*[newCapacity];
	if(!newDictionary) {
		return false;
	}
	unsigned* newCountArray = new (std::nothrow) unsigned[newCapacity];
	if(!newCountArray) {
		delete[] newDictionary;
		return false;
	}
	
	fillWithZero(newCountArray, newCapacity);

	
	for(int i = 0; i < capacity; ++i) {
		newDictionary[i] = dictionary[i];
		// we don't copy all the words, just redirect pointers in to the new
		// dictionary!!! Very inportant!!!
		newCountArray[i] = countArray[i];
	}
	
	capacity = newCapacity;

	delete[] dictionary;
	dictionary = newDictionary;
	
	delete[] countArray;
	countArray = newCountArray;

	return true;
}

int existInTheDictionary(char* word, char** dictionary, size_t size) {
	// interate the whole dictionary and compare every word with current word	
	for(int i = 0; i < size; ++i) {
		if(strcmp(dictionary[i], word) == 0) {
			return i;
		}
	}

	return -1;
}

bool addWordInDictionary(char* word, char**& dictionary, unsigned*& countArray, size_t& size, size_t& capacity) {
	if(size == capacity) { // resize if it needed
		if(!resize(dictionary, countArray, capacity)) {
			// if resize didn't succeed, terminate the fucntion and return
			// false
			return false;
		}
	}
	// on this point we have enough space in to both arrays to add the word
	dictionary[size] = new (std::nothrow) char[strlen(word) + 1];
	//allocate the memory
	if(!dictionary[size]) {
		return false;
	}
	strcpy(dictionary[size], word); // copy the cuurent word in to the end of dictionary
	countArray[size]++; // increment with 1 because exits at least once
	size++; // increment size with 1 because words increasing with one
	return true; // return true to report successfully added
}

void siftAndCountWords(char* str) {
	size_t size = 0;
	size_t capacity = 2;
	char** dictionary = new (std::nothrow) char*[capacity];
	// array for every word
	if(!dictionary) {
		return;
	}
	unsigned* countArray = new (std::nothrow) unsigned[capacity];
	// array for how many time we found a word
	if(!countArray) {
		delete[] dictionary;	
		return;
	}
	
	fillWithZero(countArray, capacity);

	char* singleWord = strtok(str, " ");
	while(singleWord) { // we can skip != nullptr
		int index = existInTheDictionary(singleWord, dictionary, size);
		// return -1 if current word didn't exist in out dictionary
		// otherwise return the index where the word is found
		if (index >= 0){
			countArray[index]++;
			// if exist in dictionary, just increment with 1 on the position in array
		} else {
			// if we don't found this word fo far, we add it in to the set
			if(!addWordInDictionary(singleWord, dictionary, countArray, size, capacity)) {
				// if adding didn't succeed, delete dictionary and countArray
				// and terminate the function
				deleteDictionary(dictionary, size);
				delete[] countArray;
				return;
			}
		}
		singleWord = strtok(nullptr, " ");
	}

	printDictionary(dictionary, countArray, size);

	deleteDictionary(dictionary, size);
	delete[] countArray;
}

int main() {

	char* dynamicInput;
	{
		char staticInput[MAX_BUFFER_SIZE];
		std::cin.getline(staticInput, MAX_BUFFER_SIZE);
		dynamicInput = new (std::nothrow) char[strlen(staticInput) + 1];

		if(!dynamicInput) { // same as dynamicInput == nullptr
			return -1;
		}
		strcpy(dynamicInput, staticInput);
	}

	siftAndCountWords(dynamicInput);

	delete[] dynamicInput;

	return 0;
}
