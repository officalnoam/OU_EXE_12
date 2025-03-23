#include "input_utils.h"
#include "magic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
This function gets the input string from the user. The size of the string isn't limited-
if the max size of the string is reached- realloc will be used to increase the max size.
*/
char* get_string_from_user() {
  char c;
  int size = 0;
  int capacity = (BUFFER_SIZE + 1) * sizeof(char);
  char* str = NULL;
  char* temp = NULL;

  str = (char*)malloc(capacity);
  if (str == NULL)
  {
    printf("Memory allocation failed");
    return NULL;
  }
  printf("Please input the numbers in the matrix being checked. \nThere needs to be %d numbers inputted, seperated by one or more whitespaces:\n", \
         MATRIX_SIZE * MATRIX_SIZE);
  while ((c=getchar()) != EOF)
  {
    /*If the size of the string has reached capacity- increase the size of the string using realloc*/
    if (size == capacity - 1)
    {
      capacity = capacity + BUFFER_SIZE * sizeof(char);
      temp = (char*)realloc(temp, capacity);
      if (temp == NULL)
      {
        printf("Memory allocation failed");
        return NULL;
      }
      if (temp != str)
      {
        strncpy(temp, str, size);
        free(str);
        str = temp;
      }
    }
    str[size] = c;
    size++;
  }
  str[size] = '\0';
  return str;
}

