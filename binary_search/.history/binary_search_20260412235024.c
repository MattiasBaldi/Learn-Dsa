#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int binary_search(int array[MAX], int n,  int target)
{

  // stop condition
  int center = (n / 2) - 1; 
  if (target == array[center]) return center;

  // if target above -> go left
  if (target > array[center])
    binary_search(array, center-1, target); 

  // if target below -> go right
  if (target < array[center])
    binary_search(array, center+1, target); 

}

int main() {

  int sorted_array[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 

  // use binary search to find 3
  int three_index = binary_search(sorted_array, MAX, 3); 

  return 1; 
}