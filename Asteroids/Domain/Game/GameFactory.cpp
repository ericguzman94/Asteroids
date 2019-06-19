

//
#include "Asteroids/Domain/Game/GameFactory.h"
//
#include "Asteroids/Domain/Game/Game.h"
#include "Asteroids/Domain/Game/Randomer.h"
#include "Asteroids/Domain/Game/GameHistory.h"


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
			GameFactory::GameFactory()
			{
				//
				this->reset();
			}
			
			//
			void GameFactory::reset()
			{
				//
			}
			
			//
			std::unique_ptr<Asteroids::Domain::Game::GameInterface> GameFactory::createGame()
			{
				//
				std::unique_ptr<Asteroids::Domain::Game::GameInterface> game(
					new Asteroids::Domain::Game::Game()
				);
				
				return game;
			}
			
			//
			std::unique_ptr<Asteroids::Domain::Game::Randomer> GameFactory::createRandomer()
			{
				//
				std::unique_ptr<Asteroids::Domain::Game::Randomer> game(
					new Asteroids::Domain::Game::Randomer()
				);
				
				return game;
			}
			
			//
			std::unique_ptr<Asteroids::Domain::Game::GameHistoryInterface> GameFactory::createGameHistory()
			{
				//
				std::unique_ptr<Asteroids::Domain::Game::GameHistoryInterface> game(
					new Asteroids::Domain::Game::GameHistory()
				);
				
				return game;
			}
		}
	}
}




