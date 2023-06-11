//*************************************************************
// Author: Cenker Ozkan
//
// Implementation of an abstract stack class in C++
// I benefited from D.S Malik's stack implementation.
//*************************************************************

#ifndef H_Stack_ADTS
#define H_Stack_ADTS
template <class T>
class stackADT{
    public:
        virtual void initialize_stack() = 0; // Initializes the stack to an empty state.
        virtual bool is_empty() = 0; // Returns true if empty.
        virtual bool is_full() = 0; // Returns true if fullç
        virtual void push(T &_value) = 0; // Adds a new element on top of the stack.
        virtual T top() = 0; // Returns the value of the top element.
        virtual void pop() = 0; // Removes the top element.
};
#endif