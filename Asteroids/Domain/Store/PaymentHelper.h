#ifndef ASTEROIDS_DOMAIN_STORE_PAYMENT_HELPER_H
#define ASTEROIDS_DOMAIN_STORE_PAYMENT_HELPER_H


//
#include "Asteroids/ForwardDeclarations.h"
#include "Asteroids/Domain/Store/PaymentHelperInterface.h"


//
namespace Asteroids
{
	//
	namespace Domain
	{
		//
		namespace Store
		{
			///	Implementation of PaymentHelperInterface
			class PaymentHelper
				: public PaymentHelperInterface
			{
				//
				public:
					
					//
					PaymentHelper( std::shared_ptr<Asteroids::Domain::Factory::FactoryInterface> factory );
					
					//
					std::vector<Enums::PaymentMethod> get_available_payment_methods();
					bool is_payment_method_implemented(Enums::PaymentMethod m);
					std::string payment_method_to_string(Enums::PaymentMethod m);
					
					//
					std::shared_ptr<Asteroids::Domain::Store::PAYMENT_RESULT_DETAILS_INTERFACE> pay_for_store_item_with_credit_card(
						std::shared_ptr<Asteroids::Domain::Store::STORE_ITEM_INTERFACE> item,
						std::string cc_number,
						std::string cc_expiration,
						std::string cc_security_code
					);
					
				//
				private:
					
					//
					std::shared_ptr<Asteroids::Domain::Factory::FactoryInterface> _factory;
					std::shared_ptr<Asteroids::Domain::Net::NetFactoryInterface> _net_factory;
					
					//
					std::shared_ptr<Asteroids::Domain::Net::ClientServerCommunicatorInterface> _client_server_comm;
					
					//
					void init();
			};
		}
	}
}











#endif
