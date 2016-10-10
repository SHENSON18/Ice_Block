#pragma once

#include "Azul.h"
#include <map>
#include "Inputable.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Records all Registered Keys' current state. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class KeyState
{
	/// <summary>	The inputable key press. </summary>
	static std::multimap<AZUL_KEY, Inputable*> InputableKeyPress;

	/// <summary>	The inputable key released. </summary>
	static std::multimap<AZUL_KEY, Inputable*> InputableKeyReleased;

	/// <summary>	The key test. </summary>
	std::map<AZUL_KEY, bool> KeyTest;

	/// <summary>	The iterator. </summary>
	std::multimap<AZUL_KEY, Inputable*>::iterator iter;

public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
	///
	/// <param name="K">	 	The AZUL_KEY to process. </param>
	/// <param name="state"> 	The state. </param>
	/// <param name="object">	[in,out] If non-null, the object. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	KeyState(AZUL_KEY K, KeyboardEnum::KeyState state, Inputable* object);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Default constructor. </summary>
	///
	/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	KeyState(){}; //base key state

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Destructor. </summary>
	///
	/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual ~KeyState(void);

//*********FUNCTIONS*********************

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Updates the key  K. </summary>
	///
	/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
	///
	/// <param name="K">	The AZUL_KEY to process. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void UpdateKeys(AZUL_KEY K); //update Key States

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Changes the KeyState to Up. </summary>
	///
	/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
	///
	/// <param name="K">	The AZUL_KEY to process. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void KeyUp(AZUL_KEY K);  // changes Key State to Up

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Changes the KeyState to Down. </summary>
	///
	/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
	///
	/// <param name="K">	The AZUL_KEY to process. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void KeyDown(AZUL_KEY K);  //changes Key State to Down



};
