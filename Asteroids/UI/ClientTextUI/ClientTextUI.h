#ifndef ASTEROIDS_UI_CLIENTTEXTUI_CLIENTTEXTUI_H
#define ASTEROIDS_UI_CLIENTTEXTUI_CLIENTTEXTUI_H


//
#include "Asteroids/ForwardDeclarations.h"


//
#include "Asteroids/UI/ClientTextUI/ClientTextUIInterface.h"
//
#include "Asteroids/UI/ClientTextUI/Defines.h"
#include "Asteroids/UI/ClientTextUI/Enums/Enums.h"
#include "Asteroids/UI/ClientTextUI/Input.h"
#include "Asteroids/UI/ClientTextUI/DisplayGrid.h"
//
#include "Asteroids/Domain/Factory/FactoryInterface.h"
//
#include "Asteroids/Domain/Game/GameFactoryInterface.h"
#include "Asteroids/Domain/Game/GameInterface.h"
//
#include "Asteroids/Domain/Net/NetFactoryInterface.h"
//
#include "Asteroids/Domain/Store/Enums/Enums.h"
#include "Asteroids/Domain/Store/StoreFactoryInterface.h"


//
#include <memory>
#include <string>


//
#ifdef __linux__
	//	Nada
#else
	//	Nada
#endif


//
namespace Asteroids
{
	//
	namespace UI
	{
		//
		namespace ClientTextUI
		{
			//
			using std::string;
			
			///	Implementation of ClientTextUIInterface
			class ClientTextUI
				: public ClientTextUIInterface
			{
				//
				public:
					
					//	CTOR
					ClientTextUI( std::shared_ptr<Asteroids::Domain::Factory::FactoryInterface> factory );
					
					//
					void reset();
					
					//
					void run();
					
				//
				private:
					
					//
					std::shared_ptr<Asteroids::Domain::Factory::FactoryInterface> _factory;
					std::unique_ptr<Asteroids::Domain::Game::GameFactoryInterface> _game_factory;
					std::unique_ptr<Asteroids::Domain::Net::NetFactoryInterface> _net_factory;
					std::unique_ptr<Asteroids::Domain::Store::StoreFactoryInterface> _store_factory;
					std::unique_ptr<Asteroids::TechnicalServices::TechnicalServicesFactoryInterface> _technical_services_factory;
					
					//
					std::shared_ptr<Asteroids::Domain::Net::Messages::AUTH_STATE> _authentication_state;
					
					//
					std::shared_ptr<Asteroids::Domain::Game::GameInterface> _game;
					std::unique_ptr<Asteroids::UI::ClientTextUI::Input> _input;
					std::unique_ptr<Asteroids::UI::ClientTextUI::DisplayGrid> _display_grid;
					
					//
					std::shared_ptr<Asteroids::Domain::Game::GameHistoryInterface> _game_history;
					
					//
					std::shared_ptr<Asteroids::Domain::Store::StoreInterface> _store;
					std::shared_ptr<Asteroids::Domain::Store::PaymentHelperInterface> _payment_helper;
					
					//
					void init();
					void initialize_display_grid();
					
					//
					void print(string s="", bool do_newline=true);
					
					//
					bool demand_authentication();
					void do_authentication();
					
					//
					void main_menu_loop();
					Enums::MainMenuChoice main_menu();
					
					//
					void play_game();
					void handle_game_input();
					void draw_game();
					void draw_actor(std::shared_ptr<Asteroids::Domain::Game::Actors::ActorInterface> actor);
					
					//
					void review_game_history();
					void share_game_history_entry_to_social_media( std::shared_ptr<Asteroids::Domain::Game::GAME_HISTORY_ENTRY_INTERFACE> entry);
					void find_friends_on_social_media();
					
					//
					void store();
					bool store_loop();
					void store_offer_available_items();
					std::shared_ptr<Asteroids::Domain::Store::POWERUP_ADDED_INFO_INTERFACE> purchasing_store_item( std::shared_ptr<Asteroids::Domain::Store::STORE_ITEM_INTERFACE> item );
					bool pay_for_store_item(
						std::shared_ptr<Asteroids::Domain::Store::STORE_ITEM_INTERFACE> item,
						Asteroids::Domain::Store::Enums::PaymentMethod payment_method
					);
					std::shared_ptr<Asteroids::Domain::Store::PAYMENT_RESULT_DETAILS_INTERFACE> pay_for_store_item_with_credit_card(std::shared_ptr<Asteroids::Domain::Store::STORE_ITEM_INTERFACE> item);
			};
		}
	}
}







#endif
