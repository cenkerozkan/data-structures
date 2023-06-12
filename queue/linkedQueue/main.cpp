#include <iostream>
#include "queue.h"

int main(void){
    queue<int> q1;
    q1.add_queue(1);
    q1.add_queue(2);
    q1.add_queue(3);
    q1.add_queue(4);
    q1.add_queue(5);
    q1.add_queue(6);
    q1.add_queue(7);
    std::cout << q1.front() << std::endl;
    std::cout << q1.back() << std::endl;
    q1.delete_queue();
    std::cout << q1.front() << std::endl;
    return 0;
}