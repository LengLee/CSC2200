
#include "ListLinked.h"

// ListNode member functions

template <typename DataType>
List<DataType>::ListNode::ListNode(const DataType& nodeData, ListNode* nextPtr)
{
	this->dataItem = nodeData;
	this->next = nextPtr;
}

// List member functions

template <typename DataType>
List<DataType>::List()
{
	head = NULL;
	cursor = NULL;
}

template <typename DataType>
List<DataType>::List(const List& other)
{
	ListNode *t = other->head;
	this->head = other->head;
	do
	{
		insert(t->dataItem);
		t = t->next;
	}(while this != other); 
	cursor = head; 
}

template <typename DataType>
List<DataType>& List<DataType>::operator=(const List& other)
{
	ListNode *t = other->head;
	this->head = other->head;
	do
	{
		insert(t->dataItem);
		t = t->next;
	}(while this != other);
	cursor = head;
	return this; 
}

template <typename DataType>
List<DataType>::~List()
{
	clear(); 
}

template <typename DataType>
void List<DataType>::insert(const DataType& newDataItem) throw (logic_error)

{
	//list empty
	if (head == nullptr)
		head = cursor = new ListNode(newDataItem, nullptr);
	//list not empty
	else
	{
		cursor->next = new ListNode(newDataItem, cursor->next );
		cursor = cursor->next; 
	}
	
	
}

template <typename DataType>
void List<DataType>::remove() throw (logic_error)
{

	if (!isEmpty())
	{
		ListNode *t;
		t = cursor->next;
		gotoPrior();
		if (cursor->next == t)
		{
			delete cursor;
			head = t;
		}

		else
		{
			delete cursor->next; 
		}
		cursor->next = t; 
		cursor = t; 
		if (cursor == NULL)
			gotoBeginning(); 
	}
}


template <typename DataType>
void List<DataType>::replace(const DataType& newDataItem) throw (logic_error)
{
	cursor->dataItem = newDataItem; 
}

template <typename DataType>
void List<DataType>::clear()
{
	
	while (cursor->next != nullptr)
	{
		head = cursor->next;
		delete cursor;
		cursor = head;
	}
	delete cursor;
	head = cursor = NULL; 
}

template <typename DataType>
bool List<DataType>::isEmpty() const
{
	if (head == NULL)
		return true; 
	return false;
}

template <typename DataType>
bool List<DataType>::isFull() const
{
	return false;
}

template <typename DataType>
void List<DataType>::gotoBeginning() throw (logic_error)
{
	cursor = head; 
}

template <typename DataType>
void List<DataType>::gotoEnd() throw (logic_error)
{
	ListNode *t;
	t = head; 
	for (; t->next != nullptr;)
		t = t->next;
	cursor = t; 
}

template <typename DataType>
bool List<DataType>::gotoNext() throw (logic_error)
{
	if (cursor->next != nullptr)
	{
		cursor = cursor->next;
		return true;
	}
	return false;
}

template <typename DataType>
bool List<DataType>::gotoPrior() throw (logic_error)
{
	ListNode *t; 
	t = cursor; 
	cursor = head;
	while (cursor->next != t)
		gotoNext(); 
	
	return true;
}

template <typename DataType>
DataType List<DataType>::getCursor() const throw (logic_error)
{

	return cursor->dataItem; 
}

template <typename DataType>
void List<DataType>::moveToBeginning () throw (logic_error)
{
	if (!isEmpty())
	{
		if (cursor != head)
		{
			ListNode* temp = cursor->next;
			ListNode* tem = cursor;
			gotoPrior();
			cursor->next = temp;
			tem->next = head;
			cursor = head = tem;
		}
	}
}

template <typename DataType>
void List<DataType>::insertBefore(const DataType& newDataItem) throw (logic_error)
{
	if (cursor != head)
	{
		gotoPrior();
		insert(newDataItem);
	}
	else
		head = cursor = new ListNode(newDataItem, head); 
}

#include "show5.cpp"

