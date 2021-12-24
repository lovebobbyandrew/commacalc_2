// Bobby Love
// December 23, 2021
// GNU GPL

#include <cmath>

namespace commacalc { // All original functions.

  namespace input_output { // String I/O functions.

  } // End of "commacalc::input_output" namespace.

  namespace format { // String formatting functions.

  } // End of "commacalc::format" namespace.

  namespace error_check { // Error checking functions.

  } // End of "commacalc::error_check" namespace.

  namespace operation { // Basic math functions.

  double Exponentiation(double base, double exponent) {
    return pow(base, exponent);
  }

  double Factorial(int argument) {
    return 0; // Temporary to ward off compilier errors.
  }

  double Multiplication(double multiplicand, double multiplier) {
  return multiplicand * multiplier;
  }

  double Division(double dividend, double divisor) {
    return dividend / divisor;
  }

  int Modulo(int dividend, int divisor) {
    return dividend % divisor;
  }

  double Addition(double addend, double augend) {
    return addend + augend;
  }
  } // End of "commacalc::operation" namespace.
} // End of "commacalc" namespace.