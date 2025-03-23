#ifndef MAGIC
  #define MAGIC
  #define MATRIX_SIZE 5  
  
  /*
  This function serves as a teardown for all the manually allocated memory throughout the program.
  If a pointer is not NULL, will free the memory.
  
  Input-
    char* str: The string inputted by the user during the program.
    int* nums: The list of integers within the string.
    int** matrix: The created matrix.
  */
  void free_pointers(char* str, int* nums, int** matrix);
#endif
