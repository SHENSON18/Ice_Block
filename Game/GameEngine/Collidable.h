#pragma once
#include "Azul.h"
#include "ColliderVolumeEnums.h"
#include "IceBlockMath.h"
////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Collidable is a inherited State that GameObject has.
/// 			This state works with the CollisionManager to observe and report on the collisions between
/// 			Registered Objects </summary>
///
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class ColliderVolume;
class BoundingSphereVolume;
class ColliderAABB;
class ColliderOBB;

class Collidable
{

private:
	Model *MainColliderObj;  //try and get this protected again.
	
public:
	/// <summary>	Set the GameObject Model you wish to be the Collider Object as this in your GameObject. </summary>
	virtual void Collision(Collidable*);

	virtual bool CollisionTest(Collidable* c1, Collidable* c2){ c1; c2; return false;};
	
	static bool TestCollisionPair(Collidable* c1, Collidable* c2); //add collisiontest call here
	
	void SetColliderVolume(ColliderVolume* Volume);
	
	Collidable(void);
	
	virtual ~Collidable(void);

	//Gets the Appropriate Graphics object for the Volume
	Model* getModel();

	//Gets the world matrix
	Matrix getWorld();

	void setModel(Model *temp);
	//seting the collision Volume for the object
	void SetColliderVolume(COLVOLUMES vol);


	//Place to simplify registration if needed

	////////VARIABLE
	Matrix WorldMat;

	BoundingSphereVolume *outerSphere;
	
	ColliderVolume *colVol;
};

