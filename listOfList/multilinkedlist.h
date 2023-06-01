#ifndef H_MLL
#define H_MLL
#include <iostream>
#include <cassert>

// NODE.
template <class T>
struct Node{
    T info;
    int index;
    Node<T> *link;          // Pointer to next parent node.
    Node<T> *child_link;    // Pointer to next child node.
};

// LINKED LIST
template <class T>
class Multilinkedlist{
    protected:
        int count;
        Node<T> *first;
        Node<T> *last;

    private:
        void copy_list();

    public:
        // Default constructor.
        Multilinkedlist(){
            first == NULL;
            last == NULL;
            count = 0;
        }
        // TO DO: Custom constructor.
        // TO DO: Destructor.
};


#endif