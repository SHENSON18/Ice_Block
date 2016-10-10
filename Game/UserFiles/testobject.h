#pragma once
#include "Game.h"
class testobject : public GameObjects
{
public:
	testobject(void);
	~testobject(void);
	virtual void Collision(Collidable*) override;
};

