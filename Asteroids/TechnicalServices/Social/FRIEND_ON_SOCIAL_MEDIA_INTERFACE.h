#ifndef ASTEROIDS_TECHNICALSERVICES_SOCIAL_FRIEND_ON_SOCIAL_MEDIA_INTERFACE_H
#define ASTEROIDS_TECHNICALSERVICES_SOCIAL_FRIEND_ON_SOCIAL_MEDIA_INTERFACE_H


//
#include "Asteroids/ForwardDeclarations.h"


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
			class FRIEND_ON_SOCIAL_MEDIA_INTERFACE
			{
				//
				public:
					
					//
					virtual void set_social_network_name(std::string s) = 0;
					virtual std::string get_social_network_name() = 0;
					
					//
					virtual void set_friend_name(std::string s) = 0;
					virtual std::string get_friend_name() = 0;
					
					//
					virtual void set_friend_social_media_handle(std::string s) = 0;
					virtual std::string get_friend_social_media_handle() = 0;
			};
		}
	}
}



#endif

