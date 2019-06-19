#ifndef ASTEROIDS_DOMAIN_NET_CLIENTSERVERCOMMUNICATOR_H
#define ASTEROIDS_DOMAIN_NET_CLIENTSERVERCOMMUNICATOR_H


//
#include "Asteroids/ForwardDeclarations.h"
#include "Asteroids/Domain/Net/ClientServerCommunicatorInterface.h"


//
namespace Asteroids
{
	//
	namespace Domain
	{
		//
		namespace Net
		{
			///	Implementation of ClientServerCommunicatorInterface
			class ClientServerCommunicator
				: public ClientServerCommunicatorInterface
			{
				//
				public:
					
					//
					bool authorizePayment(
						std::shared_ptr<Asteroids::Domain::Store::STORE_ITEM_INTERFACE> item,
						std::string cc_number,
						std::string cc_expiration,
						std::string cc_security_code
					);
					
					//
					bool notifyServerOfGameHistoryEntrySocialMediaShare(
						std::string game_history_entry_id
					);
			};
		}
	}
}









#endif
