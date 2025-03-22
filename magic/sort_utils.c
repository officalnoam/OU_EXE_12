#include "sort_utils.h"
#include <stdlib.h>
#include <string.h>

void swap(int* arr, int i, int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

int get_arr_length(int* arr)
{
  int i = 0;
  while (arr[i] != -1)
    i++;
  return i;
}

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

void quick_sort(int* arr, int low, int high)
{
  int prt;
  if (low >= high)
    return;
  
  prt = partition(arr, low, high);
  quick_sort(arr, low, prt - 1);
  quick_sort(arr, prt + 1, high);
}

int* get_sorted_arr_copy(int* arr)
{
  int* sorted_arr = NULL;
  int size = get_arr_length(arr);
  
  sorted_arr = (int*) malloc((size + 1) * sizeof(int));
  memcpy(sorted_arr, arr, (size + 1) * sizeof(int));
  quick_sort(sorted_arr, 0, size - 1);
  
  return sorted_arr;
}
