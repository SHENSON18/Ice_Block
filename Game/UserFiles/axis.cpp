#include "axis.h"
#include "ResourceManager.h"
#include "SceneManager.h"
GraphicsObjectColorNoTexture* axis::pGObj_Axis;

axis::axis(void)
{
	pGObj_Axis = new GraphicsObjectColorNoTexture(ResourceManager::GetModel("Axis"));
	
	SceneManager::getCurrentScene()->GetDrawManager()->Register(this);
	Matrix world;
	world = Matrix(IDENTITY);
	pGObj_Axis->setWorld(world);
}


axis::~axis(void)
{
	SceneManager::getCurrentScene()->GetDrawManager()->DeRegister(this);
}

void axis::DrawObject()
{
	pGObj_Axis->Render();
}
