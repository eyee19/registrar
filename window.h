//Everett Yee
//header file for the window class

#ifndef WINDOW_H
#define WINDOW_H


//window class
class Window
{
	public:
		Window();
		virtual ~Window();
		void canTakeStudent(int time);
		void getStudent(int windowTime, int studentLeave);
		void resetIdle();
		int getMaxIdle();
		bool isOpen();
		
		int idle;
	
	private:
		int maxIdle;
		int studentLeaveQueue;
		int studentWindowTime;
		bool open;
};

//Constructor, sets idle to zero and open to true
Window:: Window()
{
	idle = 0;
	open = true;
}

//Destructor
Window:: ~Window()
{
	idle = 0;
	maxIdle = 0;
	open = 0;
	studentLeaveQueue = 0;
	studentWindowTime = 0;	
}

//can take student, takes as argument time as checks to see if window can be opened or is still busy
void Window:: canTakeStudent(int time)
{
	//for if the student has visited the window for his/her allocated time, opens window
	if ((studentLeaveQueue + studentWindowTime) == time)
	{
		open = true;
	}
	else
	{
		open = false;
	}
}

//get student, gets how long student needs to be at the window and when they left the queue
void Window:: getStudent(int windowTime, int studentLeave)
{
	studentLeaveQueue = studentLeave;
	studentWindowTime = windowTime;
	open = false;
}

//reset max idle, sets maxIdle if the new idle time is greater than the one before
void Window:: resetIdle()
{
	if (idle > maxIdle)
	{
		maxIdle = idle;
		idle = 0;
	}
}

//return maxIdle
int Window:: getMaxIdle()
{
	return maxIdle;
}

//returns boolean if window is open
bool Window:: isOpen()
{
	return open;	
}
#endif