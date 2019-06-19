

//
#include "Asteroids/Domain/Store/STORE_ITEM.h"


//
#include <sstream>
#include <iomanip>


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
			STORE_ITEM::STORE_ITEM()
			{
				//
				this->init();
			}
			
			//
			void STORE_ITEM::reset()
			{
				//
				this->_name = "???";
				this->_description = "???";
				this->_price_currency_type = Enums::CurrencyType::Undefined;
				this->_price_units = 0;
			}
			
			//
			void STORE_ITEM::set_name(std::string s)
			{
				//
				this->_name = s;
			}
			
			//
			std::string STORE_ITEM::get_name()
			{
				//
				return this->_name;
			}
			
			//
			void STORE_ITEM::set_description(std::string s)
			{
				//
				this->_description = s;
			}
			
			//
			std::string STORE_ITEM::get_description()
			{
				//
				return this->_description;
			}
			
			//
			void STORE_ITEM::set_price_currency(Enums::CurrencyType t)
			{
				//
				this->_price_currency_type = t;
			}
			
			//
			Enums::CurrencyType STORE_ITEM::get_price_currency()
			{
				//
				return this->_price_currency_type;
			}
			
			//
			std::string STORE_ITEM::get_price_currency_as_string()
			{
				//
				return STORE_ITEM::price_currency_to_string(this->_price_currency_type);
			}
			
			//
			std::string STORE_ITEM::price_currency_to_string(Enums::CurrencyType t)
			{
				//
				switch( t )
				{
					//
					case Enums::CurrencyType::USA:
						return "United States Currency";
					
					case Enums::CurrencyType::Undefined:
						return "Currency not defined";
				}
				
				return "ERROR";
			}
			
			//
			void STORE_ITEM::set_price_units(int n)
			{
				//
				this->_price_units = n;
			}
			
			//
			int STORE_ITEM::get_price_units()
			{
				//
				return this->_price_units;
			}
			
			//
			std::string STORE_ITEM::get_formatted_price()
			{
				//
				std::stringstream ss;
				
				//
				switch( this->_price_currency_type )
				{
					//
					case Enums::CurrencyType::Undefined:
						ss << "???";
						break;
					
					//
					case Enums::CurrencyType::USA:
						ss
							<< std::fixed << std::setprecision(2) << std::setfill('0')
							<< (this->_price_units / 100)
							;
				}
				
				return ss.str();
			}
			
			//
			void STORE_ITEM::init()
			{
				//
				this->reset();
			}
		}
	}
}








