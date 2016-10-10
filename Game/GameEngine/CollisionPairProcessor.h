#pragma once
#include "CollisionProcessorBase.h"
#include "CollidableGroup.h"

template <class C1, class C2>
class CollisionPairProcessor: public CollisionProcessorBase{

protected:
	friend class CollisionManager;

	CollisionPairProcessor()  //Creates the Collidable groups for a potentiol set
	{
		CollisionGroup1 = &CollidableGroup<C1>::Instance();
		CollisionGroup2 = &CollidableGroup<C2>::Instance();
	}

	virtual ~CollisionPairProcessor(){}

	virtual void CollisionTest()
	{
		//check collision group first
		if (IceBlockMath::GroupCheck(CollidableGroup<C1>::MaxPoint, CollidableGroup<C1>::MinPoint, CollidableGroup<C2>::MaxPoint, CollidableGroup<C2>::MinPoint))
		{
			for( CollidableGroup<C1>::CollidableCollection::iterator itC1 = CollidableGroup<C1>::Instance().CollideCol.begin();itC1 != CollidableGroup<C1>::Instance().CollideCol.end();++itC1)
			{
				//test object sphere vs the group
				if(OuterSphereTest((*itC1), CollidableGroup<C2>::MaxPoint, CollidableGroup<C2>::MinPoint))
				{
				for( CollidableGroup<C2>::CollidableCollection::iterator itC2 = CollidableGroup<C2>::Instance().CollideCol.begin();itC2 != CollidableGroup<C2>::Instance().CollideCol.end();++itC2)
				{
					if ( Collidable::TestCollisionPair(*itC1, *itC2) ) 
					{
						(*itC1)->Collision(*itC2);
						(*itC2)->Collision(*itC1);
					}
				} 
				}
			}
		}
	}

	bool OuterSphereTest(Collidable *test, const Vect &Max, const Vect &Min)
	{
		Vect center = IceBlockMath::Clamp(test->outerSphere->GetCenter(), Max, Min);
		Vect dist = test->outerSphere->GetCenter() - center;
		return dist.mag() < test->outerSphere->GetRadius();

	}
CollidableGroupBase* CollisionGroup1;

CollidableGroupBase* CollisionGroup2;



};
