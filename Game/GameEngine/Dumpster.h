#pragma once
#include <list>

class Terminable;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	The Dumpster is designed as a failsafe.  You the User will never need to 
/// 			use this Class.  For this is used to catch any items you have forgotten to 
/// 			cleanup yourself.  Now even though this cleansup for you it is better code practice
/// 			for you to cleanup after yourself.  </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class Dumpster
{
private:

	/// <summary>	A List of the ActiveTerminables. </summary>
	std::list<Terminable*> ActiveTerminable;

	Dumpster( const Dumpster& ){};
	Dumpster &operator=(const Dumpster&){};

	friend class Terminable;
		void DeRegister(Terminable* t);

public:
	Dumpster(){};
	~Dumpster();
	static void NowUnused(Terminable* T);
	void Register(Terminable* T);
};

