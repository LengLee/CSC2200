
#include "ExpressionTree.h"

template <typename DataType>
ExprTree<DataType>::ExprTreeNode::ExprTreeNode ( char elem, ExprTreeNode *leftPtr, ExprTreeNode *rightPtr )
{
	dataItem = elem;
	left = leftPtr;
	right = rightPtr;
}

template <typename DataType>
ExprTree<DataType>::ExprTree ()
{
	root = NULL; 
}

template <typename DataType>
ExprTree<DataType>::ExprTree(const ExprTree& source)
{
	*this = source; 
}

template <typename DataType>
ExprTree<DataType>& ExprTree<DataType>::operator=(const ExprTree& source)
{
	if (this == &source)
		return *this;

	ExprTreeNode *troot = source.root;
	copyHelper(root, troot); 
	return *this; 
}


template <typename DataType>
void ExprTree<DataType>::copyHelper(ExprTreeNode *&dest,  ExprTreeNode *p)
{
	
	if (p != NULL)
	{
		dest = new ExprTreeNode(p->dataItem, 0, 0);
		copyHelper(dest->left, p->left);
		copyHelper(dest->right, p->right);
		
	}
	
}
template <typename DataType>
ExprTree<DataType>::~ExprTree ()
{
	clear(); 
}

template <typename DataType>
void ExprTree<DataType>::build ()
{
	buildHelper(root); 
}

template <>
void ExprTree<float>::buildHelper(ExprTreeNode*& p)
{
	char a; 
	cin >> a;
	p = new ExprTreeNode(a, NULL, NULL);
	if (a == '+' || a == '-' || a == '*' || a == '/')
	{
		buildHelper(p->left);
		buildHelper(p->right);
	}

}


template <>
void ExprTree<bool>::buildHelper(ExprTreeNode*& p)
{
}


template <typename DataType>
void ExprTree<DataType>::expression () const
{
	exprHelper(root); 
}

template <typename DataType>
void ExprTree<DataType>::exprHelper(ExprTreeNode* p) const
{
	if (isdigit(p->dataItem))
	{
		cout << p->dataItem;
		return;
	}
	
	exprHelper(p->left);
	cout << p->dataItem;
	exprHelper(p->right); 
}

template <typename DataType>
DataType ExprTree<DataType>::evaluate() const throw (logic_error)
{
	if (root == NULL)
		throw("Empty"); 
	return evalHelper(root);
}


template <>
float ExprTree<float>::evalHelper(ExprTreeNode* p) const
{
	switch (p->dataItem){
	case '+':
	{
				return (evalHelper(p->left) + evalHelper(p->right));
				break;
	}
	case '-':
	{
				return (evalHelper(p->left) - evalHelper(p->right));
				break;
	}
	case '*':
	{
				return (evalHelper(p->left) * evalHelper(p->right));
				break;
	}
	case '/':
	{
				return (evalHelper(p->left) / evalHelper(p->right));
				break;
	}
	
	
	default:
	{
			   return (p->dataItem - '0');
			   break; 
	}
	}

}

template <>
bool ExprTree<bool>::evalHelper(ExprTreeNode* p) const
{
	
	return true;
}

template <typename DataType>
void ExprTree<DataType>::clear ()
{
	clearHelper(root);
	root = NULL;
}

template <typename DataType>
void ExprTree<DataType>::clearHelper(ExprTreeNode *p)
{
	if (p != NULL)
	{
		clearHelper(p->left);
		clearHelper(p->right);
		delete p;
	}
}

template <typename DataType>
void ExprTree<DataType>::commute()
{
	commuteHelper(root);
}


template <typename DataType>
void ExprTree<DataType>::commuteHelper(ExprTreeNode* p)
{
	if (p == NULL)
		return;
	else if (!isdigit(p->dataItem))
	{
		ExprTreeNode *a;
		a = p->left; 
		p->left = p->right;
		p->right = a;
	}
	commuteHelper(p->left);
	commuteHelper(p->right); 
}

template <typename DataType>
bool ExprTree<DataType>::isEquivalent(const ExprTree& source) const
{
}

template <typename DataType>
bool ExprTree<DataType>::isEquivalentHelper(const ExprTreeNode* x,
	const ExprTreeNode* y) const
{}

template <typename DataType>
bool ExprTree<DataType>::isEmpty() const
{
	return false;
}

template <typename DataType>
void ExprTree<DataType>::showStructure() const

// Outputs an expression tree. The tree is output rotated counter-
// clockwise 90 degrees from its conventional orientation using a
// "reverse" inorder traversal. This operation is intended for testing
// and debugging purposes only.

{
	// No isEmpty function in this class. Add a private one if you wish.
	if (root == 0)
		cout << "Empty tree" << endl;
	else
	{
		cout << endl;
		showHelper(root, 1);
		cout << endl;
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename DataType>
void ExprTree<DataType>::showHelper(ExprTreeNode *p, int level) const

// Recursive helper for the showStructure() function. Outputs the
// subtree whose root node is pointed to by p. Parameter level is the
// level of this node within the expression tree.

{
	int j;   // Loop counter

	if (p != 0)
	{
		showHelper(p->right, level + 1);        // Output right subtree
		for (j = 0; j < level; j++)   // Tab over to level
			cout << "\t";
		cout << " " << p->dataItem;        // Output dataItem
		if ((p->left != 0) &&          // Output "connector"
			(p->right != 0))
			cout << "<";
		else if (p->right != 0)
			cout << "/";
		else if (p->left != 0)
			cout << "\\";
		cout << endl;
		showHelper(p->left, level + 1);         // Output left subtree
	}
}