#ifndef ASTEROIDS_DOMAIN_NET_NETFACTORYINTERFACE_H
#define ASTEROIDS_DOMAIN_NET_NETFACTORYINTERFACE_H


//
#include "Asteroids/ForwardDeclarations.h"


//
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
			///	Factory to generate things inside the Net package
			class NetFactoryInterface
			{
				//
				public:
					
					//
					virtual std::unique_ptr<Authentication::AuthenticationInterface> createNetworkAuthenticator() = 0;
					virtual std::unique_ptr<ClientServerCommunicatorInterface> createClientServerCommunicator() = 0;
					
				//
				private:
					
					//
					
			};
		}
	}
}











#endif
