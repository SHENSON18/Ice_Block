#pragma once
#include "Azul.h"
#include <map>
#include <string>
#include "TerrainModel.h"

class TerrainModel;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Manager for all User Resource that was loaded in with LoadAllResources. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class ResourceManager
{
private:

	//Set it as a singleton so we can call resourceManager where ever I want
	static ResourceManager* resInstance;
	ResourceManager();
	ResourceManager(const ResourceManager&){};
	ResourceManager& operator=(const ResourceManager&){};

	static ResourceManager& Instance()
	{
		if (! resInstance)
		{
			resInstance = new ResourceManager;
		}
		return *resInstance;
	};

	std::map<std::string, Texture*> TextureCache; //Stores textures
	std::map<std::string, Model*> ModelCache; //Stores models
	std::map<char*, TerrainModel*> TerrainCache; //Store Terrains

public:
	~ResourceManager();

	// Loads all resources.  This is where you add Textures and Models. 
	static void LoadAllResources();

	//Unload all resources for deletion
	static void UnLoadResources();  

	//Adds and get the textures
	static void AddTexture(std::string rKey, char* path);
	static Texture* GetTexture( std::string rKey);

	//Add the actual models
	//And get the models
	static void AddModel(std::string rKey, std::string path);
	static Model* GetModel(std::string rKey);


	//Add and get the Terrain
	static void AddTerrain(char* terrainName,char* heighmapfile ,char* texture, float Sidelength = 1, float maxheight = 1,float minheight = 0, int RepeatU = 1, int RepeatV = 1);
	static TerrainModel* GetTerrain(char* terrainName);
	//static void SetTerrain(
	/////
	static GraphicsObjectColorNoTexture* NoTexture(std::string Model);
	static GraphicsObjectFlatTexture* ModelFlatTexture(std::string Texture, std::string Model);
	static GraphicsObjectWireFrame* WireFrameModel(std::string Model);
	//*/


};

