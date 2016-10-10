#include "Game.h"
#include "TankDemo.h"
#include "level1.h"
//GraphicsObjectColorNoTexture *pGObj_Axis;
//GraphicsObjectFlatTexture *pGObj_Plane;

void Game::InitializeContent()
{
	
}

void Game::LoadGameContent()
{
	ResourceManager::LoadAllResources();   //This loads all your resources
	SceneManager::SetCurrentScene(new level1);


}

void Game::UnloadGameContent()
{
	//delete pGObj_Axis;
	//delete pGObj_Plane;
}

void Game::TerminateContent()
{


}