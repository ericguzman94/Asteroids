#ifndef ASTEROIDS_DOMAIN_SERVER_SERVERDAEMONINTERFACE_H
#define ASTEROIDS_DOMAIN_SERVER_SERVERDAEMONINTERFACE_H


//
#include "Asteroids/ForwardDeclarations.h"


//
#include <memory>
#include <string>


//
namespace Asteroids
{
	//
	namespace Domain
	{
		//
		namespace Server
		{
			///	Server daemon that would eventually listen for and service network requests (from client or local or whatever). Currently does nothing.
			class ServerDaemonInterface
			{
				//
				public:
					
					//
					virtual void run() = 0;
					virtual void quit() = 0;
					
					//
					virtual void apply_updates() = 0;
					virtual void require_restart() = 0;
					virtual bool is_restart_required() = 0;
					
					//
					virtual std::shared_ptr<HACCS_REPORT_INTERFACE> get_next_haccs_report() = 0;
					virtual void forgive_haccs_report( std::shared_ptr<HACCS_REPORT_INTERFACE> report ) = 0;
					
					//
					virtual void ban_user( std::string username ) = 0;
			};
		}
	}
}







#endif
