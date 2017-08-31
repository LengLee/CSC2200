
#include "StackLinked.h"

template <typename DataType>
StackLinked<DataType>::StackLinked (int maxNumber)
{
	top = NULL; 
}

template <typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other)
{
	 
	top = other.top; 
	while (top != NULL)
	{
		StackNode node = new StackNode(top->next->dataItem; top->next); 
		top = top->next; 
	}

}

template <typename DataType>
StackLinked<DataType>& StackLinked<DataType>::operator=(const StackLinked& other)
{
	while (top != NULL)
	{
		temp = top; 
		top = ->next; 
		delete temp; 
	}
	delete top; 
	while (top != NULL)
	{
		StackNode node = new StackNode(top->next->dataItem; top->next);
		top = top->next;
	}
	return *this; 
}

template <typename DataType>
StackLinked<DataType>::~StackLinked()
{
	clear();
}

template <typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw (logic_error)
{
	if (top < 0)
	{
		top++;
		temp = temp->next; 
	}
	else
	{
		StackNode* node = new StackNode(top->dataItem; top->next); 
		top->dataItem = newDataItem; 
		top->next = node; 
	}
}

template <typename DataType>
DataType StackLinked<DataType>::pop() throw (logic_error)
{
	DataType t; 
	t = top->dataItem; 
	StackNode* temp = top; 
	delete temp;
	return t;
}

template <typename DataType>
void StackLinked<DataType>::clear()
{
	StackNode* t;
	for (top != NULL)
	{
		t = top;
		top = top->next;
		delete t; 
	}
	
}

template <typename DataType>
bool StackLinked<DataType>::isEmpty() const
{
    return (top==NULL);
}

template <typename DataType>
bool StackLinked<DataType>::isFull() const
{
	return false;
}

template <typename DataType>
void StackLinked<DataType>::showStructure() const
{
    if( isEmpty() )
    {
	cout << "Empty stack" << endl;
    }
    else
    {
        cout << "Top\t";
	for (StackNode* temp = top; temp != 0; temp = temp->next) {
	    if( temp == top ) {
		cout << "[" << temp->dataItem << "]\t";
	    }
	    else {
		cout << temp->dataItem << "\t";
	    }
	}
        cout << "Bottom" << endl;
    }

}