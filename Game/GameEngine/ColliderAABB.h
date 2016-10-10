#pragma once
#include "Collidable.h"
#include "ColliderVolume.h"
#include "Visualizer.h"
class BoundingSphereVolume;

class ColliderAABB : public ColliderVolume
{
private:
/////////VARIABLES//////////////
	Matrix ColMatrix;
	Model *mainColobj;
	Vect Max;
	Vect Min;
	Collidable *c;

public:
	ColliderAABB(Collidable *obj)
	{
		c = obj;
		BoundryPoints();
	}
	ColliderAABB( const ColliderAABB & ){}
	ColliderAABB& operator = (const ColliderAABB& ){}
	virtual ~ColliderAABB(void);

	//Vistor Accept Function
	virtual bool Accept(ColliderVolume *other)
	{
		//calls the appropriate test for the volume
		return other->CollisionTest(this);
	}
	// Base case - I pray this doesn't get called
	bool CollisionTest(ColliderVolume* other) override
	{
		other;
		return false;
	}

	//colliding with an OBB
	virtual bool CollisionTest(ColliderOBB* other);

	//colliding with an AABB
	virtual bool CollisionTest(ColliderAABB* other)
	{
		printf("You called AABB in AABB\n");
		//Debugging help
		//Visualizer::ShowAABB(this->GetMax(),this->GetMin(), Vect(1,0,0));
		//Visualizer::ShowAABB(other->GetMax(), other->GetMin(), Vect (1,1,0));

		bool Xaxis = IceBlockMath::intervalcheck(Min[x], Max[x],other->GetMin()[x], other->GetMax()[x]);
		bool Yaxis = IceBlockMath::intervalcheck(Min[y], Max[y],other->GetMin()[y], other->GetMax()[y]);
		bool Zaxis = IceBlockMath::intervalcheck(Min[z], Max[z],other->GetMin()[z], other->GetMax()[z]);

		if (Zaxis && Yaxis && Xaxis)
		return true;
		else return false;

	};
	
	//colliding with a Sphere
	virtual bool CollisionTest(BoundingSphereVolume* other);

	virtual void Updatedata()
	{

		ColMatrix = c->getWorld();
		mainColobj = c->getModel();
		Max = IceBlockMath::findMax(mainColobj, &ColMatrix);
		Min = IceBlockMath::findMin(mainColobj, &ColMatrix);

		BoundryPoints();
	}

	Vect ABBBoundryPoint[7];

	void ColliderAABB::BoundryPoints()
	{
		Vect max = Max;
		Vect min = Min;

		ABBBoundryPoint[0] = Vect(max[x], max[y], max[z]);
		ABBBoundryPoint[1] = Vect(min[x], min[y], min[z]);
			
		ABBBoundryPoint[2] = Vect(max[x], max[y], min[z]);
		ABBBoundryPoint[3] = Vect(max[x], min[y], max[z]);
		ABBBoundryPoint[4] = Vect(max[x], min[y], min[z]);

		ABBBoundryPoint[5] = Vect(min[x], min[y], max[z]);
		ABBBoundryPoint[6] = Vect(min[x], max[y], min[z]);
		ABBBoundryPoint[7] = Vect(min[x], max[y], max[z]);
	}

	//returns the max in the ABB
	Vect GetMax()
	{
		return Max;
	}

	//returns the min in the ABB
	Vect GetMin()
	{
		return Min;
	}

	const Matrix getWorld()
	{
		Matrix temp;
		temp = ColMatrix;
		return temp;
	}
};

