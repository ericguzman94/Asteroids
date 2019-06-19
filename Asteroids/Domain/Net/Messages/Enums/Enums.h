#ifndef ASTEROIDS_DOMAIN_NET_MESSAGES_ENUMS_H
#define ASTEROIDS_DOMAIN_NET_MESSAGES_ENUMS_H


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
				namespace Enums
				{
					///	Result of an attempt by client to connect to the server
					enum class ConnectionStatus
					{
						//
						Unset,
						Successful,
						Failed
					};
				}
			}
		}
	}
}






#endif
