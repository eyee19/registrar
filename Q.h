//Everett Yee
//queue interface for implementation of queue class

//
#ifndef Q_H
#define Q_H

template <typename T>
class Q
{
	public:
		virtual void Enqueue(T d) = 0;
		virtual void Dequeue() = 0;
		virtual T getQueueFront() = 0;
		virtual bool isQueueEmpty() = 0;
		virtual int getQueueSize() = 0;
		//virtual void printQueue() = 0;
};

#endif
