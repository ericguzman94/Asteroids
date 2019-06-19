

//
#include "Asteroids/Domain/Net/Authentication/Authenticator.h"
#include "Asteroids/Domain/Net/Authentication/AuthenticationInterface.h"
#include "Asteroids/Domain/Net/Messages/AUTH_ATTEMPT.h"
#include "Asteroids/Domain/Net/Messages/AUTH_STATE.h"


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
				Authenticator::Authenticator()
				{
					//
					this->reset();
				}
				
				//
				void Authenticator::reset()
				{
					//
					
				}
				
				//
				std::shared_ptr<Messages::AUTH_STATE> Authenticator::attemptLogin(string username, string password)
				{
					//
					std::shared_ptr<Messages::AUTH_ATTEMPT> auth_data(
						new Messages::AUTH_ATTEMPT()
					);
					
					//
					auth_data->setUsername(username);
					auth_data->setPassword(password);
					
					//
					std::shared_ptr<Messages::AUTH_STATE> result = this->sendAuthToServer(auth_data);
					if ( !result ) {
						throw std::runtime_error("Got null pointer back from sendAuthToServer()");
					}
					
					//
					return result;
				}
				
				/**
					@todo Stub function that always returns success!
				*/
				std::shared_ptr<Messages::AUTH_STATE> Authenticator::sendAuthToServer(std::shared_ptr<Messages::AUTH_ATTEMPT> auth)
				{
					//
					std::shared_ptr<Messages::AUTH_STATE> result(
						new Messages::AUTH_STATE
					);
					
					//	Only succeed if an actual attempt was provided
					//	(also mutes unused-var warnings, yaaaay!)
					if ( auth ) {
						result->setAuthSuccessful(true);
					}
					else{
						result->setAuthSuccessful(false);
					}
					
					return result;
				}
			}
		}
	}
}




