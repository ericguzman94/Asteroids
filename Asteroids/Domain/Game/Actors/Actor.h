#ifndef ASTEROIDS_DOMAIN_GAME_ACTORS_ACTOR_H
#define ASTEROIDS_DOMAIN_GAME_ACTORS_ACTOR_H


//
#include "Asteroids/ForwardDeclarations.h"
#include "Asteroids/Domain/Game/Actors/ActorInterface.h"
#include "Asteroids/Domain/Game/Actors/Rect.h"
#include "Asteroids/Domain/Game/Actors/Vector.h"


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
			namespace Actors
			{
				///	Implementation of ActorInterface
				class Actor
					: public ActorInterface
				{
					//
					public:
						
						//
						Actor();
						
						//
						void reset();
						
						//
						long get_lifetime_ticks();
						bool wants_to_be_deleted();
						
						//
						void update(long elapsed_ticks);
						
						//
						void clear_input();
						void set_input_up(bool b);
						void set_input_down(bool b);
						void set_input_left(bool b);
						void set_input_right(bool b);
						void set_input_fire(bool b);
						
						//
						void set_polygon(std::vector<std::pair<double, double>> points);
						const std::vector<std::pair<double, double>>& get_polygon();
						std::vector<std::pair<double,double>> get_rotated_polygon();
						
						//
						std::vector<std::pair<double, double>> rotate_polygon(double radians);
						
						//
						void set_position(double x, double y);
						std::pair<double,double> get_position();
						double get_x();
						double get_y();
						
						//
						double set_rotation(double radians);
						double adjust_rotation(double radians);
						double get_rotation();
						
						//
						void set_velocity(double x, double y, double r);
						
						//
						std::vector<std::shared_ptr<Bullet>> get_fired_bullets(bool clear=true);
						
						//
						Rect get_rect() const;
						bool check_collision(const Asteroids::Domain::Game::Actors::Actor& other_actor);
						bool check_collision(std::shared_ptr<Asteroids::Domain::Game::Actors::Actor> other_actor);
						
					//
					protected:
						
						//
						std::unique_ptr<Vector> _vector;
						
						//
						bool
							_input_up,
							_input_down,
							_input_left,
							_input_right,
							_input_fire
							;
						
						//
						void update_rect();
						
						//
						void deleteme();
						
						//
						void set_bullet_speed(double s);
						void fire_bullet();
					
					//
					private:
						
						//
						long _lifetime_ticks;
						bool _wants_to_be_deleted;
						
						//
						double
							_pos_x,
							_pos_y,
							_rotation_radians
							;
						
						//
						std::vector<
							std::pair<double, double>
						> _polygon_points;
						Rect _rect;
						
						//
						std::vector<std::shared_ptr<Bullet>> _fired_bullets;
						double _bullet_speed;
						
						//
						void init();
						
						//
						void apply_vector_to_position(long elapsed_ticks);
				};
			}
		}
	}
}







#endif
