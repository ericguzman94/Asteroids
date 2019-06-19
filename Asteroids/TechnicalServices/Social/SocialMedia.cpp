

//
#include "Asteroids/TechnicalServices/Social/SocialMedia.h"
//
#include "Asteroids/TechnicalServices/Social/FRIEND_ON_SOCIAL_MEDIA.h"


//
#include <chrono>
#include <thread>
#include <iostream>


//
namespace Asteroids
{
	//
	namespace TechnicalServices
	{
		//
		namespace Social
		{
			//
			SocialMedia::SocialMedia()
			{
				//
			}
			
			//
			bool SocialMedia::share_game_history_entry( std::string date, int score )
			{
				///	@todo Emitting to stdout instead of actually doing anything ... for now
				std::cout << "Sharing entry from " << date << " (" << score << " points)" << std::endl;
				std::cout << "Bleep ... " << std::flush;
				std::this_thread::sleep_for(std::chrono::milliseconds(500));
				std::cout << "bloop ... " << std::flush;
				std::this_thread::sleep_for(std::chrono::milliseconds(500));
				std::cout << "blop ... " << std::flush;
				std::this_thread::sleep_for(std::chrono::milliseconds(500));
				std::cout << "bleep" << std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(500));
				
				return true;
			}
			
			//
			std::vector<std::shared_ptr<FRIEND_ON_SOCIAL_MEDIA_INTERFACE>> SocialMedia::get_game_friends_on_social_media()
			{
				//
				std::vector<std::shared_ptr<FRIEND_ON_SOCIAL_MEDIA_INTERFACE>> friends;
				
				//
				std::shared_ptr<FRIEND_ON_SOCIAL_MEDIA_INTERFACE> f;
				
				//	Friend 1
				f = std::shared_ptr<FRIEND_ON_SOCIAL_MEDIA_INTERFACE>(
					new FRIEND_ON_SOCIAL_MEDIA()
				);
				f->set_friend_name("Gary Shandling");
				f->set_social_network_name("youtwitface");
				f->set_friend_social_media_handle("@lulzdude");
				friends.push_back(f);
				
				//	Friend 2
				f = std::shared_ptr<FRIEND_ON_SOCIAL_MEDIA_INTERFACE>(
					new FRIEND_ON_SOCIAL_MEDIA()
				);
				f->set_friend_name("Walter Mathow");
				f->set_social_network_name("youtwitface");
				f->set_friend_social_media_handle("@oldndontcare");
				friends.push_back(f);
				
				return friends;
			}
		}
	}
}






