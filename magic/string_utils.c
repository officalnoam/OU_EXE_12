#include "string_utils.h"
#include "input_utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

/*
This function checks if a char is a whitespace- including a tab or newline.

Input-
  char c: The char being checked.
Output-
  bool: true if c is a whitespace, otherwise false.
*/
bool is_char_whitespace(char c)
{
  if (c == ' ' || c == '\n' || c == '\t')
    return true;
  return false;
}

/*
This function checks if a char is a number.

Input-
  char c: The char being checked.
Output-
  bool: true if c is a number, false otherwise.
*/
bool is_char_numeric(char c)
{
  if (c >= '0' && c <= '9')
    return true;
  return false;
}

int parse_int_from_substring(char* str, int* index_p)
{
  int num = 0;
  while (!is_char_whitespace(str[*index_p]))
  {
    if (!is_char_numeric(str[*index_p]))
    {
      errno = EINVAL;
      perror("Inputted non whitespace or numeric character.");
    }
    num = num * 10;
    num = num + str[*index_p] - '0';
    *index_p = *index_p + 1;
  }
  return num;
}

/*
This function will receive a string, and parse from it all numbers seperated by whitespaces- and reeturn a list of those numbers in order.

Input-
  char* str: The string being parsed

Output-
  int*: The list of integers within the string.
*/
int* parse_ints_from_string(char* str)
{
  int i = 0;
  int list_index = 0;
  int temp;
  int* parsed_ints = (int*) malloc((MATRIX_SIZE * MATRIX_SIZE + 1) * sizeof(int));
  
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
      temp = parse_int_from_substring(str, &i);
      parsed_ints[list_index] = temp;
      list_index++;
    }
    else
      i++;
  }
  parsed_ints[list_index] = LAST_ITEM;
  return parsed_ints;
}
