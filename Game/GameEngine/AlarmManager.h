#pragma once
#include "AlarmMarker.h"
#include <map>
#include <iostream>

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Manager for the alarms. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class AlarmManager
{
public:
	AlarmManager(void);
	virtual ~AlarmManager(void);
	void Deregister(AlarmMarker* a);   
	void Register(AlarmMarker* a, float timerlength); //float is time
	void UpdateAlarms();   //calls callback on alarm if they are past timeline
private:
	std::multimap<float, AlarmMarker*>timeline;//holds the times for the items
	std::multimap<float, AlarmMarker*>::iterator it;
};

