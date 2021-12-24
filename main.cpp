// Bobby Love
// December 23, 2021
// GNU GPL

#include "commacalc.hpp"
#include <iostream>

#define MAX_LENGTH 50

using namespace commacalc;

int main() {
  bool loop = true;
  int max_length = MAX_LENGTH;
  do {
    input_output::PrintMenu();
    char* input_array = input_output::ReadInput(max_length);
    if (nullptr != input_array) {
      std::string input_string = input_array;
      switch (Option(input_string)) {
        case 1:
          std::cout << "Error check." << std::endl;
          break;
        case 2:
          std::cout << "Print history." << std::endl;
          break;
        case 3:
          loop = false;
          break;
      }
    } else std::cout << "Invalid expression." << std::endl;
  } while (loop);
  return 0;
}