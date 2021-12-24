# Bobby Love
# December 23, 2021
# GNU GPL

PROGRAM := commacalc

SOURCES := $(wildcard *.cpp)
HEADERS := $(wildcard *.hpp)
OBJS := $(SOURCES:.cpp=.o)

CXXFLAGS := -std=c++11 -Wall -Werror

$(PROGRAM): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

main.o: main.cpp commacalc.hpp
commacalc.o: commacalc.cpp commacalc.hpp

.PHONY: clean
clean:
	rm -f $(PROGRAM) $(OBJS)