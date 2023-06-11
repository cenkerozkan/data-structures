#include <iostream>
#include "stack.h"

int main(void){
    stack<int> s1(25);
    s1.push(1);
    std::cout << s1.top() << "\n";
    s1.push(2);
    std::cout << s1.top() << "\n";
    s1.push(3);
    std::cout << s1.top() << "\n";
    s1.push(4);
    std::cout << s1.top() << "\n";
    s1.push(5);
    std::cout << s1.top() << "\n";
    s1.push(6);
    std::cout << s1.top() << "\n";

    s1.pop();
    std::cout << s1.top() << "\n";
    s1.pop();
    std::cout << s1.top() << "\n";
    s1.pop();
    std::cout << s1.top() << "\n";
    return 0;
}