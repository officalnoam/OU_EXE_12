#ifndef MATRIX
  #include "boolean.h"
 
  #define MATRIX
  
  /*
  This function will completely free the memory of the matrix.
  
  Input-
    int** matrix: The matrix being freed.
  */
  void free_matrix(int** matrix);

  /*
  This function will create a matrix.

  Input-
    int* arr: The values that will be assigned to the matrix.
  Output-
    int** matrix: The created matrix.
  */
  int** create_matrix(int* arr);
  /*
  This function will return the maximum length (amount of digits) that a number in the matrix can be.
  
  Output-
    int: The maximum length
  */
  int get_matrix_max_member_length();  
  /*
  This function prints a passed matrix.
  
  Input-
    int** matrix: The matrix.
  */
  void print_matrix(int** matrix);
  
  /*
  Check if the sums of all rows of the matrix are equal to the sum.

  Input-
    int** matrix: The matrix
    int sum: The sum the rows are being compared to.
  Output-
    bool: true if all of the sums of the rows are equal to sum, false otherwise.
  */
  bool check_rows(int** matrix, int sum);
  
  /*
  Check if the sums of all columns of the matrix are equal to the sum.
  Input-
    int** matrix: The matrix.
    int sum: The sum the columns are being compared to.
  Output-
    bool: true if all of the sums of the columns are equal to sum, false otherwise.
  */
  bool check_columns(int** matrix, int sum);
  
  /*
  Check if the sums of all both diagonals of the matrix are equal to the sum.
  Input-
    int** matrix: The matrix.
    int sum: The sum the columns are being compared to.
  Output-
    bool: true if both of the sums of the diagonals are equal to sum, false otherwise.
  */
  bool check_diagonals(int** matrix, int sum);
  
  /*
  This function will check if a passed matrix is a magic square.
  
  Input-
    int** matrix: The matrix.
  Output-
    bool: true if the matrix is a magic square, false otherwise.
  */
  bool is_magic(int** matrix);
#endif
