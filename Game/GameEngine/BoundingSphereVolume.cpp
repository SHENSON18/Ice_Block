#include "BoundingSphereVolume.h"
#include "ColliderAABB.h"
#include "ColliderOBB.h"
#include "IceBlockMath.h"


bool BoundingSphereVolume::CollisionTest(ColliderOBB* other)
{
	printf("You Called OBB in BoundingSphere\n");
	Vect center = GetCenter();
	center = center * ColMatrix.getInv();

	if(center[x] < other->GetMin()[x])
		center[x] = other->GetMin()[x];
	else if(center[x] > other->GetMax()[x])
		center[x] = other->GetMax()[x];

	if(center[y] < other->GetMin()[y])
		center[y] = other->GetMin()[y];
	else if(center[y] > other->GetMax()[y])
		center[y] = other->GetMax()[y];

	if(center[z] < other->GetMin()[z])
		center[z] = other->GetMin()[z];
	else if(center[z] > other->GetMax()[z])
		center[z] = other->GetMax()[z];

	center = center * ColMatrix;
	Vect dist = GetCenter() - center;
	return dist.mag() < GetRadius();
}

bool BoundingSphereVolume::CollisionTest(ColliderAABB* other)
{

	//Vect spherecenter;
	printf("You called AABB in BoundingSphere\n");

	Vect spherecenter = IceBlockMath::Clamp(center, other->GetMax(), other->GetMin());
	Vect distance = GetCenter() - spherecenter;
	return distance.mag() < GetRadius();
}



/*bool BoundingSphereVolume::CollisionTest(ColliderVolume* other)
{
	other;
	return false;
	/*
	printf("BoundingSphereVolume is calling collisionTest\n");
	Vect Obj1 = c1->MainColliderObj->getModel()->center * c1->MainColliderObj->getWorld();
	Vect Obj2 = c2->MainColliderObj->getModel()->center * c2->MainColliderObj->getWorld();
	Vect distance = Obj1 - Obj2;
	float dist = distance.mag();
	
	
//*********Get the Magnitude and combined radius of objects
	Matrix base = Matrix(SCALE, c1->MainColliderObj->getModel()->radius, c1->MainColliderObj->getModel()->radius,
		c1->MainColliderObj->getModel()->radius) * Matrix(TRANS, c1->MainColliderObj->getModel()->center);
	Matrix m = base *  c1->MainColliderObj->getWorld();  // here needs to be getWorldMatrix() ;
	Vect modcenter = Vect(0,0,0) * m;
	Vect x = modcenter - (Vect(1,0,0) * m);
	float Obj1radius = x.mag();
//********OBJ 2*************************************
	Matrix base2 = Matrix(SCALE, c2->MainColliderObj->getModel()->radius, c2->MainColliderObj->getModel()->radius,
		c2->MainColliderObj->getModel()->radius) * Matrix(TRANS, c2->MainColliderObj->getModel()->center);
	Matrix m2 = base *  c1->MainColliderObj->getWorld();  // here needs to be getWorldMatrix() ;
	Vect modcenter2 = Vect(0,0,0) * m2;
	Vect y = modcenter2 - (Vect(1,0,0) * m2);
	float Obj2radius = y.mag();


//********ADD THEM TOGATHER AND COMPARE********************
	float radiussum = Obj1radius + Obj2radius;
	
	if( radiussum >= dist)
	{
		//printf("math says I did it");
		return true;
	}
	else
		return false;

		*/

