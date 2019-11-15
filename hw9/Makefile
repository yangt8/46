CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings


dijkstras: dijkstras.cpp genGraph.cpp
	echo     ------------compiling dijkstras.cpp----------------
	g++ -ggdb -std=c++0x $(CXXFLAGS) dijkstras.cpp -o dijkstras
	g++ -std=c++11 genGraph.cpp -o genGraph

clean:
	echo ----------------removing executable program--------------------
	/bin/rm dijkstras
	/bin/rm genGraph