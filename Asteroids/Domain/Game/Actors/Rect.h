#ifndef ASTEROIDS_DOMAIN_GAME_ACTORS_RECT_H
#define ASTEROIDS_DOMAIN_GAME_ACTORS_RECT_H


//
#include "Asteroids/ForwardDeclarations.h"


//
#include <string>
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
				///	Convenience class to help manage actor rectangle boundaries and collisions
				class Rect
				{
					//
					public:
					
						//
						Rect();
						
						//
						void reset();
						
						///	Create a rect from polygon points
						static Rect consume_polygon(const std::vector<std::pair<double,double>>& points);
						
						//
						void add_offset(double x, double y);
						
						//
						void update_dimensions();
						
						//
						bool collides_with_rect(const Rect& other);
						bool is_point_within(double x, double y) const;
						
						//
						std::string to_string() const;
						
						//
						double x1, y1, x2, y2;
						double width, height;
						
					//
					private:
						
						//
						
				};
			}
		}
	}
}





#endif
