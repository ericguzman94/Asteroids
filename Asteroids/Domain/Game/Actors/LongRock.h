#ifndef ASTEROIDS_DOMAIN_GAME_ACTORS_LONGROCK_H
#define ASTEROIDS_DOMAIN_GAME_ACTORS_LONGROCK_H


//
#include "Asteroids/ForwardDeclarations.h"
#include "Asteroids/Domain/Game/Actors/Rock.h"


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
				///	A long rock is an actor that floats within the game; Can be shot by player; Can smash player
				class LongRock
					: public Rock
				{
					//
					public:
						
						//
						LongRock();
						
					//
					private:
						
						//
						void initialize_polygon();
				};
			}
		}
	}
}



//
#endif
