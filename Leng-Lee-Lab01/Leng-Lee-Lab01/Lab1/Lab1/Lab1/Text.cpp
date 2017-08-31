
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include "Text.h"



Text::Text ( const char *charSeq )
{
	bufferSize = (strlen(charSeq) + 1);
	buffer = new char[bufferSize]; 
	strcpy(buffer, charSeq); 
}

Text::Text ( const Text &other )
{
	bufferSize = (other.getLength() + 1); 
	buffer = new char[bufferSize];
	strcpy(buffer, other.buffer); 
}

void Text::operator = ( const Text &other )
{
	if (other.bufferSize > bufferSize)
	{
		delete[] buffer;
		bufferSize = other.bufferSize;
		buffer = new char[bufferSize]; 
		strcpy(buffer, other.buffer);
	}
	else 
		strcpy(buffer, other.buffer); 
}

Text::~Text ()
{
	delete[] buffer; 
}

int Text::getLength () const
{
	return (bufferSize - 1);
}

char Text::operator [] ( int n ) const
{
	assert(0 <= n && n < bufferSize);
	
	return buffer[n];
}

void Text::clear ()
{
	for (int i = 0; i < bufferSize; i++)
		buffer[i] = 0; 
}

void Text::showStructure () const
{

	int j;
	for (j = 0; j < bufferSize; j++)
		cout << j << "\t";

	cout << endl;

	for (j = 0; buffer[j] != '\0'; j++)
		cout << buffer[j] << "\t";
	cout << "\\0" << endl;
}

Text Text::toUpper( ) const
{
	Text temp(buffer);
	 
	for (int i = 0; i < bufferSize; i++)
	{
		if (islower(temp.buffer[i]))
		{
			temp.buffer[i] = toupper(temp.buffer[i]);
		}
	}
	 
	return temp;
}

Text Text::toLower( ) const
{
	Text temp(buffer);
	
	for (int i = 0; i < bufferSize; i++)
	{
		if (isupper(buffer[i]))
		{
			temp.buffer[i] = char(tolower(buffer[i]));
		}
	}

	return temp;
}

bool Text::operator == ( const Text& other ) const
{
	if (bufferSize == other.bufferSize)
	{
		if (bufferSize == 0)
		{
			return 1; 
		}
		else
		{
			for (int i = 0; i < bufferSize; i++)
			{
				if (buffer[i] != other.buffer[i])
					return 0; 
			}
			return 1; 
		}
	}
	else
	{
		return false;
	}
}

bool Text::operator <  ( const Text& other ) const
{
	for (int i = 0; i<bufferSize; i++)
	{
		if (buffer[i]>other.buffer[i])
			return 0;
		else if (other.bufferSize < bufferSize)
			return 0;
		else if (other.bufferSize == bufferSize)
			return 0;
		else
			return 1; 
	}

	return false;
}

bool Text::operator >  ( const Text& other ) const
{
	for (int i = 0; i < bufferSize; i++)
	{
		if (buffer[i] < other.buffer[i])
			return 0;
		else if (other.bufferSize>bufferSize)
			return 0;
		else if (other.bufferSize == bufferSize)
			return 0;
		else
			return 1; 
	}
	return false;
}
