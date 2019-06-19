#ifndef ASTEROIDS_DOMAIN_NET_CLIENTSERVERCOMMUNICATORINTERFACE_H
#define ASTEROIDS_DOMAIN_NET_CLIENTSERVERCOMMUNICATORINTERFACE_H


//
#include "Asteroids/ForwardDeclarations.h"


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
			///	Allows a client to communicate with the server
			/**
			 * The ClientServerCommunicatorInterface simulates things that should typically be asked of our remote
			 * Asteroids server to do on the Client's behalf.
			 * For instance, it wouldn't make sense for a Client to authorize a credit card payment
			 * directly with a payment gateway. Instead it would ask our Asteroids server to auth the payment,
			 * THEN the Asteroids server would auth with the external service, and come back with a response
			*/
			class ClientServerCommunicatorInterface
			{
				//
				public:
					
					///	@todo Need to add an account ID to this, methinks
					virtual bool authorizePayment(
						std::shared_ptr<Asteroids::Domain::Store::STORE_ITEM_INTERFACE> item,
						std::string cc_number,
						std::string cc_expiration,
						std::string cc_security_code
					) = 0;
					
					/// @todo Notify the server that we have shared a game history entry to social media (will cause powerUp added to account, later)
					virtual bool notifyServerOfGameHistoryEntrySocialMediaShare(
						std::string game_history_entry_id
					) = 0;
			};
		}
	}
}








#endif
