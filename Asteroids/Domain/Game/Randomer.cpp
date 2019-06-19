

//
#include "Asteroids/Domain/Game/Randomer.h"


//
#include <chrono>


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
			Randomer::Randomer()
			{
				//
				this->init();
			}
			
			//
			void Randomer::init()
			{
				//
				std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
				std::chrono::high_resolution_clock::duration d
					= std::chrono::high_resolution_clock::now() - start;
				unsigned seed = d.count();
				this->_random_engine.seed(seed);
				
				//
				this->reset();
			}
			
			//
			void Randomer::reset()
			{
				//
			}
			
			//
			double Randomer::get_double()
			{
				//
				return this->get_double(0.0, 1.0);
			}
			
			//
			double Randomer::get_double(double min, double max)
			{
				//
				std::uniform_real_distribution<double> my_uniform_distribution(min, max);
				
				double d = my_uniform_distribution(this->_random_engine);
				
				return d;
			}
			
			//
			bool Randomer::roll_bool(double chance)
			{
				//
				double d = this->get_double(0, 1.0);
				bool b = ( d <= chance );
				
				return b;
			}
		}
	}
}


