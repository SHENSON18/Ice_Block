#pragma once
#include "GameObjects.h"
class UserCamera : public GameObjects
{
private:
	//************VALUES*********************

	Vect CamUp;			
	Vect CamDir;			
	static float CamTranSpeed;
	static float CamRotSpeed;
	Matrix CamRot;
	Vect CamPos;
public:
	UserCamera();
	~UserCamera();


//**************Functions*****************
	void Update();
	void SetCamRot(float x, float y, float z);

};

