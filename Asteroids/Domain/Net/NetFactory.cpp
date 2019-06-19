

//
#include "Asteroids/Domain/Net/NetFactory.h"


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
			NetFactory::NetFactory()
			{
				//
				this->reset();
			}
			
			//
			void NetFactory::reset()
			{
				//
				
			}
			
			//
			std::unique_ptr<Net::Authentication::AuthenticationInterface> NetFactory::createNetworkAuthenticator()
			{
				//
				std::unique_ptr<Net::Authentication::Authenticator> authenticator(
					new Net::Authentication::Authenticator()
				);
				
				//
				return authenticator;
			}
			
			//
			std::unique_ptr<Net::ClientServerCommunicatorInterface> NetFactory::createClientServerCommunicator()
			{
				//
				std::unique_ptr<Net::ClientServerCommunicator> comm(
					new Net::ClientServerCommunicator()
				);
				
				return comm;
			}
		}
	}
}








