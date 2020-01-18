#pragma once
#include <iostream>
#include <string>
using namespace std;

struct node
	{
		string word;
		string repairs;
		node *next;
	};

class HashTable
{
private:
	int tableLen = 0;

	node** HashTab;

public:
	 HashTable();
	 HashTable(int);
	 void addItem(string);
	 int Hash(string k);
	 void print();
	 int numItemsInIndex(int index);
	 void printItemsInIndex(int index);
	 void keySearch(string key);
};
