#include "validation.h"
#include "sort_utils.h"
#include "input_utils.h"
#include <errno.h>
#include <stdio.h>

/*
This function will validate that the amount of numbers inputted by the user is the needed amount- the MATRIX_SIZE squared.
Will raise an error if the number doesn't match.

Input-
  int* arr: The inputted numbers.
*/
void validate_length(int* arr)
{
  if (get_arr_length(arr) != MATRIX_SIZE * MATRIX_SIZE)
  {
    errno = EINVAL;
    perror("The amount of numbers inputted is incorrect"); 
  }
}

/*
This function will validate the uniqueness of all of the numbers inputted by the user.
This is done by first sorting a copy of the inputted numbers, are comparing the surrounding numbers
(to avoid higher time complexities if all numbers are compared to all other numbers).

Input-
  int* arr: The inputted numbers by the user.
Output-
  bool: true if all numbers are unique, false otherwise.
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
This function will validate that all numbers inputted by the user are between 1 and the size of the matrix squared.

Input-
  int* arr: The inputted numbers.
Output-
  bool: true if all numbers are within the described range, false otherwise.
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
This function will perform validations on the inputted numbers by the user.
If according to the exercise they should cause the program to stop running- an error will be raised.

Input-
  int* arr: The numbers inputted by the user.
Output-
  bool: true if the input is valid, false otherwise.
*/
bool validate_input(int* arr)
{
  validate_length(arr);
  if (validate_uniqueness(arr) && validate_num_range(arr))
    return true;
  return false;
}
