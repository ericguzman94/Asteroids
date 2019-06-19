

//
#include "Asteroids/Domain/Server/ServerFactory.h"
//
#include "Asteroids/Domain/Server/ServerDaemon.h"
#include "Asteroids/Domain/Server/ServerUpdater.h"
#include "Asteroids/Domain/Server/HACCS_REPORT.h"


//
namespace Asteroids
{
	//
	namespace Domain
	{
		//
		namespace Server
		{
			//
			ServerFactory::ServerFactory( std::shared_ptr<Asteroids::Domain::Factory::FactoryInterface> factory )
			{
				//
				this->_factory = factory;
				
				//
				this->init();
			}
			
			//
			std::unique_ptr<Asteroids::Domain::Server::ServerDaemonInterface> ServerFactory::createDaemon()
			{
				//
				std::unique_ptr<Asteroids::Domain::Server::ServerDaemonInterface> server(
					new Asteroids::Domain::Server::ServerDaemon(this->_factory)
				);
				
				return server;
			}
			
			//
			std::unique_ptr<Asteroids::Domain::Server::ServerUpdaterInterface> ServerFactory::createUpdater()
			{
				//
				std::unique_ptr<Asteroids::Domain::Server::ServerUpdaterInterface> updater(
					new Asteroids::Domain::Server::ServerUpdater()
				);
				
				return updater;
			}
			
			//
			std::shared_ptr<Asteroids::Domain::Server::HACCS_REPORT_INTERFACE> ServerFactory::createEmptyHACCSReport()
			{
				//
				std::shared_ptr<Asteroids::Domain::Server::HACCS_REPORT_INTERFACE> report(
					new Asteroids::Domain::Server::HACCS_REPORT()
				);
				
				//
				return report;
			}
			
			//
			void ServerFactory::init()
			{
				///	bleh
			}
			
		}
	}
}








