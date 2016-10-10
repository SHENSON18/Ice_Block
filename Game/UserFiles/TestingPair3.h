#pragma once
#include "GameObjects.h"
class testGO;
class TestingPair3: public GameObjects
{
public:
	TestingPair3();
	~TestingPair3(void);

//**********VALUES*************************
Matrix TestPairScale;
Vect TestPairPos;
Matrix TestPairRot;
Matrix TestPairWorld;
Vect RenderColor;
//This for testing CollisionAABB this code will be moved to CollisionAABB class once working
	Vect* colArray;
	Vect minPoint;
	Vect maxPoint;
	Vect tempArray;


//**********FUNCTIONS**********************

	virtual void DrawObject() override;
	virtual void Update() override;
	virtual void Collision(Collidable*) override;
	virtual void Collision(testGO*) ;
	GraphicsObjectFlatTexture *testPair3Texture;
	static GraphicsObjectWireFrame *BoundingSphere;
};

