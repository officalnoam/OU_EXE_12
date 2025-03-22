#include "input_utils.h"
#include "string_utils.h"
#include <stdlib.h>

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
    free(str);
    return 1;
  }
  
  free(str);
  free(nums);
  return 1;
}
