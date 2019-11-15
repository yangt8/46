CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings


main: test_stack.cpp test_queue.cpp
	echo     ------------compiling test_stack.cpp and test_queue.cpp to create executable program main----------------
	g++ -ggdb -std=c++0x $(CXXFLAGS) test_stack.cpp -o test_stack
	g++ -ggdb -std=c++0x $(CXXFLAGS) test_queue.cpp -o test_queue

clean:
	echo ----------------removing executable program main--------------------
	/bin/rm test_stack
	/bin/rm test_queue
