

//
#include "Asteroids/Domain/Game/Actors/Actor.h"
#include "Asteroids/Domain/Game/Actors/Bullet.h"
#include "Asteroids/Domain/Game/Actors/Vector.h"
#include "Asteroids/Domain/Game/Defines.h"


//	Need to be above #include <math.h> for windows to compile correctly
#define _USE_MATH_DEFINES


//
#include <memory>
#include <math.h>


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
				//
				Actor::Actor()
				{
					//
					this->init();
				}
				
				//
				void Actor::init()
				{
					//
					this->_vector = std::unique_ptr<Vector>(
						new Vector()
					);
					
					//
					this->reset();
				}
				
				//
				void Actor::reset()
				{
					//
					this->_lifetime_ticks = 0;
					this->_wants_to_be_deleted = false;
					
					//
					this->_pos_x = 0;
					this->_pos_y = 0;
					this->_rotation_radians = 0;
					this->_bullet_speed = ASTEROIDS_GAME_BULLET_DEFAULT_SPEED;
					
					//
					this->clear_input();
					
					//
					this->_polygon_points.clear();
				}
				
				//
				long Actor::get_lifetime_ticks()
				{
					//
					return this->_lifetime_ticks;
				}
				
				//
				bool Actor::wants_to_be_deleted()
				{
					//
					return this->_wants_to_be_deleted;
				}
				
				//
				void Actor::update(long elapsed_ticks)
				{
					//
					this->_lifetime_ticks += elapsed_ticks;
					
					//
					this->_vector->update(elapsed_ticks);
					this->apply_vector_to_position(elapsed_ticks);
				}
				
				//
				void Actor::clear_input()
				{
					//
					this->_input_up = false;
					this->_input_down = false;
					this->_input_left = false;
					this->_input_right = false;
					this->_input_fire = false;
				}
				
				//
				void Actor::set_input_up(bool b)
				{
					//
					this->_input_up = b;
				}
				
				//
				void Actor::set_input_down(bool b)
				{
					//
					this->_input_down = b;
				}
				
				//
				void Actor::set_input_left(bool b)
				{
					//
					this->_input_left = b;
				}
				
				//
				void Actor::set_input_right(bool b)
				{
					//
					this->_input_right = b;
				}
				
				//
				void Actor::set_input_fire(bool b)
				{
					//
					this->_input_fire = b;
				}
				
				//
				void Actor::set_polygon(std::vector<std::pair<double, double>> points)
				{
					//
					this->_polygon_points = points;
					
					//
					this->update_rect();
				}
				
				//
				const std::vector<std::pair<double, double>>& Actor::get_polygon()
				{
					//
					return this->_polygon_points;
				}
				
				//
				std::vector<std::pair<double,double>> Actor::get_rotated_polygon()
				{
					//
					return this->rotate_polygon(this->_rotation_radians);
				}
				
				//
				std::vector<std::pair<double, double>> Actor::rotate_polygon(double radians)
				{
					//
					std::vector<std::pair<double, double>>
						points,
						points_new
						;
					double pi = M_PI;
					
					//
					points = this->_polygon_points;
					if ( fabs(radians) < 0.1 ) {
						return points;
					}
					
					//
					for ( std::pair<double,double> point : points ) {
						
						//
						double x = point.first;
						double y = point.second;
						double angle;
						
						//	Radius
						double radius = pow(
							pow(x, 2) + pow(y, 2),
							0.5
						);
						
						//	Angle
						angle = atan2( y, x );
						
						//	Now apply the rotation
						double angle_new = angle + radians;
						angle_new = fmod(angle_new, 2 * pi);
						
						//	Recalculate the point
						x = cos(angle_new) * radius;
						y = sin(angle_new) * radius;
						
						//
						points_new.push_back(std::pair<double,double>(x, y));
					}
					
					return points_new;
				}
				
				//
				void Actor::set_position(double x, double y)
				{
					//
					this->_pos_x = x;
					this->_pos_y = y;
					
					//
					this->update_rect();
				}
				
				//
				std::pair<double,double> Actor::get_position()
				{
					//
					std::pair<double,double> pair;
					
					pair.first = this->_pos_x;
					pair.second = this->_pos_y;
					
					return pair;
				}
				
				//
				double Actor::get_x()
				{
					return this->_pos_x;
				}
				
				//
				double Actor::get_y()
				{
					return this->_pos_y;
				}
				
				//
				double Actor::set_rotation(double radians)
				{
					//
					this->_rotation_radians = radians;
					
					return this->_rotation_radians;
				}
				
				//
				double Actor::adjust_rotation(double radians)
				{
					//
					return this->set_rotation(this->_rotation_radians + radians);
				}
				
				//
				double Actor::get_rotation()
				{
					//
					return this->_rotation_radians;
				}
				
				//
				void Actor::set_velocity(double x, double y, double r)
				{
					//
					this->_vector->set(x, y, r);
				}
				
				//
				std::vector<std::shared_ptr<Bullet>> Actor::get_fired_bullets(bool clear)
				{
					//
					std::vector<std::shared_ptr<Bullet>> bullets = this->_fired_bullets;
					
					//
					if ( clear ) {
						this->_fired_bullets.clear();
					}
					
					//
					return bullets;
				}
				
				//
				Rect Actor::get_rect() const
				{
					//
					return this->_rect;
				}
				
				//
				bool Actor::check_collision(const Asteroids::Domain::Game::Actors::Actor& other_actor)
				{
					//
					Rect other_rect = other_actor.get_rect();
					
					//
					if ( this->_rect.collides_with_rect(other_rect) ) {
						return true;
					}
					
					return false;
				}
				
				//
				bool Actor::check_collision(std::shared_ptr<Asteroids::Domain::Game::Actors::Actor> other_actor)
				{
					//
					return this->check_collision( *other_actor );
				}
				
				//
				void Actor::apply_vector_to_position(long elapsed_ticks)
				{
					//
					std::pair<double,double> linear = this->_vector->get_rotated_linear();
					double x = linear.first;
					double y = linear.second;
					
					//
					this->_pos_x += x * elapsed_ticks;
					this->_pos_y += y * elapsed_ticks;
					this->_rotation_radians += this->_vector->get_rotational() * elapsed_ticks;
					
					//
					this->update_rect();
				}
				
				//
				void Actor::update_rect()
				{
					//
					this->_rect = Rect::consume_polygon(this->_polygon_points);
					this->_rect.add_offset(this->_pos_x, this->_pos_y);
				}
				
				//
				void Actor::deleteme()
				{
					//
					this->_wants_to_be_deleted = true;
				}
				
				//
				void Actor::set_bullet_speed(double s)
				{
					//
					this->_bullet_speed = s;
				}
				
				//
				void Actor::fire_bullet()
				{
					//
					std::shared_ptr<Bullet> bullet(
						new Bullet()
					);
					
					//	Give the bullet its initial velocity
					double bullet_vel_x = 0;
					double bullet_vel_y = -this->_bullet_speed;
					std::pair<double,double> bullet_velocity = Vector::rotate_velocity(bullet_vel_x, bullet_vel_y, this->get_rotation());
					
					//	Add my velocity also
					bullet_velocity.first += this->_vector->get_x();
					bullet_velocity.second += this->_vector->get_y();
					
					//
					bullet->set_position(this->get_x(), this->get_y());
					bullet->set_velocity(bullet_velocity.first, bullet_velocity.second, 0.0);
					
					//
					this->_fired_bullets.push_back(bullet);
				}
			}
		}
	}
}





