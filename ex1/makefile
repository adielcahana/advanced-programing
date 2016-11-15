a.out: grid_test.o BFS.o grid.o
	g++ -Werror -o a.out grid_test.o BFS.o grid.O

grid_test.o: grid_test.cpp grid.h
	g++ -Werror -c -o grid_test.o grid_test.cpp

BFS.o: BFS.cpp BFS.h
	g++ -Werror -c -o BFS.o BFS.cpp	

clean:
	rm -f *.o a.out
