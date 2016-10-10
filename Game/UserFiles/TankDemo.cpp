#include "TankDemo.h"
#include "CollisionManager.h"
#include "TankTurret.h"
#include "TankBase.h"
#include "axis.h"
#include "floor_plane.h"
#include "Game.h"
#include "Alarmtest.h"
#include "UserCamera.h"
#include "TerrainModel.h"
//GraphicsObjectColorNoTexture *pGObj_Axis;
//GraphicsObjectFlatTexture *pGObj_Plane;
TankDemo::TankDemo()
{

}

TankDemo::~TankDemo(void)
{
}

void TankDemo::Setup(){
	TerrainModel* t1 = new TerrainModel("heightmap.tga",10,5,0,"Wolf",12,12);
	t1->RegisterDraw();
	t1;
	new UserCamera;
	TankBase* testgameobject;
	testgameobject = new TankBase();
	TankTurret* t2 = new TankTurret(testgameobject);
	t2;
	//new floor_plane;
	new axis;


}
