
#include "Heap.h"
#include<iostream>

#include<stdexcept>
using namespace std;

template < typename DataType, typename KeyType, typename Comparator >
Heap<DataType,KeyType,Comparator>::Heap ( int maxNumber = DEFAULT_MAX_HEAP_SIZE )
{
	maxSize = maxNumber; 
	size = 0; 
	dataItems = new DataType[maxSize];
}

template < typename DataType, typename KeyType, typename Comparator >
Heap<DataType,KeyType,Comparator>::Heap ( const Heap& other )
{
	*this = other; 
}

template < typename DataType, typename KeyType, typename Comparator >
Heap<DataType,KeyType,Comparator>& Heap<DataType,KeyType,Comparator>::operator= ( const Heap& other )
{
	if (this == other)
		return *this;
	else if (isEmpty()==false)
	{
		size = other.size; 
		maxSize = other.maxSize; 
		for (int i = 0; i < size; i++)
			dataItems[i] = other.dataItems[i]; 
		return *this; 
	}
}

template < typename DataType, typename KeyType, typename Comparator >
Heap<DataType,KeyType,Comparator>::~Heap ()
{
	clear(); 
	delete dataItems; 
}

template < typename DataType, typename KeyType, typename Comparator >
void Heap<DataType, KeyType, Comparator>::insert(const DataType &newDataItem)
throw (logic_error)
{
	if (isFull() == false)
	{
		int indx = size;
		Comparator compare; 
		dataItems[size] = newDataItem;
		while (compare(dataItems[indx].getPriority(),
			dataItems[(indx - 1) / 2].getPriority()))
		{
			DataType d = dataItems[(indx - 1) / 2];
			dataItems[indx] = dataItems[(indx - 1) / 2];
			dataItems[(indx - 1) / 2] = d;
		}
		size++;

	}
}

template < typename DataType, typename KeyType, typename Comparator >
DataType Heap<DataType,KeyType,Comparator>::remove () throw ( logic_error )
{
	size--; 
	DataType rData = dataItems[0]; 
	dataItems[0] = dataItems[size];
	int i = 0; 
	while (i < size)
	{
		Comparator C;
		if ((i * 2) + 2 <= size)
		{
			if (C(dataItems[i].getPriority(), dataItems[(i * 2) + 1].getPriority()
				&& C(dataItems[i].getPriority(),
				dataItems[(i * 2) + 2].getPriority())))
			{
				return rData;
			}
			else if (C(dataItems[(i * 2) + 2].getPriority(),
				dataItems[(i * 2) + 1].getPriority()))
			{
				DataType t;
				t = dataItems[i];
				dataItems[i] = dataItems[(i * 2) + 2];
				dataItems[(i * 2) + 2] = t;
				i = (i * 2) + 2;
			}
			else
			{
				DataType t;
				t = dataItems[i];
				dataItems[i] = dataItems[i + 1];
				dataItems[(i * 2) + 1] = t;
				i = (i * 2) + 1;
			}
		}
		else if ((i * 2) + 1 < +size)
		{
			if (C(dataItems[(i * 2) + 1].getPriority(),
				dataItems[i].getPriority()))
			{
				DataType t;
				t = dataItems[i];
				dataItems[i] = dataItems[(i * 2) + 1];
				dataItems[(i * 2) + 1] = t;
				i = (i * 2) + 1;
			}
			else
				return rData;
		}
		return rData;
	}
}

template < typename DataType, typename KeyType, typename Comparator >
void Heap<DataType,KeyType,Comparator>::clear ()
{
	size = 0;
}

template < typename DataType, typename KeyType, typename Comparator >
bool Heap<DataType,KeyType,Comparator>::isEmpty () const
{
	return (size==0);
}

template < typename DataType, typename KeyType, typename Comparator >
bool Heap<DataType,KeyType,Comparator>::isFull () const
{
	return (size == maxSize);
}

template < typename DataType, typename KeyType, typename Comparator >
void Heap<DataType, KeyType, Comparator>::writeLevels() const
{
	int lvlC = 1;
	int prntC = 0; 
	for (int i = 0; i < size; i++,prntC++)
	{
		if (prntC == lvlC)
		{
			prntC = 0;
			lvlC *= 2;
		}
		cout << dataItems[i].getPriority();
	}
}

#include "show11.cpp"