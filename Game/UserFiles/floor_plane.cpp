#include "floor_plane.h"
#include "ResourceManager.h"
#include "SceneManager.h"
GraphicsObjectFlatTexture* floor_plane::pGObj_Plane;
floor_plane::floor_plane(void)
{
	pGObj_Plane = new GraphicsObjectFlatTexture(ResourceManager::GetModel("Plane"),ResourceManager::GetTexture("Grid"));
	SceneManager::getCurrentScene()->GetDrawManager()->Register(this);
	Matrix world;
	world = Matrix(IDENTITY);
	world = Matrix(TRANS,0,-400,0);
	world = Matrix(SCALE, 400,400,400);
	pGObj_Plane->setWorld(world);

}


floor_plane::~floor_plane(void)
{
	SceneManager::getCurrentScene()->GetDrawManager()->DeRegister(this);
}

void floor_plane::DrawObject()
{
	pGObj_Plane->Render();
}