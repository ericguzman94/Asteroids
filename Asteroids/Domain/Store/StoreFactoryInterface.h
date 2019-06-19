#ifndef ASTEROIDS_DOMAIN_STORE_STOREFACTORYINTERFACE_H
#define ASTEROIDS_DOMAIN_STORE_STOREFACTORYINTERFACE_H


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
			///	Creates things inside the Store package
			class StoreFactoryInterface
			{
				//
				public:
					
					//
					virtual std::shared_ptr<Asteroids::Domain::Store::StoreInterface> createStore() = 0;
					virtual std::shared_ptr<Asteroids::Domain::Store::PaymentHelperInterface> createPaymentHelper() = 0;
					virtual std::shared_ptr<Asteroids::Domain::Store::PAYMENT_RESULT_DETAILS_INTERFACE> createPaymentResultDetails() = 0;
					virtual std::shared_ptr<Asteroids::Domain::Store::POWERUP_ADDED_INFO_INTERFACE> createPowerUpAddedInfo() = 0;
					
				//
				private:
					
					//
					
			};
		}
	}
}






#endif
