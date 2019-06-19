#ifndef ASTEROIDS_DOMAIN_SERVER_SERVERDAEMON_H
#define ASTEROIDS_DOMAIN_SERVER_SERVERDAEMON_H


//
#include "Asteroids/ForwardDeclarations.h"
#include "Asteroids/Domain/Server/ServerDaemonInterface.h"


//
#include <memory>
#include <atomic>


//
namespace Asteroids
{
	//
	namespace Domain
	{
		//
		namespace Server
		{
			///	Implements ServerDaemonInterface
			class ServerDaemon
				: public ServerDaemonInterface
			{
				//
				public:
					
					//
					ServerDaemon( std::shared_ptr<Asteroids::Domain::Factory::FactoryInterface> factory );
					~ServerDaemon();
					
					//
					void run();
					void quit();
					
					//
					void apply_updates();
					void require_restart();
					bool is_restart_required();
					
					//
					std::shared_ptr<HACCS_REPORT_INTERFACE> get_next_haccs_report();
					void forgive_haccs_report( std::shared_ptr<HACCS_REPORT_INTERFACE> report );
					
					//
					void ban_user( std::string username );
					
				//
				private:
					
					//
					std::shared_ptr<Asteroids::Domain::Factory::FactoryInterface> _factory;
					std::shared_ptr<Asteroids::Domain::Server::ServerFactoryInterface> _factory_server;
					std::shared_ptr<Asteroids::TechnicalServices::TechnicalServicesFactoryInterface> _factory_technical_services;
					//
					std::shared_ptr<Asteroids::TechnicalServices::Persistence::DatabaserInterface> _databaser;
					
					//
					std::atomic<bool> _restart_is_required;
					std::atomic<bool> _quit;
					
					//
					void init();
			};
		}
	}
}











#endif
