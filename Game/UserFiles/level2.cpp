#include "level2.h"
#include "CollisionManager.h"
#include "TestingPair2.h"
#include "testGO2.h"
#include "UserCamera.h"
#include "Game.h"

level2::level2(void)
{

}


level2::~level2(void)
{

}

void level2::Setup(){   //START HERE FOR DEBUGGING  erratic behavior.
	printf("LEVEL 2 LOADED\n");
	new UserCamera;
	// do the game object setup
	TestingPair2* t2 = new TestingPair2();
	testGO2* frigate;
	frigate = new testGO2();
    this->SetCollisionPair<testGO2,TestingPair2>();
	t2;
}