#ifndef ASTEROIDS_DOMAIN_GAME_GAME_HISTORY_INTERFACE_H
#define ASTEROIDS_DOMAIN_GAME_GAME_HISTORY_INTERFACE_H


//
#include "Asteroids/ForwardDeclarations.h"


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
			class GameHistoryInterface
			{
				//
				public:
					
					//
					virtual std::vector<std::shared_ptr<GAME_HISTORY_ENTRY_INTERFACE>> get_history() = 0;
			};
		}
	}
}








#endif

