

//
#include "Asteroids/Domain/Game/Game.h"
//
#include "Asteroids/Domain/Factory/Factory.h"
#include "Asteroids/Domain/Game/Defines.h"
#include "Asteroids/Domain/Game/Randomer.h"
#include "Asteroids/Domain/Game/Actors/GunShip.h"
#include "Asteroids/Domain/Game/Actors/Bullet.h"
#include "Asteroids/Domain/Game/Actors/Rock.h"


#ifdef USE_LONG_ROCKS
	#include "Asteroids/Domain/Game/Actors/LongRock.h"
#endif


//
#include <iostream>
#include <string>
#include <chrono>
#include <thread>


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
			Game::Game()
			{
				//
				this->init();
			}
			
			//
			void Game::init()
			{
				/**
				 * 
				*/
				this->_factory = std::unique_ptr<Asteroids::Domain::Factory::Factory>(
					new Asteroids::Domain::Factory::Factory()
				);
				this->_game_factory = this->_factory->createGameFactory();
				this->_randomer = this->_game_factory->createRandomer();
				
				//
				this->_player = std::unique_ptr<Actors::GunShip>(
					new Actors::GunShip()
				);
				
				//
				this->reset();
			}
			
			//
			void Game::reset()
			{
				//
				this->_ticks_per_second = ASTEROIDS_GAME_TICKS_PER_SECOND;
				
				//
				this->_is_active = false;
				this->_is_round_active = false;
				this->_round_number = 0;
				this->_player_score = 0;
				this->_last_time_ms = 0;
				
				//
				this->_board_width = ASTEROIDS_GAME_BOARD_WIDTH;
				this->_board_height = ASTEROIDS_GAME_BOARD_HEIGHT;
			}
			
			//
			void Game::start()
			{
				//
				this->_is_active = true;
				this->_round_number = 0;
				
				//
				this->randomly_place_player();
				
				//
				this->start_round();
			}
			
			//
			void Game::update()
			{
				//
				long ticks = this->calculate_ticks_since_last_update();
				std::shared_ptr<Asteroids::Domain::Game::Actors::Bullet> bullet;
				std::shared_ptr<Asteroids::Domain::Game::Actors::Rock> rock;
				std::shared_ptr<Asteroids::Domain::Game::Actors::Actor> actor;
				size_t i, j;
				
				//	Grab fired player bullets
				for ( std::shared_ptr<Asteroids::Domain::Game::Actors::Bullet> bullet : this->_player->get_fired_bullets(true) ) {
					this->_bullets.push_back(bullet);
				}
				
				//	Update player
				this->_player->update(ticks);
				//	Update bullets
				for ( i=0; i<this->_bullets.size(); i++ ) {
					bullet = this->_bullets[i];
					bullet->update(ticks);
				}
				//	Update rocks
				for ( i=0; i<this->_rocks.size(); i++ ) {
					rock = this->_rocks[i];
					rock->update(ticks);
				}
				
				//
				this->keep_actors_in_bounds();
				
				//	Check for bullet-to-rock collisions
				for ( i=0; i<this->_bullets.size(); i++ ) {
					bullet = this->_bullets[i];
					for ( j=0; j<this->_rocks.size(); j++ ) {
						rock = this->_rocks[j];
						if ( bullet->check_collision(*rock) ) {
							
							///	@todo Rocks should eventually split when hit
							this->_bullets.erase(this->_bullets.begin() + i);
							this->_rocks.erase(this->_rocks.begin() + j);
							this->_player_score += ASTEROIDS_GAME_ROCKS_POINTS;
							
							//	Start the loop over again,
							//	since the indices are messed up
							i = j = 0;
							break;
						}
					}
				}
				
				//	Delete actors that want to be deleted
				for ( i=0; i<this->_bullets.size(); i++ ) {
					actor = this->_bullets[i];
					if ( actor->wants_to_be_deleted() ) {
						this->_bullets.erase( this->_bullets.begin() + i );
					}
				}
				
				//	Maybe win or lose the round
				this->maybe_lose_round();
				this->maybe_win_round();
				
				//
				this->wait_for_frames_per_second(ASTEROIDS_GAME_TARGET_FRAMES_PER_SECOND);
			}
			
			//
			void Game::quit()
			{
				//
				this->_is_active = false;
			}
			
			//
			bool Game::is_active()
			{
				//
				return this->_is_active;
			}
			
			//
			double Game::get_board_width()
			{
				//
				return this->_board_width;
			}
			
			//
			double Game::get_board_height()
			{
				//
				return this->_board_height;
			}
			
			//
			long Game::get_ticks_per_second()
			{
				//
				return this->_ticks_per_second;
			}
			
			//
			void Game::wait_for_frames_per_second(long fps)
			{
				//
				long ticks_goal = this->_ticks_per_second / fps;
				
				//	Sleep until we've slowed down to our goal
				while ( this->calculate_ticks_since_last_update(false) < ticks_goal )
				{
					std::this_thread::sleep_for(std::chrono::milliseconds(1));
				}
			}
			
			//
			int Game::get_round()
			{
				//
				return this->_round_number;
			}
			
			//
			int Game::get_score()
			{
				//
				return this->_player_score;
			}
			
			//
			std::shared_ptr<Asteroids::Domain::Game::Actors::ActorInterface> Game::get_player()
			{
				//
				return this->_player;
			}
			
			//
			std::vector< std::shared_ptr<Asteroids::Domain::Game::Actors::ActorInterface> > Game::get_actors()
			{
				//
				std::vector<std::shared_ptr<Asteroids::Domain::Game::Actors::ActorInterface>> actors;
				
				//
				actors.push_back(this->_player);
				for ( std::shared_ptr<Asteroids::Domain::Game::Actors::Bullet> bullet : this->_bullets ) {
					actors.push_back(bullet);
				}
				for ( std::shared_ptr<Asteroids::Domain::Game::Actors::Rock> rock : this->_rocks ) {
					actors.push_back(rock);
				}
				
				return actors;
			}
			
			//
			std::pair<double,double> Game::get_random_board_position()
			{
				//
				double x = this->_randomer->get_double(0, this->_board_width);
				double y = this->_randomer->get_double(0, this->_board_height);
				
				return std::pair<double,double>(x, y);
			}
			
			///	Ticks are just microseconds
			long Game::get_current_timestamp_ticks()
			{
				//
				std::chrono::microseconds ms;
				
				//
				ms = std::chrono::duration_cast< std::chrono::microseconds >
				(
					std::chrono::system_clock::now().time_since_epoch()
				);
				
				return ms.count();
			}
			
			//
			long Game::calculate_ticks_since_last_update(bool update)
			{
				//
				long ms_now = this->get_current_timestamp_ticks();
				long dt;
				
				//
				if ( this->_last_time_ms == 0 ) {
					dt = 0;
				}
				else{
					dt = ms_now - this->_last_time_ms;
				}
				
				//
				if (update) {
					this->_last_time_ms = ms_now;
				}
				
				return dt;
			}
			
			//
			void Game::initialize_random_rocks()
			{
				//
				std::shared_ptr<Asteroids::Domain::Game::Actors::Rock> rock;
				std::pair<double,double> pos;
				
				//
				this->_rocks.clear();
				
				//
				while ( this->_rocks.size() < ASTEROIDS_GAME_ROCKS_PER_LEVEL )
				{
					//
					std::shared_ptr<Asteroids::Domain::Game::Actors::Rock> rock;
					
					//	Instantiate
					#ifdef USE_LONG_ROCKS
						if ( this->_randomer->roll_bool() ) {
							rock = std::shared_ptr<Asteroids::Domain::Game::Actors::Rock>(
								new Asteroids::Domain::Game::Actors::Rock()
							);
						}
						else{
							rock = std::shared_ptr<Asteroids::Domain::Game::Actors::Rock>(
								new Asteroids::Domain::Game::Actors::LongRock()
							);
						}
					#else
						rock = std::shared_ptr<Asteroids::Domain::Game::Actors::Rock>(
							new Asteroids::Domain::Game::Actors::Rock()
						);
					#endif
					
					//	Set random position
					pos = this->get_random_board_position();
					rock->set_position(pos.first, pos.second);
					
					//	Set random velocity
					double vel_x = this->_randomer->get_double(
						-ASTEROIDS_GAME_ROCKS_INITIAL_VELOCITY_STRENGTH, ASTEROIDS_GAME_ROCKS_INITIAL_VELOCITY_STRENGTH
					);
					double vel_y = this->_randomer->get_double(
						-ASTEROIDS_GAME_ROCKS_INITIAL_VELOCITY_STRENGTH, ASTEROIDS_GAME_ROCKS_INITIAL_VELOCITY_STRENGTH
					);
					double vel_r = this->_randomer->get_double(
						-ASTEROIDS_GAME_ROCKS_INITIAL_VELOCITY_STRENGTH, ASTEROIDS_GAME_ROCKS_INITIAL_VELOCITY_STRENGTH
					);
					rock->set_velocity(vel_x, vel_y, vel_r);
					
					//	Only place the rock if it doesn't collide with the player
					if ( !rock->check_collision( this->_player ) ) {
						this->_rocks.push_back(rock);
					}
					else{
						std::cout << "Initial Rock Collision!";
					}
				}
			}
			
			//
			void Game::start_round()
			{
				//
				this->_is_round_active = true;
				this->_round_number++;
				
				//
				this->initialize_random_rocks();
			}
			
			//
			void Game::maybe_win_round()
			{
				//
				if ( this->_is_active && this->_is_round_active && !this->_rocks.size() ) {
					this->win_round();
				}
			}
			
			//
			void Game::win_round()
			{
				//	Start the next round
				this->start_round();
			}
			
			//
			void Game::maybe_lose_round()
			{
				//
				if ( this->_is_active && this->_is_round_active ) {
					
					//	Any colliding rock breaks round
					for ( std::shared_ptr<Asteroids::Domain::Game::Actors::Actor> actor : this->_rocks ) {
						if ( actor->check_collision(this->_player) ) {
							this->lose_round();
							return;
						}
					}
				}
			}
			
			//
			void Game::lose_round()
			{
				//
				this->quit();
			}
			
			//
			void Game::randomly_place_player()
			{
				//
				std::pair<double,double> pos = this->get_random_board_position();
				
				//
				this->_player->set_position(pos.first, pos.second);
			}
			
			//
			void Game::keep_actors_in_bounds()
			{
				//	Wrap actors that are out of bounds
				for ( std::shared_ptr<Asteroids::Domain::Game::Actors::ActorInterface> actor : this->get_actors() ) {
					
					//
					double x = actor->get_x();
					double y = actor->get_y();
					bool changed_anything = false;
					
					//
					while ( x < 0 )
					{
						changed_anything = true;
						x += this->_board_width;
					}
					while ( x >= this->_board_width )
					{
						changed_anything = true;
						x -= this->_board_width;
					}
					while ( y < 0 )
					{
						changed_anything = true;
						y += this->_board_height;
					}
					while ( y >= this->_board_height )
					{
						changed_anything = true;
						y -= this->_board_height;
					}
					
					//
					if ( changed_anything) {
						actor->set_position(x, y);
					}
				}
			}
		}
	}
}






