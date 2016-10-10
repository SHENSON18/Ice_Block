#pragma once
#include "ColliderVolume.h"
#include "IceBlockMath.h"
#include "Collidable.h"
#include "Visualizer.h"

class ColliderAABB;
class BoundingSphereVolume;

class ColliderOBB : public ColliderVolume
{
private:

	Matrix ColMatrix;
	Model *mainColobj;
	Vect Max;
	Vect Min;
	Collidable *c;

public:
	ColliderOBB(Collidable *obj)
	{
			c = obj;
			Max = c->getModel()->maxPointAABB;
			Min = c->getModel()->minPointAABB;
			BoundryPoints();

	}
	ColliderOBB( const ColliderOBB & ){}
	ColliderOBB& operator = (const ColliderOBB& ){}
	virtual ~ColliderOBB(void);

	//Vistor Accept Function
	virtual bool Accept(ColliderVolume *other)
	{
		//calls the appropriate test for the volume
		return other->CollisionTest(this);
	}



	//Base case - I pray this doesn't get called
	virtual bool CollisionTest(ColliderVolume* other) override
	{
		
		other;
		return false;
	}
	virtual void Updatedata()
	{
		ColMatrix = c->getWorld();
		BoundryPoints();
	}
	//Sets Boundry of OBB Box
	Vect OBBBoundryPoint[7];
	void ColliderOBB::BoundryPoints()
	{
		Vect max = c->getModel()->maxPointAABB;
		Vect min = c->getModel()->minPointAABB;

		OBBBoundryPoint[0] = Vect(max[x], max[y], max[z]) * ColMatrix;
		OBBBoundryPoint[1] = Vect(min[x], min[y], min[z]) * ColMatrix;
			
		OBBBoundryPoint[2] = Vect(max[x], max[y], min[z]) * ColMatrix;
		OBBBoundryPoint[3] = Vect(max[x], min[y], max[z]) * ColMatrix;
		OBBBoundryPoint[4] = Vect(max[x], min[y], min[z]) * ColMatrix;

		OBBBoundryPoint[5] = Vect(min[x], min[y], max[z]) * ColMatrix;
		OBBBoundryPoint[6] = Vect(min[x], max[y], min[z]) * ColMatrix;
		OBBBoundryPoint[7] = Vect(min[x], max[y], max[z]) * ColMatrix;
	}
	//Gets the World Matrix of the Collider
	const Matrix getWorldMat()
	{
		return ColMatrix;
	}
	//Gets the Max... duh
	Vect GetMax()
	{
		return Max;
	}
	//Gets the Min... duh
	Vect GetMin()
	{
		return Min;
	}
	//colliding with an AABB
	virtual bool CollisionTest(ColliderAABB* other);

	//colliding with a Sphere
	virtual bool CollisionTest(BoundingSphereVolume* other);

	//colliding with a OBB
	virtual bool CollisionTest(ColliderOBB* other);
};

