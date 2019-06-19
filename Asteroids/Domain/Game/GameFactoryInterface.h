#ifndef ASTEROIDS_DOMAIN_GAME_GAMEFACTORYINTERFACE_H
#define ASTEROIDS_DOMAIN_GAME_GAMEFACTORYINTERFACE_H


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
		namespace Game
		{
			///	Create things inside the Game package
			class GameFactoryInterface
			{
				//
				public:
					
					//
					virtual std::unique_ptr<Asteroids::Domain::Game::GameInterface> createGame() = 0;
					virtual std::unique_ptr<Asteroids::Domain::Game::Randomer> createRandomer() = 0;
					virtual std::unique_ptr<Asteroids::Domain::Game::GameHistoryInterface> createGameHistory() = 0;
			};
		}
	}
}






#endif
