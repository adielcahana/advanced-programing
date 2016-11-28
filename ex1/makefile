a.out: main.o Bfs.o Map.o
	g++ -g -Werror -o a.out main.o Bfs.o Map.o

main.o: main.cpp Map.h
	g++ -g -Werror -c -o main.o main.cpp

Map.o: Map.cpp Map.h
	g++ -g -Werror -c -o Map.o Map.cpp	

Bfs.o: Bfs.cpp Bfs.h
	g++ -g -Werror -c -o Bfs.o Bfs.cpp	

clean:
	rm -f *.o a.out
