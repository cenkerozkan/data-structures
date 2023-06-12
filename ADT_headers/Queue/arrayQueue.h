//*************************************************************
// Author: Cenker Ozkan
//
// Implementation of a queue class with array in C++
// I benefited from D.S Malik's stack implementation.
//*************************************************************

#ifndef H_queue
#define H_queue
#include <iostream>
#include <cassert>
#include "queueADT.h"
template <class T>
class queue: public queueADT<T>{
    private:
        int queue_size;
        int count;
        int queue_front;
        int queue_back;
        T *list;

    public:
        // Constructor with size parameter.
        queue(int _size=0){
            if(queue_size <= 0){
                std::cout << "Size of the array to hold the queue must be positive!\nCreating an array of size 100.\n" ;
                queue_size = 100;
            }
            else{
                queue_size = _size;
            }
            queue_front = 0; // First element index.
            queue_back = queue_size-1; // Last element index.
            count = 0;
            list = new T[queue_size];
        }
        // Destructor.
        ~queue(){
            delete [] list;
        }


        // Function to check if the queue is empty.
        bool is_empty(){
            return (count == 0);
        }
        // Function to check if the queue is full.
        bool is_full(){
            return (count == queue_size);
        }

        // Function to initialize the queue into an empty state.
        void initialize(){
            queue_front = 0;
            queue_back = queue_size-1;
            count = 0;
        }

        // Function to return the front element of queue.
        T front(){
            assert(!is_empty());
            return list[queue_front];
        }
        // Function to return the rear element of queue.
        T back(){
            assert(!is_empty());
            return list[queue_back];
        }


        // Function to add new element into queue.
        void add_queue(T &_value){
            if(is_full() != true){
                queue_back = (queue_back + 1) % queue_size;
                count++;
                list[queue_back] = _value;
            }
            else{
                std::cout << "Cannot add new element to a full queue!\n";
            }
        }

        void add_queue(T _value){
            if(is_full() != true){
                queue_back = (queue_back + 1) % queue_size;
                count++;
                list[queue_back] = _value;
            }
            else{
                std::cout << "Cannot add new element to a full queue!\n";
            }
        }

        void delete_queue(){
            // If not empty.
            if(is_empty() != true){
                count--;
                queue_front = (queue_front + 1) % queue_size;
            }
            else{
                std::cout << "Cannot remove an element from an empty queue!\n";
            }
        }
};
#endif