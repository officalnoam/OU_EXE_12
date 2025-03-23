#include "matrix.h"
#include "magic.h"
#include <stdio.h>
#include <stdlib.h>

/*
This function will completely free all pointers in the matrix.
It will first free all of the rows that aren't null and will then free the pointer to the matrix itself.
*/
void free_matrix(int** matrix)
{
  int i;
  for (i = 0; i < MATRIX_SIZE; i++)
  {
    /*If the row is initialized- free it.*/
    if (matrix[i] != NULL)
      free(matrix[i]);
  }
  free(matrix);
}

/*
Create a matrix based on a passed array of integers.
Will first create an array to an array of integers- and will then create all of those arrays of integers.
After the creation, it will iterate over all rows, and all items within the row and assign to them the correct
integer from arr.
*/
int** create_matrix(int* arr)
{
  int i;
  int j;
  int** matrix = (int**) malloc(MATRIX_SIZE * sizeof(int*));

  if (matrix == NULL)
    return NULL;

  /*Set all pointers within the matrix to NULL, so that if there is a need to free the matrix
  after memory allocation failed, only previously initialized rows will be freed*/
  for (i = 0; i < MATRIX_SIZE; i++)
    matrix[i] = NULL;
  
  /*Allocate memory for every row in the matrix. If any fail- free all of rows and the matrix itself.*/
  for (i = 0; i < MATRIX_SIZE; i++)
  {
    matrix[i] = (int*) malloc(MATRIX_SIZE * sizeof(int));
    if (matrix[i] == NULL)
    {
      free(matrix);
      return NULL;
    }
  }
  
  for (i = 0; i < MATRIX_SIZE; i++)
  {
    for (j = 0; j < MATRIX_SIZE; j++)
      matrix[i][j] = arr[i * MATRIX_SIZE + j];
  }
  return matrix;
}

/*
This function goes over each row in the matrix- and prints its items,
so that the entire matrix is printed.
*/
void print_matrix(int** matrix)
{
  int i;
  int j;
  
  for (i = 0; i < MATRIX_SIZE; i++)
  {
    for (j = 0; j < MATRIX_SIZE; j++)
      printf("%d ", matrix[i][j]);
    printf("\n");
  }
}

/*
Will go over each row and sum the items within. If the sum isn't equal to sum, return false.
*/
bool check_rows(int** matrix, int sum)
{
  int i;
  int j;
  int temp_sum;
  
  for (i = 0; i < MATRIX_SIZE; i++)
  {
    temp_sum = 0;
    for (j = 0; j < MATRIX_SIZE; j++)
      temp_sum = temp_sum + matrix[i][j];
    
    if (temp_sum != sum)
      return false;
  }
  return true;
}

/*
Will go over each column and sum the items within. If the sum isn't equal to sum, return false.
*/
bool check_columns(int** matrix, int sum)
{
  int i;
  int j;
  int temp_sum;

  for (i = 0; i < MATRIX_SIZE; i++)
  {
    temp_sum = 0;
    for (j = 0; j < MATRIX_SIZE; j++)
      temp_sum = temp_sum + matrix[j][i];

    if (temp_sum != sum)
      return false;
  }
  return true;
}

/*
Will go over each diagonals and sum the items within. If the sum isn't equal to sum, return false.
*/
bool check_diagonals(int** matrix, int sum)
{
  int i;
  int temp_sum1 = 0;
  int temp_sum2 = 0;
  
  for (i = 0; i < MATRIX_SIZE; i++)
  {
    temp_sum1 = temp_sum1 + matrix[i][MATRIX_SIZE - i - 1];
    temp_sum2 = temp_sum2 + matrix[MATRIX_SIZE - i - 1][i];
  }
  
  if (temp_sum1 == sum && temp_sum2 == sum)
    return true;
  return false;
}

/*
Check the sum of the first row in the matrix.
If any row, column or diagonal has a different sum- return false.
*/
bool is_magic(int** matrix)
{
  int i;
  int sum = 0;
  
  for (i = 0; i < MATRIX_SIZE; i++)
    sum = sum + matrix[0][i];
  
  if (check_rows(matrix, sum) && check_columns(matrix, sum) && check_diagonals(matrix, sum))
    return true;
  return false;
}
