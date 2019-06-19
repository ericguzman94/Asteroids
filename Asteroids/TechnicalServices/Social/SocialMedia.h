#ifndef ASTEROIDS_DOMAIN_GAME_SOCIAL_MEDIA_H
#define ASTEROIDS_DOMAIN_GAME_SOCIAL_MEDIA_H


//
#include "Asteroids/ForwardDeclarations.h"
#include "Asteroids/TechnicalServices/Social/SocialMediaInterface.h"


//
#include <string>
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
			class SocialMedia
				: public SocialMediaInterface
			{
				//
				public:
					
					//
					SocialMedia();
					
					//
					bool share_game_history_entry( std::string date, int score );
					
					//
					std::vector<std::shared_ptr<FRIEND_ON_SOCIAL_MEDIA_INTERFACE>> get_game_friends_on_social_media();
			};
		}
	}
}


#endif
