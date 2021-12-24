// Bobby Love
// December 23, 2021
// GNU GPL

#include "commacalc.hpp"
#include <iostream>

#define MAX_LENGTH 256

using namespace commacalc;

int main() {
  bool loop = true;
  int max_length = MAX_LENGTH;
  std::string spaceless_string;
  std::string asterisk_string;
  std::deque<std::string> history_deque;
  do {
    input_output::PrintMenu();
    char* input_array = input_output::ReadInput(max_length);
    if (nullptr != input_array) {
      std::string input_string = input_array;
      switch (Option(input_string)) {
        case 1:
          asterisk_string = format::InsertAsterisk(input_string);
          spaceless_string = format::RemoveSpace(asterisk_string);
          std::cout << "input_string: \"" << input_string << "\"" << std::endl;
          std::cout << "asterisk_string: \"" << asterisk_string << "\"" << std::endl;
          std::cout << "spaceless_string: \"" << spaceless_string << "\"" << std::endl;
          StoreEquation(history_deque, input_string); // REPLACE input_string WITH equation_string
          break;
        case 2:
          input_output::PrintHistory(history_deque);
          break;
        case 3:
          loop = false;
          break;
      }
    } else std::cout << "Invalid expression." << std::endl;
  } while (loop);
  return 0;
}