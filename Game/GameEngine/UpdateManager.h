#pragma once
#include "Updatable.h"
#include <list>

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Manages all the Updatables for the User.  Be sure to Register the GameObject using RegisterUpdate() </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class UpdateManager
{
protected:

	/// <summary>	The registery of Updatables. </summary>
	std::list<Updatable*> URegistery;
	std::list<Updatable*>::iterator iter;

public:
	UpdateManager(){};
	virtual ~UpdateManager(){};
	
	void Register(Updatable* pointer);
	void DeRegister(Updatable* pointer);
	void UpdateAll();
	void Cleanup();
};


