//*************************************************************
// Author: Cenker Ozkan
//
// Implementation of an abstract queue class in C++
// I benefited from D.S Malik's queue implementation.
//*************************************************************

#ifndef H_Queue_ADT
#define H_Queue_ADT
template <class T>
class queueADT{
    public:
        virtual bool is_empty() = 0;    // Returns true if empty.
        virtual bool is_full() = 0;     // Returns true if full.
        virtual void initialize() = 0;  // Initializes the queue into an empty state.
        virtual T front() = 0;  // Returns the first element of the queue.
        virtual T back() = 0;   // Returns the last element of the queue.
        virtual void add_queue(T _value) = 0;   // Adds new element to queue.
        virtual void delete_queue() = 0;    // Removes the first element.
};
#endif