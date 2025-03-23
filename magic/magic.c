#include "magic.h"
#include "input_utils.h"
#include "string_utils.h"
#include "validation.h"
#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>

/*
This function will free all the pointers used in the main function to avoid duplicate code.
Will check which of the pointers are null- and will free any that isn't.
*/
void free_pointers(char* str, int* nums, int** matrix)
{
  if (str != NULL)
    free(str);
  
  if (nums != NULL)
    free(nums);

  if (matrix != NULL)
    free_matrix(matrix);
}

int main()
{
  char* str = NULL;
  int* nums = NULL;
  int** matrix = NULL;
  
  str = get_string_from_user();
  if (str == NULL)
    return 1;
  
  nums = parse_ints_from_string(str);
  if (nums == NULL)
  {
    free_pointers(str, nums, matrix);
    return 1;
  }
  
  if (!validate_input(nums))
  {
    printf("Is not a magic square due to inputted nums being out of range/not being unqiue.\n");
    free_pointers(str, nums, matrix);
    return 1;
  }
  
  matrix = create_matrix(nums);
  if (matrix == NULL)
  {
    free_pointers(str, nums, matrix);
    return 1;
  }
  
  print_matrix(matrix);
  if (is_magic(matrix))
    printf("The inputted numbers form a magic square.\n");
  else
    printf("The inputted numbers do not form a magic square.\n");

  free_pointers(str, nums, matrix);
  return 0;
}
