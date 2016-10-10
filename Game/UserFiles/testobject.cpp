#include "testobject.h"


testobject::testobject(void)
{
	//CollidableGroup<testobject>::Register(this);
}


testobject::~testobject(void)
{
	//printf("Here we go");
}

void testobject::Collision(Collidable*)
{
	//printf("test object collided with collidable\n");
}

