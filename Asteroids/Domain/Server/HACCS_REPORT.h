#ifndef ASTEROIDS_DOMAIN_SERVER_HACCS_REPORT_H
#define ASTEROIDS_DOMAIN_SERVER_HACCS_REPORT_H


//
#include "Asteroids/ForwardDeclarations.h"


//
#include "Asteroids/Domain/Server/HACCS_REPORT_INTERFACE.h"


//
#include <string>
#include <vector>


//
namespace Asteroids
{
	//
	namespace Domain
	{
		//
		namespace Server
		{
			///	Implementation of HACCS_REPORT_INTERFACE
			class HACCS_REPORT
				: public HACCS_REPORT_INTERFACE
			{
				//
				public:
					
					//
					HACCS_REPORT();
					
					//
					void reset();
					
					//
					void set_id( std::string id );
					std::string get_id();
					
					//
					void set_user_details(std::string username, std::string nickname, std::string email);
					std::string get_username();
					std::string get_nickname();
					std::string get_email();
					
					//
					void add_suspicious_activity(std::string when, std::string what);
					std::vector<std::shared_ptr<HACCS_REPORT_ACTIVITY_INTERFACE>> get_suspicious_activities();
					
				//
				private:
					
					//
					std::string _id;
					
					//
					std::string
						_username,
						_nickname,
						_email
						;
					
					///	_suspicious activities:
					std::vector< std::shared_ptr<HACCS_REPORT_ACTIVITY_INTERFACE> > _suspicious_activities;
			};
		}
	}
}











#endif
