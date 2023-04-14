#include "queuelnk.h"

template <class DT>
QueueNode<DT>::QueueNode(const DT& nodeData, QueueNode* nextPtr)
{
    dataItem = nodeData;
    next = nextPtr;
}

template <class DT>
Queue<DT>::Queue(int ignored)
{
    front = NULL;
    rear - NULL;
}

template<class DT>
Queue<DT>::~Queue()
{
    clear();
}

template<class DT>
void Queue<DT>::enqueue(const DT& newDataItem)
{
    QueueNode<DT>* newNode;
    newNode = new QueueNode<DT>(newDataItem, NULL);
    if (rear == NULL)
        front = newNode;
    else
        rear->next = newNode;
    rear = newNode;
}

template<class DT>
DT Queue<DT>::dequeue()
{
    DT item;
    QueueNode<DT>* tempPtr; 
    tempPtr = front;
    item = front->dataItem;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    delete tempPtr;
    return item;
}

template <class DT>
void Queue<DT>::clear()
{
    QueueNode<DT>* tempPtr;
    while(front != NULL) {
        tempPtr = front;
        front = front->next;
        delete tempPtr;
    }
    rear = NULL;
}

template<class DT>
bool Queue<DT>::isEmpty() const
{
    return(front == NULL);
}

template<class DT>
bool Queue<DT>::isFull() const
{
    QueueNode<DT>* ptr;
    ptr = new (nothrow) QueueNode<DT>(0, NULL);
    if (ptr == NULL)
        return true;
    else {
        delete ptr;
        return false;
    }
}

template<class DT>
void Queue<DT>::showStructure() const
{
    QueueNode<DT>* p;   // Iterates through the queue

    if (isEmpty())
        cout << "Empty queue" << endl;
    else
    {
        cout << "front ";
        for (p = front; p != nullptr; p = p->next)
            cout << p->dataItem << " ";
        cout << "rear" << endl;
    }
}