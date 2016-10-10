////////////////////////////////////////////////////////////////////////////////////////////////////
// file:	GameEngine\ResourceManager.cpp
//
// summary:	Implements the resource manager class
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "ResourceManager.h"
using namespace std;

ResourceManager* ResourceManager::resInstance = nullptr; 

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Default constructor. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

ResourceManager::ResourceManager()
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

ResourceManager::~ResourceManager()
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Unload resources. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void ResourceManager::UnLoadResources()
{
	Instance().TextureCache.clear();
	Instance().ModelCache.clear();
	delete resInstance;
	resInstance = NULL;
}

//###############################################
//   TEXTURES
//###############################################

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Adds a texture to the TextureCache. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
///
/// <param name="Key"> 	The key. </param>
/// <param name="path">	[in,out] If non-null, full pathname of the file. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void ResourceManager::AddTexture( string Key, char* path)
{
	Instance().TextureCache[Key] = GpuTexture::Create(path); // pair(string, texture)
	printf("Texture added\n ");
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets the texture. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
///
/// <param name="rKey">	The key. </param>
///
/// <returns>	null if it fails, else the texture. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

Texture* ResourceManager::GetTexture( std::string rKey)
{
	return Instance().TextureCache[rKey]; 
}


//###################################################
// MODELS
//###################################################
//*

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Adds a model to the ModelCache. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
///
/// <param name="Key"> 	The key. </param>
/// <param name="path">	Full pathname of the file. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void ResourceManager::AddModel( string Key, string path)
{
	if(path.substr(path.length() - 4, path.length()) == ".fbx")
		{
		std::string model_file_name = "ConverterDebug " + path + " > DebugInfo.txt";
		system(model_file_name.c_str());
		}
	Instance().ModelCache[Key] = GpuModel::Create(path.c_str()); //Pair(string, model)
	printf("Model added\n ");
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets the model. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
///
/// <param name="rKey">	The key. </param>
///
/// <returns>	null if it fails, else the model. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

Model* ResourceManager::GetModel( std::string rKey)
{
	return Instance().ModelCache[rKey]; 
}
//*/

void ResourceManager::AddTerrain(char* terrainName, char* heightmapfile,char* texture, float Sidelength, float maxheight, float minheight,  int RepeatU, int RepeatV)
{
	Instance().TerrainCache[terrainName] =  new TerrainModel(heightmapfile, Sidelength, maxheight, minheight, texture, RepeatU, RepeatV);

}

TerrainModel* ResourceManager::GetTerrain(char* terrainName)
{
	return Instance().TerrainCache[terrainName];
}


////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Wire frame model GraphicsObject. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
///
/// <param name="Model">	The model. </param>
///
/// <returns>	null if it fails, else a GraphicsObjectWireFrame*. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

GraphicsObjectWireFrame* WireFrameModel(std::string Model)
{
	return (new GraphicsObjectWireFrame( ResourceManager::GetModel(Model)));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	No texture GraphicsObject. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
///
/// <param name="Model">	The model. </param>
///
/// <returns>	null if it fails, else a GraphicsObjectColorNoTexture*. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

GraphicsObjectColorNoTexture* NoTexture(std::string Model)
{
	return (new GraphicsObjectColorNoTexture( ResourceManager::GetModel(Model)));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Model flat texture GraphicsObject. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
///
/// <param name="Texture">	The texture. </param>
/// <param name="Model">  	The model. </param>
///
/// <returns>	null if it fails, else a GraphicsObjectFlatTexture*. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

GraphicsObjectFlatTexture* ModelFlatTexture(std::string Texture, std::string Model)
{
	return (new GraphicsObjectFlatTexture( ResourceManager::GetModel(Model), ResourceManager::GetTexture(Texture)));
}
 

