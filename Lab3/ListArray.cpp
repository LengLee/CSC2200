
#include "ListArray.h"


template < typename DataType >
List<DataType>::List ( int maxNumber )
{
	maxSize = maxNumber;
	cursor = -1; 
	size = 0;
	dataItems = new DataType[maxSize];
}

template < typename DataType >
List<DataType>::List ( const List& source )
{
	maxSize = source.maxSize;
	cursor = source.cursor;
	size = source.size;
	dataItems = new DataType[maxSize];
	for (int i = 0; i < size; i++)
		dataItems[i] = source.dataItems[i];
}
    
template < typename DataType >
List<DataType>& List<DataType>::operator= ( const List& source )
{
	maxSize = source.maxSize;
	cursor = source.cursor;
	size = source.size;
	dataItems = new DataType[maxSize];
	for (int i = 0; i < size; i++)
		dataItems[i] = source.dataItems[i]; 
	return *this;
}

template < typename DataType >
List<DataType>::~List ()
{
	delete[] dataItems; 
}

template < typename DataType >
void List<DataType>::insert(const DataType& newDataItem)
throw (logic_error)
{
	if (size == MAX_LIST_SIZE)
	{
		throw logic_error("List full");
	}
	else
	{
		for (int i = size - 1; i > cursor; i--)
		{
			DataType inti = dataItems[i];
			dataItems[i] = dataItems[i + 1];
			dataItems[i + 1] = inti;
		}
		dataItems[cursor + 1] = newDataItem;
		size++;
		cursor++;
	}
}

template < typename DataType >
void List<DataType>::remove () throw ( logic_error )
{
	if (size == 0)
		throw logic_error("Empty");
	
	int i = cursor;
		while (i < size)
		{
			dataItems[i] = dataItems[i + 1];
			i++;
		}
		size--;
	
}

template < typename DataType >
void List<DataType>::replace ( const DataType& newDataItem )
	throw ( logic_error )
{
	if (size == 0)
		throw logic_error("Full Error");
	else
	{
		for (int i = cursor; i < 1; i++)
			dataItems[cursor] = newDataItem;
	}
}

template < typename DataType >
void List<DataType>::clear ()
{
	cursor = -1;
	size = 0; 
}

template < typename DataType >
bool List<DataType>::isEmpty () const
{
	if (size == 0)
		return true;
	return false;
}

template < typename DataType >
bool List<DataType>::isFull () const
{
	if (size == MAX_LIST_SIZE)
		return true;
	return false;
}

template < typename DataType >
void List<DataType>::gotoBeginning ()
        throw ( logic_error )
{

	if (size == 0)
		throw logic_error("Empty");
	else
		cursor = 0;
}

template < typename DataType >
void List<DataType>::gotoEnd ()
        throw ( logic_error )
{
	if (size == 0)
		throw logic_error("Empty");
	else
		cursor = size - 1;

}

template < typename DataType >
bool List<DataType>::gotoNext ()
        throw ( logic_error )
{
	if (size == 0)
		throw logic_error("Empty");
	else
	{
		cursor = cursor + 1;
		return true;
	}

	return false;
}

template < typename DataType >
bool List<DataType>::gotoPrior ()
        throw ( logic_error )
{
	if (size == 0)
		throw logic_error("Empty");
	else
	{
		if (cursor >= 1)
		{
			cursor--;
			return true;
		}
	}
	return false;
}

template < typename DataType >
DataType List<DataType>::getCursor () const
        throw ( logic_error )
{
	 
	return dataItems[cursor]; 
	
}

#include "show3.cpp"

template < typename DataType >
void List<DataType>::moveToNth ( int n )
        throw ( logic_error )
{
	if (size == 0)
		throw logic_error("List is empty");
	else
		cursor = n;
}

template < typename DataType >
bool List<DataType>::find(const DataType& searchDataItem)
throw (logic_error)
{
	if (size == 0)
		throw logic_error("List empty"); 
	for (int i = 0; i < size; i++)
	{
		if (dataItems[i] == searchDataItem)
			return true;
	}
	return false;
}