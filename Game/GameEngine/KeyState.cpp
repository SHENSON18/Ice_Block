////////////////////////////////////////////////////////////////////////////////////////////////////
// file:	GameEngine\KeyState.cpp
//
// summary:	Implements the key state class
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "KeyState.h"
std::multimap<AZUL_KEY, Inputable*> KeyState::InputableKeyPress;
std::multimap<AZUL_KEY, Inputable*> KeyState::InputableKeyReleased;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Constructor. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
///
/// <param name="K">	 	The AZUL_KEY to process. </param>
/// <param name="state"> 	The state. </param>
/// <param name="object">	[in,out] If non-null, the object. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

KeyState::KeyState(AZUL_KEY K, KeyboardEnum::KeyState state, Inputable* object)
{
	if( state == KeyboardEnum::KeyPressed)
	{
		InputableKeyPress.insert(std::pair<AZUL_KEY, Inputable*>(K, object));
	}

	else
	{
		InputableKeyReleased.insert(std::pair<AZUL_KEY, Inputable*>(K, object));
	}

	KeyTest[K] = false;

}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

KeyState::~KeyState(void)    //why is this being called on creation??
{
	//InputableKeyPress.clear();
	//InputableKeyReleased.clear();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Updates the key K. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
///
/// <param name="K">	The AZUL_KEY to process. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void KeyState::UpdateKeys(AZUL_KEY K)
{
	if ( InputMan::GetKeyboard()->GetKeyState(K) != KeyTest[K])
	{
		if(KeyTest[K] == true)  //up is true
		{
			//printf("running keyUp\n");
			KeyUp(K);
		}

		else if(KeyTest[K] == false)
		{
			//printf("running keyDown\n");
			KeyDown(K);
		}

		KeyTest[K] = !KeyTest[K]; //insure the key test isn't continues
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Changes the KeyState to Up. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
///
/// <param name="K">	The AZUL_KEY to process. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void KeyState::KeyUp(AZUL_KEY K)
{
	if(!InputableKeyReleased.empty())
	{
		for(iter = InputableKeyReleased.lower_bound(K); iter != InputableKeyReleased.upper_bound(K); iter++)
		{
			(iter)->second->KeyReleased(K);
		}
	}

}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Changes the KeyState to Down. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
///
/// <param name="K">	The AZUL_KEY to process. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void KeyState::KeyDown(AZUL_KEY K)
{
	if(!InputableKeyPress.empty())
	{
		for(iter = InputableKeyPress.lower_bound(K); iter != InputableKeyPress.upper_bound(K); iter++)
		{


			(iter)->second->KeyPressed(K);
		}
	}

}
