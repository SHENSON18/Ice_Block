#pragma once
#include "GameObjects.h"
class TestGO;
class TankBase : public GameObjects
{
public:
	TankBase();
	~TankBase(void);

//**********VALUES*************************
Matrix TestScale;
Vect TestPos;
Matrix TestRot;
Matrix World;


static float testTranslate;
static float testRotate;

//**********FUNCTIONS**********************
	virtual void Terminate() override;
	virtual void DrawObject() override;
	virtual void Update() override;
	virtual void KeyPressed(AZUL_KEY K);
	virtual void KeyReleased(AZUL_KEY K);
	virtual void Collision(Collidable*) override;
	virtual void Collision(TestGO*);
	GraphicsObjectFlatTexture *testobjectTexture;
	static GraphicsObjectWireFrame *BoundingSphere;
};
