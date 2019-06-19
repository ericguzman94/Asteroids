

//
#include "Asteroids/Domain/Store/PaymentHelper.h"
//
#include "Asteroids/Domain/Factory/FactoryInterface.h"
#include "Asteroids/Domain/Net/NetFactoryInterface.h"
#include "Asteroids/Domain/Net/ClientServerCommunicatorInterface.h"
#include "Asteroids/Domain/Store/Enums/Enums.h"
#include "Asteroids/Domain/Store/PAYMENT_RESULT_DETAILS.h"


//
#include <sstream>


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
			PaymentHelper::PaymentHelper( std::shared_ptr<Asteroids::Domain::Factory::FactoryInterface> factory )
			{
				//
				this->_factory = factory;
				
				//
				this->init();
			}
			
			//
			std::vector<Enums::PaymentMethod> PaymentHelper::get_available_payment_methods()
			{
				//
				std::vector<Enums::PaymentMethod> methods;
				
				//
				methods.push_back(Enums::PaymentMethod::AccountBalance);
				methods.push_back(Enums::PaymentMethod::Bitcoin);
				methods.push_back(Enums::PaymentMethod::Blood);
				methods.push_back(Enums::PaymentMethod::CreditCard);
				methods.push_back(Enums::PaymentMethod::Paypal);
				
				return methods;
			}
			
			//
			bool PaymentHelper::is_payment_method_implemented(Enums::PaymentMethod m)
			{
				//
				if ( m == Enums::PaymentMethod::CreditCard ) {
					return true;
				}
				
				return false;
			}
			
			//
			std::string PaymentHelper::payment_method_to_string(Enums::PaymentMethod m)
			{
				//
				std::stringstream ss;
				
				//
				switch( m )
				{
					//
					case Enums::PaymentMethod::AccountBalance:
						ss << "Account Balance";
						break;
					
					//
					case Enums::PaymentMethod::Bitcoin:
						ss << "Bitcoin";
						break;
					
					//
					case Enums::PaymentMethod::Blood:
						ss << "Blood";
						break;
					
					//
					case Enums::PaymentMethod::CreditCard:
						ss << "Credit Card";
						break;
					
					//
					case Enums::PaymentMethod::Paypal:
						ss << "Paypal";
						break;
					
					//
					case Enums::PaymentMethod::Undefined:
						ss << "Undefined";
						break;
				}
				
				return ss.str();
			}
			
			//
			std::shared_ptr<Asteroids::Domain::Store::PAYMENT_RESULT_DETAILS_INTERFACE> PaymentHelper::pay_for_store_item_with_credit_card(
				std::shared_ptr<Asteroids::Domain::Store::STORE_ITEM_INTERFACE> item,
				std::string cc_number,
				std::string cc_expiration,
				std::string cc_security_code
			)
			{
				///	@todo Uhhhhhhmmm.... using the "This object knows about payment result, therefore create it" pattern
				///	; Contrast against the normal factory pattern because normal factory pattern will make this class more dependent on factory classes and less self contained
				std::shared_ptr<Asteroids::Domain::Store::PAYMENT_RESULT_DETAILS_INTERFACE> payment_result(
					new Asteroids::Domain::Store::PAYMENT_RESULT_DETAILS()
				);
				
				///	Ask the ClientServerCommunicator to ask the server to authorize on our behalf
				///	The server itself would have the external payment gateway interface,
				///	which we'll implement there also, but ... there is no TCP between client-server yet,
				///	so the call to ClientServerCommunicator::authorizePatment() is the last call that really matters
				if ( this->_client_server_comm->authorizePayment( item, cc_number, cc_expiration, cc_security_code) ) {
					payment_result->set_message("Your payment was successful; Thanks for giving us all your money!");
					payment_result->set_was_successful(true);
				}
				
				return payment_result;
			}
			
			//
			void PaymentHelper::init()
			{
				//
				this->_net_factory = this->_factory->createNetworkFactory();
				
				//
				this->_client_server_comm = this->_net_factory->createClientServerCommunicator();
			}
		}
	}
}











