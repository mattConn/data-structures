template <class T>
class sequence {
	T *seq; // sequence array
	int capacity; // items in seq
	int numUsed; // num. elements used

public:
	sequence(); // default constructor

	sequence(const int &seqSize); // allocate seqSize spaces for seq array

	~sequence(); // destructor

	// accessor methods 
	bool isFull(); // true if array is full
	bool isEmpty(); // true if array is full
	int getCapacity(); // return capacity of array
	int getNumUsed(); // return numUsed 
	T getByPos(const int &position); // get element by position (index-1)
	int getPos(const T &elem); // get position of elem

	// mutator methods
	void replaceByPos(const int &position, const T &newElem); // replace elem. at position
	void push(const T &newElem); // add new item to next available position

	// helper method
	void doubleCapacity();
};

// default constructor
template <class T>
sequence<T>::sequence()
{
	capacity = 10;
	seq = new T [capacity];
	numUsed = 0;
}

// overloaded constructor
template <class T>
sequence<T>::sequence(const int &seqSize) 
{
	capacity = seqSize;
	seq = new T[seqSize];
	numUsed = 0;
}

// destructor
template <class T>
sequence<T>::~sequence()
{
	delete [] seq;
}

// check if sequence is full
template <class T>
bool sequence<T>::isFull()
{
	if (capacity == numUsed)
		return true;
	else
		return false;
}

// check if sequence is empty
template <class T>
bool sequence<T>::isEmpty()
{
	if (numUsed == 0)
		return true;
	else
		return false;
}

// get capacity of sequence
template <class T>
int sequence<T>::getCapacity()
{
	return capacity;
}

// get number of positions used
template <class T>
int sequence<T>::getNumUsed()
{
	return numUsed;
}

// get element by given position
template <class T>
T sequence<T>::getByPos(const int &position)
{
	return seq[position - 1];
} 

// overwrite element at position with given value
template <class T>
void sequence<T>::replaceByPos(const int &position, const T &newElem)
{
	seq[position - 1] = newElem;
}

// double sequence capacity
template <class T>
void sequence<T>::doubleCapacity()
{
	capacity *= 2;
	T *tmp = new T [capacity];

	for(int i = 0; i < numUsed; i++)
		tmp[i] = seq[i];

	seq = tmp;
}

// add new element to back
template <class T>
void sequence<T>::push(const T &newElem)
{
	if(numUsed == capacity)
		doubleCapacity();

	seq[numUsed] = newElem;
	numUsed++;
}

// get position of given element
template <class T>
int sequence<T>::getPos(const T &elem)
{
	int pos = -1;
	for (int i = 0; i < capacity; i++)
	{
		if (seq[i] == elem)
		{
			pos = i + 1;
			break;
		}
	}

	return pos;
}
