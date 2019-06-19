#ifndef ASTEROIDS_DOMAIN_NET_NETFACTORY_H
#define ASTEROIDS_DOMAIN_NET_NETFACTORY_H


//
#include "Asteroids/ForwardDeclarations.h"
#include "Asteroids/Domain/Net/NetFactoryInterface.h"
#include "Asteroids/Domain/Net/ClientServerCommunicator.h"
#include "Asteroids/Domain/Net/Authentication/Authenticator.h"


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
			///	Implementation of NetFactoryInterface
			class NetFactory
				: public NetFactoryInterface
			{
				//
				public:
					
					//	CTOR
					NetFactory();
					
					//
					void reset();
					
					//
					std::unique_ptr<Net::Authentication::AuthenticationInterface> createNetworkAuthenticator();
					std::unique_ptr<Net::ClientServerCommunicatorInterface> createClientServerCommunicator();
					
				//
				private:
					
					//
					
			};
		}
	}
}









#endif
