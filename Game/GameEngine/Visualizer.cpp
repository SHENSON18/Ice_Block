#include "Visualizer.h"
#include "ResourceManager.h"
#include "Azul.h"
Visualizer* Visualizer::pInstance = 0;
Vect Visualizer::DEFAULT_COLOR = Vect(1, 0.25f, 0);

void Visualizer::Initialize()
{
	Instance();

	//Instance().pSphere = new GraphicsObjectWireFrame( ResourceManager::GetModel("BoundingSphere"));
	//Instance().pBox = new GraphicsObjectWireFrame( ResourceManager::GetModel("BoundingBox"));
}

void Visualizer::addData( GraphicsObjectWireFrame* go, const Matrix& M, const Vect& col)
{
	visData* data = getNewData();

	data->Gobj = go;
	data->worldmat = M;
	data->Color = col;

	visRequests.push_back(data);
} 

Visualizer::visData* Visualizer::getNewData()
{
	visData* data;

	if ( ! DataPool.empty() )
	{
		data = DataPool.top();
		DataPool.pop();
	}
	else
	{
		data = new visData();
	}

	return data;
}


void Visualizer::recycleData( visData* vd)
{
	DataPool.push(vd);
}

void Visualizer::privRender()
{
	visData* vd;
	while ( ! visRequests.empty() )
	{
		vd = visRequests.front();
		visRequests.pop_front();

		(*vd).Gobj->setWorld( (*vd).worldmat);
		(*vd).Gobj->color = (*vd).Color;
		(*vd).Gobj->Render();

		recycleData( vd); // continueal recycles old data
	}
}

void Visualizer::Render()
{
	Instance().privRender();
}

void Visualizer::privShowMarker( const Vect& pos, const Vect& col, float radius)
{
	Matrix M = Matrix(SCALE, radius, radius, radius) * Matrix( TRANS, pos);
	addData( pBox, M, col);
}

void Visualizer::ShowMarker(const Vect& pos, const Vect& col, float radius)
{
	Instance().privShowMarker( pos, col, radius);
}

void Visualizer::ShowAABB(const Vect &Max, const Vect &Min, const Vect &color)
{
	Vect BoxScale =  Max - Min;
	Matrix BoxWorld = Matrix( SCALE, BoxScale) * Matrix( TRANS, (Max[x] + Min[x]) / 2, (Max[y] + Min[y]) / 2, (Max[z] + Min[z]) /2);
	Vect col = color;
	Instance().addData(Instance().pBox, BoxWorld, col);
}

void Visualizer::ShowOBB(const Vect &Max, const Vect &Min, const Vect &color, const Matrix &World)
{
	Vect BoxScale =  Max - Min;
	Matrix BoxWorld = Matrix( SCALE, BoxScale) * Matrix( TRANS, (Max[x] + Min[x]) / 2, (Max[y] + Min[y]) / 2, (Max[z] + Min[z]) /2) * World;
	Vect col = color;
	Instance().addData(Instance().pBox, BoxWorld, col);
}

void Visualizer::ShowSphere(const Vect &Center, float Radius, const Matrix &World, const Vect &color)
{
	Matrix SphereWorld = Matrix( SCALE, Radius * Vect(1,1,1) )	
			* Matrix( TRANS, Center)
			* World;
	Vect col = color;
	Instance().addData(Instance().pSphere, SphereWorld, col);
}