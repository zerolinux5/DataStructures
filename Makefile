CC = g++
CFLAGS = -Wall
TARGETS = nodeTest doubleNodeTest queueTest linkedListTest priorityQueueTest stackTest graphTest

all: $(TARGETS)

nodeTest: node.h nodeTest.cpp
	$(CC) $(CFLAGS) -o nodeTest nodeTest.cpp node.cpp

doubleNodeTest: doubleNode.h doubleNodeTest.cpp
	$(CC) $(CFLAGS) -o doubleNodeTest doubleNodeTest.cpp doubleNode.cpp

queueTest: node.h queue.h queueTest.cpp
	$(CC) $(CFLAGS) -o queueTest queueTest.cpp queue.cpp node.cpp

linkedListTest: doubleNode.h linkedList.h linkedListTest.cpp
	$(CC) $(CFLAGS) -o linkedListTest linkedListTest.cpp linkedList.cpp doubleNode.cpp

priorityQueueTest: node.h priorityQueue.h priorityQueueTest.cpp
	$(CC) $(CFLAGS) -o priorityQueueTest priorityQueueTest.cpp priorityQueue.cpp node.cpp

stackTest: node.h stack.h stackTest.cpp
	$(CC) $(CFLAGS) -o stackTest stackTest.cpp stack.cpp node.cpp

graphTest: node.h doubleNode.h queue.h linkedList.h graph.h graphTest.cpp
	$(CC) $(CFLAGS) -o graphTest graphTest.cpp graph.cpp linkedList.cpp queue.cpp doubleNode.cpp node.cpp

clean:
	rm $(TARGETS)