#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int binary_search(int array[MAX], int n,  int target)
{

  printf("N:%d", n); 

  // don't overflow / underflow
  if (n >= MAX || n < 0) return -1; 

  // stop condition
  int center = (n / 2) - 1;
  if (target == array[center]) return center;

  // if target above -> go left
  if (target > array[center])
    binary_search(array, center, target); 

  // if target below -> go right
  if (target < array[center])
    binary_search(array, center, target); 

}

int main() {

  int sorted_array[MAX] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; 

  // use binary search to find 3
  int three_index = binary_search(sorted_array, MAX, 3); 

  printf("The digit: %d, should be : 3\n", three_index);


  return 1; 
}