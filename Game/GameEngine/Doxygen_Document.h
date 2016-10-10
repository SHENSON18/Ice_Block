/** \mainpage About IceBlock
*
* The IceBlock Engine is a simple 3D game Engine derived from 
* DePaul University's Azul Engine. 
* 
*   \section sec Features
*      IceBlock supports the following components:
*      - A resource manager that organizes Textures and Graphics Models assests.  
*      - GameObjects class which you can derive all of your objects from.  
*      - A built-in game loop to update and draw the current Scene and its associated GameObject.  
*      - A built-in TimeManager to track time.  
*      - Callbacks for Collision events, alarm events, input events (keyboard). 
* 
*      The engine was designed with simplicity in mind to insure quick coding and testing
*        
*/

/**
*
* \page page1 Using IceBlock
* 		There are two documentation Modules for BlueBerry:
* 		- @ref IceBlock "Module 1: IceBlock": This is the most common case where you just want to use the existing framework.  
* 		- @ref Internals "Module 2: IceBlock's internal Workings": This is provided only for those interesting in looking inside the framework to see how it works.  
*/


/** @defgroup IceBlock IceBlock Api
 * \brief These commands are available to IceBlock Users
 * 		  
 */


/** @defgroup GameObject GameObject
*   @ingroup IceBlock
* 
*    \brief All game entities will be derived from GameObject
* 
*/

/** @defgroup Resources Resources
*   @ingroup IceBlock
*    \brief Loading external resources into the game 
*/

/** @defgroup Scene Scene
*   @ingroup IceBlock
* 
*    \brief A Scene is the space in which GameObjects exist
*/

/** @defgroup Internals Internal to IceBlock
*   \brief Yeah, you are not touching that...
* 
*/


/** @defgroup Default Default Events
*	@ingroup GameObject
*   \brief Here are a list of events that Game Objects can use.
*
*/

/** @defgroup Input Input Events
*	@ingroup GameObject
*   \brief Callbacks associated with keyboard events. IMPORTANT: In order for any of these callbacks to be acivated, the GameObject must register keys by using the RegisterKey function, with appropraite parameters.
*
*/

/** @defgroup Alarm Alarm Control and Events
*	@ingroup GameObject
*   \brief Each GameObjects can have set up to 3 separate alarms (numbered 0 through 2) which each can have their own callbacks
*/

/** @defgroup Collision Collision Set-up
*	@ingroup GameObject
*   \brief
*   	   To set up the collision system, the underlying collidable needs a Model object in order to calculate the appropriate bounding sphere.
*   	   You must also set up the World Matrix of the Objects in order for the bounding sphere to track the Model.
*/

/** @defgroup CRegistration Collision Registration
*	@ingroup GameObject
*   \brief 
*		  In order for the collision system to detect the collision you must register the CollisionPair.
*/





