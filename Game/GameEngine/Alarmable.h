#pragma once
#include "Azul.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Alarmable is a inherited State that GameObject has.
/// 			You can set up Alarm outside game objects so that you do not need
/// 			to create a Game Object to have a alarm in a scene.  See level1.h in the demofile
/// 			for a example of implementation and AlarmTest for example Alarmable
/// 			 </summary>
///
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class Alarmable
{
public:
	Alarmable(void);
	virtual ~Alarmable();
	virtual void Alarm0();  
	virtual void Alarm1();
	virtual void Alarm2();
	float TriggerTime;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Values that represent the list of AlarmID's you can use. </summary>
	///
	/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	enum AlarmID { AlarmID_0, AlarmID_1, AlarmID_2 };
	void Dispatch(AlarmID n);
private:
	//const int MAX_Alarm_Events = 3;
};

