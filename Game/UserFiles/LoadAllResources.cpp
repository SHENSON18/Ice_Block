#include "ResourceManager.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Loads all resources. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void ResourceManager::LoadAllResources()
{
	// place all your AddTexture/ AddModels here   This conversion should be automated
	printf("Converting FBX to AZUL\n");
	system("ConverterDebug space_frigate.fbx > DebugInfo.txt");
	system("ConverterDebug TankTop.fbx > DebugInfo.txt");
	system("ConverterDebug TankBottom.fbx > DebugInfo.txt");
	system("ConverterDebug TankBottomEnemy.fbx > DebugInfo.txt");
	system("ConverterDebug Axis.fbx > DebugInfo.txt");
	system("ConverterDebug Plane.fbx > DebugInfo.txt");
	printf("Converting completed\n");


	AddTexture("SpaceFrigate", "space_frigate.tga");
	AddTexture("TankBottom", "TankBottom.tga");
	AddTexture("TankTop", "TankTop.tga");
	AddTexture("TankBottomEnemy", "TankBottomEnemy.tga");
	AddTexture("TankTopEnemy", "TankTopEnemy.tga");



	AddModel("SpaceFrigate", "space_frigate.azul");
	AddModel("BoundingSphere", "BoundingSphere.azul");
	AddModel("BoundingBox", "BoundingBox.azul");
	AddModel("TankBottom", "TankBottom.azul");
	AddModel("TankTop", "TankTop.azul");
	AddModel("Axis","Axis.azul");
	AddModel("Plane","Plane.azul");
	AddTexture("Grid", "grid.tga");
	AddTexture("Wolf", "wolf.tga");

	//AddTerrain("WolfCarpet","heightmap.tga","Wolf",10,5,0,16,16);

}