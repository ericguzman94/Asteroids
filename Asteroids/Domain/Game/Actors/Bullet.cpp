
//
#include "Asteroids/Domain/Game/Actors/Bullet.h"
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
				Bullet::Bullet()
				{
					//
					this->init();
				}
				
				//
				void Bullet::init()
				{
					//
					this->reset();
				}
				
				//
				void Bullet::reset()
				{
					//
					Actor::reset();
					
					//
					this->initialize_polygon();
				}
				
				//
				void Bullet::update(long ticks)
				{
					//
					Actor::update(ticks);
					
					//
					this->maybe_die();
				}
				
				//
				void Bullet::maybe_die()
				{
					//
					if ( this->get_lifetime_ticks() > ASTEROIDS_GAME_BULLET_LIFETIME_TICKS ) {
						this->deleteme();
					}
				}
				
				//
				void Bullet::initialize_polygon()
				{
					//
					//
					std::vector<std::pair<double,double>> points;
					std::pair<double, double> point;
					
					//
					//double size = ASTEROIDS_GAME_ACTOR_SIZE_FACTOR;
					
					//	Just a dot
					point.first = 0;
					point.second = 0;
					points.push_back(point);
					
					//
					this->set_polygon(points);
				}
			}
		}
	}
}







