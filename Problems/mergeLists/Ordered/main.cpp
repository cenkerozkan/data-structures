/*
    Question:
        Merge two given linkedlists into one a single linked list.
        (Ordered)
*/

// Solution starts at line 154 on orderedlinkedlist.h

#include <iostream>
#include "orderedlinkedlist.h"

int main(void){
    Orderedlinkedlist<int> list1, list2;
    Orderedlinkedlist<int> list3, list4;


    std::cout << "Case 1: If current list is empty.\n";
    list3.merge_list(list4);

    list1.insert(3);
    list1.insert(7);
    list1.insert(8);
    list1.insert(19);
    list1.insert(40);
    list1.insert(44);
    list1.insert(53);
    list1.insert(60);


    list2.insert(1);
    list2.insert(2);
    list2.insert(9);
    list2.insert(11);
    list2.insert(15);
    list2.insert(20);
    list2.insert(23);
    list2.insert(31);
    list2.insert(45);
    list2.insert(57);
    list2.insert(62);
    list2.insert(65);

    list1.merge_list(list2);
    //list1.print();
}
