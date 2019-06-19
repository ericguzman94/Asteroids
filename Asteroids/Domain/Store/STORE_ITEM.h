#ifndef ASTEROIDS_DOMAIN_STORE_STORE_ITEM_H
#define ASTEROIDS_DOMAIN_STORE_STORE_ITEM_H


//
#include "Asteroids/ForwardDeclarations.h"
#include "Asteroids/Domain/Store/Enums/Enums.h"
#include "Asteroids/Domain/Store/STORE_ITEM_INTERFACE.h"


//
namespace Asteroids
{
	//
	namespace Domain
	{
		//
		namespace Store
		{
			///	Implementation of STORE_ITEM_INTERFACE
			class STORE_ITEM
				: public STORE_ITEM_INTERFACE
			{
				//
				public:
					
					//
					STORE_ITEM();
					
					//
					void reset();
					
					//
					void set_name(std::string s);
					std::string get_name();
					
					//
					void set_description(std::string s);
					std::string get_description();
					
					//
					void set_price_currency(Enums::CurrencyType t);
					Enums::CurrencyType get_price_currency();
					std::string get_price_currency_as_string();
					static std::string price_currency_to_string(Enums::CurrencyType t);
					
					//
					void set_price_units(int n);
					int get_price_units();
					
					//
					std::string get_formatted_price();
					
				//
				private:
					
					//
					std::string
						_name,
						_description
						;
					int _price_units;
					Enums::CurrencyType _price_currency_type;
					
					//
					void init();
			};
		}
	}
}







#endif
