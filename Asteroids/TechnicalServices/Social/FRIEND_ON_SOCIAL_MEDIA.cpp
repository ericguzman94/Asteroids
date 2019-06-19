

//
#include "Asteroids/TechnicalServices/Social/FRIEND_ON_SOCIAL_MEDIA.h"


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
			FRIEND_ON_SOCIAL_MEDIA::FRIEND_ON_SOCIAL_MEDIA()
			{
				//
			}
			
			//
			void FRIEND_ON_SOCIAL_MEDIA::set_social_network_name(std::string s)
			{
				//
				this->_social_network_name = s;
			}
			
			//
			std::string FRIEND_ON_SOCIAL_MEDIA::get_social_network_name()
			{
				//
				return this->_social_network_name;
			}
			
			//
			void FRIEND_ON_SOCIAL_MEDIA::set_friend_name(std::string s)
			{
				//
				this->_friend_name = s;
			}
			
			//
			std::string FRIEND_ON_SOCIAL_MEDIA::get_friend_name()
			{
				//
				return this->_friend_name;
			}
			
			//
			void FRIEND_ON_SOCIAL_MEDIA::set_friend_social_media_handle(std::string s)
			{
				//
				this->_friend_social_media_handle = s;
			}
			
			//
			std::string FRIEND_ON_SOCIAL_MEDIA::get_friend_social_media_handle()
			{
				//
				return this->_friend_social_media_handle;
			}
		}
	}
}









