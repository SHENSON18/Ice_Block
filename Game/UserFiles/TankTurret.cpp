#include "TankTurret.h"
#include "ResourceManager.h"
#include "SceneManager.h"
GraphicsObjectFlatTexture* TankTurret::tankturret;
float TankTurret::turretRotate = .05f;
float TankTurret::turretTranslate = 1;
TankTurret::TankTurret(TankBase *tank)
{
	tankturret = new GraphicsObjectFlatTexture(ResourceManager::GetModel("TankTop"), ResourceManager::GetTexture("TankTopEnemy"));
	tankbase = tank;
	RegisterKey(AZUL_KEY::KEY_J, KeyboardEnum::KeyPressed);
	RegisterKey(AZUL_KEY::KEY_L, KeyboardEnum::KeyPressed);

	TurretScale.set( SCALE, .5f, .5f, .5f);
	TurretRotate.set ( ROT_XYZ, 0 ,0 ,0 );
	TurretHeight.set(0,5,0);
	TurretPos.set((tankbase->TestPos)+TurretHeight);
	TurretWorld = TurretScale * TurretRotate* Matrix( TRANS, TurretPos);
	TurretWorld = Matrix(TRANS, TurretPos );
	tankturret->setWorld(TurretWorld);

	RegisterUpdate();
	RegisterDraw();

}


TankTurret::~TankTurret(void)
{
}


void TankTurret::Update()
{
	Matrix world = TurretScale * TurretRotate * Matrix( TRANS, (tankbase->TestPos)+ TurretHeight );
	tankturret->setWorld(world);

			// Ship translation movement (not using time-based values for simplicity)

	// Ship Rotation movement (not using time-based values for simplicity)
	if ( InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_L ) )
	{
		TurretRotate *= Matrix( ROT_Y, turretRotate );
	}
	else if ( InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_J ) )
	{
		TurretRotate *= Matrix( ROT_Y, -turretRotate );
	}

}

void TankTurret::KeyPressed(AZUL_KEY K)
{
	K;
}


void TankTurret::DrawObject()
{
	tankturret->Render();
}