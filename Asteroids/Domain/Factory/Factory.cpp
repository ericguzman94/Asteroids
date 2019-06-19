

//
#include "Asteroids/Domain/Factory/Factory.h"
//
#include "Asteroids/Domain/Game/GameFactory.h"
#include "Asteroids/Domain/Net/NetFactory.h"
#include "Asteroids/Domain/Server/ServerFactory.h"
#include "Asteroids/Domain/Store/StoreFactory.h"
#include "Asteroids/TechnicalServices/TechnicalServicesFactory.h"
#include "Asteroids/UI/UIFactory.h"


//
namespace Asteroids
{
	//
	namespace Domain
	{
		//
		namespace Factory
		{
			//
			Factory::Factory()
			{
				//
				this->reset();
			}
			
			//
			void Factory::reset()
			{
				//
			}
			
			//
			std::unique_ptr<Asteroids::Domain::Server::ServerFactoryInterface> Factory::createServerFactory()
			{
				//
				std::unique_ptr<Asteroids::Domain::Server::ServerFactoryInterface> factory(
					new Asteroids::Domain::Server::ServerFactory(this->this_pointer())
				);
				
				return factory;
			}
			
			//
			std::unique_ptr<Asteroids::Domain::Game::GameFactoryInterface> Factory::createGameFactory()
			{
				//
				std::unique_ptr<Asteroids::Domain::Game::GameFactoryInterface> factory(
					new Asteroids::Domain::Game::GameFactory()
				);
				
				return factory;
			}
			
			//
			std::unique_ptr<Asteroids::Domain::Net::NetFactoryInterface> Factory::createNetworkFactory()
			{
				//
				std::unique_ptr<Asteroids::Domain::Net::NetFactoryInterface> factory(
					new Asteroids::Domain::Net::NetFactory()
				);
				
				return factory;
			}
			
			//
			std::unique_ptr<Asteroids::Domain::Store::StoreFactoryInterface> Factory::createStoreFactory()
			{
				//
				std::unique_ptr<Asteroids::Domain::Store::StoreFactoryInterface> factory(
					new Asteroids::Domain::Store::StoreFactory( this->this_pointer() )
				);
				
				return factory;
			}
			
			//
			std::unique_ptr<Asteroids::UI::UIFactoryInterface> Factory::createUIFactory()
			{
				//
				std::unique_ptr<Asteroids::UI::UIFactoryInterface> factory(
					new Asteroids::UI::UIFactory(this->this_pointer())
				);
				
				return factory;
			}
			
			//
			std::unique_ptr<Asteroids::TechnicalServices::TechnicalServicesFactoryInterface> Factory::createTechnicalServicesFactory()
			{
				//
				std::unique_ptr<Asteroids::TechnicalServices::TechnicalServicesFactoryInterface> factory(
					new Asteroids::TechnicalServices::TechnicalServicesFactory()
				);
				
				return factory;
			}
			
			//
			std::shared_ptr<Factory> Factory::this_pointer()
			{
				return this->shared_from_this();
			}
		}
	}
}

