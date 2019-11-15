CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings


main: testHash.cpp
	echo     ------------compiling testHash.cpp to create executable program main----------------
	g++ -ggdb -std=c++0x $(CXXFLAGS) testHash.cpp -o main

clean:
	echo ----------------removing executable program main--------------------
	/bin/rm main
