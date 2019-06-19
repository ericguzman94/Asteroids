#ifndef ASTEROIDS_UI_UIFACTORY_H
#define ASTEROIDS_UI_UIFACTORY_H


//
#include "Asteroids/ForwardDeclarations.h"
#include "Asteroids/UI/UIFactoryInterface.h"


//
namespace Asteroids
{
	//
	namespace UI
	{
		///	Implementation of UIFactoryInterface
		class UIFactory
			: public UIFactoryInterface
		{
			//
			public:
				
				//
				UIFactory( std::shared_ptr<Asteroids::Domain::Factory::FactoryInterface> factory );
				
				//
				std::unique_ptr<Asteroids::UI::ServerTextUI::ServerTextUIInterface> createServerTextUI();
				std::unique_ptr<Asteroids::UI::ClientTextUI::ClientTextUIInterface> createClientTextUI();
				
			//
			private:
				
				//
				std::shared_ptr<Asteroids::Domain::Factory::FactoryInterface> _factory;
				
				//
				void init();
		};
		
		
	}
}







#endif
