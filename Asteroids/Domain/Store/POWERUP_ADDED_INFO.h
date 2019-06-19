#ifndef ASTEROIDS_DOMAIN_STORE_POWERUP_ADDED_INFO_H
#define ASTEROIDS_DOMAIN_STORE_POWERUP_ADDED_INFO_H


//
#include "Asteroids/ForwardDeclarations.h"
#include "Asteroids/Domain/Store/POWERUP_ADDED_INFO_INTERFACE.h"


//
namespace Asteroids
{
	//
	namespace Domain
	{
		//
		namespace Store
		{
			///	Implementation of POWERUP_ADDED_INFO_INTERFACE
			class POWERUP_ADDED_INFO
				: public POWERUP_ADDED_INFO_INTERFACE
			{
				//
				public:
					
					//
					POWERUP_ADDED_INFO();
					
					//
					void reset();
					
					//
					void set_store_item(std::shared_ptr<Asteroids::Domain::Store::STORE_ITEM_INTERFACE> item);
					std::shared_ptr<Asteroids::Domain::Store::STORE_ITEM_INTERFACE> get_store_item();
					
					void set_quantity(size_t n);
					size_t get_quantity();
				
				//
				private:
					
					//
					std::shared_ptr<Asteroids::Domain::Store::STORE_ITEM_INTERFACE> _item;
					size_t _item_quantity;
					
					//
					void init();
			};
		}
	}
}








#endif
