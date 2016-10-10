////////////////////////////////////////////////////////////////////////////////////////////////////
// file:	GameEngine\Collidable.cpp
//
// summary:	Implements the collidable class
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Collidable.h"
#include "Visualizer.h"
#include "BoundingSphereVolume.h"
#include "ColliderAABB.h"
#include "ColliderVolume.h"
#include "ColliderOBB.h"

//float negativevalue = -1000000;
//float positivevalue = 10000000;
////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Default constructor. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

Collidable::Collidable(void)
{
	colVol = NULL;
	outerSphere = new BoundingSphereVolume(this); //sets outersphere for engine use
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

Collidable::~Collidable(void)
{
	delete colVol;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Collision against the given GameObject. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
///
/// <param name="parameter1">	[in,out] GameObject. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Collidable::Collision(Collidable*)
{

	printf("I have collided");


}



void Collidable::SetColliderVolume(COLVOLUMES vol)
{
	switch (vol)
	{
		//fill as you go
	case SPHERE:
		colVol = new BoundingSphereVolume(this);
		break;
	case OBB:
		colVol = new ColliderOBB(this);
		break;
	case AABB:
		colVol = new ColliderAABB(this);
		break;
	default:
		break;
	}
}
// List of Commands that can be called by user
void Collidable::setModel(Model *temp)
{
	MainColliderObj = temp;
}

Model* Collidable::getModel()
{
	return MainColliderObj;
}

Matrix Collidable::getWorld()
{
	return WorldMat;
}




////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Tests collision pair. </summary>
///
/// <remarks>	Theonlyhunter, 3/13/2015. </remarks>
///
/// <param name="c1">	[in,out] If non-null, the first Collidable. </param>
/// <param name="c2">	[in,out] If non-null, the second Collidable. </param>
///
/// <returns>	true if a collision between the given pair happened, false a collision did not happen </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

bool Collidable::TestCollisionPair(Collidable* c1, Collidable* c2)  //This collision is for bounding spheres.  must be moved to bounding sphere class
{
	return c1->colVol->Accept(c2->colVol);
	//return Collidable::CollisionTest(Collidable* c1, Collidable c2*); here will be the call for visitor pattern
	/*

	//THIS BLOCK IS FOR SPHERE
	//printf("TestCollisionPair is calling collisionTest\n");
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


	//*/


/////////////////////////////////////////////////////////////////////////////////
	//THIS BLOCK FOR AABB
	/*
	//these are used to hold the collision state for each axis
	

	bool Xaxis;
	bool Yaxis;
	bool Zaxis;

	//Vect* colArray;
	//Vect* colArray2;
	//Vect minPointc1;   ////
	//Vect maxPointc1;   These values may not be needed
	//Vect maxPointc2;
	//Vect minPointc2;   ////
	Vect tempArray;
	Vect tempArray2;
	//colArray = c1->MainColliderObj->getModel()->getVectList(); 
	//maxc1
	float maximumXc1 = IceBlockMath::negativevalue;
	float maximumYc1 = IceBlockMath::negativevalue;
	float maximumZc1 = IceBlockMath::negativevalue;
	//minc1
	float minimumXc1 = IceBlockMath::positivevalue;
	float minimumYc1 = IceBlockMath::positivevalue;
	float minimumZc1 = IceBlockMath::positivevalue;

	//max
	float maximumXc2 = IceBlockMath::negativevalue;
	float maximumYc2 = IceBlockMath::negativevalue;
	float maximumZc2 = IceBlockMath::negativevalue;
	//min
	float minimumXc2 = IceBlockMath::positivevalue;
	float minimumYc2 = IceBlockMath::positivevalue;
	float minimumZc2 = IceBlockMath::positivevalue;

	//for loop
	for(int i=0; i < c1->MainColliderObj->getModel()->numVerts; i++)
	{
		tempArray= *(c1->MainColliderObj->getModel()->getVectList()+i); //This makes the temp arrary equal to the items vector list
		tempArray = tempArray*(c1->MainColliderObj->getWorld());  //this makes the array aligned with world.

		if(tempArray[x] < minimumXc1)
			minimumXc1 = tempArray[x];

		else if(tempArray[x] > maximumXc1)
			maximumXc1 = tempArray[x];

		else if(tempArray[y] < minimumYc1)
			minimumYc1 = tempArray[y];

		else if(tempArray[y] > maximumYc1)
			maximumYc1 = tempArray[y];

		else if(tempArray[z] < minimumZc1)
			minimumZc1 = tempArray[z];

		else if(tempArray[z] > maximumZc1)
			maximumZc1 = tempArray[z];
	}
	//printf("%f min x \n%f max x \n %f min y\n %f max y\n %f min z \n %f max z\n",minimumX,maximumX,minimumY,maximumY,minimumZ,maximumZ);
	//minPointc1 = Vect(minimumXc1,minimumYc1,minimumZc1);
	//maxPointc1 = Vect(maximumXc1,maximumYc1, maximumZc1);
		//for loop two for c2
	//colArray2 = c2->MainColliderObj->getModel()->getVectList();

	for(int i=0; i < c2->MainColliderObj->getModel()->numVerts; i++)
	{
		tempArray2= *(c2->MainColliderObj->getModel()->getVectList()+i); //this makes the array aligned with world.
		tempArray2 = tempArray2*(c2->MainColliderObj->getWorld());
		//make this a funciton for GetMax where you find the max for each point and GetMin min for each point

		if(tempArray2[x] < minimumXc2)
			minimumXc2 = tempArray2[x];

		else if(tempArray2[x] > maximumXc2)
			maximumXc2 = tempArray2[x];

		else if(tempArray2[y] < minimumYc2)
			minimumYc2 = tempArray2[y];

		else if(tempArray2[y] > maximumYc2)
			maximumYc2 = tempArray2[y];

		else if(tempArray2[z] < minimumZc2)
			minimumZc2 = tempArray2[z];

		else if(tempArray2[z] > maximumZc2)
			maximumZc2 = tempArray2[z];
	}
	//minPointc2 = Vect(minimumXc2,minimumYc2,minimumZc2);
	//maxPointc2 = Vect(maximumXc2,maximumYc2, maximumZc2);
	
	///////////////////////////////////
	//Now the actual math
	Visualizer::ShowMarker(tempArray,tempArray,1);
	Xaxis = IceBlockMath::intervalcheck(minimumXc1,maximumXc1,minimumXc2,maximumXc2);
	Yaxis = IceBlockMath::intervalcheck(minimumYc1,maximumYc1,minimumYc2,maximumYc2);
	Zaxis = IceBlockMath::intervalcheck(minimumZc1,maximumZc1,minimumZc2,maximumZc2);

	if (Zaxis && Yaxis && Xaxis)
		return true;
	 return false;


//////////////////////////////////////////////////////////////////
//		End of AABB COLLISION BLOCK  THIS WILL NEED TO BE MOVED TO AABB COLLIDER VOLUME
	//*/
}