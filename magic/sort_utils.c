#include "sort_utils.h"
#include "string_utils.h"
#include <stdlib.h>
#include <string.h>

/*
Swap between arr[i] and arr[j]
*/
void swap(int* arr, int i, int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

/*
Go over the array- and count the items until LAST_ITEM.
*/
int get_arr_length(int* arr)
{
  int i = 0;
  while (arr[i] != LAST_ITEM)
    i++;
  return i;
}

/*
The paritition logic within the classic quicksort algorithm.
Go over all index between low and high, and organize is so all members
that are smaller than arr[high] are to it's left, and all larger than it
to its right, and return the new index of arr[high].
*/
int partition(int* arr, int low, int high)
{
  int j;
  int i = low - 1;
  
  for (j = low; j < high; j++)
  {
    /*Make sure that if arr[j] is smaller than arr[high], it will be to the left
    of arr[high] after parittion is done.*/
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
QUicksort recursive algorithm- time complexity of O(nlogn)
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
Make a copy for the passed array to not change it's order, and then sort the copy.
Time complexity is O(nlogn).
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
