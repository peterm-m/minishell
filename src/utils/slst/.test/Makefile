# tested ADT 
# Vector/ Stack/ Queue/ PriorityQueue/ RedBlackTree/ HashTable/ BloomFilter/ DirectedGraph/ UndirectedGraph/ WeightedUndirectedGraph
ADT ?= HashTable

# compiler settings
CC = gcc
CFLAGS =

# ADTlib directory path
LIB = ../lst

# executable program
EXEC = test

# object file
OBJS = test.o

$(ADT): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS) -L.. -l lst

.PHONY: run help clear

# run the test
run: $(ADT)
	./$(EXEC)

# run valgrind - check for memory errors
help: $(EXEC)
	valgrind valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$(EXEC)

clean:
	rm -f $(OBJS) $(EXEC)