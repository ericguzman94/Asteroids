#ifndef ASTEROIDS_DOMAIN_GAME_GAME_HISTORY_ENTRY_INTERFACE_H
#define ASTEROIDS_DOMAIN_GAME_GAME_HISTORY_ENTRY_INTERFACE_H


//
#include "Asteroids/ForwardDeclarations.h"


//
#include <string>


//
namespace Asteroids
{
	//
	namespace Domain
	{
		//
		namespace Game
		{
			///	Holds one entry of gameplay historical data
			class GAME_HISTORY_ENTRY_INTERFACE
			{
				//
				public:
					
					//
					virtual void set_id(std::string id) = 0;
					virtual std::string get_id() = 0;
					
					//
					virtual void set_date(std::string d) = 0;
					virtual std::string get_date() = 0;
					
					//
					virtual void set_score(int s) = 0;
					virtual int get_score() = 0;
			};
		}
	}
}



#endif
