#include "listdbl.h"

template < class DT >
ListNode<DT>::ListNode(const DT& data, ListNode* priorPtr, ListNode* nextPtr)
{
    dataItem = data;
    prior = priorPtr;
    next = nextPtr;
}

// Constructor
template < class DT >
List<DT>::List(int ignored)
{
    head = nullptr;
    cursor = nullptr;
}

// Destructor
template < class DT >
List<DT>::~List()
{
    clear();
    delete head;
    delete cursor;
}


//------------ List manipulation operations ------------------

// Insert after cursor
template < class DT >
void List<DT>::insert(const DT& newDataItem)
{
    if (isEmpty()) {
        ListNode<DT>* newNode = new ListNode<DT>(newDataItem, NULL, NULL);
        head = newNode;
        cursor = newNode;
        newNode->next = head;
    }
    else if (cursor->next == head) {
        ListNode<DT>* newNode = new ListNode<DT>(newDataItem, cursor, head);
        cursor->next = newNode;
        cursor = cursor->next;
    }
    else {
        ListNode<DT>* newNode = new ListNode<DT>(newDataItem, cursor, cursor->next);
        cursor->next->prior = newNode;
        cursor->next = newNode;
        cursor = cursor->next;
    }
}

// Remove data item
template < class DT >
void List<DT>::remove()
{
    if (!isEmpty()) {
        ListNode<DT>* Node;
        Node = cursor;
        if (cursor->prior == NULL) {
            if (cursor->next == head) {
                head = nullptr;
                cursor = nullptr;
            }
            else {
                cursor->next->prior = NULL;
                gotoEnd();
                head = head->next;
                cursor->next = head;
                cursor = head;
            }
        }
        else {
            if (cursor->next == head) {
                cursor->prior->next = head;
            }
            else {
                cursor->next->prior = cursor->prior;
                cursor->prior->next = cursor->next;
            }
            cursor = cursor->next;
        }
        delete Node;
    }
}

// Replace data item
template < class DT >
void List<DT>::replace(const DT& newDataItem)
{
    if (isEmpty() != true) {
        cursor->dataItem = newDataItem;
    }
}

// Clear list
template < class DT >
void List<DT>::clear()
{
    while (head != NULL) {
        remove();
    }
}


//------------ List status operations ------------------

// List is empty
template < class DT >
bool List<DT>::isEmpty() const
{
    return(head == NULL);
}

// List is full
template < class DT >
bool List<DT>::isFull() const
{
    ListNode<DT>* location;
    location = new (nothrow) ListNode<DT>(0, NULL, NULL);
    if (location == NULL)
        return true;
    else {
        delete location;
        return false;
    }
}


//------------ List manipulation operations ------------------

// Go to beginning
template < class DT >
void List<DT>::gotoBeginning()
{
    cursor = head;
}

// Go to end
template < class DT >
void List<DT>::gotoEnd()
{
    while (gotoNext()) {
    }
}

// Go to next data item
template < class DT >
bool List<DT>::gotoNext()
{
    if (cursor->next == head)
        return false;
    else {
        cursor = cursor->next;
        return true;
    }
}

// Go to prior data item
template < class DT >
bool List<DT>::gotoPrior()
{
    if (cursor == NULL || cursor->prior == NULL)
        return false;
    else {
        cursor = cursor->prior;
        return true;
    }
}


template < class DT >
DT List<DT>::getCursor() const
{
    if (!isEmpty()) {
        return (cursor->dataItem);
    }
}


//-----------------------------------------------------------

template < class DT >
void List<DT>::showStructure() const
{
    ListNode<DT>* p;   // Iterates through the list

    if (isEmpty())
        cout << "Empty list" << endl;
    else
    {
        p = head;
        do
        {
            if (p == cursor)
                cout << "[" << p->dataItem << "] ";
            else
                cout << p->dataItem << " ";
            p = p->next;
        } while (p != head);
        cout << endl;
    }
}


//-----------------------------------------------------------
// In-lab2 operation
template <class DT>
void List<DT>::reverse()
{
    if (head->next != head) {
        ListNode<DT>* curPtr = head;
        ListNode<DT>* tempPtr = NULL;
        do {
            tempPtr = curPtr->prior;
            curPtr->prior = curPtr->next;
            curPtr->next = tempPtr;
            curPtr = curPtr->prior;
        } while (curPtr != head);
        head = tempPtr->prior;
        head->prior->next = head;
        head->prior = NULL;
    }
}

// In-lab3 operation
template <class DT >
int List<DT>::getLength() const
{
    int length = 0;
    ListNode<DT>* curPtr;
    curPtr = head;
    do {
        curPtr = curPtr->next;
        length++;
    } while (curPtr != head);
    return length;
}

template <class DT>
int List<DT>::getPosition() const
{
    int position = 0;
    ListNode<DT>* curPtr;
    curPtr = head;
    while (curPtr != cursor) {
        curPtr = curPtr->next;
        position++;
    }
    return position;
}