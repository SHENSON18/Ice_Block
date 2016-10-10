#pragma once
#include "CollisionProcessorBase.h"
#include "CollidableGroup.h"

template <class C1>
class CollisionSingleProcessor: public CollisionProcessorBase{

protected:
	friend class CollisionManager;

	CollisionSingleProcessor()  //Creates the Collidable groups for a potentiol set
	{
		CollisionGroup = &CollidableGroup<C>::Instance();
	}

	virtual ~CollisionSingleProcessor(){}

	virtual void CollisionTest(){
			for( CollidableGroup<C>::CollidableCollection::iterator it_C = CollidableGroup<C>::Instance().CollideCol.begin();it_C != CollidableGroup<C>::Instance().CollideCol.end();++it_C){
			for( CollidableGroup<C>::CollidableCollection::iterator it_Cother = next(it_C); it_Cohter != CollidableGroup<C>::Instance().CollideCol.end();++it_Cother)
				if ( Collidable::TestCollisionPair(*it_C, *it_Cother) ) {
					(*it_C)->Collision(*it_Cother);
					(*it_Cother)->Collision(*it_C);

				}
			}
		} 
	}
;
CollidableGroupBase* CollisionGroup;




};
