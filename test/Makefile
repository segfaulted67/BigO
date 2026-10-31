compile: test.cpp
	g++ -g -Wall -Wextra -Werror -Wsign-conversion -pedantic -std=c++11 -I../ -o test test.cpp

valgrind: compile
	valgrind ./test

test: compile
	./test

clean:
	rm test
