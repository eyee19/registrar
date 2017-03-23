//Everett Yee
//header file for the student class

#ifndef STUDENT_H
#define STUDENT_H

//student class
class Student
{
	public:
		Student();
		Student(int window, int enterQueue);
		virtual ~Student();
		int windowTime();
		int timeEnterQueue();
		int queueWait(int TimeExitQueue);
	
	private:
		int WindowTime;
		int TimeEnterQueue;			
};

//default constructor
Student:: Student()
{
	WindowTime = 0;
	TimeEnterQueue = 0;
}

//constructor, sets time at window and when they entered the queue to 0
Student:: Student(int window, int enterQueue)
{
	WindowTime = window;
	TimeEnterQueue = enterQueue;
}

//destructor
Student:: ~Student()
{
	WindowTime = 0;
	TimeEnterQueue = 0;
}

//return Time enter queue
int Student:: timeEnterQueue()
{
	return TimeEnterQueue;
}

//return students time needed at window
int Student:: windowTime()
{
	return WindowTime;
}

//returns how long student waited in queue, takes in when they left queue and subtracts it from when they entered
int Student:: queueWait(int TimeExitQueue)
{
	return (TimeExitQueue - TimeEnterQueue);
}
#endif