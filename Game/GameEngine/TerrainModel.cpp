#include "TerrainModel.h"
#include <Azul.h>
#include <assert.h>
#include <string>
#include <vector>
#include <assert.h>
float userheight;
float userlength;
// Note: the heightmap file should not be a pre-loaded texture from the texture manager
TerrainModel::TerrainModel( char* heightmapFile, float Sidelength, float maxheight, float zeroHeight, char* TextureKey, int RepeatU, int RepeatV)
{

	userlength = Sidelength;
	userheight = maxheight;
	zeroHeight;
	RepeatU;
	RepeatV;
	// Create the model 
	// *** and save it to an .azul file ***
	// *** and loads in the the Model Manager ***
	CreateTerrainModel( heightmapFile, RepeatU, RepeatV);

	// and then load it back in through the model manager... Because it's easier than modding AZUL
	ResourceManager::AddModel("AzulTerrain", "AZULTERRAIN.azul");

	// Scale and adjust position if needed
	WorldMat= Matrix(IDENTITY);
	// Connect the model to a graphics object
	pGObjFT = new GraphicsObjectFlatTexture( ResourceManager::GetModel("AzulTerrain"), ResourceManager::GetTexture(TextureKey)	);
	pGObjFT->setWorld( WorldMat );

	//*  
	// This is for debugging only
	pGObjFT2 = new GraphicsObjectWireFrame( ResourceManager::GetModel("AzulTerrain")); TextureKey;
	pGObjFT2->setWorld( WorldMat );
	//*/
	//RegisterDraw();
	//RegisterUpdate();
}

void TerrainModel::DrawObject()
{
	pGObjFT->Render();
	pGObjFT2->Render();  // Debug tool only
}

// Creates the actual model mesh
void TerrainModel::CreateTerrainModel( char* heightmapFile, int RepeatU, int RepeatV)
{
	RepeatU,
	RepeatV;
	// Using GLTools to read in the file
	int imgWidth, imgHeigth, icomp;
	unsigned int dtype;
	GLbyte* imgData = gltReadTGABits( heightmapFile, &imgWidth, &imgHeigth, &icomp, &dtype);
	assert( imgWidth == imgHeigth); // We need square images for heightmaps
	/// Insert much work to create and the model
	imgData;
	vertsArray = new VertexStride_VUN[imgHeigth*imgWidth];
	trianglelist = new TriangleIndex[(imgHeigth-1)*(imgWidth-1)*2];
	for(int i = 0; i < imgWidth; i++)
	{
		for(int j = 0; j < imgHeigth; j++)
		{
			VertexStride_VUN* temp = &vertsArray[(i*imgHeigth) + j]; //storing it
			//texture id
			temp->txt = 0.0f;
			// normals
			temp->nx = 0.0f;
			temp->ny = 0.0f;
			temp->nz = 0.0f;
			//UVs
			temp->u =(float) i*RepeatU/imgWidth;
			temp->v = (float)j*RepeatV/imgWidth;
			//vertices position

			temp->x = (float) j * userlength;
			temp->z = (float) i * userlength;
			temp->y = static_cast<unsigned char>(imgData[((i*imgHeigth)+j)*3]); //adjust this a little
			
			temp->y /= userheight;


		}
	}
//create triangles
	int mycell = 0;
	for(int i = 0; i < imgHeigth-1; i++)
	{
		for (int j = 0; j < imgWidth-1; j++)
		{
			TriangleIndex* triangletemp = &trianglelist[mycell];
			//do both triangles on each run
			triangletemp->v0 = ((j+1)+i * imgHeigth);
			triangletemp->v1 = ((j+1)+(i+1)*imgHeigth);
			triangletemp->v2 = ((i+1)*imgHeigth+j);

			mycell++;
			triangletemp = &trianglelist[mycell];
			triangletemp->v0 = ((i+1)*imgHeigth +j);
			triangletemp->v1 = ((i)*imgHeigth +j);
			triangletemp->v2 = ((i)*imgHeigth +(j+1));
			mycell++;
		}
	}

	TerrainModel::SaveTerrainModel( vertsArray, imgWidth*imgHeigth, trianglelist, (imgHeigth-1)*(imgWidth-1) *2);

} 

// Saves the model to file in the Azul format   this you call after done finding items in creation.
// (realistically, the filename should be parametrized)
void TerrainModel::SaveTerrainModel( VertexStride_VUN* pVerts, int num_verts, TriangleIndex* tlist, int num_tri)
{
	char* TerrainName = "AZULTERRAIN";
	char* TerrainFilename = "../Assets/AZULTERRAIN.azul";

	//// Write the data to a file ----------------------------
	FileHandle fh;
	FileError  ferror;
	std::vector<std::string> FBX_textNames; // (Ed) purposefully empty to be consistent 

	// 1) Create a blank header

		// // write the data
		AzulFileHdr  azulFileHdr;
		strcpy_s(azulFileHdr.objName, OBJECT_NAME_SIZE, TerrainName);

	// 2)  Write the data (Header, Buffers) to the files

	// write the header (Take 1) 

		// create the file, write the header
		ferror = File::open(fh, TerrainFilename, FILE_READ_WRITE );
		assert( ferror == FILE_SUCCESS );

		// write the data
		ferror = File::write( fh, &azulFileHdr, sizeof(azulFileHdr) );
		assert( ferror == FILE_SUCCESS );

	// update the header: numTextures, textureNamesOffset
		azulFileHdr.numTextures = FBX_textNames.size();

		// update the offset
		ferror = File::tell( fh, azulFileHdr.textureNamesOffset );
		assert( ferror == FILE_SUCCESS );

	
	std::vector<std::string>::iterator FBX_textNames_iterator;

	int i=0;
	for( FBX_textNames_iterator = FBX_textNames.begin(); 
		    FBX_textNames_iterator != FBX_textNames.end();
		    FBX_textNames_iterator++ )
	{
		const char *ss = (*FBX_textNames_iterator).c_str();
		// write the vertex data
		ferror = File::write( fh, ss, strlen(ss) + 1);
		assert( ferror == FILE_SUCCESS );
		i++;
	}

	// update the header: numVerts, VertBufferOffset

		// update the number of verts
		azulFileHdr.numVerts = num_verts;
   
		// update the offset
		ferror = File::tell( fh, azulFileHdr.vertBufferOffset );
		assert( ferror == FILE_SUCCESS );

	// write the vertex data
	ferror = File::write( fh, pVerts, num_verts * sizeof(VertexStride_VUN) );
	assert( ferror == FILE_SUCCESS );

	// update the header: numTriList, triListBufferOffset

		// update the number of verts
		azulFileHdr.numTriangles = num_tri;

		// update the offset
		ferror = File::tell( fh, azulFileHdr.triangleListBufferOffset );
		assert( ferror == FILE_SUCCESS );

	// write the triListBuffer data
	ferror = File::write( fh, tlist, num_tri * sizeof(TriangleIndex) );
	assert( ferror == FILE_SUCCESS );
	    
	// write the header (Take 2) now with updated data

		azulFileHdr.textureNamesInBytes = azulFileHdr.vertBufferOffset - azulFileHdr.textureNamesOffset;

		// reset to the beginning of file
		ferror = File::seek( fh, FILE_SEEK_BEGIN, 0 );
		assert( ferror == FILE_SUCCESS );

		// write the buffer
		ferror = File::write( fh, &azulFileHdr, sizeof(azulFileHdr) );
		assert( ferror == FILE_SUCCESS );

	// All done - bye bye
	ferror = File::close( fh );
	assert( ferror == FILE_SUCCESS );
}

