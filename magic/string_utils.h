#ifndef STRING_UTILS
  #include "boolean.h"
  
  #define STRING_UTILS
  
  bool is_char_whitespace(char c);
  bool is_char_numeric(char c);
  int parse_int_from_substring(char* str, int* index_p);
  int* parse_ints_from_string(char* str);
#endif 
