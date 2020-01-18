#pragma once
#include <iostream>
#include "HashTable.h"

using namespace std;

class SpellChecker
{
private:

public:
	void swapAdjacent(HashTable* h,string word);
	void insertChar(HashTable* h,string);
	void deleteChar(HashTable*, string);
	void replaceChar(HashTable*, string);
};
