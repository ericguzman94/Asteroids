

//
#include "Asteroids/Domain/Store/StoreFactory.h"
//
#include "Asteroids/Domain/Store/Store.h"
#include "Asteroids/Domain/Store/PaymentHelper.h"
#include "Asteroids/Domain/Store/PAYMENT_RESULT_DETAILS.h"
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
			StoreFactory::StoreFactory( std::shared_ptr<Asteroids::Domain::Factory::FactoryInterface> factory )
			{
				//
				this->_factory = factory;
			}
			
			//
			std::shared_ptr<Asteroids::Domain::Store::StoreInterface> StoreFactory::createStore()
			{
				//
				std::shared_ptr<Asteroids::Domain::Store::Store> store(
					new Asteroids::Domain::Store::Store()
				);
				
				return store;
			}
			
			//
			std::shared_ptr<Asteroids::Domain::Store::PaymentHelperInterface> StoreFactory::createPaymentHelper()
			{
				//
				std::shared_ptr<Asteroids::Domain::Store::PaymentHelper> payment_helper(
					new Asteroids::Domain::Store::PaymentHelper(this->_factory)
				);
				
				return payment_helper;
			}
			
			//
			std::shared_ptr<Asteroids::Domain::Store::PAYMENT_RESULT_DETAILS_INTERFACE> StoreFactory::createPaymentResultDetails()
			{
				//
				std::shared_ptr<Asteroids::Domain::Store::PAYMENT_RESULT_DETAILS> details(
					new Asteroids::Domain::Store::PAYMENT_RESULT_DETAILS()
				);
				
				return details;
			}
			
			//
			std::shared_ptr<Asteroids::Domain::Store::POWERUP_ADDED_INFO_INTERFACE> StoreFactory::createPowerUpAddedInfo()
			{
				//
				std::shared_ptr<Asteroids::Domain::Store::POWERUP_ADDED_INFO> info(
					new Asteroids::Domain::Store::POWERUP_ADDED_INFO()
				);
				
				return info;
			}
		}
	}
}










