//*************************************************************
// Author: Cenker Ozkan
//
// Implementation of a stack class with array in C++
// I benefited from D.S Malik's stack implementation.
//*************************************************************

#ifndef H_Stack
#define H_Stack
#include <iostream>
#include <cassert>
#include "stackADT.h"

template <class T>
class stack: public stackADT<T>{
    private:
        int size;      // Maximum size of the stack.
        int stack_top; // Variable that holds the top index value of the stack.
        T *list;       // Pointer to the array that holds the stack elements.

        // Function to make a copy of another stack.
        void copy_stack(const stack<T> &_param){
            delete [] list;
            size = _param.size;
            stack_top = _param.stack_top;

            list = new T[size];

            for(int i=0; i<stack_top; i++){
                list[i] = _param.list[i];
            }
        }


    public:
        // Constructor
        stack(){};  
        stack(int _size){
            if(_size <= 0){
                std::cout << "Size cannot be zero or negative\nCreating the stack with default size 100\n";
                size = 100;
            }
            else{
                size = _size;
            }
            stack_top = 0;
            list = new T[size];
        }

        // Copy constructor.
        stack(stack<T> &_param){
            list = NULL;
            copy_stack(_param);
        }

        // Destructor.
        ~stack(){
            delete [] list;
        }

        stack<T> operator= (stack<T> &_param){
            if(this != &_param){
                copy_stack(_param);
            }
            return *this;
        }
        

        // Initializes the stack into an empty state.
        void initialize_stack(){
            stack_top = 0;
        }

        bool is_empty(){
            return (stack_top == 0);
        }

        bool is_full(){
            return (stack_top == size);
        }

        // Takes const variables as parameter.
        void push(T &_param){
            if(!is_full()){
                list[stack_top] = _param;
                stack_top++;
            }
            else{
                std::cout << "Cannot add to a full stack\n";
            }
        }
        // Takes non-const variables as parameter.
        void push(T _param){
            if(!is_full()){
                list[stack_top] = _param;
                stack_top++;
            }
            else{
                std::cout << "Cannot add to a full stack\n";
            }
        }

        T top(){
            assert(stack_top != 0);
            return list[stack_top-1];
        }

        void pop(){
            if(!is_empty()){
                stack_top--;
            }
            else{
                std::cout << "Cannot remove from an empty stack\n";
            }
        }
};
#endif