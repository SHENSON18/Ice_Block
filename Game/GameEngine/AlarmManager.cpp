////////////////////////////////////////////////////////////////////////////////////////////////////
// file:	GameEngine\AlarmManager.cpp
//
// summary:	Implements the alarm manager class
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "AlarmManager.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Default constructor. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

AlarmManager::AlarmManager(void)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

AlarmManager::~AlarmManager(void)
{
	//run cleanup here
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Deregisters this Alarm/ GameObject. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
///
/// <param name="a">	[in,out] A AlarmMarker* is used. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void AlarmManager::Deregister(AlarmMarker* a)
{
	float key = a->GetTime();
	timeline.erase(key);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Registers this object. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
///
/// <param name="a">		  	[in,out] If non-null, the AlarmMarker* to process. </param>
/// <param name="timerlength">	The length of time on the Alarm. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void AlarmManager::Register(AlarmMarker* a, float timerlength) 
{
	float time = TimeManager::GetTotalTime();
	timerlength += time;
	timeline.insert (std::pair<float, AlarmMarker*>(timerlength,a) ); //insert need to test if goes right
	printf("I have registered a alarm\n");
	char buff[50];
	sprintf_s(buff, "TimerLenght: %.2fs \n",timerlength);
	printf(buff);

}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Updates the alarms. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void AlarmManager::UpdateAlarms()
{
	AlarmMarker* am;
	Alarmable::AlarmID alarmID;
	float time = TimeManager::GetTotalTime();
	it = timeline.begin();
	while(it != timeline.end() &&  it->second->GetTime() <= time)
	{
		char buff[50];
		sprintf_s(buff, "TimerLenght: %.2fs \n",it->second->GetTime());
		printf(buff);
		//printf("I ran the loop\n");
		am = it->second;
		alarmID = am->GetAlarmID();
		am->ExecuteCallaback(alarmID);

		delete am;   //delete the AlarmMarker
		timeline.erase(it);

		it = timeline.begin();
	}
	//printf("I tried update Alarms\n");
}
