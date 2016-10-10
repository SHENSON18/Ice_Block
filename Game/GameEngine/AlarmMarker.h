#pragma once
#include "Azul.h"
#include "Alarmable.h"
#include "TimeManager.h" //might not need here

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	This is the AlarmMarker class.  This is used to 
/// 			mark the active alarms. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class AlarmMarker
{
public:
	AlarmMarker(Alarmable* ptr,Alarmable::AlarmID id ,float time); //time should be how long you want the alarm 
	virtual ~AlarmMarker(void);
	void ExecuteCallaback(Alarmable::AlarmID n);
	Alarmable* GetAlarmmable();
	float GetTime();
	Alarmable* ptrAlarmable;
	Alarmable::AlarmID alarmID;
	Alarmable::AlarmID GetAlarmID();
};

