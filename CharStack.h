#ifndef CHARSTACK_H
#define CHARSTACK_H


/*  header file for part 1 of assignemnt 6
    this class defines a stack of characters.  Values
    may be pushed onto the stack and popped off.
    The top element may be accessed, and it may
    be determined if the stack is empty.  Stacks
    are constructed empty. */

#include <iostream>
using namespace std;

class CharStack {
    

    public:
        // exceptions
            class Overflow{};
            class Underflow{};

        CharStack();
            // constructs empty stack with a default
            // number of elements available

        CharStack(const CharStack &v);
            // copy constructor

        ~CharStack();
            // destructor

        CharStack& operator =(const CharStack &v);
            // assignment operator

        void push(char value) throw(Overflow) ;
            // pushes value onto top of stack
            // throws exception if full

        void pop() throw(Underflow);
            // pops top value off stack
            // throws exception if empty

        char top() const throw(Underflow); 
            // returns top value on stack
            // throws exception if empty

        bool empty() const;
            // returns true if stack is empty

        bool full() const;
            // returns true if stack is full
  
        void output(ostream &s) const;
            // outputs elements of stack

    private:
        struct Elem {
            char info;
            Elem *next;
        };

        Elem *head; 

        void copyCode(const CharStack & v);
            // common code for copy constructor and assignment

        void destructCode();
            // common code for destructor and assignment
};


ostream & operator << (ostream & s, const CharStack & v); 

#endif
