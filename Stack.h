#ifndef STACK_H
#define STACK_H

/* this class defines a generic stack 
   make class Elem top level instead of an inner class */

#include <iostream>
using namespace std;

template<class T>
struct Elem {
    T info;
    Elem<T> *next;
};


template<class T>
class Stack {
    public:
        // exceptions
            class Overflow{};
            class Underflow{};

        Stack();
            // constructs empty stack with a default
            // number of elements available

        Stack(const Stack<T> &v);
            // copy constructor

        ~Stack();
            // destructor

        Stack<T>& operator =(const Stack<T> &v);
            // assignment operator

        void push(T value) throw(Overflow) ;
            // pushes value onto top of stack
            // throws exception if full

        void pop() throw(Underflow);
            // pops top value off stack
            // throws exception if empty

        T top() const throw(Underflow);
            // returns top value on stack
            // throws exception if empty

        bool empty() const;
            // returns true if stack is empty

        bool full() const;
            // returns true if stack is full
  
        void output(ostream &s) const;
            // outputs elements of stack

    private:

        Elem<T> *head; 

        void copyCode(const Stack<T> & v);
            // common code for copy constructor and assignment

        void destructCode();
            // common code for destructor and assignment
};

template<class T>
ostream & operator << (ostream & s, const Stack<T> & v);
    // outputs using keyword operation



#include "Stack.cpp"
#endif
