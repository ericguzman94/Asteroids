#ifndef ASTEROIDS_DOMAIN_NET_MESSAGES_AUTH_STATE_H
#define ASTEROIDS_DOMAIN_NET_MESSAGES_AUTH_STATE_H


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
		namespace Net
		{
			//
			namespace Messages
			{
				//
				using std::string;
				
				///	Information about the current authentication state
				/**
					Currently only tells you whether or not you're authenticated
				*/
				class AUTH_STATE
				{
					//
					public:
						
						//
						AUTH_STATE();
						
						//
						void reset();
						
						//
						void setAuthSuccessful(bool b);
						bool isAuthSuccessful();
					
					//
					private:
						
						//
						bool _auth_successful;
				};
			}
		}
	}
}






#endif
