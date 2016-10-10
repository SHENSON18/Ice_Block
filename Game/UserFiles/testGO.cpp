#include "testGO.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include "level2.h"
#include "level1.h"
GraphicsObjectFlatTexture* testGO::testobjectTexture;
GraphicsObjectWireFrame* testGO::BoundingSphere;
float testGO::testTranslate = 70;
float testGO::testRotate = 5;
testGO::testGO()
{
	//  Add textures and Collider Obj
	//BoundingSphere = new GraphicsObjectWireFrame( ResourceManager::GetModel("BoundingSphere"));  // Switch this for box and sphere
	testobjectTexture = new GraphicsObjectFlatTexture(ResourceManager::GetModel("SpaceFrigate"), ResourceManager::GetTexture("SpaceFrigate"));

	// Register Keys
	RegisterKey(AZUL_KEY::KEY_W, KeyboardEnum::KeyPressed);
	RegisterKey(AZUL_KEY::KEY_S, KeyboardEnum::KeyPressed);
	RegisterKey(AZUL_KEY::KEY_A, KeyboardEnum::KeyPressed);
	RegisterKey(AZUL_KEY::KEY_D, KeyboardEnum::KeyPressed);
	RegisterKey(AZUL_KEY::KEY_Z, KeyboardEnum::KeyPressed);
	RegisterKey(AZUL_KEY::KEY_X, KeyboardEnum::KeyPressed);
	RegisterKey(AZUL_KEY::KEY_C, KeyboardEnum::KeyPressed);
	RegisterKey(AZUL_KEY::KEY_V, KeyboardEnum::KeyPressed);
	
	RenderColor = Vect(0,0,1);
	//Set Matrixes
	TestScale.set( SCALE, .5f, .5f, .5f);  // was .5f
	TestRot.set( ROT_XYZ, 0, 0, 0);
	TestPos.set(0,20,0);  //was (0,20,0)
	
	World = TestScale * TestRot * Matrix( TRANS, TestPos );
	World = Matrix(TRANS, TestPos );
	testobjectTexture->setWorld(World);
	ResourceManager::UnLoadResources();
	//Setting up collision
	setModel(testobjectTexture->getModel());
	SetColliderVolume(SPHERE);

	//Register to managers
	CollidableGroup<testGO>::Register(this);
	RegisterUpdate();     ///register the item
	RegisterDraw();
	RegisterTime();
	outerSphere->Updatedata();
	//This is added to MINPOINT and MAXPOINT BE SURE THIS IS ADDED TO THE COLLISION VOLUME CLASS for OBB
	//maxPoint = testobjectTexture->getModel()->maxPointAABB;
	//minPoint = testobjectTexture->getModel()->minPointAABB;


}


testGO::~testGO(void)
{
	//SceneManager::getCurrentScene()->GetDumpster()->NowUnused(this);
	delete BoundingSphere;
	delete testobjectTexture;
	//printf("HERE WE GO I DIED\n");
}


void testGO::Update()
{
	
	//RenderColor = Vect(0,0,1);
	Matrix world =  TestScale * TestRot * Matrix( TRANS, TestPos );
	testobjectTexture->setWorld( world );
	outerSphere->Updatedata();
	WorldMat = world;
	colVol->Updatedata();

	//Visualize OBB
	//Vect OBBmax = testobjectTexture->getModel()->maxPointAABB;
	//Vect OBBmin = testobjectTexture->getModel()->minPointAABB;
	//Visualizer::ShowOBB(OBBmax,OBBmin,RenderColor, world);

	//Visualize AABB
	//Vect max = IceBlockMath::findMax(testobjectTexture->getModel(), &world);
	//Vect min = IceBlockMath::findMin(testobjectTexture->getModel(), &world);
	//Visualizer::ShowAABB(max, min, RenderColor);

	//Visualize BoundingSPHERE
	Visualizer::ShowSphere(testobjectTexture->getModel()->center, testobjectTexture->getModel()->radius, testobjectTexture->getWorld(), RenderColor);
	

		// Ship translation movement (Using TimeManager to make them Frame independent and controlled by )
	if ( InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_W ) )
	{
		TestPos += Vect(0,0,1) * TestRot * testTranslate * LeisureTime();
	}
	else if ( InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_S ) )
	{
		TestPos += Vect(0,0,1) * TestRot * - testTranslate * LeisureTime();
	}

	// Ship Rotation movement (not using time-based values for simplicity)
	if ( InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_A ) )
	{
		TestRot *= Matrix( ROT_Y, testRotate * LeisureTime());
	}
	else if ( InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_D ) )
	{
		TestRot *= Matrix( ROT_Y, -testRotate * LeisureTime());
	}
	outerSphere->Updatedata();
	colVol->Updatedata();
	RenderColor = Vect(0,0,1);
}

void testGO::DrawObject()
{
	//BoundingSphere->Render();
	testobjectTexture->Render();
}

void testGO::KeyPressed(AZUL_KEY K)
{
		if( K ==AZUL_KEY::KEY_Z)
	{
		SetTimeScale(0);
		printf ("TimeScale = 0\n");
	}
		if( K ==AZUL_KEY::KEY_X)
	{
		SetTimeScale(0.25f);
		printf ("TimeScale = .025f\n");
	}
		if( K ==AZUL_KEY::KEY_C)
	{
		SetTimeScale(-1);
		printf ("TimeScale = -1\n");
	}
		if( K ==AZUL_KEY::KEY_V)
	{
		SetTimeScale(1);
		        
		printf ("TimeScale = 1\n");
	}
	
}

void testGO::KeyReleased(AZUL_KEY K)
{
	K;
}

//***************COLLISIONS********************
void testGO::Collision(Collidable*)
{
	//printf("TestGo collided with Collidable\n");
}

void testGO::Collision(TestingPair2*)
{
	//MarkForTermination();
	//SceneManager::NextScene(new level2);
	//printf("TestGo collided with TestingPair2\n");
	RenderColor = Vect(1,1,0);

}

void testGO::Collision(TestingPair3*)
{
	RenderColor = Vect(1,0,1);
}

void testGO::Terminate()
{
	DeRegisterUpdate();
	DeRegisterDraw();
	//SceneManager::getCurrentScene()->GetDrawManager()->DeRegister(this);
	CollidableGroup<testGO>::deregister(this);
	DeRegisterKey(this, AZUL_KEY::KEY_W, KeyboardEnum::KeyPressed);
	DeRegisterKey(this, AZUL_KEY::KEY_A, KeyboardEnum::KeyPressed);
	DeRegisterKey(this, AZUL_KEY::KEY_S, KeyboardEnum::KeyPressed);
	DeRegisterKey(this, AZUL_KEY::KEY_D, KeyboardEnum::KeyPressed);
}

void testGO::Alarm0()
{
	printf("I am testGO Alarm0");
}