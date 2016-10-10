#pragma once
#include <set>
#include "CollidableGroup.h"
#include "CollisionProcessorBase.h"
#include "CollisionPairProcessor.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Manages the GameObjects that the User has Registered into the CollidableGroup </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////
class Collidable;
class CollidableGroupBase;

class CollisionManager 
{
	typedef std::set<CollidableGroupBase*> CollidableGroupCollection;
	 friend class Scene;
public:
	~CollisionManager();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Defines an alias representing collection of collision groups. </summary>
	///
	/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	//typedef std::set<CollidableGroupBase*> CollisionGroupCollection; //set of collidable groups 
	// //new code  all commented here is old code
	CollidableGroupCollection colgroupCol;
	typedef std::set<CollisionProcessorBase*>CollisionProcessorCollection;

	
	void ProcessCollisions();
	CollisionManager();
	
	void Cleanup();



//  SET COLLISION PAIR
	template <class C1, class C2>
	void SetCollisionPair()
	{
	//printf("SetCollisionPair was called in CollisionManager\n");   //testing code
	colProcessorCol.insert(new CollisionPairProcessor<C1,C2>() );

	colgroupCol.insert(&CollidableGroup<C1>::Instance());
	colgroupCol.insert(&CollidableGroup<C2>::Instance());

	}
 //ADD SETSELF COLLISION HERE



 /**
	\brief This is the list of pairs and self collisions considered for collisions.
	*/
	CollisionProcessorCollection colProcessorCol;

};
