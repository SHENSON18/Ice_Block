#include "TankBase.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include "level2.h"
#include "level1.h"
#include "BoundingSphereVolume.h"
float TankBase::testTranslate = 1;
float TankBase::testRotate = .05f;
TankBase::TankBase()
{
	//  Add textures and Collider Obj
	//BoundingSphere = new GraphicsObjectWireFrame( ResourceManager::GetModel("BoundingSphere"));
	testobjectTexture = new GraphicsObjectFlatTexture(ResourceManager::GetModel("TankBottom"), ResourceManager::GetTexture("TankBottomEnemy"));
	//MainColliderObj = testobjectTexture;  this is being changed
	// Register Keys
	RegisterKey(AZUL_KEY::KEY_W, KeyboardEnum::KeyPressed);
	RegisterKey(AZUL_KEY::KEY_S, KeyboardEnum::KeyPressed);
	RegisterKey(AZUL_KEY::KEY_A, KeyboardEnum::KeyPressed);
	RegisterKey(AZUL_KEY::KEY_D, KeyboardEnum::KeyPressed);
	RegisterKey(AZUL_KEY::KEY_T, KeyboardEnum::KeyPressed);
	RegisterKey(AZUL_KEY::KEY_T, KeyboardEnum::KeyReleased);
	//Set Matrixes
	TestScale.set( SCALE, .5f, .5f, .5f);  // was .5f
	TestRot.set( ROT_XYZ, 0, 0, 0);
	World = TestScale * TestRot * Matrix( TRANS, TestPos );
	World = Matrix(TRANS, TestPos );
	testobjectTexture->setWorld(World);
	//Register to managers and Collider
	setModel(testobjectTexture->getModel());
	SetColliderVolume(AABB);

	CollidableGroup<TankBase>::Register(this);  //this probably is no longer needed
	RegisterUpdate();  ///register the item
	RegisterDraw();
	//SceneManager::getCurrentScene()->GetUpdateManager()->Register(testgameobject);     ///used to be this in level1.cpp
	//SceneManager::getCurrentScene()->GetDrawManager()->Register(testgameobject);
}


TankBase::~TankBase(void)
{
	//delete BoundingSphere;
	delete testobjectTexture;
	printf("HERE WE GO I DIED\n");
}


void TankBase::Update()
{
	Matrix world =  TestScale * TestRot * Matrix( TRANS, TestPos );
	testobjectTexture->setWorld( world );
	outerSphere->Updatedata();
	colVol->Updatedata();

	//Visualize AABB
	Vect max = IceBlockMath::findMax(testobjectTexture->getModel(), &world);
	Vect min = IceBlockMath::findMin(testobjectTexture->getModel(), &world);
	Visualizer::ShowAABB(max, min, Vect(0,1,0));

	
		// Ship translation movement (not using time-based values for simplicity)
	//if ( InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_W ) )
	//{
	//	TestPos += Vect(0,0,1) * TestRot * testTranslate;
	//}
	//else if ( InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_S ) )
	//{
	//	TestPos += Vect(0,0,1) * TestRot * - testTranslate;
	//}

	//// Ship Rotation movement (not using time-based values for simplicity)
	//if ( InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_A ) )
	//{
	//	TestRot *= Matrix( ROT_Y, testRotate );
	//}
	//else if ( InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_D ) )
	//{
	//	TestRot *= Matrix( ROT_Y, -testRotate );
	//}

}

void TankBase::DrawObject()
{
	//BoundingSphere->Render();
	testobjectTexture->Render();
}  

void TankBase::KeyPressed(AZUL_KEY K)
{
	if( K ==AZUL_KEY::KEY_T)
	{
		testobjectTexture->pTexture0 = ResourceManager::GetTexture("TankBottom");  //make this a funciton call
		//MainColliderObj = testobjectTexture;
	}
	
}

void TankBase::KeyReleased(AZUL_KEY K)
{
	if( K == AZUL_KEY::KEY_T)
	{
		testobjectTexture->pTexture0 = ResourceManager::GetTexture("TankBottomEnemy"); 
		//MainColliderObj = testobjectTexture;
	}
}

//***************COLLISIONS********************
void TankBase::Collision(Collidable*)
{
	//printf("TestGo collided with Collidable\n");
}

void TankBase::Collision(TestGO*)
{
	//MarkForTermination();
	//SceneManager::NextScene(new level1);
	//printf("TestGo collided with TestingPair2\n");

}

void TankBase::Terminate()
{
	DeRegisterUpdate();
	DeRegisterDraw();
	CollidableGroup<TankBase>::deregister(this);
	DeRegisterKey(this, AZUL_KEY::KEY_W, KeyboardEnum::KeyPressed);
	DeRegisterKey(this, AZUL_KEY::KEY_A, KeyboardEnum::KeyPressed);
	DeRegisterKey(this, AZUL_KEY::KEY_S, KeyboardEnum::KeyPressed);
	DeRegisterKey(this, AZUL_KEY::KEY_D, KeyboardEnum::KeyPressed);
	//delete(this);
}
