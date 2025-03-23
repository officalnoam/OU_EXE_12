#ifndef STRING_UTILS
  #include "boolean.h"
  
  #define STRING_UTILS
  #define LAST_ITEM -1
  
  /*
  This function checks if a char is a whitespace- including a tab or newline.

  Input-
    char c: The char being checked.
  Output-
    bool: true if c is a whitespace, otherwise false.
  */
  bool is_char_whitespace(char c);
  
  /*
  This function checks if a char is a number.

  Input-
    char c: The char being checked.
  Output-
    bool: true if c is a number, false otherwise.
  */
  bool is_char_numeric(char c);
  
  /*
  This function will parse an integer from a string starting from a specific index.

  Input-
    char* str: The string being parsed from.
    int* index_p: A pointer to the index to start the parsing from.
  Output-
    jnt: The parsed number.
  */
  int parse_int_from_substring(char* str, int* index_p);
  
  /*
  This function will receive a string, and parse from it all numbers seperated by whitespaces- and reeturn a list of those numbers in order.
  
  Input-
    char* str: The string being parsed
  
  Output-
    int*: The list of integers within the string.
  */
  int* parse_ints_from_string(char* str);
#endif 
