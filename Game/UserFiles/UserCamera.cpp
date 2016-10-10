#include "UserCamera.h"
#include "Game.h"

float UserCamera::CamTranSpeed = 2;
float UserCamera::CamRotSpeed = .02f;

UserCamera::UserCamera(void)
{
	//Set Matrix 
	CamPos.set(50,50,100.0f);
	CamRot.set( IDENTITY);
	CamUp.set(0, 1, 0);
	CamDir.set(0,0,1);

	CameraMan::GetCurrent()->setViewport( 0, 0, Game::WindowWidth(), Game::WindowHeight());
	CameraMan::GetCurrent()->setPerspective( 45, float(Game::WindowWidth())/float(Game::WindowHeight()), 1, 5000);
	
	Vect Target(0,0,0);
	CamRot = Matrix( Quat( ROT_ORIENT, Target - CamPos, CamUp));

	CameraMan::GetCurrent()->setOrientAndPosition( CamUp * CamRot, CamPos + CamDir * CamRot, CamPos);
	CameraMan::GetCurrent()->updateCamera();
	//Register to update
	SceneManager::getCurrentScene()->GetUpdateManager()->Register(this);
}


UserCamera::~UserCamera(void)
{
	SceneManager::getCurrentScene()->GetUpdateManager()->DeRegister(this);
}

void UserCamera::Update()
{
		// Camera translation movement (not using time-based values for simplicity)
	if ( InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_I ) )
	{
		CamPos += Vect(0,0,1) * CamRot * CamTranSpeed;
	}
	else if ( InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_K ) )
	{
		CamPos += Vect(0,0,1) * CamRot * - CamTranSpeed;
	}

	if ( InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_J ) )
	{
		CamPos += Vect(1,0,0) * CamRot * CamTranSpeed;
	}
	else if ( InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_L ) )
	{
		CamPos += Vect(1,0,0) * CamRot * -CamTranSpeed;
	}

	// Camera Rotation movement (not using time-based values for simplicity)
	if ( InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_LEFT ) )
	{
		CamRot *= Matrix( ROT_Y, CamRotSpeed );
	}
	else if ( InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_RIGHT ) )
	{
		CamRot *= Matrix( ROT_Y, -CamRotSpeed );
	}

	if ( InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_UP ) )
	{
		CamRot *= Matrix( Quat( ROT_AXIS_ANGLE, Vect(1,0,0) * CamRot, -CamRotSpeed) );
	}
	else if ( InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_DOWN ) )
	{
		CamRot *= Matrix( Quat( ROT_AXIS_ANGLE, Vect(1,0,0) * CamRot, CamRotSpeed) );
	}


	CameraMan::GetCurrent()->setOrientAndPosition( CamUp * CamRot, CamPos + CamDir * CamRot, CamPos);
	CameraMan::GetCurrent()->updateCamera();
	
}
