
#include "QueueLinked.h"

template <typename DataType>
QueueLinked<DataType>::QueueNode::QueueNode(const DataType& nodeData, QueueNode* nextPtr)
{
	dataItem = nodeData; 
	next = nextPtr; 
}

template <typename DataType>
QueueLinked<DataType>::QueueLinked(int maxNumber = Queue<DataType>::MAX_QUEUE_SIZE)
{
	front = back = NULL;
}

template <typename DataType>
QueueLinked<DataType>::QueueLinked(const QueueLinked& other)
{
	QueueNode* temp; 
	front = new QueueNode(other.front->dataItem, other.front->next); 
	temp = front; 
	return *this; 
}

template <typename DataType>
QueueLinked<DataType>& QueueLinked<DataType>::operator=(const QueueLinked& other)
{
	QueueNode *temp; 
	front = new QueueNode(other.front->dataItem, other.front->next);
	temp = front; 
	back = new QueueNode(other.back->dataItem, other.back->next); 
	return *this;
}

template <typename DataType>
QueueLinked<DataType>::~QueueLinked()
{
	clear(); 
}

template <typename DataType>
void QueueLinked<DataType>::enqueue(const DataType& newDataItem) throw (logic_error)
{
	if (front == NULL)
		front = new QueueNode(newDataItem, nullptr); 
	else if (back == NULL)
	{
		back = new QueueNode(newDataItem, nullptr);
		front->next = back;
	}
	else
	{
		QueueNode *t; 
		t = new QueueNode(newDataItem, nullptr);
		back->next = t; 
		back = t; 
	}
	
}

template <typename DataType>
DataType QueueLinked<DataType>::dequeue() throw (logic_error)
{
	DataType temp;
	QueueNode *t; 
	t = front;
	temp = front->dataItem;
	front = front->next;
	delete t;
	return temp;
}

template <typename DataType>
void QueueLinked<DataType>::clear()
{
	QueueNode *temp; 
	while (front->next != nullptr)
	{
		temp = front;
		front = front->next; 
		delete temp;
	}
	front = back = NULL; 
}

template <typename DataType>
bool QueueLinked<DataType>::isEmpty() const
{
	return (front==NULL);
}

template <typename DataType>
bool QueueLinked<DataType>::isFull() const
{
		return false;
}

template <typename DataType>
void QueueLinked<DataType>::putFront(const DataType& newDataItem) throw (logic_error)
{
	QueueNode *temp; 
	temp = new QueueNode(newDataItem, nullptr); 
	front = temp; 
}

template <typename DataType>
DataType QueueLinked<DataType>::getRear() throw (logic_error)
{
	DataType temp;
	temp = back->dataItem;

	QueueNode *t = front;
	QueueNode *t2; 
	while (t->next != back)
		t = t->next;
	t2 = t->next; 
	t->next = back; 
	back->dataItem = t2->dataItem; 
	delete t2;
	

	return temp;
}

template <typename DataType>
int QueueLinked<DataType>::getLength() const
{
	QueueNode *t; 
	t = front;
	int iterator = 0; 
	while (t != NULL)
	{
		t = t->next; 
		iterator++; 
	}
	return iterator; 
}

template <typename DataType>
void QueueLinked<DataType>::showStructure() const
{
    QueueNode *p;   // Iterates through the queue

    if ( isEmpty() )
	cout << "Empty queue" << endl;
    else
    {
	cout << "Front\t";
	for ( p = front ; p != 0 ; p = p->next )
	{
	    if( p == front ) 
	    {
		cout << '[' << p->dataItem << "] ";
	    }
	    else
	    {
		cout << p->dataItem << " ";
	    }
	}
	cout << "\trear" << endl;
    }
}