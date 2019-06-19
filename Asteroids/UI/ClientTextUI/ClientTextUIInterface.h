#ifndef ASTEROIDS_UI_CLIENTTEXTUI_CLIENTTEXTUIINTERFACE_H
#define ASTEROIDS_UI_CLIENTTEXTUI_CLIENTTEXTUIINTERFACE_H


//
#include "Asteroids/ForwardDeclarations.h"


//
namespace Asteroids
{
	//
	namespace UI
	{
		//
		namespace ClientTextUI
		{
			///	Interface to the main client text user interface; Just runs, basically
			class ClientTextUIInterface
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
