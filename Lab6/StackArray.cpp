
#include "StackArray.h"

template <typename DataType>
StackArray<DataType>::StackArray(int maxNumber)
{
	maxSize = maxNumber;
	top = -1;
	dataItems = new DataType[MAX_STACK_SIZE];
	
}

template <typename DataType>
StackArray<DataType>::StackArray(const StackArray& other)
{
	maxSize = other.maxSize;
	top = other.top;
	dataItems = other.dataItems;
}

template <typename DataType>
StackArray<DataType>& StackArray<DataType>::operator=(const StackArray& other)
{
	maxSize = other.maxSize;
	top = other.top;
	dataItems = other.dataItems;
}

template <typename DataType>
StackArray<DataType>::~StackArray()
{
	delete [] dataItems; 
}

template <typename DataType>
void StackArray<DataType>::push(const DataType& newDataItem) throw (logic_error)
{
	if (top < 0)
	{
		top++;
		dataItems[top] = newDataItem;
	}
	else
	{
		dataItems[top] = newDataItem;
		top++;
	}
}

template <typename DataType>
DataType StackArray<DataType>::pop() throw (logic_error)
{
	dataItems[top] = NULL;
	top = top - 1; 
	return dataItems[top]; 
}

template <typename DataType>
void StackArray<DataType>::clear()
{
	for (int i = 0; i < top; i++)
	{
		dataItems[top] = NULL;
	}
	top = -1; 
	
}

template <typename DataType>
bool StackArray<DataType>::isEmpty() const
{
	if (top == -1)
		return true;
	else
		return false;
}

template <typename DataType>
bool StackArray<DataType>::isFull() const
{
	if (top >= MAX_STACK_SIZE)
		return true;
	else
		return false;
}

template <typename DataType>
void StackArray<DataType>::showStructure() const 

// Array implementation. Outputs the data items in a stack. If the
// stack is empty, outputs "Empty stack". This operation is intended
// for testing and debugging purposes only.

{
    if( isEmpty() ) {
	cout << "Empty stack." << endl;
    }
    else {
	int j;
	cout << "Top = " << top << endl;
	for ( j = 0 ; j < maxSize ; j++ )
	    cout << j << "\t";
	cout << endl;
	for ( j = 0 ; j <= top  ; j++ )
	{
	    if( j == top )
	    {
	        cout << '[' << dataItems[j] << ']'<< "\t"; // Identify top
	    }
	    else
	    {
		cout << dataItems[j] << "\t";
	    }
	}
	cout << endl;
    }
    cout << endl;
}