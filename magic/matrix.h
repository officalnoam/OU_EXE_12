#ifndef MATRIX
  #include "boolean.h"
 
  #define MATRIX
  
  void free_matrix(int** matrix);
  int** create_matrix(int* arr);
  void print_matrix(int** matrix);
  bool check_rows(int** matrix, int sum);
  bool check_columns(int** matrix, int sum);
  bool check_diagonals(int** matrix, int sum);
  bool is_magic(int** matrix);
#endif
