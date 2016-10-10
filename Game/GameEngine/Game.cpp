////////////////////////////////////////////////////////////////////////////////////////////////////
// file:	GameEngine\Game.cpp
//
// summary:	Implements the game class
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Game.h"
//#include "Visualizer.h"
Game* Game::ptrGame = NULL;
//-----------------------------------------------------------------------------
//  Game::Game()
//		Game Engine Constructor
//-----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Constructor. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
///
/// <param name="windowName">  	Name of the window. </param>
/// <param name="widthScreen"> 	The width screen. </param>
/// <param name="heightScreen">	The height screen. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

Game::Game( const char * const windowName, int widthScreen, int heightScreen )
: Engine( windowName, widthScreen, heightScreen)
{
	printf("Game(): started\n");
	glfwSetWindowPos(this->window, 20, 30);
	ptrGame = this;

	ptrGame->windowHeight = heightScreen;
	ptrGame->windowWidth = widthScreen;
}

//-----------------------------------------------------------------------------
// Game::Initialize()
//		Allows the engine to perform any initialization it needs to before 
//      starting to run.  This is where it can query for any required services 
//      and load any non-graphic related content. 
//-----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Initializes this object. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Game::Initialize()
{
	InitializeContent();
}

//-----------------------------------------------------------------------------
// Game::LoadContent()
//		Allows you to load all content needed for your engine,
//	    such as objects, graphics, etc.
//		Also holds call for the visualizer tool
//-----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Loads the content. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Game::LoadContent()
{
	LoadGameContent();  //User defined in Ice_Block_Content

	Visualizer::Initialize();
}

//-----------------------------------------------------------------------------
// Game::Update()
//      Called once per frame, update data, tranformations, etc
//      Use this function to control process order
//      Input, AI, Physics, Animation, and Graphics
//-----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Updates this object. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Game::Update()
{
	TimeManager::Update();
	SceneManager::UpdateCurrentScene();    //Update the Scene

}

//-----------------------------------------------------------------------------
// Game::Draw()
//		This function is called once per frame
//	    Use this for draw graphics to the screen.
//      Only do rendering here
//-----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Draws this object. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Game::Draw()
{ 
	SceneManager::DrawCurrentScene();
}

//-----------------------------------------------------------------------------
// Game::UnLoadContent()
//       unload content (resources loaded above)
//       unload all content that was loaded before the Engine Loop started
//       (also used to clean up whatever was created in Game::Initialize()  )
//-----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Un load content. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Game::UnLoadContent()
{
	UnloadGameContent();
	ResourceManager::UnLoadResources();
	SceneManager::DeleteCurrentScene(); //Also deletes SceneManager
	TimeManager::Delete();

	TerminateContent();   //user context

}

// End of Game.cpp
