#include "sort_utils.h"
#include "string_utils.h"
#include <stdlib.h>
#include <string.h>

/*
This function swaps two integers within an array of integers.

Input-
  int* arr: The array.
  int i: The index of one of the items being swapped.
  int j: The index of the second item being swapped.
 */
void swap(int* arr, int i, int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

/*
This function gets the length of the array of integers- using the definition of the last item of the array in string utils.

Input-
  int* arr: The array.
Output-
  int: The length of the array.
*/
int get_arr_length(int* arr)
{
  int i = 0;
  while (arr[i] != LAST_ITEM)
    i++;
  return i;
}

/*
This function is the partition logic for the quicksort algorithm- it returns an index between high and low,
for which all numbers in the indexes between low and it are smaller, and all the indexes between high and it are larger.

Input-
  int* arr: The array.
  int low: The minimum index for the part in the array the partition is for.
  int high: The maximum index for the part in the array the partition is for.
Output-
  int: The index of the partition.
*/
int partition(int* arr, int low, int high)
{
  int j;
  int i = low - 1;
  
  for (j = low; j < high; j++)
  {
    if (arr[j] < arr[high])
    {
      i++;
      swap(arr, i, j);
    }
  }
  i++;
  
  swap(arr, i, high);
  return i;
}

/*
This function performs the quick sort algorithm for an array.

Input-
  int* arr: The array being sorted.
  int low: The minimum index for the part of the being sorted.
  int high: The maximum index for the part of the array being sorted. 
*/
void quick_sort(int* arr, int low, int high)
{
  int prt;
  if (low >= high)
    return;
  
  /* Get the partition and sort recursively*/
  prt = partition(arr, low, high);
  quick_sort(arr, low, prt - 1);
  quick_sort(arr, prt + 1, high);
}

/*
This function will return a new array, which is a sorted version of the inputted array- which stays unchanged.

Input-
  int* arr: The array whose values will be in a new, seperate, sorted array.
Output-
  int*: The sorted array.
*/
int* get_sorted_arr_copy(int* arr)
{
  int* sorted_arr = NULL;
  int size = get_arr_length(arr);
  
  sorted_arr = (int*) malloc((size + 1) * sizeof(int));
  memcpy(sorted_arr, arr, (size + 1) * sizeof(int));
  quick_sort(sorted_arr, 0, size - 1);
  
  return sorted_arr;
}
