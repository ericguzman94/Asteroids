#ifndef ASTEROIDS_DOMAIN_STORE_PAYMENT_HELPER_INTERFACE_H
#define ASTEROIDS_DOMAIN_STORE_PAYMENT_HELPER_INTERFACE_H


//
#include "Asteroids/ForwardDeclarations.h"


//
#include <string>
#include <vector>
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
			///	A class that lets you attempt to make payments
			class PaymentHelperInterface
			{
				//
				public:
					
					//
					virtual std::vector<Enums::PaymentMethod> get_available_payment_methods() = 0;
					virtual bool is_payment_method_implemented(Enums::PaymentMethod m) = 0;
					virtual std::string payment_method_to_string(Enums::PaymentMethod m) = 0;
					
					//
					virtual std::shared_ptr<Asteroids::Domain::Store::PAYMENT_RESULT_DETAILS_INTERFACE> pay_for_store_item_with_credit_card(
						std::shared_ptr<Asteroids::Domain::Store::STORE_ITEM_INTERFACE> item,
						std::string cc_number,
						std::string cc_expiration,
						std::string cc_security_code
					) = 0;
					
				//
				private:
					
					//
					
			};
		}
	}
}







#endif
