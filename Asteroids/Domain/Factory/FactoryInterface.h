#ifndef ASTEROIDS_DOMAIN_FACTORY_FACTORYINTERFACE_H
#define ASTEROIDS_DOMAIN_FACTORY_FACTORYINTERFACE_H


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
		namespace Factory
		{
			///	The main FactoryInterface is responsible for generating other factories of subpackages
			class FactoryInterface
			{
				//
				public:
					
					//
					virtual std::unique_ptr<Asteroids::Domain::Server::ServerFactoryInterface> createServerFactory() = 0;
					virtual std::unique_ptr<Asteroids::Domain::Game::GameFactoryInterface> createGameFactory() = 0;
					virtual std::unique_ptr<Asteroids::Domain::Net::NetFactoryInterface> createNetworkFactory() = 0;
					virtual std::unique_ptr<Asteroids::Domain::Store::StoreFactoryInterface> createStoreFactory() = 0;
					virtual std::unique_ptr<Asteroids::UI::UIFactoryInterface> createUIFactory() = 0;
					virtual std::unique_ptr<Asteroids::TechnicalServices::TechnicalServicesFactoryInterface> createTechnicalServicesFactory() = 0;
					
				//
				private:
					
					//
					
			};
		}
	}
}


#endif
