#ifndef ASTEROIDS_DOMAIN_GAME_GAME_HISTORY_ENTRY_H
#define ASTEROIDS_DOMAIN_GAME_GAME_HISTORY_ENTRY_H


//
#include "Asteroids/ForwardDeclarations.h"
//
#include "Asteroids/Domain/Game/GAME_HISTORY_ENTRY_INTERFACE.h"


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
			///	Implements GAME_HISTORY_ENTRY_INTERFACE
			class GAME_HISTORY_ENTRY
				: public GAME_HISTORY_ENTRY_INTERFACE
			{
				//
				public:
					
					//
					GAME_HISTORY_ENTRY();
					
					//
					void reset();
					
					//
					void set_id(std::string id);
					std::string get_id();
					
					//
					void set_date(std::string d);
					std::string get_date();
					
					//
					void set_score(int s);
					int get_score();
				
				//
				private:
					
					//
					std::string _id;
					std::string _date;
					int _score;
			};
		}
	}
}



#endif
