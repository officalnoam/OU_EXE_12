#ifndef INPUT_UTILS
  #define INPUT_UTILS
  #define BUFFER_SIZE 50
  
  /*
  This function will get a string from the user. Validations of the string will not be performed. There isn't an upper limit on the size of the
  string that can be received, except for the need for memory that can store it.
  The string input will stop after EOF is inputted).
  
  Output-
    char*: the string that the user inputted. 
  */
  char* get_string_from_user();
#endif
