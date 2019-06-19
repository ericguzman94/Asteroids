#ifndef ASTEROIDS_DOMAIN_GAME_GAMEFACTORY_H
#define ASTEROIDS_DOMAIN_GAME_GAMEFACTORY_H


//
#include "Asteroids/Domain/Game/GameFactoryInterface.h"


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
			///	Implements GameFactoryInterface
			class GameFactory
				: public GameFactoryInterface
			{
				//
				public:
					
					//	CTOR
					GameFactory();
					
					//
					void reset();
					
					//
					std::unique_ptr<Asteroids::Domain::Game::GameInterface> createGame();
					std::unique_ptr<Asteroids::Domain::Game::Randomer> createRandomer();
					std::unique_ptr<Asteroids::Domain::Game::GameHistoryInterface> createGameHistory();
			};
		}
	}
}





#endif
