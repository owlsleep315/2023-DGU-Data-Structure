// 2022110879 Á¤Ã¤È²
//--------------------------------------------------------------------
//
//                                                       listarr.cpp
//
//  SOLUTION: Array implementation of the List ADT
//
//--------------------------------------------------------------------

#include "listarr.h"

//--------------------------------------------------------------------

List::List(int maxNumber)

// Creates an empty list. Allocates enough memory for maxNumber
// data items (defaults to defMaxListSize).
{
	// pre-lab
	maxSize = maxNumber;
	size = 0;
	cursor = -1;
	dataItems = new char[maxSize];
}

//--------------------------------------------------------------------

List:: ~List()
// Frees the memory used by a list.

{
	// pre-lab
	delete[] dataItems;
}

//--------------------------------------------------------------------

void List::insert(const DataType& newDataItem)

// Inserts newDataItem after the cursor. If the list is empty, then
// newDataItem is inserted as the first (and only) data items in the
// list. In either case, moves the cursor to newDataItem.

{
	// pre-lab
	if (isFull())
		cout << "List is full" << endl;
	else {
		dataItems[size] = newDataItem;
		size++;
		cursor = size - 1;
	}
}

//--------------------------------------------------------------------

void List::remove()

// Removes the data items  marked by the cursor from a list. Moves the
// cursor to the next data item item in the list. Assumes that the
// first list data items "follows" the last list data item.
{
	// pre-lab
	if (isEmpty())
	{
		cout << "List is empty" << endl;
		return;
	}
	for (int index = cursor; index < size - 1; index++)
		dataItems[index] = dataItems[index + 1];
	size--;
	if (size == 0)
	{
		cursor = -1;
		cout << "List is empty" << endl;
	}
	else if (cursor == size)
		cursor = 0;
}

//--------------------------------------------------------------------

void List::replace(const DataType& newDataItem)

// Replaces the item marked by the cursor with newDataItem and
// leaves the cursor at newDataItem.
{
	// Requires that the list is not empty
	// pre-lab
	dataItems[cursor] = newDataItem;
}
//--------------------------------------------------------------------

void List::clear()
// Removes all the data items from a list.
{
	// pre-lab
	size = 0;
	cursor = -1;
	cout << "List is empty" << endl;
}

//--------------------------------------------------------------------

bool List::isEmpty() const
// Returns true if a list is empty. Otherwise, returns false.
{
	// pre-lab
	return (size == 0);
}

//--------------------------------------------------------------------

bool List::isFull() const
// Returns true if a list is full. Otherwise, returns false.
{
	// pre-lab
	return (size == maxSize);
}

//--------------------------------------------------------------------

void List::gotoBeginning()
// Moves the cursor to the beginning of the list.
{
	// pre-lab
	cursor = 0;
}

//--------------------------------------------------------------------

void List::gotoEnd()

// Moves the cursor to the end of the list.

{
	// pre-lab
	cursor = size - 1;
}

//--------------------------------------------------------------------

bool List::gotoNext()

// If the cursor is not at the end of a list, then moves the
// cursor to the next item in the list and returns true. Otherwise,
// returns false.
{
	// pre-lab
	if (cursor == size - 1)
		return false;
	else {
		cursor++;
		return true;
	}
}

//--------------------------------------------------------------------

bool List::gotoPrior()

// If the cursor is not at the beginning of a list, then moves the
// cursor to the preceeding item in the list and returns true.
// Otherwise, returns false.

{
	// pre-lab
	if (cursor == -1)
		return false;
	else {
		cursor--;
		return true;
	}
}

//--------------------------------------------------------------------

DataType List::getCursor() const
// Returns the item marked by the cursor.

{
	// pre-lab
	return dataItems[cursor];
}

//--------------------------------------------------------------------

void List::showStructure() const
// Outputs the data items in a list. If the list is empty, outputs
// "Empty list". This operation is intended for testing/debugging
// purposes only.

{
	// pre-lab
	cout << "size = " << size << "\t" << "cursor = " << cursor << endl;
	for (int i = 0; i < maxSize; i++)
	{
		cout << "[ " << i << " ]\t";
	}
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "  " << dataItems[i] << "  \t";
	}
	cout << endl;
}

//--------------------------------------------------------------------

//in-lab
void List::moveToNth(int n)
{
	// in-lab 2
	int a = dataItems[cursor];
	remove();
	for (int index = size; index >= n; index--)
		dataItems[index + 1] = dataItems[index];
	size++;
	cursor = n;
	dataItems[cursor] = a;
}

bool List::find(const DataType& searchDataItem)
{
	// in-lab 3
	for (cursor; cursor < size; cursor++)
	{
		if (dataItems[cursor] == searchDataItem)
			return true;
	}
	cursor--;
	return false;
}