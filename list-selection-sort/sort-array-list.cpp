#include <iostream>
#include <string>
#include "array-list/ArrayList.h"

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
	cout << string(10,'=') << endl;
	
	list.insert(list.getLength()+1, 13);
	
	printList(list);
	cout << string(10,'=') << endl;

	list.insert(list.getLength()+1, 74);
	
	printList(list);
	cout << string(10,'=') << endl;

	
	
	return 0;
}

template<class T>
void fileToList(const string &fileName, ArrayList<T> &list)
{
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
