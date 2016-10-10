#pragma once
#include "Collidable.h"
#include "CollidableGroupBase.h"
#include <set>
#include <iostream>
#include "Visualizer.h"
template< typename C>

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	A Template Class that generates all the Collidable Groups that you have Registered. See testGo in the DemoFiles
/// 			for a example of how this is used</summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class CollidableGroup : public CollidableGroupBase
{
friend class CollisionManager;
friend class CollidableGroup;
template <class T>
friend class CollisionSingleProcessor;

template <class T, class T2>
friend class CollisionPairProcessor;   //why is this template call needed?
public:
	// Vectors for the Group Box
	static Vect MaxPoint;

	static Vect MinPoint;

	typedef std::set<C*> CollidableCollection;

	static void Register(C* p)
	{
		Instance().CollideCol.insert(p);    //inserts into the CollideCollection
		//printf("I registered\n");
	}

	static void deregister(C* p)
	{
		Instance().CollideCol.erase(p); 
		//printf("I deregistered\n");
	}

	static CollidableGroup<C>& Instance()
	{
		if(!gameInstance)
			gameInstance = new CollidableGroup<C>();
			
		return *gameInstance;
	}

	void CleanUp()
	{
		delete gameInstance;
	}
	~CollidableGroup()
	{
		Instance().CollideCol.clear();
		gameInstance = NULL;
	}

	void UpdateVolData()
	{
		//printf("UpdateDatawas called \n");
		if(!CollideCol.empty())
		{
			for( CollidableCollection::iterator it_mine =Instance().CollideCol.begin(); it_mine != Instance().CollideCol.end(); ++it_mine)
			{
				//printf("UpdateDatawas called\n");
				(*it_mine)->colVol;  //these need to call update data
				(*it_mine)->outerSphere;
			}
			GroupBox();
		}

	}

	//create Group aabb
	static void GroupBox()
	{
		std::set<C*>::iterator it = Instance().CollideCol.begin();

		Instance().MaxPoint = (*it)->outerSphere->GetCenter();
		Instance().MinPoint = (*it)->outerSphere->GetCenter();

		for (it = Instance().CollideCol.begin(); it != Instance().CollideCol.end(); ++it)
		{
			Vect center = (*it)->outerSphere->GetCenter();
			float rad = (*it)->outerSphere->GetRadius();

			if(center[x] + rad > Instance().MaxPoint[x])
				Instance().MaxPoint[x] = center[x] + rad;
			if(center[y] + rad > Instance().MaxPoint[y])
				Instance().MaxPoint[y] = center[y] + rad;
			if(center[z] + rad > Instance().MaxPoint[z])
				Instance().MaxPoint[z] = center[z] + rad;

			if(center[x] - rad < Instance().MinPoint[x])
				Instance().MinPoint[x] = center[x] - rad;
			if(center[y] - rad < Instance().MinPoint[y])
				Instance().MinPoint[y] = center[y] - rad;
			if(center[z] - rad < Instance().MinPoint[z])
				Instance().MinPoint[z] = center[z] - rad;
		}
		//Visualizer::ShowAABB(Instance().MaxPoint, Instance().MinPoint, Vect(1,0,0));
	}

	void Cleanup()
	{
		delete gameInstance;  
	}
private:

	CollidableCollection CollideCol;

	static CollidableGroup<C>* gameInstance;
	CollidableGroup<C>(){
		CollideCol = std::set<C*>();
	}
	//I really don't want this
	CollidableGroup<C>( const CollidableGroup<C> & ){}
	CollidableGroup<C>& operator = (const CollidableGroup<C>& ){ }
	//Delete this block when it is working to see if needed
	/*virtual ~CollidableGroup<C>(){
		gameInstance().CollideCol.clear();
		gameInstance = NULL;
	}*/
	/*CollidableGroup(){};
	CollidableGroup(const CollidableGroup&){};
	CollidableGroup& operator=(const CollidableGroup&){};
	static CollidableGroup<C>* gameInstance;
	*/

};

template <typename C>
CollidableGroup<C>* CollidableGroup<C>::gameInstance = NULL;  //makes the game instance for each collidable group

template <class C>
Vect CollidableGroup<C>::MaxPoint = Vect(IceBlockMath::negativevalue,IceBlockMath::negativevalue,IceBlockMath::negativevalue);

template <class C>
Vect CollidableGroup<C>::MinPoint = Vect(IceBlockMath::positivevalue,IceBlockMath::positivevalue,IceBlockMath::positivevalue);