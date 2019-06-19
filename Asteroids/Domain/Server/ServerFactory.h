#ifndef ASTEROIDS_DOMAIN_SERVER_SERVERFACTORY_H
#define ASTEROIDS_DOMAIN_SERVER_SERVERFACTORY_H


//
#include "Asteroids/ForwardDeclarations.h"
#include "Asteroids/Domain/Server/ServerFactoryInterface.h"
//
#include "Asteroids/Domain/Server/ServerDaemonInterface.h"
#include "Asteroids/Domain/Server/ServerUpdaterInterface.h"
#include "Asteroids/Domain/Server/HACCS_REPORT_INTERFACE.h"


//
namespace Asteroids
{
	//
	namespace Domain
	{
		//
		namespace Server
		{
			///	Implements the ServerFactoryInterface
			class ServerFactory
				:public ServerFactoryInterface
			{
				//
				public:
					
					//
					ServerFactory( std::shared_ptr<Asteroids::Domain::Factory::FactoryInterface> factory );
					
					//
					std::unique_ptr<Asteroids::Domain::Server::ServerDaemonInterface> createDaemon();
					std::unique_ptr<Asteroids::Domain::Server::ServerUpdaterInterface> createUpdater();
					std::shared_ptr<Asteroids::Domain::Server::HACCS_REPORT_INTERFACE> createEmptyHACCSReport();
					
				//
				private:
					
					//
					std::shared_ptr<Asteroids::Domain::Factory::FactoryInterface> _factory;
					
					//
					void init();
			};
		}
	}
}












#endif
