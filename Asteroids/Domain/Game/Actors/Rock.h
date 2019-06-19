#ifndef ASTEROIDS_DOMAIN_GAME_ACTORS_ROCK_H
#define ASTEROIDS_DOMAIN_GAME_ACTORS_ROCK_H


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
				///	A rock is an actor that floats within the game; Can be shot by player; Can smash player
				class Rock
					: public Actor
				{
					//
					public:
						
						//
						Rock();
						
						//
						void reset();
						
					//
					protected:
						
						//
						void init();
						void initialize_polygon();
				};
			}
		}
	}
}



//
#endif
