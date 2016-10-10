#include "TestingPair3.h"
#include "ResourceManager.h"
#include "SceneManager.h"
//GraphicsObjectWireFrame* TestingPair2::BoundingSphere;

TestingPair3::TestingPair3()
{
	//  Add Textures and Collider Obj
	//BoundingSphere = new GraphicsObjectWireFrame( ResourceManager::GetModel("BoundingBox"));
	testPair3Texture = new GraphicsObjectFlatTexture(ResourceManager::GetModel("SpaceFrigate"), ResourceManager::GetTexture("SpaceFrigate")); 

//	MainColliderObj = testPair2Texture;

	//Set Matrices
	TestPairScale.set( SCALE, .6f, .6f, .6f);
	TestPairRot.set( ROT_XYZ, 0, 90, 0);
	TestPairPos.set(-90,20,0);
	
	TestPairWorld = TestPairScale * TestPairRot * Matrix( TRANS, TestPairPos );
	TestPairWorld = Matrix(TRANS, TestPairPos );
	testPair3Texture->setWorld(TestPairWorld);
	RenderColor = Vect(0,0,1);

	//  Setting Collider
	setModel(testPair3Texture->getModel());
	SetColliderVolume(AABB);

	//Register to managers
	RegisterTime();
	RegisterUpdate();
	RegisterDraw();
	CollidableGroup<TestingPair3>::Register(this);
}
void TestingPair3::Update()
{
	Matrix world =  TestPairScale * TestPairRot * Matrix( TRANS, TestPairPos );
	testPair3Texture->setWorld( world );
	outerSphere->Updatedata();
	WorldMat = world;
	colVol->Updatedata();
	//Visualize AABB
	Vect max = IceBlockMath::findMax(testPair3Texture->getModel(), &world);
	Vect min = IceBlockMath::findMin(testPair3Texture->getModel(), &world);
	Visualizer::ShowAABB(max, min, RenderColor);

	TestPairRot *= Matrix( ROT_Y, 5 * DeltaTime());
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

void TestingPair3::DrawObject()
{
	//BoundingSphere->Render();
	this->testPair3Texture->Render();
}
TestingPair3::~TestingPair3(void)
{
	printf("Testing Pair2 deleted");
}

void TestingPair3::Collision(Collidable*)
{
	//printf("TestingPair2 colliding with Collidable\n");
}

void TestingPair3::Collision(testGO*)
{
	//printf("TestingPair2 colliding with testGO\n");
}