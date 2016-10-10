#pragma once
#include "GameObjects.h"
#include "TankBase.h"
class TankTurret : public GameObjects
{
public:
	TankTurret(TankBase* tank);
	virtual ~TankTurret(void);

Matrix TurretRotate;
Vect TurretPos;
Vect TurretHeight;
Matrix TurretScale;
Matrix TurretWorld;
TankBase* tankbase;
static float turretRotate;
static float turretTranslate;

virtual void Update() override;
virtual void KeyPressed(AZUL_KEY K) override;
virtual void DrawObject() override;


static GraphicsObjectFlatTexture *tankturret;
};

