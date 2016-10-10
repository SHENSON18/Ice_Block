#include "testGO2.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include "level2.h"
#include "level1.h"
#include "BoundingSphereVolume.h"
GraphicsObjectFlatTexture* testGO2::testobjectTexture;
GraphicsObjectWireFrame* testGO2::BoundingSphere;
float testGO2::testTranslate = 1;
float testGO2::testRotate = .05f;
testGO2::testGO2()
{
	//  Add textures and Collider Obj
	BoundingSphere = new GraphicsObjectWireFrame( ResourceManager::GetModel("BoundingSphere"));
	testobjectTexture = new GraphicsObjectFlatTexture(ResourceManager::GetModel("SpaceFrigate"), ResourceManager::GetTexture("SpaceFrigate"));
//	MainColliderObj = testobjectTexture;
	// Register Keys
	RegisterKey(AZUL_KEY::KEY_W, KeyboardEnum::KeyPressed);
	RegisterKey(AZUL_KEY::KEY_S, KeyboardEnum::KeyPressed);
	RegisterKey(AZUL_KEY::KEY_A, KeyboardEnum::KeyPressed);
	RegisterKey(AZUL_KEY::KEY_D, KeyboardEnum::KeyPressed);
	//Set Matrixes
	TestScale.set( SCALE, .5f, .5f, .5f);  // was .5f
	TestRot.set( ROT_XYZ, 0, 0, 0);
	TestPos.set(0,0,0);
	
	World = TestScale * TestRot * Matrix( TRANS, TestPos );
	World = Matrix(TRANS, TestPos );
	testobjectTexture->setWorld(World);
	//Register to managers and Collider
	//collidervolume = new BoundingSphereVolume(&World,testobjectTexture);   //this is new
	CollidableGroup<testGO2>::Register(this);  //this probably is no longer needed
	RegisterUpdate();  ///register the item
	RegisterDraw();
	//SceneManager::getCurrentScene()->GetUpdateManager()->Register(testgameobject);     ///used to be this in level1.cpp
	//SceneManager::getCurrentScene()->GetDrawManager()->Register(testgameobject);
}


testGO2::~testGO2(void)
{
	delete BoundingSphere;
	delete testobjectTexture;
	printf("HERE WE GO I DIED\n");
}


void testGO2::Update()
{
	Matrix world =  TestScale * TestRot * Matrix( TRANS, TestPos );
	testobjectTexture->setWorld( world );
	//collidervolume->Updatedata();  //this is holding collider and new code
	world = Matrix( SCALE, testobjectTexture->getModel()->radius * Vect(1,1,1) )	
		* Matrix( TRANS, testobjectTexture->getModel()->center)
		* world;

	BoundingSphere->setWorld( world );


	
		// Ship translation movement (not using time-based values for simplicity)
	if ( InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_W ) )
	{
		TestPos += Vect(0,0,1) * TestRot * testTranslate;
	}
	else if ( InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_S ) )
	{
		TestPos += Vect(0,0,1) * TestRot * - testTranslate;
	}

	// Ship Rotation movement (not using time-based values for simplicity)
	if ( InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_A ) )
	{
		TestRot *= Matrix( ROT_Y, testRotate );
	}
	else if ( InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_D ) )
	{
		TestRot *= Matrix( ROT_Y, -testRotate );
	}

}

void testGO2::DrawObject()
{
	BoundingSphere->Render();
	testobjectTexture->Render();
}

void testGO2::KeyPressed(AZUL_KEY K)
{
	K;
	
}

void testGO2::KeyReleased(AZUL_KEY K)
{
	K;
}

//***************COLLISIONS********************
void testGO2::Collision(Collidable*)
{
	//printf("TestGo collided with Collidable\n");
}

void testGO2::Collision(TestingPair2*)
{
	MarkForTermination();
	SceneManager::NextScene(new level1);
	//printf("TestGo collided with TestingPair2\n");

}

void testGO2::Terminate()
{
	DeRegisterUpdate();
	DeRegisterDraw();
	CollidableGroup<testGO2>::deregister(this);
	DeRegisterKey(this, AZUL_KEY::KEY_W, KeyboardEnum::KeyPressed);
	DeRegisterKey(this, AZUL_KEY::KEY_A, KeyboardEnum::KeyPressed);
	DeRegisterKey(this, AZUL_KEY::KEY_S, KeyboardEnum::KeyPressed);
	DeRegisterKey(this, AZUL_KEY::KEY_D, KeyboardEnum::KeyPressed);
	//delete(this);
}
