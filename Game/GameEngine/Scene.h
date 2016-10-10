#pragma once
#include "UpdateManager.h"
#include "DrawManager.h"
#include "InputableManager.h"
#include "AlarmManager.h"
#include "TerminableManager.h"
#include "CollisionManager.h"
#include "Dumpster.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Holds All the Managers.   </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class Scene
{
protected:
	//Member Variables
	UpdateManager UpdateableMan; 
	DrawManager DrawMan;  //creates a manager for the scene
	InputableManager InputMan; //creates manager for the scene
	TerminableManager Terminator;
	Dumpster Trash;


public:
	Scene();
	virtual ~Scene();
	void UpdateScene();  
	virtual void Setup() = 0;
	virtual void SceneEnd(){}; //user code for what to do
	//Sets Up Manager pointers
	UpdateManager* GetUpdateManager(){return &UpdateableMan;} ;
	DrawManager* GetDrawManager(){return &DrawMan;} ;
	InputableManager* GetInputableManager(){return &InputMan;};
	TerminableManager* GetTerminableManager(){return &Terminator;};
	Dumpster* GetDumpster(){return &Trash;};
	AlarmManager AlarmMan; //creates a alarm manager
	CollisionManager CollisionMan;
	void DrawScene();


	//#######################################3
	//Collision Template for scene
	template <class C1, class C2>
	void SetCollisionPair()
	{
		this->CollisionMan.SetCollisionPair<C1,C2>();
	}
	//ADD SET SELF COLLISION HERE
private:

};