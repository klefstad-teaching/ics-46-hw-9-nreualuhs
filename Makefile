CXX = g++
CXXFLAGS = -ggdb -std=c++20 -Wall -Wextra -Werror -Wfatal-errors -pedantic -Isrc

all: dijkstras_main #student_gtests

#main: src/main.cpp bst.o bstree.o avltree.o
#	$(CXX) $(CXXFLAGS) src/main.cpp -o main bst.o bstree.o avltree.o

dijkstras_main: src/dijkstras_main.cpp dijkstras.o
	$(CXX) $(CXXFLAGS) src/dijkstras_main.cpp -o dijkstras_main dijkstras.o

ladder_main: src/ladder_main.cpp ladder.o
	$(CXX) $(CXXFLAGS) src/ladder_main.cpp -o ladder_main ladder.o

dijkstras.o: src/dijkstras.cpp src/dijkstras.h
	$(CXX) $(CXXFLAGS) -c src/dijkstras.cpp -o dijkstras.o

ladder.o: src/ladder.cpp src/ladder.h
	$(CXX) $(CXXFLAGS) -c src/ladder.cpp -o ladder.o

student_gtests: gtest/student_gtests.cpp dijkstras.o ladder.o 
	$(CXX) $(CXXFLAGS) gtest/student_gtests.cpp dijkstras.o ladder.o -o student_gtests -lgtest -lgtest_main -pthread

clean:
	rm -f *.o dijkstras_main dijkstras