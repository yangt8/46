CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings


main: main.cpp
	echo     ------------compiling main.cpp to create executable program main----------------
	g++ -ggdb -std=c++0x $(CXXFLAGS) main.cpp -o main

clean:
	echo ----------------removing executable program main--------------------
	/bin/rm main
