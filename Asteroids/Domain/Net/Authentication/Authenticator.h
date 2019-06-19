#ifndef ASTEROIDS_DOMAIN_NET_AUTHENTICATION_AUTHENTICATOR_H
#define ASTEROIDS_DOMAIN_NET_AUTHENTICATION_AUTHENTICATOR_H


//
#include "Asteroids/ForwardDeclarations.h"
#include "Asteroids/Domain/Net/Authentication/AuthenticationInterface.h"


//
#include <string>
#include <memory>


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
				
				///	Implementation of AuthenticationInterface
				class Authenticator
					: public AuthenticationInterface
				{
					//
					public:
						
						//
						Authenticator();
						
						//
						void reset();
						
						//
						std::shared_ptr<Messages::AUTH_STATE> attemptLogin(string username, string password);
					
					//
					private:
						
						//
						std::shared_ptr<Messages::AUTH_STATE> sendAuthToServer(std::shared_ptr<Messages::AUTH_ATTEMPT> auth);
				};
			}
		}
	}
}





#endif
