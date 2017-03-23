//Everett Yee
//Template Queue class, uses dlist for most of the queue manipulations, uses class Q
//as its base class

#ifndef QUEUE_H
#define QUEUE_H

//uses generic doubly link lists for all of the functions for a queue
#include "dlist.h"
#include "Q.h"		//base class

//Queue class, uses Q as its base class to implement its functions
//doubly link list is used for all functions in queue
template <typename T>
class Queue: public Q<T>
{
	public:
		Queue();
		virtual ~Queue();
		void Enqueue(T d);
		void Dequeue();
		T getQueueFront();
		bool isQueueEmpty();
		int getQueueSize();
		//void printQueue();
		
	private:
		DList<T> queue; //initalize queue as doubly linked list
};

//default constructor
template <typename T>
Queue<T>:: Queue()
{
	//DList<T> queue = new DList();
}

//destructor
template <typename T>
Queue<T>:: ~Queue()
{
	while (!isQueueEmpty())
	{
		Dequeue();
	}	
}

//Enqueue, uses addBack from doubly linked list
template <typename T>
void Queue<T>:: Enqueue(T d)
{
	queue.addBack(d);
}

//Dequeue, uses removeFront from doubly linked last
template <typename T>
void Queue<T>:: Dequeue()
{
	queue.removeFront();
}

//gets first item in the queue, uses getFront from doubly linked list
template <typename T>
T Queue<T>:: getQueueFront()
{
	return queue.getFront();	
}

//checks if queue is empty, uses isEmpty from doubly linked list
template <typename T>
bool Queue<T>:: isQueueEmpty()
{
	return (queue.isEmpty());
}

//gets size of queue, uses getSize from doubly linked list
template <typename T>
int Queue<T>:: getQueueSize()
{
	return queue.getSize();
}

//prints queue, uses printList from doubly linked list. For debugging purposes
/*template <typename T>
void Queue<T>:: printQueue()
{
	queue.printList();
}*/

#endif