CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings


kruskals: kruskals.cpp genGraph.cpp
	echo     ------------compiling kruskals.cpp----------------
	g++ -ggdb -std=c++0x $(CXXFLAGS) kruskals.cpp -o kruskals
	g++ -std=c++11 genGraph.cpp -o genGraph

clean:
	echo ----------------removing executable program--------------------
	/bin/rm kruskals
	/bin/rm genGraph