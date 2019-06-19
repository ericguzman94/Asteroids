#ifndef ASTEROIDS_DOMAIN_GAME_GAME_H
#define ASTEROIDS_DOMAIN_GAME_GAME_H


//
#include "Asteroids/ForwardDeclarations.h"
#include "Asteroids/Domain/Game/GameInterface.h"
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
			///	Implementation of GameInterface (ie: The game ...)
			class Game
				: public GameInterface
			{
				//
				public:
					
					//
					Game();
					
					//
					void reset();
					
					//
					void start();
					void update();
					void quit();
					bool is_active();
					
					//
					double get_board_width();
					double get_board_height();
					
					//
					long get_ticks_per_second();
					
					///	Implement GameInterface methods
					void wait_for_frames_per_second(long tps);
					int get_round();
					int get_score();
					std::shared_ptr<Asteroids::Domain::Game::Actors::ActorInterface> get_player();
					std::vector< std::shared_ptr<Asteroids::Domain::Game::Actors::ActorInterface> > get_actors();
					
				//
				private:
					
					//
					std::unique_ptr<Asteroids::Domain::Factory::Factory> _factory;
					std::unique_ptr<Asteroids::Domain::Game::GameFactoryInterface> _game_factory;
					std::unique_ptr<Randomer> _randomer;
					
					//
					long _ticks_per_second;
					
					//
					bool _is_active;
					bool _is_round_active;
					int _round_number;
					long _last_time_ms;
					
					//
					double
						_board_width,
						_board_height
						;
					
					//
					std::shared_ptr<Actors::GunShip> _player;
					int _player_score;
					
					//
					std::vector<std::shared_ptr<Asteroids::Domain::Game::Actors::Bullet>> _bullets;
					std::vector<std::shared_ptr<Asteroids::Domain::Game::Actors::Rock>> _rocks;
					
					//
					void init();
					
					//
					std::pair<double,double> get_random_board_position();
					
					//
					long get_current_timestamp_ticks();
					long calculate_ticks_since_last_update(bool update=true);
					
					//
					void initialize_random_rocks();
					
					//
					void start_round();
					//
					void maybe_win_round();
					void win_round();
					//
					void maybe_lose_round();
					void lose_round();
					
					//
					void randomly_place_player();
					
					//
					void keep_actors_in_bounds();
			};
		}
	}
}




#endif
