#pragma once
#include "ColliderVolume.h"
#include "Collidable.h"
#include "Visualizer.h"

class ColliderAAbb;

class BoundingSphereVolume : public ColliderVolume
{
private:
	
	Matrix ColMatrix;
	Model *mainColobj;
	Vect center;
	float radius;
	Collidable* c;
	float distance;

public:
	BoundingSphereVolume(Collidable* obj)
	{
		c = obj;
	}
	BoundingSphereVolume( const BoundingSphereVolume & ){}
	BoundingSphereVolume& operator = (const BoundingSphereVolume& ) { }
	virtual ~BoundingSphereVolume(void){};
	virtual bool Accept(ColliderVolume *other)
	{
		//calls the appropriate test for the volume
		return other->CollisionTest(this);
	}
	//default case - I pray this doesn't get called
	virtual bool CollisionTest(ColliderVolume* other) 
	{
		other;
		printf("Collision test on item without a volume attached");
		return false;
	}
	//colliding with an OBB
	virtual bool CollisionTest(ColliderOBB* other);

	//colliding with an AABB
	virtual bool CollisionTest(ColliderAABB* other);
	
	//colliding with a Sphere
	virtual bool CollisionTest(BoundingSphereVolume* other)
	{
		printf("You called for BoundingSphere in BoundingSphere\n");
		Vect dist = center - other->GetCenter();
		 distance = dist.mag();

		float SumRadius = radius + other->GetRadius();

		if (distance <= SumRadius)
		{
			printf("Collision Occured");
			return true;
		}
		return false;
	
	};

	//Update Sphere data
	virtual void Updatedata() override
	{
		//printf("Shpere called update\n");
		ColMatrix = c->getWorld();
		mainColobj = c->getModel();
		//assigns center data to mainColobj center
		center = mainColobj->center * ColMatrix;
		Matrix  BaseC1 = Matrix( SCALE, mainColobj->radius * Vect(1,1,1) ) * Matrix(TRANS, mainColobj->center);
		Matrix M1 = BaseC1 * ColMatrix;
		Vect newCenterC1 = Vect(0,0,0) * M1;
		Vect temp1 = newCenterC1 - (Vect(1,0,0) * M1);
		radius = temp1.mag();
	}
	//return the center of the sphere
	Vect GetCenter()
	{
		return center;
	}
	//return the spheres radius
	float GetRadius()
	{
		return radius;
	}
};

