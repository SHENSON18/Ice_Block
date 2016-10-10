#pragma once
#include "Azul.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Updatable is a inherited State that GameObject has.
/// 			This state works with the UpdateManager to Update all Registered Objects </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class Updatable
{
public:
	virtual void Update();
	void RegisterUpdate();
	void DeRegisterUpdate();
};

