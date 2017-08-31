
#include "QueueArray.h"

template <typename DataType>
QueueArray<DataType>::QueueArray(int maxNumber)
{
	maxSize = maxNumber;
	front = back = -1; 
	dataItems = new DataType[MAX_QUEUE_SIZE]; 
}

template <typename DataType>
QueueArray<DataType>::QueueArray(const QueueArray& other)
{
	maxSize = other.maxSize; 
	front = other.front;
	back = other.back; 
	dataItems = other.dataItems;
}

template <typename DataType>
QueueArray<DataType>& QueueArray<DataType>::operator=(const QueueArray& other)
{
	maxSize = other.maxSize;
	front = other.front;
	back = other.back;
	dataItems = other.dataItems
}

template <typename DataType>
QueueArray<DataType>::~QueueArray()
{
	delete[] dataItems; 
}


template <typename DataType>
void QueueArray<DataType>::enqueue(const DataType& newDataItem) throw (logic_error)
{
	if (front % MAX_QUEUE_SIZE == 0)
	{
		front = 0;
		dataItems[front] = newDataItem;
		front++;
	}
	else
	{
		front++;
		dataItems[front] = newDataItem;
	}
}

template <typename DataType>
DataType QueueArray<DataType>::dequeue() throw (logic_error)
{
	DataType temp;
	if (back % MAX_QUEUE_SIZE == 0)
	{
		back = 0;
		temp = dataItems[back]; 
		dataItems[back] = NULL;
		back++;
	}
	else
	{
		back++;
		temp = dataItems[back];
		dataItems[back] = NULL; 
	}
	return temp;
}

template <typename DataType>
void QueueArray<DataType>::clear()
{
	for (int i = 0; i < maxSize; i++)
		dataItems[i] = NULL;
	front = back = -1;
}

template <typename DataType>
bool QueueArray<DataType>::isEmpty() const
{
	if (front == -1)
		return true;
	
}

template <typename DataType>
bool QueueArray<DataType>::isFull() const
{
	if (back == front )
		return false;
	
}

template <typename DataType>
void QueueArray<DataType>::putFront(const DataType& newDataItem) throw (logic_error)
{
	if (front % MAX_QUEUE_SIZE == 0)
	{
		front = 0;
		dataItems[front] = newDataItem;
	}
	else
	{
		front++;
		dataItems[front] = newDataItem;
	}
}

template <typename DataType>
DataType QueueArray<DataType>::getRear() throw (logic_error)
{
	return dataItems[back];
}

template <typename DataType>
int QueueArray<DataType>::getLength() const
{
	int iterator = 0;
	if (back > front)
	{
		for (int i = front; i < maxSize; i++)
			iterator++; 
		for (int i = back; i < maxSize; i++)
			iterator++;
	}
	return iterator;
}

//--------------------------------------------------------------------

template <typename DataType>
void QueueArray<DataType>::showStructure() const 
// Array implementation. Outputs the data items in a queue. If the
// queue is empty, outputs "Empty queue". This operation is intended
// for testing and debugging purposes only.

{
    int j;   // Loop counter

    if ( front == -1 )
       cout << "Empty queue" << endl;
    else
    {
       cout << "Front = " << front << "  Back = " << back << endl;
       for ( j = 0 ; j < maxSize ; j++ )
           cout << j << "\t";
       cout << endl;
       if ( back >= front )
          for ( j = 0 ; j < maxSize ; j++ )
              if ( ( j >= front ) && ( j <= back ) )
                 cout << dataItems[j] << "\t";
              else
                 cout << " \t";
       else
          for ( j = 0 ; j < maxSize ; j++ )
              if ( ( j >= front ) || ( j <= back ) )
                 cout << dataItems[j] << "\t";
              else
                 cout << " \t";
       cout << endl;
    }
}