

//
#include "Asteroids/Domain/Game/GAME_HISTORY_ENTRY.h"


//
using std::string;


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
			GAME_HISTORY_ENTRY::GAME_HISTORY_ENTRY()
			{
				//
				this->reset();
			}
			
			//
			void GAME_HISTORY_ENTRY::reset()
			{
				//
				this->set_date("");
				this->set_score(0);
			}
			
			//
			void GAME_HISTORY_ENTRY::set_id(std::string id)
			{
				//
				this->_id = id;
			}
			
			//
			std::string GAME_HISTORY_ENTRY::get_id()
			{
				//
				return this->_id;
			}
			
			//
			void GAME_HISTORY_ENTRY::set_date(string d)
			{
				//
				this->_date = d;
			}
			
			//
			string GAME_HISTORY_ENTRY::get_date()
			{
				//
				return this->_date;
			}
			
			//
			void GAME_HISTORY_ENTRY::set_score(int s)
			{
				//
				this->_score = s;
			}
			
			//
			int GAME_HISTORY_ENTRY::get_score()
			{
				//
				return this->_score;
			}
		}
	}
}




