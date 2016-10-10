#pragma once
#include "GameObjects.h"
class axis : public GameObjects
{

public:
	axis(void);
	~axis(void);
	virtual void DrawObject();
	static GraphicsObjectColorNoTexture *pGObj_Axis;
};

