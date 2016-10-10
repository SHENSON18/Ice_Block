#include "level1.h"
#include "CollisionManager.h"
#include "TestingPair2.h"
#include "TestingPair3.h"
#include "testGO.h"
#include "axis.h"
#include "floor_plane.h"
#include "Game.h"
#include "Alarmtest.h"
#include "UserCamera.h"
//GraphicsObjectColorNoTexture *pGObj_Axis;
//GraphicsObjectFlatTexture *pGObj_Plane;
level1::level1()
{

}

level1::~level1(void)
{
}

void level1::Setup(){
	new UserCamera;
	TestingPair2* t2 = new TestingPair2();
	TestingPair2* t3 = new TestingPair2();
	TestingPair3* t4 = new TestingPair3();
	TestingPair3* t5 = new TestingPair3();
	testGO* testgameobject;
	testgameobject = new testGO();
	SetCollisionPair<testGO, TestingPair3>();
	SetCollisionPair<testGO,TestingPair2>();
	t2;
	t3->TestPairPos = Vect(-90,20,-120);
	t4->TestPairPos = Vect(90,20,-120);
	t5->TestPairPos = Vect(90,20,0);
	new floor_plane;
	new axis;
	//Setting Up Alarms for this level
	//Alarm0
	//Alarmable* testalarm = new Alarmtest();
	//AlarmMarker* testmarker = new AlarmMarker(testalarm, Alarmable::AlarmID_0,5);
	//AlarmMan.Register(testmarker,5);
	//Alarm1
	//Alarmable* testalarm1 = new Alarmtest();
	//AlarmMarker* testmarker1 = new AlarmMarker(testalarm1, Alarmable::AlarmID_1,10);
	//AlarmMan.Register(testmarker1,10);


}
