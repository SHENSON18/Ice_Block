#pragma once
#include "Azul.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	 Terminable is a inherited State that GameObject has.
/// 			This state works with the TerminableManager to Terminate all Registered Objects </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class Terminable
{
	bool _MarkedForTermination;
public:
//*******FUNCTIONS*******************
	virtual void Terminate();
	virtual ~Terminable();
	void MarkForTermination();

};

