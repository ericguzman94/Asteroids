#ifndef ASTEROIDS_DOMAIN_GAME_SOCIAL_MEDIA_INTERFACE_H
#define ASTEROIDS_DOMAIN_GAME_SOCIAL_MEDIA_INTERFACE_H


//
#include "Asteroids/ForwardDeclarations.h"


//
#include <string>
#include <vector>
#include <memory>


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
			class SocialMediaInterface
			{
				//
				public:
					
					//
					virtual bool share_game_history_entry( std::string date, int score ) = 0;
					
					//
					virtual std::vector<std::shared_ptr<FRIEND_ON_SOCIAL_MEDIA_INTERFACE>> get_game_friends_on_social_media() = 0;
			};
		}
	}
}



#endif
