#pragma once
/////////////////////////////////////////////////
///  <summary>
/// The Timeable is a parent class of GameObject.  For a Game object can be set to use DeltaTime, LeisureTime, or AlphaTime to insure
/// that it is not frame rate independant.  This also allows the user to quickly slow down or speed up actions in their game.  From counters
/// to movement this could be used in a variety of manners to assist the user.
////////////////////////////////////////////////////////
class Timeable
{
private:
	//These Variables will only be used if the Object Registers itself to TimeManager 
	//When registered this is default set to 1
	float MyTimeScale;
	float mytime;

public:
	//Used if you want a Individual Time Scale
	void RegisterTime();
	void DeRegisterTime();
	void UpdateMyTime();
	//Only Used if the Item wishes to have its own timeScale
	void SetMyTimeScale(float value);
	//These are used to call TimeManagers items
	float AlphaTime();
	float DeltaTime();
	float LeisureTime();
	//Set GlobalTimeScale
	void SetTimeScale(float value);
	
};

