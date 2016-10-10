#include "ColliderAABB.h"
#include "ColliderOBB.h"
#include "BoundingSphereVolume.h"


ColliderAABB::~ColliderAABB(void)
{
}

bool ColliderAABB::CollisionTest(ColliderOBB* other)
{
	printf("You Called OBB in AABB\n");
	Vect a1 = ColMatrix.get(MatrixRowType::ROW_0);
	Vect a2 = ColMatrix.get(MatrixRowType::ROW_1);
	Vect a3 = ColMatrix.get(MatrixRowType::ROW_2);

	Vect b1 = getWorld().get(MatrixRowType::ROW_0);
	Vect b2 = getWorld().get(MatrixRowType::ROW_1);
	Vect b3 = getWorld().get(MatrixRowType::ROW_2);
	
	return (IceBlockMath::SATintervalCheck(other->OBBBoundryPoint, 8, ABBBoundryPoint, 8, a1)
		 && IceBlockMath::SATintervalCheck(other->OBBBoundryPoint, 8, ABBBoundryPoint, 8, a2)
		 && IceBlockMath::SATintervalCheck(other->OBBBoundryPoint, 8, ABBBoundryPoint, 8, a3)
		 && IceBlockMath::SATintervalCheck(other->OBBBoundryPoint, 8, ABBBoundryPoint, 8, b1)
		 && IceBlockMath::SATintervalCheck(other->OBBBoundryPoint, 8, ABBBoundryPoint, 8, b2)
		 && IceBlockMath::SATintervalCheck(other->OBBBoundryPoint, 8, ABBBoundryPoint, 8, b3)
		 && IceBlockMath::SATintervalCheck(other->OBBBoundryPoint, 8, ABBBoundryPoint, 8, a1.cross(b1))
		 && IceBlockMath::SATintervalCheck(other->OBBBoundryPoint, 8, ABBBoundryPoint, 8, a1.cross(b2))
		 && IceBlockMath::SATintervalCheck(other->OBBBoundryPoint, 8, ABBBoundryPoint, 8, a1.cross(b3))
		 && IceBlockMath::SATintervalCheck(other->OBBBoundryPoint, 8, ABBBoundryPoint, 8, a2.cross(b1))
		 && IceBlockMath::SATintervalCheck(other->OBBBoundryPoint, 8, ABBBoundryPoint, 8, a2.cross(b2))
		 && IceBlockMath::SATintervalCheck(other->OBBBoundryPoint, 8, ABBBoundryPoint, 8, a2.cross(b3))
		 && IceBlockMath::SATintervalCheck(other->OBBBoundryPoint, 8, ABBBoundryPoint, 8, a3.cross(b1))
		 && IceBlockMath::SATintervalCheck(other->OBBBoundryPoint, 8, ABBBoundryPoint, 8, a3.cross(b2))
		 && IceBlockMath::SATintervalCheck(other->OBBBoundryPoint, 8, ABBBoundryPoint, 8, a3.cross(b3)));


}

bool ColliderAABB::CollisionTest(BoundingSphereVolume* other)
	{
		printf("You called BoundingSphere in AABB\n");
		Vect spherecenter = IceBlockMath::Clamp(other->GetCenter(), Max, Min);
		Vect distance = other->GetCenter() - spherecenter;
		return distance.mag() < other->GetRadius();
	}


//bool ColliderAABB::CollisionTest(ColliderVolume* other)
//{
//	other;
//	return false;
//	/*
//		//these are used to 
//	bool Xaxis;
//	bool Yaxis;
//	bool Zaxis;
//
//	Vect* colArray;
//	Vect* colArray2;
//	Vect minPointc1;
//	Vect maxPointc1;
//	Vect maxPointc2;
//	Vect minPointc2;
//	Vect tempArray;
//	Vect tempArray2;
//	colArray = c1->MainColliderObj->getModel()->getVectList(); 
//	//maxc1
//	float maximumXc1 = tempArray[x];
//	float maximumYc1 = tempArray[y];
//	float maximumZc1 = tempArray[z];
//	//minc1
//	float minimumXc1 = tempArray[x];
//	float minimumYc1 = tempArray[y];
//	float minimumZc1 = tempArray[z];
//
//	//max
//	float maximumXc2 = tempArray2[x];
//	float maximumYc2 = tempArray2[y];
//	float maximumZc2 = tempArray2[z];
//	//min
//	float minimumXc2 = tempArray2[x];
//	float minimumYc2 = tempArray2[y];
//	float minimumZc2 = tempArray2[z];
//
//	//for loop
//	for(int i=0; i < c1->MainColliderObj->getModel()->numVerts; i++)
//	{
//		tempArray= colArray[i]*(c1->MainColliderObj->getWorld());  //this makes the array aligned with world.
//
//		if(tempArray[x] < minimumXc1)
//			minimumXc1 = tempArray[x];
//
//		else if(tempArray[x] > maximumXc1)
//			maximumXc1 = tempArray[x];
//
//		else if(tempArray[y] < minimumYc1)
//			minimumYc1 = tempArray[y];
//
//		else if(tempArray[y] > maximumYc1)
//			maximumYc1 = tempArray[y];
//
//		else if(tempArray[z] < minimumZc1)
//			minimumZc1 = tempArray[z];
//
//		else if(tempArray[z] > maximumZc1)
//			maximumZc1 = tempArray[z];
//	}
//	//printf("%f min x \n%f max x \n %f min y\n %f max y\n %f min z \n %f max z\n",minimumX,maximumX,minimumY,maximumY,minimumZ,maximumZ);
//	minPointc1 = Vect(minimumXc1,minimumYc1,minimumZc1);
//	maxPointc1 = Vect(maximumXc1,maximumYc1, maximumZc1);
//		//for loop two for c2
//	colArray2 = c2->MainColliderObj->getModel()->getVectList();
//
//	for(int i=0; i < c2->MainColliderObj->getModel()->numVerts; i++)
//	{
//		tempArray2= colArray2[i]*(c2->MainColliderObj->getWorld());  //this makes the array aligned with world.
//
//		if(tempArray2[x] < minimumXc2)
//			minimumXc2 = tempArray2[x];
//
//		else if(tempArray2[x] > maximumXc2)
//			maximumXc2 = tempArray2[x];
//
//		else if(tempArray2[y] < minimumYc2)
//			minimumYc2 = tempArray2[y];
//
//		else if(tempArray2[y] > maximumYc2)
//			maximumYc2 = tempArray2[y];
//
//		else if(tempArray2[z] < minimumZc2)
//			minimumZc2 = tempArray2[z];
//
//		else if(tempArray2[z] > maximumZc2)
//			maximumZc2 = tempArray2[z];
//	}
//	minPointc2 = Vect(minimumXc2,minimumYc2,minimumZc2);
//	maxPointc2 = Vect(maximumXc2,maximumYc2, maximumZc2);
//	
//	///////////////////////////////////
//	//Now the actual math
//
//	Xaxis = IceBlockMath::intervalcheck(minimumXc1,maximumXc1,minimumXc2,maximumXc2);
//	Yaxis = IceBlockMath::intervalcheck(minimumYc1,maximumYc1,minimumYc2,maximumYc2);
//	Zaxis = IceBlockMath::intervalcheck(minimumZc1,maximumZc1,minimumZc2,maximumZc2);
//
//	if (Zaxis && Yaxis && Xaxis)
//		return true;
//	else return false;
//	*/
//}
