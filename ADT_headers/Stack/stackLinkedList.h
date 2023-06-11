//*************************************************************
// Author: Cenker Ozkan
//
// Implementation of a stack class with linked list in C++
// I benefited from D.S Malik's stack implementation.
//*************************************************************
#ifndef H_Stack
#define H_Stack
#include <iostream>
#include <cassert>
#include "stackADT.h"

template <class T>
struct Node{
    T info;
    Node<T> *link;
};

template <class T>
class stack: public stackADT<T>{
    private:
        Node<T> *stack_top;

        // Function to copy the given stack.
        void copy_stack(stack<T> &_source){
            Node<T> *new_node, *current, *last;
            if(stack_top != NULL){
                initialize_stack();
            }
            if(_source.stack_top == NULL){
                stack_top = NULL;
            }
            else{
                // Beginning with the top node.
                current = _source.stack_top;
                stack_top = new Node<T>;
                stack_top->info = current->info;
                stack_top->link = NULL;
                last = stack_top;
                current = current->link;

                // Good old traverse code.
                while(current != NULL){
                    new_node = new Node<T>;
                    new_node->info = current->info;
                    new_node->link = NULL;
                    last->link = new_node;
                    last = new_node;
                    current = current->link;
                }
            }
        }

    public:
        // Default constructor.
        stack(){
            stack_top = NULL;
        }
        // Copy constructor.
        stack(stack<T> &_source){
            stack_top = NULL;
            copy_stack(_source);
        }
        // Destructor.
        ~stack(){
            initialize_stack();            
        }

        // Function to control if the stack is empty.
        bool is_empty(){
            return (stack_top == NULL);
        }
        // Function to control if the stack is full.
        // In array implementation, a stack might be full
        // since the size of an array is limited, so the
        // function may useful to check if it is full but in
        // linked list implementation, a stack cannot be full
        // theoratically, so the method always returns false
        // when called.
        bool is_full(){
            return false;
        }

        // Function to initialize the stack to an empty state.
        void initialize_stack(){
            Node<T> *temp;
            // Good old traverse code.
            while(stack_top != NULL){
                temp = stack_top;
                stack_top = stack_top->link;
                delete temp;
            }
        }

        // Function to add a new element at top of the stack.
        // New added element will be linked to top element of 
        // the stack, then the top pointer will point the new 
        // node.
        void push(T &_value){
            Node<T> *new_node;
            new_node = new Node<T>;
            new_node->info = _value;
            new_node->link = stack_top;
            stack_top = new_node;
        }

        void push(T _value){
            Node<T> *new_node;
            new_node = new Node<T>;
            new_node->info = _value;
            new_node->link = stack_top;
            stack_top = new_node;
        }

        // Function to return the value of top element.
        T top(){
            assert(stack_top != NULL);
            return stack_top->info;
        }

        // Function to remove the top element.
        void pop(){
            Node<T> *temp;

            // Check if the list is empty.
            if(stack_top != NULL){
                temp = stack_top;
                stack_top = stack_top->link;
                delete temp;   
            }
            else{
                std::cout << "Cannot remove from an empty stack.\n";
            }
        }

        stack<T> operator= (stack<T> &_source){
            if(this != &_source){
                copy_stack(_source);
            }
            return *this;
        }
};
#endif