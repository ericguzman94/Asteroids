

//
#include "Asteroids/Domain/Game/Actors/Vector.h"
//
#include "Asteroids/Domain/Game/Defines.h"


//
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
				Vector::Vector()
				{
					//
					this->reset();
				}
				
				//
				void Vector::reset()
				{
					//
					this->_x = 0;
					this->_y = 0;
				}
				
				//
				std::pair<double,double> Vector::adjust(double x, double y, double r)
				{
					//
					return this->set(this->_x + x, this->_y + y, this->_r + r);
				}
				
				//
				std::pair<double,double> Vector::set(double x, double y, double r)
				{
					//
					this->_x = x;
					this->_y = y;
					this->_r = r;
					
					return this->get_linear();
				}
				
				//
				std::pair<double,double> Vector::get_linear()
				{
					//
					return std::pair<double, double>(this->_x, this->_y);
				}
				
				//
				std::pair<double,double> Vector::get_rotated_linear()
				{
					//
					return Vector::rotate_velocity(
						this->_x,
						this->_y,
						this->_r
					);
				}
				
				//
				double Vector::get_x()
				{
					//
					return this->_x;
				}
				
				//
				double Vector::get_y()
				{
					//
					return this->_y;
				}
				
				//
				double Vector::get_rotational()
				{
					//
					return this->_r;
				}
				
				//
				std::pair<double,double> Vector::rotate_velocity(double x, double y, double rotate_radians)
				{
					//
					double radius = pow(
						pow(x, 2) + pow(y, 2),
						0.5
					);
					double angle = atan2(y, x);
					
					//
					angle += rotate_radians;
					
					//
					x = cos(angle) * radius;
					y = sin(angle) * radius;
					
					//
					return std::pair<double,double>(x, y);
				}
				
				//
				void Vector::update(long ticks)
				{
					//
					this->apply_limits();
					this->dampen(ticks);
				}
				
				//
				void Vector::apply_limits()
				{
					//
					if ( this->_y > ASTEROIDS_GAME_VELOCITY_MAX ) {
						this->_y = ASTEROIDS_GAME_VELOCITY_MAX;
					}
					else if ( this->_y < -ASTEROIDS_GAME_VELOCITY_MAX ) {
						this->_y = -ASTEROIDS_GAME_VELOCITY_MAX;
					}
					
					//
					if ( this->_x > ASTEROIDS_GAME_VELOCITY_MAX ) {
						this->_x = ASTEROIDS_GAME_VELOCITY_MAX;
					}
					else if ( this->_x < -ASTEROIDS_GAME_VELOCITY_MAX ) {
						this->_x = -ASTEROIDS_GAME_VELOCITY_MAX;
					}
					
					//
					if ( this->_r > ASTEROIDS_GAME_VELOCITY_ROTATIONAL_MAX ) {
						this->_r = ASTEROIDS_GAME_VELOCITY_ROTATIONAL_MAX;
					}
					else if ( this->_r < -ASTEROIDS_GAME_VELOCITY_ROTATIONAL_MAX ) {
						this->_r = -ASTEROIDS_GAME_VELOCITY_ROTATIONAL_MAX;
					}
				}
				
				//
				void Vector::dampen(long ticks)
				{
					//
					double factor = pow(ASTEROIDS_GAME_VELOCITY_DAMPENING_TICKS_FACTOR, ticks);
					
					//
					this->_y *= factor;
					this->_x *= factor;
					this->_r *= factor;
				}
			}
		}
	}
}


