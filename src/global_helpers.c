#include "../includes/common_includes.h"
#include "../includes/global_helpers.h"

void error(char* msg, int line_num) {
  /*
  Shows error message in red color and exits the current process

  Params
  ======
  msg      (char*)
    : The message to be shown as error message
  line_num (int)
    : Line number
  */

  // Prints the error to screen in red color and then exits
  printf("\033[91m[Line %d] Error: %s", line_num, msg);
}

bool is_digit(char ch) {
  /*
  Checks if character is digit or not

  Params
  ======
  ch (char)
    : Single character mostly part of a longer string

  Returns
  =======
  bool
    : Checks whether the character is number or not, since '.' is not considered an alphabet by the
      standard isdigit function
  */

  return (ch >= '0' && ch <= '9') || (ch == '.');
}

bool is_alpha(char ch) {
  /*
  Checks if character is alphabet or not

  Params
  ======
  ch (char)
    : Single character mostly part of a longer string

  Returns
  =======
  bool
    : Checks whether the character is alphabet or not, since '_' is not considered a digit by the
      standard isalpha function
  */

  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch == '_');
}

bool is_alnum(char ch) {
  /*
  Checks if character is alphabet or digit or none

  Params
  ======
  char (string)
    : Single character mostly part of a longer string

  Returns
  =======
  bool
    : Checks whether the character is alphabet/digit not, since '_' is not considered an alphabet by the
      isalpha function, and '.' is not considered a digit by the standard isdigit function
  */

  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch == '_') ||
         (ch >= '0' && ch <= '9') || (ch == '.');
}
