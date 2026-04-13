#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int binary_search(int array[MAX], int low, int high, int target)
{

  if (low > high) return -1; 

  // stop condition
  int center = low + (high - low) / 2;

  if (target == array[center]) return center;

  // if target above -> go left
  if (target > array[center])
    return binary_search(array, low, center - 1, target); 

  // if target below -> go right
  if (target < array[center])
    return binary_search(array, center + 1, high, target); 

}

int main() {

  int sorted_array[MAX] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; 

  // use binary search to find 3
  int three_index = binary_search(sorted_array, 0, MAX, 3); 

  printf("The digit: %d, should be : 3\n", three_index);


  return 1; 
}