

//
#include "Asteroids/Domain/Store/Store.h"
//
#include "Asteroids/Domain/Store/STORE_ITEM.h"


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
			Store::Store()
			{
				//
			}
			
			///	@todo Should 
			///	@todo Currently returning dummy data;
			///	Eventually maybe actually communicate with the server via network
			std::vector<std::shared_ptr<STORE_ITEM_INTERFACE>> Store::get_available_store_items()
			{
				//
				std::vector<std::shared_ptr<STORE_ITEM_INTERFACE>> items;
				std::shared_ptr<STORE_ITEM> item;
				
				//	Three extra lives
				///	@todo Extra lives not actually implemented in the game yet
				item = std::shared_ptr<STORE_ITEM>(new STORE_ITEM());
				item->set_name("Three Extra Lives");
				item->set_description("Live way longer with three WHOLE extra lives !!!!");
				item->set_price_units(300);
				item->set_price_currency(Enums::CurrencyType::USA);
				items.push_back(item);
				
				//	Large bullets
				///	@todo Large bullets not actually implemented in the game yet
				item = std::shared_ptr<STORE_ITEM>(new STORE_ITEM());
				item->set_name("Large Bullets");
				item->set_description("Murder everything in sight with giant bullets !!");
				item->set_price_units(100);
				item->set_price_currency(Enums::CurrencyType::USA);
				items.push_back(item);
				
				//	Rocklike Ship
				///	@todo Rocklike Ship not actually implemented in the game yet
				item = std::shared_ptr<STORE_ITEM>(new STORE_ITEM());
				item->set_name("Rock-Ship");
				item->set_description("Enjoy playing a game with a ship ... that looks like a rock!");
				item->set_price_units(999);
				item->set_price_currency(Enums::CurrencyType::USA);
				items.push_back(item);
				
				return items;
			}
		}
	}
}










