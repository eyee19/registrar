//Everett Yee
//main 

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>

#include "queue.h"
#include "student.h"
#include "window.h"

using namespace std;

//reads from command line
int main(int argc, char ** argv)
{	
	//shows how program needs to run if command line entry was wrong
	if (argc != 2)
	{
		cout << "usage: "<< argv[0] <<  " </../nameOfFile.txt>" << endl;
	}
	//actual program
	else
	{
		string fileName = argv[1];
		ifstream file(fileName.c_str());
		
		//check if did not open
		if (!file.is_open())
		{
     	cout<< "Could not open file" << endl;
		}
    	//if file is open
    	else 
    	{
    		//greats Queue object of types students
    		Queue<Student> studentQueue;
    		    		
    		//declared variables for implementation
    		int numWindows;		//for getting number of windows
			int timeEnter;		//for when student enters queue
			int numberStudents;	//for reading when number of students arrive at a time to the queue
			int studentTimeNeeded;		//for reading in time needed at windwo
			int queueTimeTotal = 0; 	//for end calculations
			int windowsOpen;			//for simulation loop to end simulation
			int studentArr = 0;	 		//for placement into array for student wait times
			int numStudents;			//number of students total in queue
			string line;				//for reading in line
    		
    		//READ FROM FILE
    		
    		//gets number of windows
    		getline(file, line);
    		numWindows = atoi(line.c_str());			//gets first line, number of windows
    		Window* windows = new Window[numWindows];	//creates array of type window
    		
    		while (!file.eof())
    		{
    			//gets student time entered queue
    			getline(file, line);
    			timeEnter = atoi(line.c_str());
    			
    			//gets number of students who enter at specific time
    			getline(file, line);
    			numberStudents = atoi(line.c_str());
    			
    			//loop to get next lines depending on how many students entered queue at said time
    			//adds students to the queue
    			for (int i = 0; i < numberStudents; ++i)
    			{
    				getline(file, line);
    				studentTimeNeeded = atoi(line.c_str());
    				Student student(studentTimeNeeded, timeEnter); 
    				studentQueue.Enqueue(student);
    			}
    		}
    		
    		//creates int array for wait times while in the queue
    		int* studentQueueArray = new int[studentQueue.getQueueSize()];
    		numStudents = studentQueue.getQueueSize();
    		
    		//RUN SIMULATION
    		
    		//main simulation for assignment
    		for (int time = 0; time < 1000000000; ++time)
    		{	
    			//for ending the simulation, counts every window if open and if the queue is empty
    			windowsOpen = 0;
    			for (int i = 0; i < numWindows; ++i)
    			{
    				if (windows[i].isOpen() && studentQueue.isQueueEmpty())
    				{
    					++windowsOpen;
    				}
    			}
    			//end simulation if number of open windows equals total number of windows
    			if (windowsOpen == numWindows)
    			{
    				//reset idle times for all windows
    				for (int i = 0; i < numWindows; ++i)
    				{
    					windows[i].resetIdle();
    				}
    				//ends simulation
    				break;
    			}
    			
    			//for adding student to window
    			for (int i = 0; i < numWindows; ++i)
    			{
    				//checks to see if queue is not empty, if it is no need to add students to window
    				if (!studentQueue.isQueueEmpty())
    				{
    					//gets the first student's data in the queue
    					Student getStudent = studentQueue.getQueueFront();
    					//checks if window is open and if time is greater than or equal to when student entered
	    				if (windows[i].isOpen() && (time >= getStudent.timeEnterQueue()))
	    				{
		    				windows[i].resetIdle(); //reset idle
	    					windows[i].getStudent(getStudent.windowTime(), time); //puts student at the window
	    					queueTimeTotal += getStudent.queueWait(time); //add students wait time to total, for mean
	    					studentQueueArray[studentArr] = getStudent.queueWait(time);	//puts wait time in array
	    					studentQueue.Dequeue();	//dequeue student						
	    					++studentArr;		//increment position in array for next student
	    				}
    				}
    				
    				//for incrementing idle for windows without students
    				if (windows[i].isOpen())
    				{
    					++windows[i].idle;
    				}
    				
    				//freeing up window if student is ready to leave
    				if (!windows[i].isOpen())
    				{
    					windows[i].canTakeStudent(time);
    				}
    			}
    		}
    		
			//DISPLAY DATA
			
			//student mean
			cout << "Mean student Wait time: " << (float) queueTimeTotal/numStudents << endl;;
			
			//student median
			sort(studentQueueArray, studentQueueArray + numStudents);	//sorts array
			//if total number of students is even
			if (numStudents % 2 == 0)
			{
				int a = (numStudents/2) - 1;
				int b = (numStudents/2);
				cout << "Median student wait time: " << (float) (studentQueueArray[a] + studentQueueArray[b])/2 << endl;
			}
			//total number of students is odd
			else
			{
				cout << "Median student wait time: " << (float) studentQueueArray[numStudents/2] << endl;
			}
			
			//longest wait, since sorted get the last number in the array
			cout << "Longest Student wait time: " << studentQueueArray[numStudents-1] << endl;
			
			//student Wait over 10
			int numWait10 = 0;
			for (int i = 0; i < numStudents; ++i)
			{
				if (studentQueueArray[i] > 10)
				{
					++numWait10;
				}
			}
			cout << "Number of Students waiting over 10 minutes: " << numWait10 << endl;
			
			//mean and longest window idle time
			int totalMaxIdle = 0;
			int longestMaxIdle = 0;
			int numOver5 = 0;
			for (int i = 0; i < numWindows; ++i)
			{
				totalMaxIdle += windows[i].getMaxIdle();
				if (longestMaxIdle < windows[i].getMaxIdle())
				{
					longestMaxIdle = windows[i].getMaxIdle();
				}
				if (windows[i].getMaxIdle() > 5)
				{
					++numOver5;
				}
			}
			cout << "Mean window idle time: " << (float) totalMaxIdle/numWindows << endl;
			cout << "Longest window idle time: " << longestMaxIdle << endl;
			cout << "Number of windows idle over 5 min: " << numOver5 << endl;
			
			//deallocating arrays to free up memory
			delete [] studentQueueArray;
			delete [] windows;
			
		}
		//closes file stream
		file.close();
	}
	return 0;	
}