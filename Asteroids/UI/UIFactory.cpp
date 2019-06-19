

//
#include "Asteroids/UI/UIFactory.h"
//
#include "Asteroids/UI/ServerTextUI/ServerTextUI.h"
#include "Asteroids/UI/ClientTextUI/ClientTextUI.h"


//
namespace Asteroids
{
	//
	namespace UI
	{
		//
		UIFactory::UIFactory( std::shared_ptr<Asteroids::Domain::Factory::FactoryInterface> factory )
		{
			//
			this->_factory = factory;
			
			//
			this->init();
		}
		
		//
		std::unique_ptr<Asteroids::UI::ServerTextUI::ServerTextUIInterface> UIFactory::createServerTextUI()
		{
			//
			std::unique_ptr<Asteroids::UI::ServerTextUI::ServerTextUIInterface> ui(
				new Asteroids::UI::ServerTextUI::ServerTextUI(this->_factory)
			);
			
			return ui;
		}
		
		//
		std::unique_ptr<Asteroids::UI::ClientTextUI::ClientTextUIInterface> UIFactory::createClientTextUI()
		{
			//
			std::unique_ptr<Asteroids::UI::ClientTextUI::ClientTextUIInterface> ui(
				new Asteroids::UI::ClientTextUI::ClientTextUI(this->_factory)
			);
			
			return ui;
		}
		
		//
		void UIFactory::init()
		{
			/// bleh	
		}
		
		
	}
}









