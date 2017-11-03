
#include "BSTree.h"


template <typename DataType, class KeyType>
BSTree<DataType, KeyType>::BSTreeNode::BSTreeNode(const DataType &nodeDataItem, BSTreeNode *leftPtr, BSTreeNode *rightPtr)
{
	dataItem = nodeDataItem;
	left = leftPtr;
	right = rightPtr;
}

template < typename DataType, class KeyType >
BSTree<DataType, KeyType>::BSTree()
{
	root = NULL;
}

template < typename DataType, class KeyType >
BSTree<DataType, KeyType>::BSTree(const BSTree<DataType, KeyType>& other)
{
	*this = other;
}

template < typename DataType, class KeyType >
BSTree<DataType, KeyType>& BSTree<DataType, KeyType>:: operator= (const BSTree<DataType, KeyType>& other)
{
	if (this == other)
		return *this;
	clear();
	copyHelper(root, other.root);
	return *this;
}
template<typename DataType, class KeyType>
void BSTree<DataType, KeyType>::copyTreeHelper(BSTreeNode *&p, BSTreeNode * other)
{
	if (other != NULL)
	{
		copyHelper(p->left, other->left);
		copyHelper(p->right, other->right);
		p = new BSTreeNode(other->dataItem, 0, 0);
	}
}

template < typename DataType, class KeyType >
BSTree<DataType, KeyType>::~BSTree()
{
	clear();
}

template<typename DataType, class KeyType>
void BSTree<DataType, KeyType>::insertHelper(BSTreeNode *& p, DataType &newDataItem)
{
	if (p == NULL)
		p = new BSTreeNode(newDataItem, NULL, NULL);
	else
	{
		if ((p->dataItem).getKey() == newDataItem.getKey())
			p->dataItem = newDataItem;
		else if (newDataItem.getKey() < p->dataItem.getKey())
			insertHelper(p->left, newDataItem);
		else if (newDataItem.getKey() > p->dataItem.getKey())
			insertHelper(p->right, newDataItem);
		else
			p->dataItem = newDataItem;
	}
}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::insert(const DataType& newDataItem)
{
	DataType temp = newDataItem;
	insertHelper(root, temp);
}

template < typename DataType, class KeyType >
bool BSTree<DataType, KeyType>::retrieve(const KeyType& searchKey, DataType& searchDataItem) const
{
	return  retrieveHelper(root, searchKey, searchDataItem);
}

template < typename DataType, typename KeyType >
bool BSTree<DataType, KeyType>::retrieveHelper(BSTreeNode *p, const KeyType& searchKey, DataType &searchDataItem) const
{
	bool result;
	if (p == 0)
	{

		result = false;
	}
	else if (searchKey < p->dataItem.getKey())
	{

		result = retrieveHelper(p->left, searchKey, searchDataItem);
	}
	else if (searchKey > p->dataItem.getKey())
	{

		result = retrieveHelper(p->right, searchKey, searchDataItem);
	}
	else
	{
		searchDataItem = p->dataItem;
		result = true;
	}

	return result;
}
template < typename DataType, class KeyType >
bool BSTree<DataType, KeyType>::remove(const KeyType& deleteKey)
{
	return removeHelper(root, deleteKey);

}
template < typename DataType, typename KeyType >
bool BSTree<DataType, KeyType>::removeHelper(BSTreeNode *&p, const KeyType& deleteKey)
{
	BSTreeNode *delPtr;
	int result;

	if (p == 0)
		result = false;
	else if (deleteKey < p->dataItem.getKey())
		result = removeHelper(p->left, deleteKey);
	else if (deleteKey > p->dataItem.getKey())
		result = removeHelper(p->right, deleteKey);
	else
	{
		delPtr = p;
		if (p->left == 0)
		{
			p = p->right;
			delete delPtr;
		}
		else if (p->right == 0)
		{
			p = p->left;
			delete delPtr;
		}
		else
		{

			BSTreeNode* temp = p->left;
			while (temp->right) {
				temp = temp->right;
			}

			p->dataItem = temp->dataItem;

			removeHelper(p->left, temp->dataItem.getKey());
		}
		result = true;
	}


	return result;
}
template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::writeKeys() const
{
	writeKeysHelper(root);
}
template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::writeKeysHelper(BSTreeNode *p) const
{
	if (p != 0)
	{
		writeKeysHelper(p->left);
		cout << p->dataItem.getKey() << " ";
		writeKeysHelper(p->right);
	}
}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::clear()
{
	clearHelper(root);
	root = NULL;
}
template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::clearHelper(BSTreeNode *&p)
{
	if (p != 0)
	{
		clearHelper(p->left);
		clearHelper(p->right);
		delete p;
	}

}

template < typename DataType, class KeyType >
bool BSTree<DataType, KeyType>::isEmpty() const
{
	return (root == NULL);
}

template < typename DataType, class KeyType >
int BSTree<DataType, KeyType>::getHeight() const
{
	return getHeightHelper(root, 0);
}

template < typename DataType, class KeyType >
int BSTree<DataType, KeyType>::getHeightHelper(BSTreeNode *p, int n) const
{
	static int m = 0;
	if (p == NULL)
	{
		if (n > m)
			m = n;
	}
	else
	{
		getHeightHelper(p->left, n + 1);
		getHeightHelper(p->right, n + 1);
	}
	return (m-1);
}

template < typename DataType, class KeyType >
int BSTree<DataType, KeyType>::getCount() const
{
	return getCountHelper(root);
}

template < typename DataType, class KeyType >
int BSTree<DataType, KeyType>::getCountHelper(BSTreeNode *p) const
{
	if (p == NULL)
		return 0;
	else
		return 1 + getCountHelper(p->left) + getCountHelper(p->right);
}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::writeLessThan(const KeyType& searchKey) const
{
	if (isEmpty())
		cout << "Empty ";
	else
		writeLTHelper(root, searchKey); 
}

template<typename DataType, class KeyType>
void BSTree<DataType, KeyType>::writeLTHelper(BSTreeNode* p, const KeyType &searchKey) const
{
	if (p != NULL)  {
		if (p->dataItem.getKey() >= searchKey)  {
			writeLTHelper(p->left, searchKey);
		}
		else  {
			writeKeysHelper(p->left);
			cout << p->dataItem.getKey() << endl;
			writeLTHelper(p->right, searchKey);
		}
	}
}

#include "show9.cpp"