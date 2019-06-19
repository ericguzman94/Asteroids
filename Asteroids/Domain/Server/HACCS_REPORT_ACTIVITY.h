#ifndef ASTEROIDS_DOMAIN_SERVER_HACCS_REPORT_ACTIVITY_H
#define ASTEROIDS_DOMAIN_SERVER_HACCS_REPORT_ACTIVITY_H


//
#include "Asteroids/ForwardDeclarations.h"


//
#include "Asteroids/Domain/Server/HACCS_REPORT_ACTIVITY_INTERFACE.h"


//
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
			///	Implements the HACCS_REPORT_ACTIVITY_INTERFACE interface
			/**
				Owned and created by HACCS_REPORT, since they're the only one that will create us
				(ie not created by normal factory)
			*/
			class HACCS_REPORT_ACTIVITY
				: public HACCS_REPORT_ACTIVITY_INTERFACE
			{
				//
				public:
					
					//
					HACCS_REPORT_ACTIVITY();
					
					//
					void reset();
					
					//
					void set_when(std::string when);
					std::string get_when();
					
					//
					void set_what(std::string what);
					std::string get_what();
				
				//
				private:
					
					//
					std::string
						_when,
						_what
						;
			};
		}
	}
}


#endif
