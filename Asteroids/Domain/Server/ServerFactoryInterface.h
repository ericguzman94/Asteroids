#ifndef ASTEROIDS_DOMAIN_SERVER_SERVERFACTORYINTERFACE_H
#define ASTEROIDS_DOMAIN_SERVER_SERVERFACTORYINTERFACE_H


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
		namespace Server
		{
			///	Creates things inside the Server package
			class ServerFactoryInterface
			{
				//
				public:
					
					//
					virtual std::unique_ptr<Asteroids::Domain::Server::ServerDaemonInterface> createDaemon() = 0;
					virtual std::unique_ptr<Asteroids::Domain::Server::ServerUpdaterInterface> createUpdater() = 0;
					virtual std::shared_ptr<Asteroids::Domain::Server::HACCS_REPORT_INTERFACE> createEmptyHACCSReport() = 0;
			};
		}
	}
}









#endif

