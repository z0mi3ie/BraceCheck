/* Kyle Vickers
   ID: 984418528
   Assignment 6: CharStack
   CS515
*/

/* Stack.cpp: This is the function defintions for
   a Stack template. The same functionality of
   C++ Stack is given here. 
*/

//#include "Stack.h"
#include <iostream>
#include <string>


//--------------------------------------------
// Constructor
//--------------------------------------------
template< class T >
Stack< T >::Stack()
{
	head = 0;
}

//---------------------------------------------------
// destructCode()
// This is the code that is called whenever the
// datastructure needs to be deleted an element
// at a time
//---------------------------------------------------
template< class T >
void Stack< T >::destructCode()
{
	Elem<T> * temp = head;
	Elem<T> * next = head;
	
	while( temp != 0 )
	{
		next = temp -> next;
		delete temp;
		temp = next;
	}
	head = 0;
}

//---------------------------------------------------
// Copy Constructor
//---------------------------------------------------
template< class T >
Stack< T >::Stack( const Stack<T> &v )
{
    copyCode(v);
}

//---------------------------------------------------
// Destructor
//---------------------------------------------------
template< class T >
Stack< T >::~Stack()
{
	destructCode();
}

//---------------------------------------------------
// push( T value )
// Makes a new element on the stack with the given
// character saved in the elements info
//---------------------------------------------------
template< class T >
void Stack< T >::push(T value) throw(Overflow)
{
	Elem<T> * pushed = new Elem<T>;
	pushed->info = value;

	if( head == 0 )
	{
		head = pushed;
		head->next = 0;
	}
	else
	{
		Elem<T> * cur = head;
		while( cur-> next != 0 )
		{
			cur = cur->next;
		}
		cur->next = pushed;
		pushed->next = 0;
	}
}


//---------------------------------------------------
// pop() 
// Deletes the top element of the stack
//---------------------------------------------------
template< class T >
void Stack< T >::pop() throw(Underflow)
{
	if( head == 0 )
	{
		cout << "Stack is empty" << endl;
	}
	else
	{
		Elem<T> * cur = head;
		Elem<T> * prev = 0;

		while( cur->next )
		{
			prev = cur;
			cur = cur -> next;	
		}

		if( head == cur )
		{
			head = 0;
		}
		else
		{
			prev->next = 0;
			delete cur;
		}
		
	}
}

//---------------------------------------------------
// Overloaded << operator
// Enables the use of << in stream output to 
// easily view the contents of the stack
//---------------------------------------------------
template< class T >
ostream& operator <<(ostream &s, const Stack<T> &v)
{
    v.output(s);
    return s;	
}



//---------------------------------------------------
// output( ostream )
// The common output code for the stack
//---------------------------------------------------
template< class T >
void Stack<T>::output(ostream &s) const
{
     Elem<T> *p = head;
     while (p) 
     {
           s << p->info << '\n';
           p = p->next;
     }
}

//---------------------------------------------------
// overloaded = operator
// Enables one stack to be copied to another through
// a deep copy of the elements.
//---------------------------------------------------
template< class T >
Stack<T>& Stack<T>::operator =(const Stack<T> &v)
{
    if (this != &v) 
    {
        destructCode();
        copyCode(v);
    }
    return *this;
}

//---------------------------------------------------
// copyCode( const CharStack )
// Common code for copying of a stack
//---------------------------------------------------
template< class T >
void Stack<T>::copyCode( const Stack<T> & v )
{
             
	Elem<T> *p1;
	Elem<T> *p2;
	if (v.head==0)
		head = 0;
	else 
	{
		head = new T;
		head->info = v.head->info;
		p1 = head;
		p2 = v.head->next;
		while (p2) 
		{
			p1->next = new T;
			p1 = p1->next;
			p1->info = p2->info;
			p2 = p2->next;
		}

		p1->next = 0;
	}
}

//---------------------------------------------------
// top()
// Returns the char of the top of the stack
//---------------------------------------------------
template< class T >
T Stack<T>::top() const throw(Underflow)
{
	if( head == 0 )
	{
		cout << "Stack is empty" << endl;
	}
	else
	{
		Elem<T> * cur = head;
		while( cur->next != 0 )
		{
			cur = cur->next;
		}
		return cur->info;
	}
}

//---------------------------------------------------
// empty()
// Returns true if the stack is empty
//---------------------------------------------------
template< class T >
bool Stack<T>::empty() const
{
     if( head == 0 )
         return true;
     else
         return false;
}

//---------------------------------------------------
// full()
// Returns true if the heap is full.
//---------------------------------------------------
template< class T >
bool Stack<T>::full() const
{
	try
	{
		Elem<T> * temp = new Elem<T>;
		delete temp;
	}
	catch(...)
	{
		cout << "Stack is full " << endl;
		return 1;
	}
	
	return 0;
}
