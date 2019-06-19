

//
#include "Asteroids/Domain/Net/ClientServerCommunicator.h"


//
namespace Asteroids
{
	//
	namespace Domain
	{
		//
		namespace Net
		{
			///	Dummy stub thingy
			///	; Always pretend the payment authorized successfully
			bool ClientServerCommunicator::authorizePayment(
				std::shared_ptr<Asteroids::Domain::Store::STORE_ITEM_INTERFACE> item,
				std::string cc_number,
				std::string cc_expiration,
				std::string cc_security_code
			)
			{
				///	Assign input args to their freaking selves, to mute "unused var"
				///	warnings
				item = item;
				cc_number = cc_number;
				cc_expiration = cc_expiration;
				cc_security_code = cc_security_code;
				
				return true;
			}
			
			///	Dummy stub. Would eventually notify server, which in turn would cause PowerUp added to account
			bool ClientServerCommunicator::notifyServerOfGameHistoryEntrySocialMediaShare(
				std::string game_history_entry_id
			)
			{
				//
				game_history_entry_id = game_history_entry_id;
				
				return true;
			}
		}
	}
}









