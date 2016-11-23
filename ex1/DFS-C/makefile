a.out: main.o Binary_tree.o
	g++ -Werror -o a.out main.o Binary_tree.o

main.o: main.cpp 
	g++ -Werror -c -o main.o main.cpp

Binary_tree.o: Binary_tree.cpp Binary_tree.h
	g++ -Werror -c -o Binary_tree.o Binary_tree.cpp

clean:
	rm -f *.o a.out
