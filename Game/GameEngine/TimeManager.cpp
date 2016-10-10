////////////////////////////////////////////////////////////////////////////////////////////////////
// file:	GameEngine\TimeManager.cpp
//
// summary:	Implements the time manager class
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "TimeManager.h"

TimeManager* TimeManager::gameInstance = nullptr;

float TimeManager::deltatime = .02f;
float TimeManager::Timescale = 1;
float TimeManager::Leisure = 0;
float TimeManager::leisuretime = 0;
float TimeManager::defaulttime = 1;
////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Deletes this object. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void TimeManager::Delete()
{
	delete gameInstance;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Updates this object. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void TimeManager::Update()
{
	Instance().FrameTime.toc();
	Instance().FrameTime.tic();
	Instance().TotalTime.toc();
	//TimeManager::LeisureUpdate();
	TimeManager::Instance().deltatime = Instance().FrameTime.timeInSeconds() * TimeManager::Instance().Timescale; //TimeScale is the global Time scale.  Change this to slow time down
	TimeManager::Instance().leisuretime = Instance().FrameTime.timeInSeconds();//not needed duh (TimeManager::Instance().Timescale + TimeManager::Instance().Leisure); // Use time but don't be affected by TimeScale
	//TimeManager::TimeScaleCheck();
	TimeManager::UpdateClock();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets frame time. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
///
/// <returns>	The frame time. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

float TimeManager::GetFrameTime()
{
	return Instance().FrameTime.timeInSeconds();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Displays the frame time. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
///
/// <returns>	A float. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

float TimeManager::DisplayFrameTime()
{
	//*  for displaying frame time
	char buff[70];
	sprintf_s(buff, "FrameTime: %.2f (%.0f FPS) %.2f is deltatime\n",Instance().FrameTime.timeInSeconds(), 1/Instance().FrameTime.timeInSeconds(), TimeManager::Instance().deltatime);
	printf(buff);
	//*/

	return Instance().FrameTime.timeInSeconds();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets total time. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
///
/// <returns>	The total time. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

float TimeManager::GetTotalTime()
{
	/*    for displaying the time
	char buff[50];
	sprintf_s(buff, "TotalTime: %.2fs \n",Instance().TotalTime.timeInSeconds());
	printf(buff);
	//*/
	return Instance().TotalTime.timeInSeconds();  //returns value of total time;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Displays the total time. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
///
/// <returns>	A float. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

float TimeManager::DisplayTotalTime()
{
	//*    for displaying the time
	char buff[50];
	sprintf_s(buff, "TotalTime: %.2fs \n",Instance().TotalTime.timeInSeconds());
	printf(buff);
	//*/
	return Instance().TotalTime.timeInSeconds();  //returns value of total time;
}


//////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>  Updates Liesure time so it is the correct inverse of TimeScale
///
///////////////////////////////////////////////////////////////////////////////////////////////////

//void TimeManager::LeisureUpdate()
//{
//	//set Leisure time to be the inverse of TimeScale so that it negates the effect on selected object
//	Instance().Leisure = (1 - TimeManager::Instance().Timescale); 
//
//
//}
//


///////////////////////////////////////////////////////////////
/// <summary>  Checks TimeScale so it is not in the negatives
///////////////////////////////////////////////////////////////

//void TimeManager::TimeScaleCheck()
//{
//	try {
//		if(TimeManager::Instance().Timescale < 0)
//			throw 714;
//		}
//	catch(int x) {
//		TimeManager::Instance().Timescale = 1;
//		cout << "TimeScale cannot be a negative number, Error Number:  " << x << "\nResetting to default value"<<endl;
//	}
//
//
//}

void TimeManager::UpdateClock()
{
	Instance().iter = Instance().Clock.begin();
	while (Instance().iter != Instance().Clock.end())
	{
		(*Instance().iter)->UpdateMyTime();
		Instance().iter++;
	}
}

void TimeManager::Register(Timeable* pointer)
{
	if (std::find(std::begin(Instance().Clock), std::end(Instance().Clock), pointer) == std::end(Instance().Clock))  //check if item is already in list
	{
		pointer->SetMyTimeScale(Instance().defaulttime);
		Instance().Clock.push_back(pointer);
	}
}

void TimeManager::DeRegister(Timeable* pointer)
{
	Instance().Clock.remove(pointer);
}