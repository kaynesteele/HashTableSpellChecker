#include "SpellChecker.h";
#include <string>
#include <algorithm>
#include "HashTable.h"

void SpellChecker::swapAdjacent(HashTable* h,string word)
{
	string temp = word;
	bool found = false;

	for (int i = 1; i < word.length(); i++) // every element of the word will have their neighbors swapped
	{
		swap(word[i], word[i - 1]); // swaps word index i with the one before it.
        h->keySearch(word); // search for the new word
		word = temp;
	}
}

void SpellChecker::insertChar(HashTable* h, string word)
{
	string  temp = word;
	int counter = 0;
	while (counter < word.length()) // access every element of word
	{
		for (int i = 97; i < 123; i++) // tries adding every letter in alphabet
			{
				word.insert(counter,1,char(i)); // inserts letter in index of counter
				h->keySearch(word);
				word = temp; //restore word to normal
			}
		counter++;
	}
}

void SpellChecker::deleteChar(HashTable* h, string word)
{
	string temp = word;

	for (int i = 0; i < word.length(); i++)
	{
		word.erase(i,1); // erase letter at index of i
		h->keySearch(word);
		word = temp;
	}
}

void SpellChecker::replaceChar(HashTable* h, string word)
{
	string temp = word;
	int counter = 0;

	while (counter < word.length())
	{
		for (int i = 97; i < 123; i++)
		{
			word.erase(counter, 1); //erases char at index counter;
			word.insert(counter, 1, char(i)); //inserts char of i at index counter
			h->keySearch(word);
			word = temp;
		}
		counter++;
	}
}
