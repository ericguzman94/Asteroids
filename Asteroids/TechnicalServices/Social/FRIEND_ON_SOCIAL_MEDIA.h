#ifndef ASTEROIDS_TECHNICALSERVICES_SOCIAL_FRIEND_ON_SOCIAL_MEDIA_H
#define ASTEROIDS_TECHNICALSERVICES_SOCIAL_FRIEND_ON_SOCIAL_MEDIA_H


//
#include "Asteroids/ForwardDeclarations.h"


//
#include "Asteroids/TechnicalServices/Social/FRIEND_ON_SOCIAL_MEDIA_INTERFACE.h"


//
#include <string>
#include <vector>


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
			class FRIEND_ON_SOCIAL_MEDIA
				: public FRIEND_ON_SOCIAL_MEDIA_INTERFACE
			{
				//
				public:
					
					//
					FRIEND_ON_SOCIAL_MEDIA();
					
					//
					void set_social_network_name(std::string s);
					std::string get_social_network_name();
					
					//
					void set_friend_name(std::string s);
					std::string get_friend_name();
					
					//
					void set_friend_social_media_handle(std::string s);
					std::string get_friend_social_media_handle();
				
				//
				private:
					
					//
					std::string
						_social_network_name,
						_friend_name,
						_friend_social_media_handle
						;
			};
		}
	}
}



#endif

