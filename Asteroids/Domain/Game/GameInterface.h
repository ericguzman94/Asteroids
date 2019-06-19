#ifndef ASTEROIDS_DOMAIN_GAME_GAME_INTERFACE_H
#define ASTEROIDS_DOMAIN_GAME_GAME_INTERFACE_H


//
#include <vector>
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
			///	Interface that allows users to control the main client game
			class GameInterface
			{
				//
				public:
					
					//
					virtual void reset() = 0;
					virtual void start() = 0;
					virtual void update() = 0;
					virtual void quit() = 0;
					virtual bool is_active() = 0;
					
					//
					virtual double get_board_width() = 0;
					virtual double get_board_height() = 0;
					
					///
					virtual void wait_for_frames_per_second(long tps) = 0;
					
					///
					virtual int get_round() = 0;
					virtual int get_score() = 0;
					
					///	Return the player
					virtual std::shared_ptr<Asteroids::Domain::Game::Actors::ActorInterface> get_player() = 0;
					
					///	Return all actors in the game
					virtual std::vector< std::shared_ptr<Asteroids::Domain::Game::Actors::ActorInterface> > get_actors() = 0;
			};
		}
	}
}


#endif
