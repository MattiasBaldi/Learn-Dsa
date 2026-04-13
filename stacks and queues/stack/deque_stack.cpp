#include <iostream>
#include <deque>
#include <stack>
#include <list>
#include <vector>

/**
   * https://www.geeksforgeeks.org/dsa/stack-implementation-using-deque/
   * Deque's for stacks are very common, although less common than dynamic arrays in most languages, 
   * However, in C++ stl it's used as the default implementation, because it ensures no reallocation risk
   * However, However, in modern C++, std::vector is often preferred when performance and cache efficiency matter.
   * In practice, most C++ developers use std::vector for stack behavior.
 */

 int main() {

  // Using a deque
  std::deque<int> stack; 

  stack.push_back(10); 
  stack.push_back(20); 
  stack.push_back(30); 

  std::cout << stack.back() << " popper from deque " << std::endl; 
  stack.pop_back(); 
  std::cout << "Top element is: " << stack.back() << std::endl; 

  // Std stack is using a deque under the hood already, by default, but you can change it if you want
  std::stack<int> stack_standard;
  stack_standard.push(10);
  stack_standard.push(20);
  stack_standard.push(30);

  std::cout << stack_standard.top() << std::endl;
  stack_standard.pop();

  std::cout << stack_standard.top() << std::endl;

  // std stack using a dynamic array AKA vector
  std::stack<int, std::vector<int>> stack_vector;

  stack_vector.push(10);
  stack_vector.push(20);
  stack_vector.push(30);

  std::cout << stack_vector.top() << std::endl; // 30
  stack_vector.pop();

  std::cout << stack_vector.top() << std::endl; // 20

  // Std stack using a doubly linked list
  std::stack<int, std::list<int>> stack_linked_list;

  stack_linked_list.push(10);
  stack_linked_list.push(20);
  stack_linked_list.push(30);

  std::cout << stack_linked_list.top() << std::endl; // 30
  stack_linked_list.pop();

  std::cout << stack_linked_list.top() << std::endl; // 20

  return 0;  

 }