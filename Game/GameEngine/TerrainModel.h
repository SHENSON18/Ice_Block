#ifndef _TerrainModel
#define _TerrainModel

#include "Game.h"
#include <tuple>

class TerrainModel : public GameObjects
{
private:
	GraphicsObject* pGObjFT;
	GraphicsObjectWireFrame* pGObjFT2;
	Matrix WorldMat;

	void CreateTerrainModel( char* heightmapFile, int RepeatU, int RepeatV);
	void SaveTerrainModel( VertexStride_VUN* pVerts, int num_verts, TriangleIndex* tlist, int num_tri); 
	int VertexIndex(int side, int i, int j);  //used to assign vertex values
	VertexStride_VUN *vertsArray;
	TriangleIndex *trianglelist;

public:
	TerrainModel( char* heightmapFile, float Sidelenght, float maxheight, float zeroHeight, char* TextureKey, int RepeatU, int RepeatV);
	virtual void DrawObject() override;

};


#endif _TerrainModel