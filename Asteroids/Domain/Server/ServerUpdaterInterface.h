#ifndef ASTEROIDS_DOMAIN_SERVER_SERVERUPDATERINTERFACE_H
#define ASTEROIDS_DOMAIN_SERVER_SERVERUPDATERINTERFACE_H


//
#include "Asteroids/ForwardDeclarations.h"


//
namespace Asteroids
{
	//
	namespace Domain
	{
		//
		namespace Server
		{
			///	Interface for updating the server
			class ServerUpdaterInterface
			{
				//
				public:
					
					//
					virtual void update() = 0;
			};
		}
	}
}






#endif
