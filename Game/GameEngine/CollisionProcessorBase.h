#pragma once

class CollisionProcessorBase{

	friend class CollisionManager;

protected:

	CollisionProcessorBase(){}
	virtual ~CollisionProcessorBase(){}

	virtual void CollisionTest() = 0;
	//virtual void CleanUp() override;

};