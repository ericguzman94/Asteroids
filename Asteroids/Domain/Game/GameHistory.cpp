

//
#include "Asteroids/Domain/Game/GameHistory.h"
//
#include "Asteroids/Domain/Game/GAME_HISTORY_ENTRY.h"


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
			GameHistory::GameHistory()
			{
				//
			}
			
			///	@todo Still returning dummy data
			std::vector<std::shared_ptr<GAME_HISTORY_ENTRY_INTERFACE>> GameHistory::get_history()
			{
				//
				std::vector<std::shared_ptr<GAME_HISTORY_ENTRY_INTERFACE>> entries;
				std::shared_ptr<GAME_HISTORY_ENTRY_INTERFACE> entry;
				
				//	Last Tuesday's Entry (Fake)
				entry = std::shared_ptr<GAME_HISTORY_ENTRY_INTERFACE>(
					new GAME_HISTORY_ENTRY()
				);
				entry->set_id("AA");
				entry->set_date("Last Tuesday");
				entry->set_score(100);
				entries.push_back(entry);
				
				//	Yesterday's Entry (Fake)
				entry = std::shared_ptr<GAME_HISTORY_ENTRY_INTERFACE>(
					new GAME_HISTORY_ENTRY()
				);
				entry->set_id("AB");
				entry->set_date("Yesterday");
				entry->set_score(500);
				entries.push_back(entry);
				
				//	This Morning's Entry (Fake)
				entry = std::shared_ptr<GAME_HISTORY_ENTRY_INTERFACE>(
					new GAME_HISTORY_ENTRY()
				);
				entry->set_id("AC");
				entry->set_date("This Morning");
				entry->set_score(1000);
				entries.push_back(entry);
				
				return entries;
			}
		}
	}
}










