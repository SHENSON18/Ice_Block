#pragma once
using namespace::std;
#include "Azul.h"
#include "Scene.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Manages the Scenes. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class SceneManager
{
private:
	static SceneManager *gameInstance;
	SceneManager();

	SceneManager(const SceneManager&){};
	SceneManager& operator=(const SceneManager&){};
	static SceneManager& Instance()
	{
		if(!gameInstance)
			gameInstance = new SceneManager();
			return *gameInstance;
	};
    Scene *currentscene;  //pointer to current scene
	Scene *ptrNextScene;  //pointer to next scene
	void PrivateSetCurrentScene(Scene* s);
public:
	~SceneManager();
	static void SetCurrentScene(Scene* s);
	static void NextScene(Scene* s);
	static void Insantiate();
	static void DrawCurrentScene();
	static void DeleteCurrentScene();
	static void UpdateCurrentScene();
	static Scene* getCurrentScene(){ return Instance().currentscene;};


};

