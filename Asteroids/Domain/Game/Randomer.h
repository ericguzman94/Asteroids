#ifndef ASTEROIDS_DOMAIN_GAME_RANDOMER_H
#define ASTEROIDS_DOMAIN_GAME_RANDOMER_H


//
#include "Asteroids/ForwardDeclarations.h"


//
#include <random>


//
namespace Asteroids
{
	//
	namespace Domain
	{
		//
		namespace Game
		{
			///	Helper class to generate random numbers for the Game
			class Randomer
			{
				//
				public:
					
					//
					Randomer();
					
					//
					void reset();
					
					//
					double get_double();
					double get_double(double min, double max);
					
					//
					bool roll_bool(double chance=0.5);
					
				//
				private:
					
					//
					std::default_random_engine _random_engine;
					
					//
					void init();
			};
		}
	}
}





#endif
