#ifndef ASTEROIDS_DOMAIN_NET_MESSAGES_AUTH_ATTEMPT_H
#define ASTEROIDS_DOMAIN_NET_MESSAGES_AUTH_ATTEMPT_H


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
		namespace Net
		{
			//
			namespace Messages
			{
				//
				using std::string;
				
				///	Just holds one authentication attempt; Is "sent to server"
				class AUTH_ATTEMPT
				{
					//
					public:
						
						//
						AUTH_ATTEMPT();
						
						//
						void reset();
						
						//
						void setUsername(string username);
						void setPassword(string password);
						
						//
						static constexpr const char * DEFAULT_USERNAME = "";
						static constexpr const char * DEFAULT_PASSWORD = "";
					
					//
					private:
						
						//
						string
							_username,
							_password
							;
				};
			}
		}
	}
}






#endif
