#ifndef ASTEROIDS_DOMAIN_STORE_STOREINTERFACE_H
#define ASTEROIDS_DOMAIN_STORE_STOREINTERFACE_H


//
#include "Asteroids/ForwardDeclarations.h"


//
#include <memory>
#include <vector>


//
namespace Asteroids
{
	//
	namespace Domain
	{
		//
		namespace Store
		{
			///	The Store interface lets you poll things that ... a store would tell you... such as what items are available for sale
			class StoreInterface
			{
				//
				public:
					
					//
					virtual std::vector<std::shared_ptr<STORE_ITEM_INTERFACE>> get_available_store_items() = 0;
			};
		}
	}
}









#endif
