#ifndef ASTEROIDS_UI_UIFACTORYINTERFACE_H
#define ASTEROIDS_UI_UIFACTORYINTERFACE_H


//
#include "Asteroids/ForwardDeclarations.h"


//
#include <memory>


//
namespace Asteroids
{
	//
	namespace UI
	{
		///	Creates things inside the UI package
		class UIFactoryInterface
		{
			//
			public:
				
				//
				virtual std::unique_ptr<Asteroids::UI::ServerTextUI::ServerTextUIInterface> createServerTextUI() = 0;
				virtual std::unique_ptr<Asteroids::UI::ClientTextUI::ClientTextUIInterface> createClientTextUI() = 0;
		};
	}
}








#endif
