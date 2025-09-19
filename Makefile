CXX = g++
CXXFLAGS = -std=c++17 -Wall -Werror -Wpedantic

all: test

test: test.cpp
	$(CXX) $(CXXFLAGS) test.cpp -o test

clean:
	rm *.o test
