//--------------------------------------------------------------------
//  2022110879 Á¤Ã¤È²
// 
//  Laboratory 5                                        stackarr.cpp
//
//  SOLUTION: Array implementation of the Stack ADT
//
//--------------------------------------------------------------------
#include "stacklnk.h"

//--------------------------------------------------------------------

template <class DT>
StackNode<DT>::StackNode(const DT& nodeData, StackNode* nextPtr)
{
    dataItem = nodeData;
    next = nextPtr;
}


//--------------------------------------------------------------------

template <class DT>
Stack<DT>::Stack(int ignored)
{
    top = NULL;
}

//--------------------------------------------------------------------

template <class DT>
Stack<DT>:: ~Stack()
{
    clear();
}

//--------------------------------------------------------------------

template <class DT>
void Stack<DT>::push(const DT& newDataItem)
{
    StackNode<DT>* location;
    location = new StackNode<DT>(newDataItem, top);
    top = location;
}

//--------------------------------------------------------------------

template <class DT>
DT Stack<DT>::pop()
{
    StackNode<DT>* tempPtr;
    DT item;
    item = top->dataItem;
    tempPtr = top;
    top = top->next;
    delete tempPtr;
    return item;
}

//--------------------------------------------------------------------

template <class DT>
void Stack<DT>::clear()
{
    StackNode<DT>* tempPtr;
    while (top != NULL) {
        tempPtr = top;
        top = top->next;
        delete tempPtr;
    }
}

//--------------------------------------------------------------------

template <class DT>
bool Stack<DT>::isEmpty() const
{
    return (top == NULL);
}

//--------------------------------------------------------------------

template <class DT>
bool Stack<DT>::isFull() const
{
    StackNode<DT>* location;
    location = new (nothrow) StackNode<DT>(0, NULL);
    if (location == NULL)
        return true;
    else {
        delete location;
        return false;
    }
}

//--------------------------------------------------------------------

template < class DT >
void Stack<DT>::showStructure() const

// Linked list implementation. Outputs the data items in a stack.
// If the stack is empty, outputs "Empty stack". This operation is
// intended for testing and debugging purposes only.

{
    StackNode<DT>* p;   // Iterates through the stack

    if (top == 0)
        cout << "Empty stack" << endl;
    else
    {
        cout << "top ";
        for (p = top; p != nullptr; p = p->next)
            cout << p->dataItem << " ";
        cout << "bottom" << endl;
    }
}