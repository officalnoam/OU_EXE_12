#include "string_utils.h"
#include "input_utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

bool is_char_whitespace(char c)
{
  if (c == ' ' || c == '\n' || c == '\t')
    return true;
  return false;
}

bool is_char_numeric(char c)
{
  if (c >= '0' && c <= '9')
    return true;
  return false;
}

int* parse_ints_from_string(char* str)
{
  int i = 0;
  int list_index = 0;
  int temp;
  int* parsed_ints = (int*)malloc((MATRIX_SIZE * MATRIX_SIZE + 1) * sizeof(int));
  
  while (str[i] != '\0')
  {
    temp = 0;
    if (!is_char_whitespace(str[i]))
    {
      if (list_index == MATRIX_SIZE * MATRIX_SIZE)
      {
        errno = EINVAL;
        perror("Inputted number amount larger than the amount of numbers in the matrix");
      }

      while (!is_char_whitespace(str[i]))
      {
        if (!is_char_numeric(str[i]))
        {
          errno = EINVAL;
          perror("Inputted non whitespace or numeric char");
        }
        temp = temp * 10;
        temp = temp + (str[i] - '0');
        i++;
      }
      parsed_ints[list_index] = temp;
      list_index++;
    }
    else
      i++;
  }
  parsed_ints[list_index] = -1;
  return parsed_ints;
}
