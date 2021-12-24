// Bobby Love
// December 23, 2021
// GNU GPL

#include <cmath>
#include "commacalc.hpp"
#include <iostream>
#include <limits>

namespace commacalc { // All original functions.

int Option(std::string input_string) {
  int choice;
  std::string input_copy = input_string;
  for (long unsigned int i = 0; i < input_copy.length(); ++i) { // Capitalize all letters in the string.
    input_copy[i] = std::toupper(input_copy[i]);
  }
  if ("EXIT" == input_copy) {
    choice = 3;
  } else if ("HISTORY" == input_copy) {
    choice = 2;
  } else choice = 1;
  return choice;
}

void StoreEquation(std::deque<std::string>& history_deque, const std::string& equation) {
  if (history_deque.size() < 10) {
    history_deque.push_front(equation);
  } else { // Prevents dequeue from growing greater than 10 indexes large.
    history_deque.pop_back();
    history_deque.push_front(equation);
  }
}

namespace input_output { // I/O functions.

void PrintMenu(void) {
  std::cout << "Type expression to calculate result." << std::endl;
  std::cout << "Type \"HISTORY\" to show history." << std::endl;
  std::cout << "Type \"EXIT\" to exit program." << std::endl;
}

char* ReadInput(const int& max_length) {
  char* input_array = new char[max_length];
  if (std::cin.getline(input_array, max_length).fail()) { // If failbit is true, then input array is of invalid length.
    delete[] input_array;
    input_array = nullptr;
    ClearStdin(); // Clear input buffer.
  }
  return input_array;
}

void ClearStdin(void) {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void PrintHistory(const std::deque<std::string>& history_deque) {
  for (long unsigned int i = 0; i < history_deque.size(); ++i) {
    std::cout << history_deque.at(i) << std::endl;
  }
}
} // End of "commacalc::input_output" namespace.

namespace format { // String formatting functions.
std::string RemoveSpace(const std::string& input_string) {
  std::string hold = "";
  return hold;
}
} // End of "commacalc::format" namespace.

namespace error_check { // Error checking functions.

bool CheckNeighbor(const std::string& input_string) {
  return false;
}
} // End of "commacalc::error_check" namespace.

namespace operation { // Basic math functions.

double Exponentiation(const double& base, const double& exponent) {
   return pow(base, exponent);
}

double Factorial(const int& argument) {
  return 0; // Temporary to ward off compilier errors.
}

double Multiplication(const double& multiplicand, const double& multiplier) {
  return multiplicand * multiplier;
}

double Division(const double& dividend, const double& divisor) {
  return dividend / divisor;
}

int Modulo(const int& dividend, const int& divisor) {
  return dividend % divisor;
}

double Addition(const double& addend, const double& augend) {
    return addend + augend;
}
} // End of "commacalc::operation" namespace.
} // End of "commacalc" namespace.