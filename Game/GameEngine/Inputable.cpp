////////////////////////////////////////////////////////////////////////////////////////////////////
// file:	GameEngine\Inputable.cpp
//
// summary:	Implements the inputable class
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "SceneManager.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Registers the object to Observe a Keys State. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
///
/// <param name="K">		The AZUL_KEY to process. </param>
/// <param name="state">	The state you wish to Register to.  Ex. KeyPressed/KeyReleased </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Inputable::RegisterKey(AZUL_KEY K, KeyboardEnum::KeyState state)
{
	SceneManager::getCurrentScene()->GetInputableManager()->Register(this, state, K);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	DeRegister the object from Observing a Key State. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
///
/// <param name="gameobject">	[in,out] If non-null, the gameobject. </param>
/// <param name="K">		 	The AZUL_KEY to process. </param>
/// <param name="state">	 	The state you wish to DeRegister from. Ex. KeyPressed/KeyReleased </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Inputable::DeRegisterKey(Inputable* gameobject, AZUL_KEY K, KeyboardEnum::KeyState state)
{
	SceneManager::getCurrentScene()->GetInputableManager()->DeRegister(gameobject,state,K);
}

