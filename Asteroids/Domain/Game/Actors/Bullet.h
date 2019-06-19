#ifndef ASTEROIDS_DOMAIN_GAME_ACTORS_BULLET_H
#define ASTEROIDS_DOMAIN_GAME_ACTORS_BULLET_H


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
				///	A bullet is... a bullet... Can be shot by the player (eventually Alien too); Player's bullet kills rocks/alien; Alien bullet kills rocks/player
				class Bullet
					: public Actor
				{
					//
					public:
						
						//
						Bullet();
						
						//
						void reset();
						
						//
						void update(long ticks);
						
					//
					private:
						
						//
						void init();
						void initialize_polygon();
						
						//
						void maybe_die();
				};
			}
		}
	}
}


#endif
