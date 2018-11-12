#include <iostream>
#include <string>
#include <fstream>
#include "array-list/ArrayList.h"

#define DEFAULT_CAPACITY 15

using namespace std;

// copy file contents to list obj.
template<class T>
void fileToList(const string &fileName, ArrayList<T> &list);

// print items in list
template<class T>
void printList(const ArrayList<T> &list);

int main()
{
	ArrayList<int> list;

	printList(list);
	fileToList("data.txt", list);
	printList(list);
	

	
	
	return 0;
}

template<class T>
void fileToList(const string &fileName, ArrayList<T> &list)
{
	fstream inFile;
	inFile.open(fileName);

	T tmp;
	int insertionCount = 0;
	while(inFile >> tmp)
	{
		if(!list.insert(list.getLength()+1, tmp))
		{
			cout << "fileToList: Max capacity reached at " << insertionCount << " insertion(s)." << endl;
			break;
		}

		insertionCount++;
	}

	inFile.close();
}

template<class T>
void printList(const ArrayList<T> &list)
{
	if(list.getLength() == 0)
	{
		cout << "List is empty." << endl;
		return;
	}

	int i = 0;
	for(; i < list.getLength()-1; i++)
		cout << list.getEntry(i+1) << ", ";

	cout << list.getEntry(i+1) << endl;
}
