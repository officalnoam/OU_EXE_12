#include "validation.h"
#include "sort_utils.h"
#include "magic.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

/*
This function will raise an error if the size of the array isn't the required size- the MATRIX_SIZE squared.
*/
void validate_length(int* arr)
{
  if (get_arr_length(arr) != MATRIX_SIZE * MATRIX_SIZE)
  {
    errno = EINVAL;
    perror("The amount of numbers inputted is incorrect");
    exit(1); 
  }
}

/*
This function validates the unjiqueness of all items in the array.
This is done by creating a sorted copy of the array (with the time complexity O(nlogn))
and then all items in the sorted array are compared to the item before and after it.
*/
bool validate_uniqueness(int* arr)
{
  int i;
  int* sorted_arr = get_sorted_arr_copy(arr);
  for (i = 1; i < get_arr_length(sorted_arr) - 1; i++)
  {
    if (sorted_arr[i] == sorted_arr[i - 1] || sorted_arr[i] == sorted_arr[i + 1])
      return false;
  }
  return true;
} 

/*
This function will validate that all items in the array are within the valid sizes of 1-MATRIX_SIZE squared.
*/
bool validate_num_range(int* arr)
{
  int i;
  for (i = 0; i < get_arr_length(arr); i++)
  {
    if (arr[i] < 1 || arr[i] > MATRIX_SIZE * MATRIX_SIZE)
      return false;
  }
  return true;
}

/*
This function validates the ability of an inputted array to be a magic square,
orior to comparing the sums of the rows, columns and diagonals.
*/
bool validate_input(int* arr)
{
  validate_length(arr);
  if (validate_uniqueness(arr) && validate_num_range(arr))
    return true;
  return false;
}
