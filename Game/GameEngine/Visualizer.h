#pragma once
#include "Azul.h"
#include <list>
#include <stack>

class Scene;

class Visualizer
{
friend class Scene;
private:
	static Visualizer* pInstance;

	struct visData
	{
		GraphicsObjectWireFrame* Gobj;
		Matrix worldmat;
		Vect Color;

		visData(): Gobj(0), worldmat( Matrix(IDENTITY)), Color(Vect(0,0,0)){}
	};

	typedef std::list<visData*> VisCollection;
	VisCollection visRequests;
	std::stack<visData*> DataPool;

	GraphicsObjectWireFrame* pSphere;
	GraphicsObjectWireFrame* pBox;

	static Vect DEFAULT_COLOR;

	Visualizer(){ pInstance = 0; }
	~Visualizer();
	Visualizer( const Visualizer& ){}
	Visualizer operator=( const Visualizer& ){}

	static Visualizer& Instance()
	{
		if ( ! pInstance)
			pInstance = new Visualizer;

		return *pInstance;
	}

	void addData(  GraphicsObjectWireFrame* go, const Matrix& M, const Vect& col);

	visData* getNewData();
	void recycleData( visData* vd );

	void privRender();
	void privShowMarker( const Vect& pos, const Vect& col, float radius );
	//void privShowSphere( const Vect& center, float rad, const Vect& col = DEFAULT_COLOR);
	//void privShowBox( const Vect& Min, const Vect& Max, const Matrix& Mat, const Vect& col = DEFAULT_COLOR);

	static void Render();
public:
	static void Initialize();
	static void ShowMarker( const Vect& pos, const Vect& col, float radius );
	static void ShowAABB(const Vect &Max, const Vect &Min, const Vect &color);
	static void ShowOBB(const Vect &Max, const Vect &Min, const Vect &color, const Matrix &World);
	static void ShowSphere(const Vect &Center, float Radius, const Matrix &World, const Vect &color);
};

