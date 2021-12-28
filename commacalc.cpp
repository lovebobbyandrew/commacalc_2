// Bobby Love
// December 23, 2021
// GNU GPL

#include <algorithm>
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

std::string InsertAsterisk(const std::string& input_string) {
  bool period_found;
  std::string copy_string = input_string;
  for (long unsigned int i = 0; i < copy_string.length(); ++i) { // Inserts 1 asterisk between number/parenthesis and bang/number/parenthesis
    if (isdigit(copy_string[i]) || '.' == copy_string[i] ||
        ')' == copy_string[i]) {
      if (copy_string.length() > i + 1) { // Prevents out of bounds indexing.
        if ('(' == copy_string[i + 1]) {
          copy_string.insert(i + 1, "*");
        }
      }
      if (copy_string.length() > i + 2) { // Prevents out of bounds indexing.
        for (long unsigned int j = i + 1; j < copy_string.length(); ++j) {
          if (isspace(copy_string[j])) {
            if (isdigit(copy_string[j + 1]) || '.' == copy_string[j + 1] ||
                '-' == copy_string[j + 1] || '(' == copy_string[j + 1] ||
                '!' == copy_string[j + 1]) {
              copy_string.insert(j + 1, "*");
              break;
            } 
          } else break;
        }
      }
    }
  }
  for (long unsigned int i = 0; i < copy_string.length(); ++i) {
    period_found = false;
    if ('.' == copy_string[i] || isdigit(copy_string[i])) {
      if ('.' == copy_string[i]) {
        period_found = true;
      }
      for (long unsigned int j = i + 1; j < copy_string.length(); ++j) {
        if ('.' != copy_string[j] && !isdigit(copy_string[j])) {
          break;
        } else if ('.' == copy_string[j] && period_found) {
          copy_string.insert(j, 1, '*');
          break;
        } else if ('.' == copy_string[j]) {
          period_found = true;
        }
      }
    }
  }
  return copy_string;
}

std::string RemoveSpace(const std::string& input_string) {
  std::string copy_string = input_string;
  copy_string.erase(std::remove_if(copy_string.begin(), copy_string.end(),
                    isspace), copy_string.end());
  return copy_string;
}

std::string KeepChangeChange(const std::string& input_string) {
  std::string copy_string = input_string;
  for (long unsigned int i = 0; i < copy_string.length(); ++i) {
    if (i + 2 < copy_string.length()) {
      if ('-' == copy_string[i] && '-' == copy_string[i + 1] &&
        (isdigit(copy_string[i + 2]) || '.' == copy_string[i + 2] ||
          '(' == copy_string[i + 2])) {
        copy_string.replace(i, 2, 1, '+'); // If adjacent to a number or '(', replace 2 '-' with 1 '+'.
      }
    }
  }
  return copy_string;
}

std::string InsertPlus(const std::string& input_string) {
  std::string copy_string = input_string;
  for (long unsigned int i = 0; i < copy_string.length(); ++i) {
    if (copy_string.length() > i + 2) {
      if ((')' == copy_string[i] || '.' == copy_string[i] ||
          isdigit(copy_string[i])) && '-' == copy_string[i + 1] &&
          ('(' == copy_string[i + 2] || '!' == copy_string[i + 2] ||
            '.' == copy_string[i + 2] || isdigit(copy_string[i + 2]))) {
        copy_string.insert(i + 1, 1, '+');
        ++i;
      }
    }
  }
  return copy_string;
}

std::string InsertZero(const std::string& input_string) {
  std::string copy_string = input_string;
  if ('.' == copy_string[0]) {
    copy_string.insert(0, 1, '0');
  }
  for (long unsigned int i = 0; i < copy_string.length(); ++i) {
    if (copy_string.length() > i + 1) {
      if ('.' == copy_string[i]) {
        if ('(' == copy_string[i + 1] || ')' == copy_string[i + 1] ||
            '^' == copy_string[i + 1] || '!' == copy_string[i + 1] ||
            '*' == copy_string[i + 1] || '/' == copy_string[i + 1] ||
            '%' == copy_string[i + 1] || '+' == copy_string[i + 1] ||
            '-' == copy_string[i + 1]) {
          copy_string.insert(i + 1, 1, '0');
          ++i;
        }
      }
    }
    if (i - 1 >= 0) {
      if ('.' == copy_string[i]) {
        if ('(' == copy_string[i - 1] || ')' == copy_string[i - 1] ||
            '^' == copy_string[i - 1] || '!' == copy_string[i - 1] ||
            '*' == copy_string[i - 1] || '/' == copy_string[i - 1] ||
            '%' == copy_string[i - 1] || '+' == copy_string[i - 1] ||
            '-' == copy_string[i - 1]) {
          copy_string.insert(i, 1, '0');
          ++i;
        }
      }
    }
  }
  if ('.' == copy_string[copy_string.length() - 1]) {
    copy_string.insert(copy_string.length(), 1, '0');
  }
  return copy_string;
}
} // End of "commacalc::format" namespace.

