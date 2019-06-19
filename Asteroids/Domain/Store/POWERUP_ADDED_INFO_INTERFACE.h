#ifndef ASTEROIDS_DOMAIN_STORE_POWERUP_ADDED_INFO_INTERFACE_H
#define ASTEROIDS_DOMAIN_STORE_POWERUP_ADDED_INFO_INTERFACE_H


//
#include "Asteroids/ForwardDeclarations.h"


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
			///	Information what powerup was just added to your account
			class POWERUP_ADDED_INFO_INTERFACE
			{
				//
				public:
					
					//
					virtual void set_store_item(std::shared_ptr<Asteroids::Domain::Store::STORE_ITEM_INTERFACE> item) = 0;
					virtual std::shared_ptr<Asteroids::Domain::Store::STORE_ITEM_INTERFACE> get_store_item() = 0;
					
					virtual void set_quantity(size_t n) = 0;
					virtual size_t get_quantity() = 0;
			};
		}
	}
}










#endif
