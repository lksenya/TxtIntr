CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11

calculator: main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f calculator
