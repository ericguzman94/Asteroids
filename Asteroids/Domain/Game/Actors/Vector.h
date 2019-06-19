#ifndef ASTEROIDS_DOMAIN_GAME_ACTORS_VECTOR_H
#define ASTEROIDS_DOMAIN_GAME_ACTORS_VECTOR_H


//
#include "Asteroids/ForwardDeclarations.h"


//
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
				///	Simple class to store 2D vector and rotation, to lend physics to game actors
				class Vector
				{
					//
					public:
					
						//
						Vector();
						
						//
						void reset();
						
						//
						std::pair<double,double> adjust(double x, double y, double r=0.0);
						std::pair<double,double> set(double x, double y, double r);
						std::pair<double,double> get_linear();
						std::pair<double,double> get_rotated_linear();
						double get_x();
						double get_y();
						double get_rotational();
						
						//
						static std::pair<double,double> rotate_velocity(double x, double y, double rotate_radians);
						
						//
						void update(long ticks);
						
					//
					private:
						
						//
						double _x, _y, _r;
						
						//
						void apply_limits();
						void dampen(long ticks);
				};
			}
		}
	}
}


#endif
