a.out: grid_test.o BFS.o grid.o
	g++ -g -Werror -o a.out grid_test.o BFS.o grid.o

grid_test.o: grid_test.cpp grid.h
	g++ -g -Werror -c -o grid_test.o grid_test.cpp

grid.o: grid.cpp grid.h
	g++ -g -Werror -c -o grid.o grid.cpp	

BFS.o: BFS.cpp BFS.h
	g++ -g -Werror -c -o BFS.o BFS.cpp	

clean:
	rm -f *.o a.out
