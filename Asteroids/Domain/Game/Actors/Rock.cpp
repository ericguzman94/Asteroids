

//
#include "Asteroids/Domain/Game/Actors/Rock.h"
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
				Rock::Rock()
				{
					//
					this->init();
				}
				
				//
				void Rock::init()
				{	
					//
					this->reset();
				}
				
				//
				void Rock::reset()
				{
					//
					Actor::reset();
					
					//
					this->initialize_polygon();
				}
				
				///	@todo Make the rocks more round
				void Rock::initialize_polygon()
				{
					//
					std::vector<std::pair<double,double>> points;
					std::pair<double, double> point;
					
					//
					double size = ASTEROIDS_GAME_ACTOR_SIZE_FACTOR;
					double radius = size * 2;
					
					//	Base
					//point.first = 0;
					//point.second = 0;
					//points.push_back(point);
					
					//	TopLeft Corner
					point.first = -radius;
					point.second = -radius;
					points.push_back(point);
					
					//	TopRight Corner
					point.first = radius;
					point.second = -radius;
					points.push_back(point);
					
					//	BottomLeft Corner
					point.first = -radius;
					point.second = radius;
					points.push_back(point);
					
					//	BottomRight Corner
					point.first = radius;
					point.second = radius;
					points.push_back(point);
					
					//
					this->set_polygon(points);
				}
			}
		}
	}
}







