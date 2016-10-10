#include "Timeable.h"
#include "TimeManager.h"


void Timeable::RegisterTime()
{
	TimeManager::Register(this);
}

void Timeable::DeRegisterTime()
{
	TimeManager::DeRegister(this);
}

void Timeable::UpdateMyTime()
{
	mytime = TimeManager::leisuretime * MyTimeScale;
}

float Timeable::AlphaTime()
{
	return Timeable::mytime;
}

float Timeable::DeltaTime()
{
	return TimeManager::deltatime;
}

float Timeable::LeisureTime()
{
	return TimeManager::leisuretime;
}

void Timeable::SetMyTimeScale(float value)
{
	if(value >= 0)
	MyTimeScale = value;
	else
	printf("MyTimeScale cannot be negative\n");
}

void Timeable::SetTimeScale(float value)
{
		if(value >= 0)
		TimeManager::Timescale = value;
		else
		printf("TimeScale cannot be negative\n");
}