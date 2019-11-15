CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings


main: TestAndMeasure.cpp
	echo     ------------compiling TestAndMeasure.cpp to create executable program main----------------
	g++ -ggdb -std=c++0x $(CXXFLAGS) TestAndMeasure.cpp -o main

clean:
	echo ----------------removing executable program main--------------------
	/bin/rm main
