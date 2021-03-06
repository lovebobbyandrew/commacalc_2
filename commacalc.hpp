// Bobby Love
// December 23, 2021
// GNU GPL

#include <deque>
#include <string>

namespace commacalc { // All custom functions.

int Option(std::string); // Uses input string to determine user's choice.

void StoreEquation(std::deque<std::string>&, const std::string&); // Stores equation string into dequeue.

  namespace input_output { // I/O functions.

  void PrintMenu(void); // Prints menu options.

  char* ReadInput(const int&); // Reads char* array from stdin and returns nullptr upon failure.

  void ClearStdin(void); // Clears input buffer upon ReadInput failure.

  void PrintHistory(const std::deque<std::string>&); // Prints the history dequeue.
  } // End of "commacalc::input_output" namespace.

  namespace format { // String formatting functions.

  std::string InsertAsterisk(const std::string&); // Inserts a single asterisk at the beginning of whitespace flanked by numbers or between two period separated numbers.

  std::string RemoveSpace(const std::string&); // Outputs a whitespaceless copy of the input string.

  std::string KeepChangeChange(const std::string&); // Replaces double '-' with a single '+' when found to the left of a number or '('.

  std::string InsertPlus(const std::string&); // Replaces individual '-' that are flanked by numbers or parenthesises with "+-".

  std::string InsertZero(const std::string&); // Inserts a '0' before or after any decimal adjacent to an operator.
  } // End of "commacalc::format" namespace.

  namespace error_check { // Error checking functions.

  bool LonePeriod(const std::string&); // Searches for lone periods in input string.

  bool PeriodEnd(const std::string&); // Checks if expression ends with "*.".

  bool ErrorCheck(const std::string&); // Calls other error checking functions.

  bool EmptyString(const std::string&); // Checks if input string is empty.

  bool CheckCharacters(const std::string&); // Checks if any invalid characters are present in input string.

  bool CheckBeginEnd(const std::string&); // Checks if an invalid operator is located at the beggining or end of the input string. 

  bool CheckNeighbor(const std::string&); // Checks if adjacent indexes are valid (whitespace must have been removed prior).

  bool CheckParenPairs(std::string); // Checks that all left parenthesis have a matching right parenthesis.

  bool IsInteger(const double&); // Checks that input is an integer.

  bool IsNatural(const double&); // Checks that input is natural.
  } // End of "commacalc::error_check" namespace.

  namespace operation { // Basic math functions.

  double Exponentiation(double, double);

  int Factorial(int); // SAME PRECEDENCE AS EXPONENT. NOTE: CAN ONLY BE USED ON NATURAL NUMBERS. MAKE A FUNCTION THAT CAN DETERMINE WHETHER THE INPUT IS A NATURAL NUMBER.

  double Multiplication(double, double); // 

  double Division(double, double);

  int Modulo(int, int); // SAME PRECEDENCE AS MULTIPLY AND DIVIDE. NOTE: CAN ONLY BE USED ON INTEGERS. MAKE A FUNCTION THAT CAN DETERMINE WHETHER THE INPUTS ARE INTEGERS OR NOT.

  double Addition(double, double); // Subtraction is negative addtion.
  } // End of "commacalc::operation" namespace.
} // End of "commacalc" namespace.