#ifndef ASTEROIDS_DOMAIN_SERVER_SERVERUPDATER_H
#define ASTEROIDS_DOMAIN_SERVER_SERVERUPDATER_H


//
#include "Asteroids/ForwardDeclarations.h"
//
#include "Asteroids/Domain/Server/ServerUpdaterInterface.h"


//
namespace Asteroids
{
	//
	namespace Domain
	{
		//
		namespace Server
		{
			///	Implements ServerUpdaterInterface
			class ServerUpdater
				: public ServerUpdaterInterface
			{
				//
				public:
					
					//
					ServerUpdater();
					
					//
					void update();
			};
		}
	}
}






#endif
