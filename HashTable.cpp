#include <iostream>
#include "HashTable.h"
#include <string>
#include <windows.h>
using namespace std;

HashTable::HashTable()
{
	for (int i = 0; i < tableLen; i++)
	{
		HashTab[i] = new node;
		HashTab[i]->word = "null";
		HashTab[i]->repairs = "null";
		HashTab[i]->next = NULL;
    }
}

HashTable::HashTable(int x)
{
    this->tableLen = x;
    this->HashTab = new node* [x];

    for (int i = 0; i < x; i++)
	{
		HashTab[i] = new node;
		HashTab[i]->word = "null";
		HashTab[i]->repairs = "null";
		HashTab[i]->next = NULL;
    }
}

int HashTable::Hash(string k)
{
	int index;
	int hash=0;

	for (int i = 0; i < k.length(); i++)
	{
		hash += (int)k[i];
	}

	index = hash % tableLen;

	return index;
}

void HashTable::addItem(string word)
{
	int index = Hash(word);

	if (HashTab[index]->word == "null")
	{
		HashTab[index]->word = word;
	}
	else
	{
		node* iter = HashTab[index];
		node* temp = new node;

		temp->word = word;
		temp->next = NULL;

		while (iter->next != NULL)
		{
			iter = iter->next;
		}
		iter->next = temp;
	}
}

int HashTable::numItemsInIndex(int index)
{
	int count = 0;

	if (HashTab[index]->word == "null")
	{
		return count;
	}
	else
	{
		count++;
		node* counter = HashTab[index];
		while (counter->next != NULL)
		{
			count++;
			counter = counter->next;
		}
	}
	return count;
}

void HashTable::print()
{
	int num;
	for (int i = 0; i < tableLen; i++)
	{
		num = numItemsInIndex(i);
		cout << "\n\n";
		cout << "index = " << i << endl;
		if (num > 1)
		{
			printItemsInIndex(i);
		}
		else
		{
			cout << HashTab[i]->word << endl;
		}

		cout << "Num Items: " << num << endl;


	}
}

void HashTable::printItemsInIndex(int index)
{
	node* iter = HashTab[index];

	if (iter->word == "null")
	{
		cout << "index = " << index << " is empty";
	}
	else
	{
		while (iter != NULL)
		{
			cout << iter->word << endl;
			iter = iter->next;
		}
	}
}

void HashTable::keySearch(string key)
{
	int index = Hash(key);

	string word;

	node* iter = HashTab[index];
	while (iter != NULL)
	{
	    //cout << iter->word << endl;
		if (iter->word.find(key) != string::npos)
		{
			word = iter->word;
			cout << iter->word << endl;
		}
		iter = iter->next;
	}
		//cout << "Found: "<< repairs <<endl;
}
