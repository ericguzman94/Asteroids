#ifndef ASTEROIDS_DOMAIN_STORE_STOREFACTORY_H
#define ASTEROIDS_DOMAIN_STORE_STOREFACTORY_H


//
#include "Asteroids/ForwardDeclarations.h"
#include "Asteroids/Domain/Store/StoreFactoryInterface.h"


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
			///	Implementation of StoreFactoryInterface
			class StoreFactory
				: public StoreFactoryInterface
			{
				//
				public:
					
					//
					StoreFactory( std::shared_ptr<Asteroids::Domain::Factory::FactoryInterface> factory );
					
					//
					std::shared_ptr<Asteroids::Domain::Store::StoreInterface> createStore();
					std::shared_ptr<Asteroids::Domain::Store::PaymentHelperInterface> createPaymentHelper();
					std::shared_ptr<Asteroids::Domain::Store::PAYMENT_RESULT_DETAILS_INTERFACE> createPaymentResultDetails();
					std::shared_ptr<Asteroids::Domain::Store::POWERUP_ADDED_INFO_INTERFACE> createPowerUpAddedInfo();
					
				//
				private:
					
					//
					std::shared_ptr<Asteroids::Domain::Factory::FactoryInterface> _factory;
			};
		}
	}
}








#endif
