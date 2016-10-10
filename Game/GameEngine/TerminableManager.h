#pragma once
#include "Terminable.h"
#include <list>

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Manages the Terminables and holds them in a list until they are removed. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class TerminableManager
{
public:


	~TerminableManager();
//*********FUNCTIONS*******************
	void ProcessTerminationEvent();
	void Register(Terminable* t);
	void Cleanup();


	/// <summary>	List of Terminable Objects. </summary>
	std::list<Terminable*> DeathList;
};

