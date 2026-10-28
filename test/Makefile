compile: test.cpp
	g++ -Wall -Wextra -Werror -std=c++11 -I../ -o test test.cpp

valgrind: compile
	valgrind ./test

test: compile
	./test
