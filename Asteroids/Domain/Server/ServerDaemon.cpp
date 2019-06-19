

//
#include "Asteroids/Domain/Server/ServerDaemon.h"
//
#include "Asteroids/Domain/Factory/FactoryInterface.h"
#include "Asteroids/TechnicalServices/TechnicalServicesFactoryInterface.h"
#include "Asteroids/TechnicalServices/Persistence/DatabaserInterface.h"
#include "Asteroids/Domain/Server/ServerFactoryInterface.h"
#include "Asteroids/Domain/Server/ServerUpdater.h"
#include "Asteroids/Domain/Server/HACCS_REPORT_INTERFACE.h"


//
#include <iostream>
#include <thread>
#include <chrono>


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
			ServerDaemon::ServerDaemon( std::shared_ptr<Asteroids::Domain::Factory::FactoryInterface> factory )
			{
				//
				this->_factory = factory;
				
				//
				this->init();
			}
			
			//
			ServerDaemon::~ServerDaemon()
			{
				//	Nada so far
			}
			
			//
			void ServerDaemon::run()
			{
				//
				this->_restart_is_required = false;
				this->_quit = false;
				
				//	Uhm ... do nothing .... in a loop
				while ( !this->_quit )
				{
					//
					//std::cout << "Daemon is actually looping inside run()" << std::endl;
					std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				}
			}
			
			//
			void ServerDaemon::quit()
			{
				//
				this->_quit = true;
			}
			
			//
			void ServerDaemon::apply_updates()
			{
				//
				std::unique_ptr<Asteroids::Domain::Server::ServerUpdaterInterface> updater = this->_factory_server->createUpdater();
				
				//
				updater->update();
				
				//
				this->require_restart();
			}
			
			//
			void ServerDaemon::require_restart()
			{
				//
				this->_restart_is_required = true;
			}
			
			//
			bool ServerDaemon::is_restart_required()
			{
				//
				return this->_restart_is_required;
			}
			
			///	Get the next user to review for breaking TOS/AUP; Returns dummy data at the moment
			///	@todo Still returning dummy data!
			std::shared_ptr<HACCS_REPORT_INTERFACE> ServerDaemon::get_next_haccs_report()
			{
				//	Ask the factory for a new object
				std::shared_ptr<HACCS_REPORT_INTERFACE> report = this->_factory_server->createEmptyHACCSReport();
				
				//	Fill with dummy data
				report->set_user_details("l33tH4x0r_5", "The L33t3st of L33ts", "haxxxx@example.com");
				report->add_suspicious_activity("2018/10/27 02:00:00", "System detected 10+ in-game disconnects in a row in the last 24 hours");
				report->add_suspicious_activity("2018/10/27 01:00:00", "System detected user tried a failed payment method more than 5 times in the last 24 hours");
				report->add_suspicious_activity("2018/10/27 02:00:00", "System detected this user's ranking improved over 500% in the last 24 hours");
				report->add_suspicious_activity("2018/10/27 02:00:00", "System detected this user's ranking improved over 5000% in the last 7 days");
				
				return report;
			}
			
			///	Forgive a HACCS report
			/**
				@todo Doesn't actually do anything yet
			*/
			void ServerDaemon::forgive_haccs_report( std::shared_ptr<HACCS_REPORT_INTERFACE> report )
			{
				//	Mute warnings... lulz
				report = report;
				
				//	Create a query for saving the data, and execute
				///	@todo Query not yet implemented
				std::string query = "MY QUERY";
				this->_databaser->query(query);
			}
			
			///	Ban a user from the system
			/**
				@todo Doesn't do anything yet
			*/
			void ServerDaemon::ban_user( std::string username )
			{
				//	Mute warnings ... lulz
				username = username;
				
				//	Create a query for saving the data, and execute
				///	@todo Query not yet implemented
				std::string query = "MY QUERY";
				this->_databaser->query(query);
			}
			
			//
			void ServerDaemon::init()
			{
				//	Make more factories
				this->_factory_server = this->_factory->createServerFactory();
				this->_factory_technical_services = this->_factory->createTechnicalServicesFactory();
				
				//	Create a databaser
				this->_databaser = this->_factory_technical_services->createDatabaser();
			}
		}
	}
}







