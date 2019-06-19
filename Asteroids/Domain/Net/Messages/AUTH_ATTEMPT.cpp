

//
#include "Asteroids/Domain/Net/Messages/AUTH_ATTEMPT.h"


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
				AUTH_ATTEMPT::AUTH_ATTEMPT()
				{
					//
					this->reset();
				}
				
				//
				void AUTH_ATTEMPT::reset()
				{
					//
					this->setUsername(AUTH_ATTEMPT::DEFAULT_USERNAME);
					this->setPassword(AUTH_ATTEMPT::DEFAULT_PASSWORD);
				}
				
				//
				void AUTH_ATTEMPT::setUsername(string username)
				{
					//
					this->_username = username;
				}
				
				//
				void AUTH_ATTEMPT::setPassword(string password)
				{
					//
					this->_password = password;
				}
			}
		}
	}
}






