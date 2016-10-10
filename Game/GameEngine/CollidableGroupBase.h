#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	The base class of all Collidable Groups.  Users will not need to worry about this class </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class CollidableGroupBase
{
public:
	
	//virtual void CallAllTestFunctions() = 0;  delete if this works
	virtual void CleanUp(){};
	CollidableGroupBase(void);
	virtual void UpdateVolData() = 0;
	virtual ~CollidableGroupBase(void);
};

