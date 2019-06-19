

//
#include "Asteroids/Domain/Game/Actors/GunShip.h"
//
#include "Asteroids/Domain/Game/Defines.h"


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
				GunShip::GunShip()
				{
					//
					this->init();
				}
				
				//
				void GunShip::reset()
				{
					//
					Actor::reset();
					
					//
					this->set_bullet_speed(ASTEROIDS_GAME_GUNSHIP_BULLET_SPEED);
					
					//
					this->initialize_polygon();
				}
				
				//
				void GunShip::update(long ticks)
				{
					//
					Actor::update(ticks);
					
					//
					this->use_input(ticks);
				}
				
				//
				void GunShip::use_input(long elapsed_ticks)
				{
					//
					double strength = ASTEROIDS_GAME_VELOCITY_INPUT_TICKS_FACTOR * elapsed_ticks;
					double adjust_x = 0;
					double adjust_y = 0;
					std::pair<double,double> adjustment_rotated;
					
					//	Accelerate forward or back
					if ( this->_input_up ) {
						adjust_y -= strength;
					}
					else if ( this->_input_down ) {
						adjust_y += strength;
					}
					adjustment_rotated = Vector::rotate_velocity(adjust_x, adjust_y, this->get_rotation());
					adjust_x = adjustment_rotated.first;
					adjust_y = adjustment_rotated.second;
					this->_vector->adjust(adjust_x, adjust_y, 0);
					
					//
					if ( this->_input_left ) {
						this->_vector->adjust(0, 0, -strength);
					}
					else if ( this->_input_right ) {
						this->_vector->adjust(0, 0, strength);
					}
					
					//
					if ( this->_input_fire ) {
						
						//
						this->set_input_fire(false);
						
						//
						this->fire_bullet();
					}
				}
				
				//
				void GunShip::init()
				{
					//
					this->reset();
				}
				
				//
				void GunShip::initialize_polygon()
				{
					//
					std::vector<std::pair<double,double>> points;
					std::pair<double, double> point;
					
					//
					double size = ASTEROIDS_GAME_ACTOR_SIZE_FACTOR;
					
					//	Base
					point.first = 0;
					point.second = 0;
					points.push_back(point);
					
					//	Front tip
					point.first = 0;
					point.second = -size * 2;
					points.push_back(point);
					
					//	Back left wing
					point.first = -size;
					point.second = size;
					points.push_back(point);
					
					//	Back right wing
					point.first = size;
					point.second = size;
					points.push_back(point);
					
					//
					this->set_polygon(points);
				}
			}
		}
	}
}





