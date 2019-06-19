#ifndef ASTEROIDS_DOMAIN_GAME_ACTORS_ACTORINTERFACE_H
#define ASTEROIDS_DOMAIN_GAME_ACTORS_ACTORINTERFACE_H


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
				///	Main superclass for game board actors
				/**
					Allow other packages to access important properties of actors
				*/
				class ActorInterface
				{
					//
					public:
						
						//
						virtual void clear_input() = 0;
						virtual void set_input_up(bool b) = 0;
						virtual void set_input_down(bool b) = 0;
						virtual void set_input_left(bool b) = 0;
						virtual void set_input_right(bool b) = 0;
						virtual void set_input_fire(bool b) = 0;
						
						//
						virtual void set_position(double x, double y) = 0;
						
						//
						virtual double get_x() = 0;
						virtual double get_y() = 0;
						
						//
						virtual const std::vector<std::pair<double,double>>& get_polygon() = 0;
						virtual std::vector<std::pair<double,double>> get_rotated_polygon() = 0;
						
					//
					private:
						
						//
						
				};
			}
		}
	}
}


#endif
