// Bobby Love
// December 23, 2021
// GNU GPL

namespace commacalc { // All custom functions.

  namespace input_output { // String I/O functions.

  } // End of "commacalc::input_output" namespace.

  namespace format { // String formatting functions.

  } // End of "commacalc::format" namespace.

  namespace error_check { // Error checking functions.

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