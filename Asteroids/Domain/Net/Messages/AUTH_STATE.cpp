

//
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
			namespace Messages
			{
				//
				AUTH_STATE::AUTH_STATE()
				{
					//
					this->reset();
				}
				
				//
				void AUTH_STATE::reset()
				{
					//
					this->setAuthSuccessful(false);
				}
				
				//
				void AUTH_STATE::setAuthSuccessful(bool b)
				{
					//
					this->_auth_successful = b;
				}
				
				//
				bool AUTH_STATE::isAuthSuccessful()
				{
					//
					return this->_auth_successful;
				}
			}
		}
	}
}









