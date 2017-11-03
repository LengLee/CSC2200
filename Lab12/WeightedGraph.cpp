//--------------------------------------------------------------------
//
//  Laboratory 12                                    WeightedGraph.cpp
//
//--------------------------------------------------------------------

#ifndef WEIGHTEDGRAPH_CPP
#define WEIGHTEDGRAPH_CPP

using namespace std;

#include "WeightedGraph.h"
#include "config.h"


//--------------------------------------------------------------------

WeightedGraph::WeightedGraph(int maxNumber)

// Creates an empty graph. Allocates enough memory for maxNumber
// vertices (defaults to defMaxGraphSize).
{ 
	maxSize = maxNumber; 
	size = 0;
	vertexList = new Vertex[maxNumber]; 
	adjMatrix = new int[maxNumber*maxNumber];
	for (int i = 0; i < maxSize; i++)
	{
		for (int j = 0; j < maxSize; j++)
			setEdge(i, j, INFINITE_EDGE_WT);
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

WeightedGraph::WeightedGraph(const WeightedGraph& other)

// Creates an empty graph. Allocates enough memory for maxNumber
// vertices (defaults to defMaxGraphSize).
{
	*this = other;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

WeightedGraph& WeightedGraph:: operator= ( const WeightedGraph& other )

// Copies from another WeightedGraph. 
{

	if (this == &other)
		return *this; 
	if (!isEmpty())
	{
		delete[] vertexList;
		delete[] adjMatrix; 
	}
	maxSize = other.maxSize; 
	vertexList = new Vertex[maxSize]; 
	adjMatrix = new int [maxSize*maxSize];
	for (int i = 0; i < maxSize; i++)
	{
		vertexList[i] = other.vertexList[i]; 
		for (int j = 0; j < size; j++)
		{
			adjMatrix[i*maxSize + j] = other.adjMatrix[i*maxSize + j];
		}
	}
	return *this;
}

//--------------------------------------------------------------------

WeightedGraph:: ~WeightedGraph ()

// Frees the memory used by a graph.
{
	clear(); 
}

//--------------------------------------------------------------------

void WeightedGraph:: insertVertex ( const Vertex& newVertex ) throw ( logic_error )

// Inserts newVertex into a graph. If a vertex with the same label
// as newVertex already exists in the graph, then updates that
// vertex's data with newVertex's data.
{
	for (int i = 0; i < size; i++)
	{
		if (vertexList[i].getLabel() == newVertex.getLabel())
		{
			vertexList[i] = newVertex;
			for (int j = 0; j < size; j++)
			{
				setEdge(i, j, INFINITE_EDGE_WT);
			}
			return;
		}
	}
	if (isFull())
	{
		throw logic_error("Full");
	}
	vertexList[size] = newVertex; 
	for (int i = 0; i < size; i++)
		setEdge(size, i, INFINITE_EDGE_WT); 
	size++; 
	

}

//--------------------------------------------------------------------

void WeightedGraph:: insertEdge ( const string& v1, const string& v2, int wt )
    throw ( logic_error )

// Insert an edge with the specified weight between vertices
// v1 and v2.
{
	int idx1 = getIndex(v1); 
	int idx2 = getIndex(v2); 

	if (idx1 == -1 || idx2 == -1)
		throw logic_error("Not found"); 
	setEdge(idx1,idx2, wt); 
}

//--------------------------------------------------------------------

bool WeightedGraph:: retrieveVertex ( const string& v, Vertex &vData ) const

// Searches a graph for vertex v. If the vertex is found, then copies
// the vertex data to vData and returns 1. Otherwise, returns 0 with
// vData undefined.
{
	for (int i = 0; i < size; i++)
	{
		if (vertexList[i].getLabel() == v)
			vData = vertexList[i];
		return true;
	}
	return false;
}

//--------------------------------------------------------------------

bool WeightedGraph:: getEdgeWeight ( const string& v1, const string& v2, int &wt ) const
    throw ( logic_error )

// If there is an edge connecting vertices v1 and v2, then returns 1
// with wt returning the weight of the edge. Otherwise, returns 0
// with wt undefined.
{
	int idx1 = getIndex(v1);
	int idx2 = getIndex(v2); 
	
	if (getEdge(idx1, idx2) != INFINITE_EDGE_WT)
	{
		wt = getEdge(idx1, idx2); 
		return true;
	}
	else
		return false;
}

//--------------------------------------------------------------------

void WeightedGraph:: removeVertex ( const string& v ) throw ( logic_error )

// Removes vertex v from a graph.
{
	for (int i = 0; i < size; i++)
	{
		if (vertexList[i].getLabel() == v)
		{
			for (int j = i; j < size - 1; j++)
			{
				for (int k = 0; k < size; k++)
					adjMatrix[k*maxSize + 1] =
					adjMatrix[(k*maxSize) + (j + 1)]; 
			}

			for (int a = 0; a < size - 1; a++)
			{
				for (int k = i; k < size; k++)
					adjMatrix[k*maxSize + a] =
					adjMatrix[k*maxSize + (a + maxSize)];
			}

			for (int j = i; j < size; j++)
				vertexList[j] = vertexList[j + 1]; 
			size--; 
			return; 
		}
	}
}

//--------------------------------------------------------------------

void WeightedGraph:: removeEdge ( const string& v1, const string& v2 ) throw ( logic_error )

// Removes the edge between vertices v1 and v2 from a graph.

{
	int idx1 = getIndex(v1);
	int idx2 = getIndex(v2);

	if (idx1 != -1 && idx2 != -1)
		setEdge(idx1, idx2, INFINITE_EDGE_WT);
	else
		throw logic_error("Not found"); 

}

//--------------------------------------------------------------------

void WeightedGraph:: clear ()

// Removes all the vertices and edges from a graph.

{ 
	size = 0; 
}

//--------------------------------------------------------------------

bool WeightedGraph:: isEmpty () const

// Returns 1 if a graph is empty. Otherwise, returns 0.

{
	return (size == 0);
}

//--------------------------------------------------------------------

bool WeightedGraph:: isFull () const

// Returns 1 if a graph is full. Otherwise, returns 0.

{
	return (size == maxSize);
}

//--------------------------------------------------------------------

void WeightedGraph:: showStructure () const

// Outputs a graph's vertex list and adjacency matrix. This operation
// is intended for testing/debugging purposes only.

{
    if ( size == 0 ) {
       cout << "Empty graph" << endl;
    } else {
       cout << endl << "Vertex list : " << endl;
       for ( int row = 0 ; row < size ; row++ ) {
           cout << row << '\t' << vertexList[row].getLabel();
#if LAB12_TEST2
	   cout << '\t' << vertexList[row].getColor();
#endif
	   cout << endl;
       }

       cout << endl << "Edge matrix : " << endl << '\t';
       for ( int col = 0 ; col < size ; col++ )
           cout << col << '\t';
       cout << endl;
       for ( int row = 0 ; row < size ; row++ )
       {
           cout << row << '\t';
           for ( int col = 0 ; col < size ; col++ )
           {
               int wt = getEdge(row,col);
               if ( wt == INFINITE_EDGE_WT )
                  cout << "- \t";
               else
                  cout << wt << '\t';
           }
           cout << endl;
       }
    }
}




//--------------------------------------------------------------------
//
//  Facilitator functions
//

int WeightedGraph:: getIndex ( const string& v ) const

// Returns the adjacency matrix index for vertex v. Returns size if
// the vertex does not exist.

{
	for (int j = 0; j < size; j++)
	{
		if (v == vertexList[j].getLabel())
			return j; 
	}
	return size;
}
       
//--------------------------------------------------------------------

int WeightedGraph:: getEdge ( int row, int col ) const

// Gets adjMatrix[row][col].

{
	return adjMatrix[maxSize*row+col];
}

void WeightedGraph:: setEdge ( int row, int col, int wt )

// sets adjMatrix[row][col].

{
	adjMatrix[maxSize*row + col] = wt; 
}


#endif