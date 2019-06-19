#ifndef ASTEROIDS_DOMAIN_STORE_STORE_H
#define ASTEROIDS_DOMAIN_STORE_STORE_H


//
#include "Asteroids/ForwardDeclarations.h"
#include "Asteroids/Domain/Store/StoreInterface.h"


//
#include <memory>


//
namespace Asteroids
{
	//
	namespace Domain
	{
		//
		namespace Store
		{
			///	Implementation of StoreInterface
			class Store
				: public StoreInterface
			{
				//
				public:
					
					//
					Store();
					
					//
					std::vector<std::shared_ptr<STORE_ITEM_INTERFACE>> get_available_store_items();
					
				private:
					
					//
					
			};
		}
	}
}










#endif
