#ifndef VALIDATION
  #include "boolean.h"

  #define VALIDATION
  
  /*
  This function will validate that the amount of numbers inputted by the user is the needed amount- the MATRIX_SIZE squared.
  Will raise an error if the number doesn't match.

  Input-
    int* arr: The inputted numbers.
  */
  void validate_length(int* arr);
  
  /*
  This function will validate the uniqueness of all of the numbers inputted by the user.
  This is done by first sorting a copy of the inputted numbers, are comparing the surrounding numbers
  (to avoid higher time complexities if all numbers are compared to all other numbers).

  Input-
    int* arr: The inputted numbers by the user.
  Output-
    bool: true if all numbers are unique, false otherwise.
  */
  bool validate_uniqueness(int* arr);
  
  /*
  This function will validate that all numbers inputted by the user are between 1 and the size of the matrix squared.

  Input-
    int* arr: The inputted numbers.
  Output-
    bool: true if all numbers are within the described range, false otherwise.
  */
  bool validate_num_range(int* arr);
  
  /*
  This function will perform validations on the inputted numbers by the user.
  If according to the exercise they should cause the program to stop running- an error will be raised.
  
  Input-
    int* arr: The numbers inputted by the user.
  Output-
    bool: true if the input is valid, false otherwise.
  */
  bool validate_input(int* arr);
#endif
