#include "queuearr.h"

template < class DT >
Queue<DT>::Queue(int maxNumber)
{
    maxSize = maxNumber + 1;
    front = maxSize - 1;
    rear = maxSize - 1;
    dataItems = new DT[maxSize];
}

template < class DT >
Queue<DT>::~Queue()
{
    delete[] dataItems;
}

template < class DT >
void Queue<DT>::enqueue(const DT& newDataItem)
{
    if (!isFull()) {
        rear = (rear + 1) % maxSize;
        dataItems[rear] = newDataItem;
    }
}

template < class DT >
DT Queue<DT>::dequeue()
{
    if (!isEmpty()) {
        front = (front + 1) % maxSize;
        return dataItems[front];
    }
}

template < class DT >
void Queue<DT>::clear()
{
    front = maxSize - 1;
    rear = maxSize - 1;
}

template < class DT >
bool Queue<DT>::isEmpty() const
{
    return(rear == front);
}

template < class DT >
bool Queue<DT>::isFull() const
{
    return ((rear + 1) % maxSize == front);
}

template < class DT >
void Queue<DT>::showStructure() const
{
    int j;   // Loop counter

    if (isEmpty())
        cout << "Empty queue" << endl;
    else
    {
        cout << "front = " << front << "  rear = " << rear << endl;
        for (j = 0; j < maxSize; j++)
            cout << j << "\t";
        cout << endl;
        if (rear > front)
            for (j = 0; j < maxSize; j++)
                if ((j > front) && (j <= rear))
                    cout << dataItems[j] << "\t";
                else
                    cout << " \t";
        else
            for (j = 0; j < maxSize; j++)
                if ((j > front) || (j <= rear))
                    cout << dataItems[j] << "\t";
                else
                    cout << " \t";
        cout << endl;
    }

}

// In-lab operations
template < class DT >
void Queue<DT>::putFront(const DT& newDataItem) throw (logic_error)
{
    // In-lab 2
    if (!isFull()) {
        dataItems[front] = newDataItem;
        if (front == 0)
            front = maxSize - 1;
        else
            front = front - 1;
    }
}

template < class DT >
DT Queue<DT>::getRear() throw (logic_error)
{
    // In-lab 2
    if (!isEmpty()) {
        if (rear == 0)
            rear = maxSize - 1;
        else
            rear = rear - 1;
        return dataItems[rear + 1];
    }
}

template < class DT >
int Queue<DT>::getLength() const
{
    // In-lab 3
    if (front > rear)
        return(maxSize - front + rear);
    else
        return(rear - front);
}