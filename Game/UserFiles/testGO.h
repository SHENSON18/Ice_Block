#pragma once
#include "GameObjects.h"
class TestingPair2;
class TestingPair3;
class testGO : public GameObjects
{
public:
	testGO();
	~testGO(void);

//**********VALUES*************************
Matrix TestScale;
Vect TestPos;
Matrix TestRot;
Matrix World;
Vect RenderColor;
//This for testing CollisionAABB this code will be moved to CollisionAABB class once working
	Vect* colArray;
	Vect minPoint;
	Vect maxPoint;
	Vect tempArray;

static float testTranslate;
static float testRotate;

//**********FUNCTIONS**********************
	virtual void Terminate() override;
	virtual void DrawObject() override;
	virtual void Update() override;
	virtual void KeyPressed(AZUL_KEY K);
	virtual void KeyReleased(AZUL_KEY K);
	virtual void Collision(Collidable*) override;
	virtual void Collision(TestingPair2*);
	virtual void Collision(TestingPair3*);
	static GraphicsObjectFlatTexture *testobjectTexture;
	static GraphicsObjectWireFrame *BoundingSphere;
	virtual void Alarm0();

};

