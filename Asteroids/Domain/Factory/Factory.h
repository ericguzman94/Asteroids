#ifndef ASTEROIDS_DOMAIN_FACTORY_FACTORY_H
#define ASTEROIDS_DOMAIN_FACTORY_FACTORY_H


//
#include "Asteroids/Domain/Factory/FactoryInterface.h"


//
#include <memory>


//
namespace Asteroids
{
	//
	namespace Domain
	{
		//
		namespace Factory
		{
			///	Implementation of FactoryInterface
			class Factory
				:
					public FactoryInterface,
					public std::enable_shared_from_this<Factory>
			{
				//
				public:
					
					//	CTOR
					Factory();
					
					//
					void reset();
					
					//
					std::unique_ptr<Asteroids::Domain::Server::ServerFactoryInterface> createServerFactory();
					std::unique_ptr<Asteroids::Domain::Game::GameFactoryInterface> createGameFactory();
					std::unique_ptr<Asteroids::Domain::Net::NetFactoryInterface> createNetworkFactory();
					std::unique_ptr<Asteroids::Domain::Store::StoreFactoryInterface> createStoreFactory();
					std::unique_ptr<Asteroids::UI::UIFactoryInterface> createUIFactory();
					std::unique_ptr<Asteroids::TechnicalServices::TechnicalServicesFactoryInterface> createTechnicalServicesFactory();
					
				//
				private:
					
					//
					std::shared_ptr<Factory> this_pointer();
			};
		}
	}
}


#endif
