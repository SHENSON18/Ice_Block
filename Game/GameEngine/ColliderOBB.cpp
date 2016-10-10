#include "ColliderOBB.h"
#include "BoundingSphereVolume.h"
#include "ColliderAABB.h"


ColliderOBB::~ColliderOBB(void)
{
}

bool ColliderOBB::CollisionTest(ColliderAABB* other)
{
	printf("You Called AABB in OBB\n");
	Vect a1 = ColMatrix.get(MatrixRowType::ROW_0);
	Vect a2 = ColMatrix.get(MatrixRowType::ROW_1);
	Vect a3 = ColMatrix.get(MatrixRowType::ROW_2);

	Vect b1 = other->getWorld().get(MatrixRowType::ROW_0);
	Vect b2 = other->getWorld().get(MatrixRowType::ROW_1);
	Vect b3 = other->getWorld().get(MatrixRowType::ROW_2);
	
	return (IceBlockMath::SATintervalCheck(OBBBoundryPoint, 8, other->ABBBoundryPoint, 8, a1)
		 && IceBlockMath::SATintervalCheck(OBBBoundryPoint, 8, other->ABBBoundryPoint, 8, a2)
		 && IceBlockMath::SATintervalCheck(OBBBoundryPoint, 8, other->ABBBoundryPoint, 8, a3)
		 && IceBlockMath::SATintervalCheck(OBBBoundryPoint, 8, other->ABBBoundryPoint, 8, b1)
		 && IceBlockMath::SATintervalCheck(OBBBoundryPoint, 8, other->ABBBoundryPoint, 8, b2)
		 && IceBlockMath::SATintervalCheck(OBBBoundryPoint, 8, other->ABBBoundryPoint, 8, b3)
		 && IceBlockMath::SATintervalCheck(OBBBoundryPoint, 8, other->ABBBoundryPoint, 8, a1.cross(b1))
		 && IceBlockMath::SATintervalCheck(OBBBoundryPoint, 8, other->ABBBoundryPoint, 8, a1.cross(b2))
		 && IceBlockMath::SATintervalCheck(OBBBoundryPoint, 8, other->ABBBoundryPoint, 8, a1.cross(b3))
		 && IceBlockMath::SATintervalCheck(OBBBoundryPoint, 8, other->ABBBoundryPoint, 8, a2.cross(b1))
		 && IceBlockMath::SATintervalCheck(OBBBoundryPoint, 8, other->ABBBoundryPoint, 8, a2.cross(b2))
		 && IceBlockMath::SATintervalCheck(OBBBoundryPoint, 8, other->ABBBoundryPoint, 8, a2.cross(b3))
		 && IceBlockMath::SATintervalCheck(OBBBoundryPoint, 8, other->ABBBoundryPoint, 8, a3.cross(b1))
		 && IceBlockMath::SATintervalCheck(OBBBoundryPoint, 8, other->ABBBoundryPoint, 8, a3.cross(b2))
		 && IceBlockMath::SATintervalCheck(OBBBoundryPoint, 8, other->ABBBoundryPoint, 8, a3.cross(b3)));



}

bool ColliderOBB::CollisionTest(BoundingSphereVolume* other)
{
	//reformat
	printf("You Called Bounding SPhere in OBB\n");
	Vect center = other->GetCenter();
	center = center * ColMatrix.getInv();

	if(center[x] < Min[x])
		center[x] = Min[x];
	else if(center[x] > Max[x])
		center[x] = Max[x];

	if(center[y] < Min[y])
		center[y] = Min[y];
	else if(center[y] > Max[y])
		center[y] = Max[y];

	if(center[z] < Min[z])
		center[z] = Min[z];
	else if(center[z] > Max[z])
		center[z] = Max[z];

	center = center * ColMatrix;
	Vect dist = other->GetCenter() - center;
	return dist.mag() < other->GetRadius();
}

bool ColliderOBB::CollisionTest(ColliderOBB* other)
{
	//printf("You Called OBB in OBB\n");
	Vect a1 = ColMatrix.get(MatrixRowType::ROW_0);
	Vect a2 = ColMatrix.get(MatrixRowType::ROW_1);
	Vect a3 = ColMatrix.get(MatrixRowType::ROW_2);

	Vect b1 = other->getWorldMat().get(MatrixRowType::ROW_0);
	Vect b2 = other->getWorldMat().get(MatrixRowType::ROW_1);
	Vect b3 = other->getWorldMat().get(MatrixRowType::ROW_2);
	
	return (IceBlockMath::SATintervalCheck(OBBBoundryPoint, 8, other->OBBBoundryPoint, 8, a1)
		 && IceBlockMath::SATintervalCheck(OBBBoundryPoint, 8, other->OBBBoundryPoint, 8, a2)
		 && IceBlockMath::SATintervalCheck(OBBBoundryPoint, 8, other->OBBBoundryPoint, 8, a3)
		 && IceBlockMath::SATintervalCheck(OBBBoundryPoint, 8, other->OBBBoundryPoint, 8, b1)
		 && IceBlockMath::SATintervalCheck(OBBBoundryPoint, 8, other->OBBBoundryPoint, 8, b2)
		 && IceBlockMath::SATintervalCheck(OBBBoundryPoint, 8, other->OBBBoundryPoint, 8, b3)
		 && IceBlockMath::SATintervalCheck(OBBBoundryPoint, 8, other->OBBBoundryPoint, 8, a1.cross(b1))
		 && IceBlockMath::SATintervalCheck(OBBBoundryPoint, 8, other->OBBBoundryPoint, 8, a1.cross(b2))
		 && IceBlockMath::SATintervalCheck(OBBBoundryPoint, 8, other->OBBBoundryPoint, 8, a1.cross(b3))
		 && IceBlockMath::SATintervalCheck(OBBBoundryPoint, 8, other->OBBBoundryPoint, 8, a2.cross(b1))
		 && IceBlockMath::SATintervalCheck(OBBBoundryPoint, 8, other->OBBBoundryPoint, 8, a2.cross(b2))
		 && IceBlockMath::SATintervalCheck(OBBBoundryPoint, 8, other->OBBBoundryPoint, 8, a2.cross(b3))
		 && IceBlockMath::SATintervalCheck(OBBBoundryPoint, 8, other->OBBBoundryPoint, 8, a3.cross(b1))
		 && IceBlockMath::SATintervalCheck(OBBBoundryPoint, 8, other->OBBBoundryPoint, 8, a3.cross(b2))
		 && IceBlockMath::SATintervalCheck(OBBBoundryPoint, 8, other->OBBBoundryPoint, 8, a3.cross(b3)));


}