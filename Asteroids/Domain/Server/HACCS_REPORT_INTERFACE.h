#ifndef ASTEROIDS_DOMAIN_SERVER_HACCS_REPORT_INTERFACE_H
#define ASTEROIDS_DOMAIN_SERVER_HACCS_REPORT_INTERFACE_H


//
#include "Asteroids/ForwardDeclarations.h"


//
#include <string>
#include <vector>
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
			///	Just a class that contains one report of one suspicious user
			class HACCS_REPORT_INTERFACE
			{
				//
				public:
					
					//
					virtual void reset() = 0;
					
					//
					virtual void set_id( std::string id ) = 0;
					virtual std::string get_id() = 0;
					
					//
					virtual void set_user_details(std::string username, std::string nickname, std::string email) = 0;
					virtual std::string get_username() = 0;
					virtual std::string get_nickname() = 0;
					virtual std::string get_email() = 0;
					
					//
					virtual void add_suspicious_activity(std::string when, std::string what) = 0;
					virtual std::vector<std::shared_ptr<HACCS_REPORT_ACTIVITY_INTERFACE>> get_suspicious_activities() = 0;
			};
		}
	}
}











#endif
