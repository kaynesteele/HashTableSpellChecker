#include <iostream>
#include "HashTable.h"
#include "SpellChecker.h"
#include <fstream>
#include <string>

int main()
{
	HashTable h(3134);
	SpellChecker sc;
	string word;
	ifstream inFile("words.txt");
	string input, lane, repairs;


	while (!inFile.eof())
	{
		getline(inFile, word);
            h.addItem(word);
        }

	inFile.close();

	h.print();
	while (input != "-1")
	{
		cout << "Input Word: ";
		bool foundWord = false;
		cin >> input;
		sc.insertChar(&h, input);
		sc.deleteChar(&h, input);
		sc.replaceChar(&h, input);
		sc.swapAdjacent(&h, input);
		h.keySearch(input);

	}

	cin.get();
	return 0;
}
