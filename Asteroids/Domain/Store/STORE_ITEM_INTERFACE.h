#ifndef ASTEROIDS_DOMAIN_STORE_STORE_ITEM_INTERFACE_H
#define ASTEROIDS_DOMAIN_STORE_STORE_ITEM_INTERFACE_H


//
#include "Asteroids/ForwardDeclarations.h"


//
#include <string>


//
namespace Asteroids
{
	//
	namespace Domain
	{
		//
		namespace Store
		{
			///	Interface for one item available for purchase, inside the Store
			class STORE_ITEM_INTERFACE
			{
				//
				public:
					
					//
					virtual std::string get_name() = 0;
					virtual std::string get_description() = 0;
					virtual Enums::CurrencyType get_price_currency() = 0;
					virtual std::string get_price_currency_as_string() = 0;
					virtual int get_price_units() = 0;
					virtual std::string get_formatted_price() = 0;
			};
		}
	}
}








#endif
