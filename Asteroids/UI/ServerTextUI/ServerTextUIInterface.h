#ifndef ASTEROIDS_UI_SERVERTEXTUI_SERVERTEXTUIINTERFACE_H
#define ASTEROIDS_UI_SERVERTEXTUI_SERVERTEXTUIINTERFACE_H


//
#include "Asteroids/ForwardDeclarations.h"


//
namespace Asteroids
{
	//
	namespace UI
	{
		//
		namespace ServerTextUI
		{
			///	Main interface to the server's text user interface; Just runs
			class ServerTextUIInterface
			{
				//
				public:
					
					//
					virtual void run() = 0;
			};
		}
	}
}






#endif
