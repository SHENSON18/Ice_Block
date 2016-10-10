#include "TestingPair2.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include "math.h"
//GraphicsObjectWireFrame* TestingPair2::BoundingSphere;

TestingPair2::TestingPair2()
{
	srand(0);
	//  Add Textures and Collider Obj
	//BoundingSphere = new GraphicsObjectWireFrame( ResourceManager::GetModel("BoundingBox"));
	testPair2Texture = new GraphicsObjectFlatTexture(ResourceManager::GetModel("SpaceFrigate"), ResourceManager::GetTexture("SpaceFrigate")); 

//	MainColliderObj = testPair2Texture;

	//Set Matrices
	TestPairScale.set( SCALE, .6f, .6f, .6f);
	TestPairRot.set( ROT_XYZ, 0, 90, 0);
	TestPairPos.set(-90,20,0);
	
	TestPairWorld = TestPairScale * TestPairRot * Matrix( TRANS, TestPairPos );
	TestPairWorld = Matrix(TRANS, TestPairPos );
	testPair2Texture->setWorld(TestPairWorld);
	RenderColor = Vect(0,0,1);

	//  Setting Collider
	setModel(testPair2Texture->getModel());
	SetColliderVolume(OBB);

	//Register to managers
	RegisterTime();
	RegisterUpdate();
	RegisterDraw();
	CollidableGroup<TestingPair2>::Register(this);

	// Register Keys
	RegisterKey(AZUL_KEY::KEY_G, KeyboardEnum::KeyPressed);

}
void TestingPair2::Update()
{
	Matrix world =  TestPairScale * TestPairRot * Matrix( TRANS, TestPairPos );
	testPair2Texture->setWorld( world );
	outerSphere->Updatedata();
	WorldMat = world;
	colVol->Updatedata();
	//Visualize OBB
	Vect OBBmax = testPair2Texture->getModel()->maxPointAABB;
	Vect OBBmin = testPair2Texture->getModel()->minPointAABB;
	Visualizer::ShowOBB(OBBmax,OBBmin,RenderColor, world);

	TestPairRot *= Matrix( ROT_Y, 5 * AlphaTime());
	//Visualize AABB
	//Vect max = IceBlockMath::findMax(testPair2Texture->getModel(), &world);
	//Vect min = IceBlockMath::findMin(testPair2Texture->getModel(), &world);
	//Visualizer::ShowAABB(max,min, RenderColor);
	/*
	//TestPairPos += Vect(0,0,1) * TestPairRot * 50 * TimeManager::deltatime;
//sets collider move this to each individual class when you work.
///////////////////////////////////////////////////////////////////////////////	
	//find min and max
	colArray = MainColliderObj->getModel()->getVectList();  //was boundingsphere
	//max
	float maximumX= tempArray[x];
	float maximumY= tempArray[y];
	float maximumZ= tempArray[z];
	//min
	float minimumX= tempArray[x];
	float minimumY= tempArray[y];
	float minimumZ= tempArray[z];

	//for loop
	for(int i=0; i < MainColliderObj->getModel()->numVerts; i++)
	{
		tempArray= colArray[i]*(world);  //this makes the array aligned with world.
		//printf("TempArray X = %f and maximumX = %f \n",tempArray[x], maximumX ); 
		if(tempArray[x] < minimumX)
			minimumX = tempArray[x];

		else if(tempArray[x] > maximumX)
			maximumX = tempArray[x];

		else if(tempArray[y] < minimumY)
			minimumY = tempArray[y];

		else if(tempArray[y] > maximumY)
			maximumY = tempArray[y];

		else if(tempArray[z] < minimumZ)
			minimumZ = tempArray[z];

		else if(tempArray[z] > maximumZ)
			maximumZ = tempArray[z];
	}
	//printf("%f min x \n%f max x \n %f min y\n %f max y\n %f min z \n %f max z\n",minimumX,maximumX,minimumY,maximumY,minimumZ,maximumZ);
	minPoint = Vect(minimumX,minimumY,minimumZ);
	//minPoint,MainColliderObj->getModel()->minPointAABB;

	maxPoint = Vect(maximumX,maximumY, maximumZ);
	//maxPoint,MainColliderObj->getModel()->maxPointAABB;


	//encapsulate this to return center
	Vect center = .5f*(minPoint + maxPoint);

	///////////////////////////////////
	world = Matrix( SCALE, maxPoint - minPoint )	
		* Matrix( TRANS, center);

	BoundingSphere->setWorld( world );
	*/
/////////////////////////////////////////////////////////

}

void TestingPair2::DrawObject()
{
	//BoundingSphere->Render();
	this->testPair2Texture->Render();
}
TestingPair2::~TestingPair2(void)
{
	printf("Testing Pair2 deleted");
}

void TestingPair2::Collision(Collidable*)
{
	//printf("TestingPair2 colliding with Collidable\n");
}

void TestingPair2::Collision(testGO*)
{
	//printf("TestingPair2 colliding with testGO\n");
}

void TestingPair2::KeyPressed(AZUL_KEY K)
{
	int v2;
		if( K ==AZUL_KEY::KEY_G)
	{
		v2 = rand() % 100;
		if (v2 < 100 && v2 > 75)
		{
			SetMyTimeScale(0);
		}
		if (v2 <  50 && v2 > 25)
		{
			SetMyTimeScale(1);
		}
		if (v2 <  50 && v2 > 25)
		{
			SetMyTimeScale(.50f);
		}
		if (v2 >  0 && v2 < 25)
		{
			SetMyTimeScale(2);
		}
	}
	
}