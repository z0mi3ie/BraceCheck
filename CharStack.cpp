/* Kyle Vickers
   ID: 984418528
   Assignment 6: CharStack
   CS515
*/

/* CharStack.cpp: This is the function definitions for
   a CharStack datastructure. The same functionality of
   the standard stack in C++ is given in this example. 
*/

#include "CharStack.h"
#include <iostream>
#include <string>

//---------------------------------------------------
// O(1) Constructur
//---------------------------------------------------
CharStack::CharStack()
{
	head = 0;
}

//---------------------------------------------------
// O(n) destructCode()
//       This is the code that is called whenever the
//       datastructure needs to be deleted an element
//       at a time
//---------------------------------------------------
void CharStack::destructCode()
{
	Elem * temp = head;
	Elem * next = head;
	
	while( temp != 0 )
	{
		next = temp -> next;
		delete temp;
		temp = next;
	}
	head = 0;
}

//---------------------------------------------------
//  O(n^2) Copy Constructor
//---------------------------------------------------
CharStack::CharStack( const CharStack &v )
{
    copyCode(v);
}

//---------------------------------------------------
// O(n) Destructor
//---------------------------------------------------
CharStack::~CharStack()
{
    destructCode();
}

//---------------------------------------------------
// O(n) push( char value )
//      Makes a new element on the stack with the given
//      character saved in the elements info
//---------------------------------------------------
void CharStack::push(char value) throw(Overflow)
{
	Elem * pushed = new Elem;
	pushed->info = value;

	if( head == 0 )
	{
		head = pushed;
		head->next = 0;
	}
	else
	{
		Elem * cur = head;
		while( cur-> next != 0 )
		{
			cur = cur->next;
		}
		cur->next = pushed;
		pushed->next = 0;
	}
}

//---------------------------------------------------
// O(n)   pop() 
//        Deletes the top element of the stack
//---------------------------------------------------
void CharStack::pop() throw(Underflow)
{
	if( head == 0 )
	{
		cout << "Stack is empty" << endl;
	}
	else
	{
		Elem * cur = head;
		Elem * prev = 0;

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
// O(n)  Overloaded << operator
//       Enables the use of << in stream output to 
//       easily view the contents of the stack
//---------------------------------------------------
ostream& operator <<(ostream &s, const CharStack &v)
{
    v.output(s);
    return s;	
}

//---------------------------------------------------
// O(n)  output( ostream )
//       The common output code for the stack
//---------------------------------------------------
void CharStack::output(ostream &s) const
{
     Elem *p = head;
     while (p) 
     {
           s << p->info << '\n';
           p = p->next;
     }
}

//---------------------------------------------------
// O(n^2) overloaded = operator
//        Enables one stack to be copied to another through
//        a deep copy of the elements.
//---------------------------------------------------
CharStack& CharStack::operator =(const CharStack &v)
{
    if (this != &v) 
    {
        destructCode();
        copyCode(v);
    }
    return *this;
}

//---------------------------------------------------
// O(n^2) copyCode( const CharStack )
//        Common code for copying of a stack
//---------------------------------------------------
void CharStack::copyCode( const CharStack & v )
{
             
	Elem *p1;
	Elem *p2;
	if (v.head==0)
		head = 0;
	else 
	{
		head = new Elem;
		head->info = v.head->info;
		p1 = head;
		p2 = v.head->next;
		while (p2) 
		{
			p1->next = new Elem;
			p1 = p1->next;
			p1->info = p2->info;
			p2 = p2->next;
		}

		p1->next = 0;
	}
}

//---------------------------------------------------
// O(n)   top()
//        Returns the char of the top of the stack
//---------------------------------------------------
char CharStack::top() const throw(Underflow)
{
	if( head == 0 )
	{
		cout << "Stack is empty" << endl;
	}
	else
	{
		Elem * cur = head;
		while( cur->next != 0 )
		{
			cur = cur->next;
		}
		return cur->info;
	}
}

//---------------------------------------------------
// O(1) empty()
//      Returns true if the stack is empty
//---------------------------------------------------
bool CharStack::empty() const
{
     if( head == 0 )
         return true;
     else
         return false;
}

//---------------------------------------------------
// O(1)  full()
//   Returns true if the heap is full.
//---------------------------------------------------
bool CharStack::full() const
{
	try
	{
		Elem * testelem = new Elem;
		delete testelem;
	}
	catch(...)
	{
		//cout << "The stack is full" << endl;
		return 1;
	}
	
	return 0;
}

/*
int main()
{
 
   CharStack s;

   s.push('a');
   s.push('b');
   s.push('c');
   s.push('d');
   s.push('e');
  
   CharStack t;
   t = s;
   cout << "t-------------------" << endl;
   cout << t;
   t.pop();
   t.pop();
   cout << "t after pop---------------" << endl;
   cout << t;
   cout << "-------------------" << endl;
   cout << "Top of stack " << t.top() << endl;
   t.pop();
   cout << "Top of stack after pop " << t.top() << endl;
   CharStack u( t );
   u.push('z');
   cout << u;
   cout << endl << u.empty() << endl;
   u.pop();
   u.pop();
   u.pop();
   cout << u.empty() << endl;

   return 0;
 
}
*/

