#ifndef ASTEROIDS_DOMAIN_GAME_GAME_HISTORY_H
#define ASTEROIDS_DOMAIN_GAME_GAME_HISTORY_H


//
#include "Asteroids/ForwardDeclarations.h"
//
#include "Asteroids/Domain/Game/GameHistoryInterface.h"


//
#include <memory>
#include <vector>


//
namespace Asteroids
{
	//
	namespace Domain
	{
		//
		namespace Game
		{
			//
			class GameHistory
				: public GameHistoryInterface
			{
				//
				public:
					
					//
					GameHistory();
					
					//
					std::vector<std::shared_ptr<GAME_HISTORY_ENTRY_INTERFACE>> get_history();
			};
		}
	}
}








#endif

