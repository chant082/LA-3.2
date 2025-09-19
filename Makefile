CXX = g++
CXXFLAGS = -std=c++17 -Wall -Werror -Wpedantic

all: test

test: test.cpp functions_to_implement.cpp
	$(CXX) $(CXXFLAGS) test.cpp functions_to_implement.cpp -o test

clean:
	rm *.o test
