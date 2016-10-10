#pragma once
#include "Azul.h"
class IceBlockMath
{
public:
	//Variable for AABB
	static float negativevalue;
	static float positivevalue;
	//Tool for checking intervals along a axis
	static bool intervalcheck(float min1, float max1, float min2, float max2);
	//Finds the Max/Min of a model
	static Vect findMax(Model *obj, Matrix * objMat);
	static Vect findMin(Model *obj, Matrix * objMat);

	//Clamping Tool for objects
	static Vect Clamp(const Vect &pos,const Vect &Maxpoint,const Vect &Minpoint);
	//Separating Axis therom
	static bool SATintervalCheck(Vect ABoundry[], float Asize, Vect BBoundry[], float Bsize, const Vect &axis);
	//group check for collision groups
	static bool GroupCheck(const Vect &C1Max, const Vect &C1Min, const Vect &C2Max, const Vect &C2Min);
};