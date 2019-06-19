#ifndef ASTEROIDS_UI_SERVERTEXTUI_SERVERTEXTUI_H
#define ASTEROIDS_UI_SERVERTEXTUI_SERVERTEXTUI_H


//
#include "Asteroids/ForwardDeclarations.h"

//
#include "Asteroids/UI/ServerTextUI/ServerTextUIInterface.h"
#include "Asteroids/UI/ServerTextUI/Enums/Enums.h"


//
#include <memory>


//
namespace Asteroids
{
	//
	namespace UI
	{
		//
		namespace ServerTextUI
		{
			///	Implementation of ServerTextUIInterface
			class ServerTextUI
				: public ServerTextUIInterface
			{
				//
				public:
					
					//
					ServerTextUI( std::shared_ptr<Asteroids::Domain::Factory::FactoryInterface> factory );
					
					//
					void run();
				
				//
				private:
					
					//
					std::shared_ptr<Asteroids::Domain::Factory::FactoryInterface> _factory;
					std::shared_ptr<Asteroids::Domain::Server::ServerFactoryInterface> _factory_server;
					std::shared_ptr<Asteroids::TechnicalServices::TechnicalServicesFactoryInterface> _factory_technical_services;
					//
					std::shared_ptr<Asteroids::Domain::Server::ServerDaemonInterface> _daemon;
					
					//
					void init();
					
					//
					void main_menu_loop();
					Enums::MainMenuChoice main_menu();
					
					//
					void do_process_credit_card_payment();
					void do_apply_updates();
					void do_review_flagged_users();
					bool do_review_flagged_user();
			};
		}
	}
}







#endif
