#pragma once
#include "Azul.h"
#include <iostream>
#include <list>
#include "Timeable.h"
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Manager for the GameTime. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class TimeManager
{
private:
	std::list<Timeable*> Clock;
	std::list<Timeable*>::iterator iter;
	static float defaulttime;
	static TimeManager *gameInstance;
	TimeManager()
	{
	StopWatch::initStopWatch();  //When TimeManager is started the clock starts as well
	TotalTime.tic();
	//printf("this worked");
	};
	TimeManager(const TimeManager&){};
	TimeManager& operator=(const TimeManager&){};
	static TimeManager& Instance()

	{
		if(!gameInstance)
			gameInstance = new TimeManager();
			return *gameInstance;
	};
	StopWatch FrameTime;   //Measures Frames
	StopWatch TotalTime;   //Measures total play time 
	//static void LeisureUpdate();  //Updates leisure to be the inverse of Time scale
	//static void TimeScaleCheck();  //Checks to insure user did not put Timescale in the negatives

public: 
	static float Leisure;   //The inverse of TimeScale.
	static float Timescale;       //The Scale of time,  use this for slow down and speed up
	static float deltatime;            //delta time is frame time 
	static float leisuretime;  //used to have the object use time but be unaffected by changes to time scale
	static float GetFrameTime();  //returns Frame Rate
	static float GetTotalTime();  //Returns Total Time
	static float DisplayTotalTime();  //Displays Total Time to User
	static float DisplayFrameTime();  //Displays Frame Time
	static void Delete();
	static void Update();

	static void Register(Timeable* pointer);
	static void DeRegister(Timeable* pointer);
	static void UpdateClock();

};

