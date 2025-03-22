#include "magic.h"
#include "input_utils.h"
#include "string_utils.h"
#include "validation.h"
#include <stdlib.h>
#include <stdio.h>

/*
This function serves as a teardown for all the manually allocated memory throughout the program.
If a pointer is not NULL, will free the memory.

Input-
  char* str: The string inputted by the user during the program.
  int* nums: The list of integers within the string.
*/
void free_pointers(char* str, int* nums)
{
  if (str != NULL)
    free(str);
  
  if (nums != NULL)
    free(nums);
}

int main()
{
  char* str = NULL;
  int* nums = NULL;
  
  str = get_string_from_user();
  if (str == NULL)
    return 1;
  
  nums = parse_ints_from_string(str);
  if (nums == NULL)
  {
    free_pointers(str, nums);
    return 1;
  }
  
  if (!validate_input(nums))
    free_pointers(str, nums);
  
  free_pointers(str, nums);
  return 1;
}
