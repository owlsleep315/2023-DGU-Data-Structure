//2022110879 Á¤Ã¤È²
//--------------------------------------------------------------------
//
//  Laboratory 5                                        stackarr.cpp
//
//  SOLUTION: Array implementation of the Stack ADT
//
//--------------------------------------------------------------------
#include "stackarr.h"

//--------------------------------------------------------------------

template <class DT>
Stack<DT>::Stack(int maxNumber)
{
    top = -1;
    maxSize = maxNumber;
    dataItems = new DT[maxSize];
}

//--------------------------------------------------------------------

template <class DT>
Stack<DT>:: ~Stack()
{
    delete[] dataItems;
}

//--------------------------------------------------------------------

template <class DT>
void Stack<DT>::push(const DT& newDataItem)
{
    if (top == maxSize - 1)
        return;
    else {
        top++;
        dataItems[top] = newDataItem;
    }
}

//--------------------------------------------------------------------

template <class DT>
DT Stack<DT>::pop()
{
    if (top == -1) 
        return NULL;
    else {
        top--;
        return dataItems[top + 1];
    }
}

//--------------------------------------------------------------------

template <class DT>
void Stack<DT>::clear()
{
    top = -1;
}

//--------------------------------------------------------------------

template <class DT>
bool Stack<DT>::isEmpty() const
{
    return (top == -1);
}

//--------------------------------------------------------------------

template <class DT>
bool Stack<DT>::isFull() const
{
    return (top == maxSize - 1);
}

//--------------------------------------------------------------------

template < class DT >
void Stack<DT>::showStructure() const

// Array implementation. Outputs the data items in a stack. If the
// stack is empty, outputs "Empty stack". This operation is intended
// for testing and debugging purposes only.

{
    int j;   // Loop counter

    if (top == -1)
        cout << "Empty stack" << endl;
    else
    {
        cout << "top = " << top << endl;
        for (j = 0; j < maxSize; j++)
            cout << j << "\t";
        cout << endl;
        for (j = 0; j <= top; j++)
            cout << dataItems[j] << "\t";
        cout << endl;
    }
}