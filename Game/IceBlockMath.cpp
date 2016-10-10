#include "IceBlockMath.h"
#include <iostream>
#include <math.h>
float IceBlockMath::negativevalue = -10000000;
float IceBlockMath::positivevalue = 10000000;
bool IceBlockMath::intervalcheck(float min1, float max1, float min2, float max2)
	{
		float i0 = max(min1,min2);
		float i1 = min(max1,max2);
		return (i0 <= i1);
	}

Vect IceBlockMath::findMax(Model *obj, Matrix *objMat)
{
	Vect tempVect = *(obj->getVectList());
	tempVect = tempVect * *objMat;
	float maxX = tempVect[x];
	float maxY = tempVect[y];
	float maxZ = tempVect[z];
	for( int i = 0; i < obj->numVerts; i++)
	{
		tempVect = *(obj->getVectList() + i);
		tempVect = tempVect * *objMat;
	if( tempVect[x] > maxX)
		maxX = tempVect[x];
	if( tempVect[y] > maxY)
		maxY = tempVect[y];
	if( tempVect[z] > maxZ)
		maxZ = tempVect[z];
	}
	return Vect(maxX,maxY,maxZ);
}

Vect IceBlockMath::findMin(Model *obj, Matrix *objMat)
{
	Vect tempVect = *(obj->getVectList());
	tempVect = tempVect * *objMat;
	float minX = tempVect[x];
	float minY = tempVect[y];
	float minZ = tempVect[z];
	for( int i = 0; i < obj->numVerts; i++)
	{
		tempVect = *(obj->getVectList() + i);
		tempVect = tempVect * *objMat;
	if( tempVect[x] < minX)
		minX = tempVect[x];
	if( tempVect[y] < minY)
		minY = tempVect[y];
	if( tempVect[z] < minZ)
		minZ = tempVect[z];
	}
	return Vect(minX,minY,minZ);
}

Vect IceBlockMath::Clamp(const Vect &pos,const Vect &Maxpoint, const Vect &Minpoint)
{
	Vect center = pos;
	if (center[x] > Maxpoint[x])
		center[x] = Maxpoint[x];
	else if (center[x] < Minpoint[x])
		center[x] = Minpoint[x];
	
	if (center[y] > Maxpoint[y])
		center[y] = Maxpoint[y];
	else if (center[y] < Minpoint[y])
		center[y] = Minpoint[y];
	
	if (center[z] > Maxpoint[z])
	center[z] = Maxpoint[z];
	else if (center[z] < Minpoint[z])
	center[z] = Minpoint[z];

	return center;
}

bool IceBlockMath::GroupCheck(const Vect &C1Max, const Vect &C1Min, const Vect &C2Max, const Vect &C2Min)
{
	return (IceBlockMath::intervalcheck(C1Min[x], C1Max[x], C2Min[x], C2Max[x])
		&&IceBlockMath::intervalcheck(C1Min[y], C1Max[y], C2Min[y], C2Max[y])
		&&IceBlockMath::intervalcheck(C1Min[z], C1Max[z], C2Min[z], C2Max[z]));
}

bool IceBlockMath::SATintervalCheck(Vect Aboundry[], float Asize, Vect Bboundry[], float Bsize, const Vect &axis)
{
	float maxA = Aboundry[0].dot(axis);
	float minA = Aboundry[0].dot(axis);
	float maxB = Bboundry[0].dot(axis);
	float minB = Bboundry[0].dot(axis);

	for(int i = 1; i < Asize; i++)
	{
		float temp = Aboundry[i].dot(axis);

		maxA = max(maxA, temp);
		minA = min(minA, temp);
	}

	for(int i = 1; i < Bsize; i++)
	{
		float temp = Bboundry[i].dot(axis);

		maxB = max(maxB, temp);
		minB = min(minB, temp);
	}
	return intervalcheck(minA,maxA,minB,maxB);
}