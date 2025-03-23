#include "matrix.h"
#include "magic.h"
#include <stdio.h>
#include <stdlib.h>

/*
This function will completely free the memory of the matrix.

Input-
  int** matrix: The matrix being freed.
*/
void free_matrix(int** matrix)
{
  int i;
  for (i = 0; i < MATRIX_SIZE; i++)
  {
    if (matrix[i] != NULL)
      free(matrix[i]);
  }
  free(matrix);
}

/*
This function will create a matrix.

Input-
  int* arr: The values that will be assigned to the matrix.
Output-
  int** matrix: The created matrix.
*/
int** create_matrix(int* arr)
{
  int i;
  int j;
  int** matrix = (int**) malloc(MATRIX_SIZE * sizeof(int*));

  if (matrix == NULL)
    return NULL;

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
This function prints a passed matrix.

Input-
  int** matrix: The matrix.
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
Check if the sums of all rows of the matrix are equal to the sum.

Input-
  int** matrix: The matrix
  int sum: The sum the rows are being compared to.
Output-
  bool: true if all of the sums of the rows are equal to sum, false otherwise.
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
Check if the sums of all columns of the matrix are equal to the sum.
Input-
  int** matrix: The matrix.
  int sum: The sum the columns are being compared to.
Output-
  bool: true if all of the sums of the columns are equal to sum, false otherwise.
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
Check if the sums of all both diagonals of the matrix are equal to the sum.
Input-
  int** matrix: The matrix.
  int sum: The sum the columns are being compared to.
Output-
  bool: true if both of the sums of the diagonals are equal to sum, false otherwise.
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
This function will check if a passed matrix is a magic square.

Input-
  int** matrix: The matrix.
Output-
  bool: true if the matrix is a magic square, false otherwise.
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
