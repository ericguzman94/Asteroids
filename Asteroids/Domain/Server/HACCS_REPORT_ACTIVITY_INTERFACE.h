#ifndef ASTEROIDS_DOMAIN_SERVER_HACCS_REPORT_ACTIVITY_INTERFACE_H
#define ASTEROIDS_DOMAIN_SERVER_HACCS_REPORT_ACTIVITY_INTERFACE_H


//
#include "Asteroids/ForwardDeclarations.h"


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
			///	Data structure class that contains a description of one suspicious activity
			class HACCS_REPORT_ACTIVITY_INTERFACE
			{
				//
				public:
					
					//
					virtual void reset() = 0;
					
					//
					virtual void set_when(std::string when) = 0;
					virtual std::string get_when() = 0;
					
					//
					virtual void set_what(std::string what) = 0;
					virtual std::string get_what() = 0;
			};
		}
	}
}


#endif
