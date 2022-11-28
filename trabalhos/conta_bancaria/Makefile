UTIL=bankAccount.c binaryTree.c linkedList.c
MAIN=main.c
BINARY=main

all:
	gcc -Wall -g $(UTIL) $(MAIN) -o $(BINARY)

run:
	./$(BINARY)

debug:
	gcc -DDEBUG -Wall $(MAIN) $(UTIL) -o $(BINARY)

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)

zip:
	zip conta_bancaria.zip Makefile main.c linkedList.c bankAccount.h bankAccount.c binaryTree.h binaryTree.c
clean:
	@rm *.o
