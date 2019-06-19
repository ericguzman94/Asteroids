#ifndef ASTEROIDS_DOMAIN_NET_AUTHENTICATION_AUTHENTICATION_INTERFACE_H
#define ASTEROIDS_DOMAIN_NET_AUTHENTICATION_AUTHENTICATION_INTERFACE_H


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
		namespace Net
		{
			//
			namespace Authentication
			{
				//
				using std::string;
				
				///	Main interface for client to authenticate with server
				class AuthenticationInterface
				{
					//
					public:
						
						//
						virtual std::shared_ptr<Asteroids::Domain::Net::Messages::AUTH_STATE> attemptLogin(string username, string password) = 0;
				};
			}
		}
	}
}







#endif
