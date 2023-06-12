//*************************************************************
// Author: Cenker Ozkan
//
// Implementation of a queue class with linked list in C++
// I benefited from D.S Malik's stack implementation.
//*************************************************************
#ifndef H_Stack_LL
#define H_Stack_LL
#include <iostream>
#include <cassert>
#include "queueADT.h"

template <class T>
struct Node{
    T info;
    Node<T> *link;
};

template <class T>
class queue: public queueADT<T>{
    private:
        Node<T> *queue_front;
        Node<T> *queue_back;

    public:
        // Constructor.
        queue(){
            queue_front = NULL;
            queue_back = NULL;
        }
        // Destructor.
        ~queue(){
            initialize();
        }

        // Function to check if queue is empty.
        bool is_empty(){
            return (queue_front == NULL);
        }
        // Function to check if queue is full
        // Since using linked list implementation,
        // it can never be full theoratically.
        bool is_full(){
            return false;
        }

        void initialize(){
            Node<T> *temp;

            // Good old traverse code.
            while(queue_front != NULL){
                temp = queue_front;
                queue_front = queue_front->link;
                delete temp;
            }
            queue_back = NULL;
        }

        void add_queue(T _value){
            Node<T> *new_node;
            new_node = new Node<T>;
            new_node->info = _value;
            new_node->link = NULL;

            if(queue_front == NULL){
                queue_front = new_node;
                queue_back = new_node;
            }
            else{
                queue_back->link = new_node;
                queue_back = queue_back->link;
            }
        }

        T front(){
            assert(queue_front != NULL);
            return (queue_front->info);
        }
        T back(){
            assert(queue_back != NULL);
            return (queue_back->info);
        }

        void delete_queue(){
            Node<T> *temp;
            if(is_empty() != true){
                temp = queue_front;
                queue_front = queue_front->link;
                delete temp;

                if(queue_front == NULL){
                    queue_back = NULL;
                }
            }
            else{
                std::cout << "Cannot remove from an empty queue!\n";
            }
        }
};


#endif