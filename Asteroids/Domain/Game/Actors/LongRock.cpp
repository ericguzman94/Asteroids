

//
#include "Asteroids/Domain/Game/Actors/LongRock.h"
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
				LongRock::LongRock()
				{
					//
					this->initialize_polygon();
				}
				
				//
				void LongRock::initialize_polygon()
				{
					//
					std::vector<std::pair<double,double>> points;
					std::pair<double, double> point;
					
					//
					double size = ASTEROIDS_GAME_ACTOR_SIZE_FACTOR;
					double radius = size * 2;
					
					//	TopLeft Corner
					point.first = -(radius * 2);
					point.second = -(radius / 2);
					points.push_back(point);
					
					//	TopRight Corner
					point.first = radius * 2;
					point.second = -(radius / 2);
					points.push_back(point);
					
					//	BottomLeft Corner
					point.first = -(radius * 2);
					point.second = radius / 2;
					points.push_back(point);
					
					//	BottomRight Corner
					point.first = radius * 2;
					point.second = radius / 2;
					points.push_back(point);
					
					//
					this->set_polygon(points);
				}
			}
		}
	}
}







