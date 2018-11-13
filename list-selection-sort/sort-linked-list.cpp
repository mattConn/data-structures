#include <iostream>
#include <string>
#include <fstream>
#include "linked-list/LinkedList.h"

using namespace std;

// copy file contents to list obj.
template<class T>
void fileToList(const string &fileName, LinkedList<T> &list, const bool &verbose = false);

// print items in list
template<class T>
void printList(const LinkedList<T> &list);

// sort list with selection sort
template<class T>
void sort(LinkedList<T> &list);

int main()
{
	LinkedList<int> list;

	// status strings for printing
	string beforeMsg, afterMsg;
	beforeMsg = "Before sort:";
	afterMsg = "After sort:";

	// copy file to list and print
	fileToList("data.txt", list, true);
	cout << beforeMsg << "\n" << string(beforeMsg.length(), '=') << endl;
	printList(list);

	// sort list and print
	sort(list);
	cout << afterMsg << "\n" << string(afterMsg.length(), '=') << endl;
	printList(list);
	

	
	
	return 0;
}

template<class T>
void fileToList(const string &fileName, LinkedList<T> &list, const bool &verbose)
{
	fstream inFile;
	inFile.open(fileName);

	T smallest;
	int insertionCount = 0;
	while(inFile >> smallest)
	{
		if(!list.insert(list.getLength()+1, smallest))
		{
			if(verbose) // check verbose flag
				cout << "fileToList: Max capacity reached at " << insertionCount << " insertion(s)." << endl;
			break;
		}

		insertionCount++;
	}

	inFile.close();
}

template<class T>
void printList(const LinkedList<T> &list)
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

template<class T>
void sort(LinkedList<T> &list)
{

	// preconditions for beginning sort
	if(list.getLength() == 0 || list.getLength() == 1)
	{
		cout << "List cannot be sorted." << endl;
		cout << "List length: " << list.getLength() << endl;
		return;
	}

	T smallest = list.getEntry(1);
	int position = 1;

	// begin sort
	for(int i = 1; i < list.getLength()+1; i++)
	{
		smallest = list.getEntry(i);

		for(int j = i+1; j < list.getLength()+1; j++)
		{
			if(list.getEntry(j) < smallest)
			{
				smallest = list.getEntry(j);
				position = j; // position smallest was found at
			}
		}

		//swap front with smallest if smallest was found
		if(position > 0)
		{
			list.replace(position, list.getEntry(i)); // replace smallest with front item
			list.replace(i, smallest); // replace front item with smallest
		}
		else
			return;

		// reset position
		position = -1;
	}
}
