#include "input_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  printf("Please input the numbers in the matrix being checked.\n There needs to be %d numbers inputted, seperated by one or more whitespaces:\n", \
         MATRIX_SIZE * MATRIX_SIZE);
  while ((c=getchar()) != EOF)
  {
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

