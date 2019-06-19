#ifndef ASTEROIDS_DOMAIN_GAME_ACTORS_GUNSHIP_H
#define ASTEROIDS_DOMAIN_GAME_ACTORS_GUNSHIP_H


//
#include "Asteroids/ForwardDeclarations.h"
#include "Asteroids/Domain/Game/Actors/Actor.h"


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
				///	GunShip is the player's main actor; Subclass of Actor; Flies around and shoots at stuff
				class GunShip
					: public Actor
				{
					//
					public:
						
						//
						GunShip();
						
						//
						void reset();
						
						//
						void update(long ticks);
						
					//
					private:
						
						//
						void init();
						
						//
						void initialize_polygon();
						
						//
						void use_input(long elapsed_ticks);
						void fire_gun();
				};
			}
		}
	}
}








#endif
