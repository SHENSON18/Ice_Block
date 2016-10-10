#pragma once 
#include "Azul.h"

class ColliderAABB;
class BoundingSphereVolume;
class ColliderOBB;

class ColliderVolume 
{

public:
	//this will be the update the world matrix for collidables
	virtual void Updatedata()= 0;
	//this is the Accept call for the visitor pattern.
	virtual bool Accept(ColliderVolume* other)=0;
	//the rest are calls to each of the collisionTests
	virtual bool CollisionTest(ColliderAABB* other) = 0;
	virtual bool CollisionTest(ColliderVolume* other) = 0;
	virtual bool CollisionTest(ColliderOBB* other) = 0;
	virtual bool CollisionTest(BoundingSphereVolume* other) = 0;






	
};