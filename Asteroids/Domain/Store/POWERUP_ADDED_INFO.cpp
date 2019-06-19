

//
#include "Asteroids/Domain/Store/POWERUP_ADDED_INFO.h"


//
namespace Asteroids
{
	//
	namespace Domain
	{
		//
		namespace Store
		{
			//
			POWERUP_ADDED_INFO::POWERUP_ADDED_INFO()
			{
				//
				this->init();
			}
			
			//
			void POWERUP_ADDED_INFO::reset()
			{
				//
				this->_item = nullptr;
				this->_item_quantity = 0;
			}
			
			//
			void POWERUP_ADDED_INFO::set_store_item(std::shared_ptr<Asteroids::Domain::Store::STORE_ITEM_INTERFACE> item)
			{
				//
				this->_item = item;
			}
			
			//
			std::shared_ptr<Asteroids::Domain::Store::STORE_ITEM_INTERFACE> POWERUP_ADDED_INFO::get_store_item()
			{
				//
				return this->_item;
			}
			
			//
			void POWERUP_ADDED_INFO::set_quantity(size_t n)
			{
				//
				this->_item_quantity = n;
			}
			
			//
			size_t POWERUP_ADDED_INFO::get_quantity()
			{
				//
				return this->_item_quantity;
			}
			
			//
			void POWERUP_ADDED_INFO::init()
			{
				//
				this->reset();
			}
		}
	}
}













