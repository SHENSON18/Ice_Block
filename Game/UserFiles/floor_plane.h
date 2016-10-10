#pragma once
#include "GameObjects.h"
class floor_plane : public GameObjects
{
private:
	static GraphicsObjectFlatTexture *pGObj_Plane;
public:
	floor_plane(void);
	~floor_plane(void);
	virtual void DrawObject() override;
};