namespace error_check { // Error checking functions.

bool LonePeriod(const std::string& input_string) {
  bool error = false;
  if (2 == input_string.length()) {
    if(('.' == input_string[0] && '-' == input_string[1]) ||
        ('-' == input_string[0] && '.' == input_string[1])) {
      error = true;
    }
  }
  if (1 == input_string.length()) {
    if ('.' == input_string[0]) {
      error = true;
    }
  }
  if (1 < input_string.length()) {
    if ('.' == input_string[0] && isspace(input_string[1])) {
      error = true;
    }
    if ('.' == input_string[input_string.length() - 1] &&
        isspace(input_string[input_string.length() - 2])) {
      error = true;
    }
  }
  for (long unsigned int i = 0; i < input_string.length(); ++i) {
    if (i >= 0 && i < input_string.length()) {
      if (isspace(input_string[i - 1]) && '.' == input_string[i] &&
          isspace(input_string[i + 1])) {
        error = true;
        break;
      }
    }
  }
  return error;
}

bool ErrorCheck(const std::string& input_string) {
  bool error = false;
  do {
  error = EmptyString(input_string);
  std::cout << "EmptyString return is " << error << std::endl;
  if (error) break;
  error = CheckCharacters(input_string);
  std::cout << "CheckCharacters return is " << error << std::endl;
  if (error) break;
  error = CheckBeginEnd(input_string);
  std::cout << "CheckBeginEnd return is " << error << std::endl;
  if (error) break;
  error = CheckNeighbor(input_string);
  std::cout << "CheckNeighbor return is: " << error << std::endl;
  if (error) break;
  error = CheckParenPairs(input_string);
  std::cout << "CheckParenPairs return is: " << error << std::endl;
  if (error) break;
  } while (error);
  return error;
}

bool EmptyString(const std::string& input_string) {
  bool error = false;
  if (0 == input_string.length()) {
    error = true;
  }
  return error;
}

bool CheckBeginEnd(const std::string& input_string) {
  bool error = false;
  long unsigned int final_index = input_string.length() - 1;
  if (')' == input_string[0] || '^' == input_string[0] ||
      '*' == input_string[0] || '/' == input_string[0] ||
      '%' == input_string[0] || '+' == input_string[0]) {
    error = true;
  }
  if ('(' == input_string[final_index] || '^' == input_string[final_index] ||
      '!' == input_string[final_index] || '*' == input_string[final_index] ||
      '/' == input_string[final_index] || '%' == input_string[final_index] ||
      '+' == input_string[final_index] || '-' == input_string[final_index]) {
      error = true;
  }
  return error;
}

bool CheckCharacters(const std::string& input_string) {
  bool error = false;
  for (long unsigned int i = 0; i < input_string.length(); ++i) {
    if ('(' != input_string[i] && ')' != input_string[i] &&
        '^' != input_string[i] && '!' != input_string[i] &&
        '*' != input_string[i] && '/' != input_string[i] &&
        '%' != input_string[i] && '+' != input_string[i] &&
        '-' != input_string[i] && '.' != input_string[i] &&
        !isdigit(input_string[i])) {
      error = true;
      break;
    }
  }
  return error;
}

bool CheckNeighbor(const std::string& input_string) {
  bool error = false;
  for (long unsigned int i = 0; i < input_string.length(); ++i) {
    if (input_string.length() > i + 1) { // Prevents out of bounds indexing.
      switch (input_string[i]) {
        case '(':
          if ('(' != input_string[i + 1] && '!' != input_string[i + 1] &&
              '-' != input_string[i + 1] && '.' != input_string[i + 1] &&
              !isdigit(input_string[i + 1])) {
            error = true;
          }
          break;
        case ')':
          if (')' != input_string[i + 1] && '^' != input_string[i + 1] &&
              '*' != input_string[i + 1] && '/' != input_string[i + 1] &&
              '%' != input_string[i + 1] && '+' != input_string[i + 1] &&
              '-' != input_string[i + 1]) {
            error = true;
          }
          break;
        case '^':
          if ('(' != input_string[i + 1] && '!' != input_string[i + 1] &&
              '-' != input_string[i + 1] && '.' != input_string[i + 1] &&
              !isdigit(input_string[i + 1])) {
            error = true;
          }
          break;
        case '!':
          if ('(' != input_string[i + 1] && '.' != input_string[i + 1] &&
              !isdigit(input_string[i + 1])) {
            error = true;
          }
          break;
        case '*':
          if ('(' != input_string[i + 1] && '!' != input_string[i + 1] &&
              '-' != input_string[i + 1] && '.' != input_string[i + 1] &&
              !isdigit(input_string[i + 1])) {
            error = true;
          }
          break;
        case '/':
          if ('(' != input_string[i + 1] && '!' != input_string[i + 1] &&
              '-' != input_string[i + 1] && '.' != input_string[i + 1] &&
              !isdigit(input_string[i + 1])) {
            error = true;
          }
          break;
        case '%':
          if ('(' != input_string[i + 1] && '!' != input_string[i + 1] &&
              '-' != input_string[i + 1] && '.' != input_string[i + 1] &&
              !isdigit(input_string[i + 1])) {
            error = true;
          }
          break;
        case '+':
          if ('(' != input_string[i + 1] && '!' != input_string[i + 1] &&
              '-' != input_string[i + 1] && '.' != input_string[i + 1] &&
              !isdigit(input_string[i + 1])) {
            error = true;
          }
          break;
        case '-':
          if ('(' != input_string[i + 1] && '!' != input_string[i + 1] &&
              '.' != input_string[i + 1] && !isdigit(input_string[i + 1])) {
            error = true;
          }
          break;
        case '.':
          if (')' != input_string[i + 1] && '^' != input_string[i + 1] &&
              '*' != input_string[i + 1] && '/' != input_string[i + 1] &&
              '%' != input_string[i + 1] && '+' != input_string[i + 1] &&
              '-' != input_string[i + 1] && !isdigit(input_string[i + 1])) {
            error = true;
          }
          break;
        default:
          if (isdigit(input_string[i])) {
            if (')' != input_string[i + 1] && '^' != input_string[i + 1] &&
                '*' != input_string[i + 1] && '/' != input_string[i + 1] &&
                '%' != input_string[i + 1] && '+' != input_string[i + 1] &&
                '-' != input_string[i + 1] && '.' != input_string[i + 1] &&
                !isdigit(input_string[i + 1])) {
              error = true;
            }
          } else error = true; // If input_string[i] is not an operator or a digit, then it is an invalid character.
          break;
      }
    }
    if (true == error) {
      break;
    }
  }
  return error;
}

bool CheckParenPairs(std::string copy_string) {
  bool error = false;
  bool loop = true;
  bool left_paren;
  bool right_paren;
  unsigned int left_paren_count = 0;
  unsigned int right_paren_count = 0;
  for (long unsigned int i = 0; i < copy_string.length(); ++i) {
    if ('(' == copy_string[i]) {
      ++left_paren_count;
    }
    if (')' == copy_string[i]) {
      ++right_paren_count;
    }
  }
  do {
    left_paren = false;
    right_paren = false;
    for (long unsigned int i = 0; i < copy_string.length(); ++i) {
      left_paren = false;
      right_paren = false;
      if ('(' == copy_string[i]) { // If a left parenthesis is found, search for a right parenthesis.
        left_paren = true;
        for (long unsigned int j = i + 1; j < copy_string.length(); ++j) {
          if (')' == copy_string[j]) {
            right_paren = true;
            copy_string[j] = '~'; // Remove right parenthesis to prevent recounting.
            break;
          }
        }
        if (true == left_paren && false == right_paren) {
          error = true;
          break;
        }
      }
      if (copy_string.length() - 1 == i || true == error) {
        loop = false;
      }
    }
  } while (loop);
  if (left_paren_count != right_paren_count) { // Accounts for right parenthesis that appear before left parenthesis.
    error = true;
  }
  return error;
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