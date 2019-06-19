

//
#include "Asteroids/UI/ClientTextUI/ClientTextUI.h"
//
#include "Asteroids/UI/ClientTextUI/Input.h"
#include "Asteroids/UI/ClientTextUI/DisplayGrid.h"
//
#include "Asteroids/Domain/Factory/FactoryInterface.h"
#include "Asteroids/Domain/Game/GameFactoryInterface.h"
#include "Asteroids/Domain/Game/GameInterface.h"
#include "Asteroids/Domain/Game/Actors/ActorInterface.h"
#include "Asteroids/Domain/Game/GameHistory.h"
#include "Asteroids/Domain/Game/GAME_HISTORY_ENTRY_INTERFACE.h"
//
#include "Asteroids/Domain/Net/NetFactoryInterface.h"
#include "Asteroids/Domain/Net/ClientServerCommunicatorInterface.h"
#include "Asteroids/Domain/Net/Authentication/AuthenticationInterface.h"
#include "Asteroids/Domain/Net/Messages/AUTH_ATTEMPT.h"
#include "Asteroids/Domain/Net/Messages/AUTH_STATE.h"
//
#include "Asteroids/Domain/Store/StoreFactoryInterface.h"
#include "Asteroids/Domain/Store/StoreInterface.h"
#include "Asteroids/Domain/Store/STORE_ITEM_INTERFACE.h"
#include "Asteroids/Domain/Store/PaymentHelperInterface.h"
#include "Asteroids/Domain/Store/PAYMENT_RESULT_DETAILS_INTERFACE.h"
#include "Asteroids/Domain/Store/POWERUP_ADDED_INFO_INTERFACE.h"
//
#include "Asteroids/TechnicalServices/TechnicalServicesFactoryInterface.h"
#include "Asteroids/TechnicalServices/Social/SocialMediaInterface.h"
#include "Asteroids/TechnicalServices/Social/FRIEND_ON_SOCIAL_MEDIA_INTERFACE.h"


//
#include <algorithm>
#include <iostream>


//
#ifdef __linux__
	//
#else
	
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
			ClientTextUI::ClientTextUI(std::shared_ptr<Asteroids::Domain::Factory::FactoryInterface> factory)
			{
				//
				this->_factory = factory;
				
				//
				this->init();
				this->reset();
			}
			
			//
			void ClientTextUI::init()
			{
				//
				this->_game_factory = this->_factory->createGameFactory();
				this->_net_factory = this->_factory->createNetworkFactory();
				this->_store_factory = this->_factory->createStoreFactory();
				this->_technical_services_factory = this->_factory->createTechnicalServicesFactory();
				
				///	@todo Make a TextUI Factory instead of doing this here
				this->_input = std::unique_ptr<Asteroids::UI::ClientTextUI::Input>(
					new Asteroids::UI::ClientTextUI::Input()
				);
			}
			
			//
			void ClientTextUI::initialize_display_grid()
			{
				//
				if ( !this->_game ) {
					return;
				}
				
				///	@todo Make a TextUI Factory instead of doing this here
				this->_display_grid = std::unique_ptr<Asteroids::UI::ClientTextUI::DisplayGrid>(
					new Asteroids::UI::ClientTextUI::DisplayGrid(
						this->_game->get_board_width(),
						this->_game->get_board_height(),
						ASTEROIDS_UI_TEXTUI_DISPLAYGRID_WIDTH,
						ASTEROIDS_UI_TEXTUI_DISPLAYGRID_HEIGHT
					)
				);
			}
			
			//
			void ClientTextUI::print(string s, bool do_newline)
			{
				//
				#ifdef __linux__
					
					printf(s.c_str(), "");
					if (do_newline) {
						printf("\r\n");
					}
				#else
					std::cout << s;
					if (do_newline) {
						std::cout << std::endl;
					}
				#endif
			}
			
			//
			void ClientTextUI::reset()
			{
				//
				this->_authentication_state = nullptr;
			}
			
			///	Begin the user interface
			void ClientTextUI::run()
			{
				//	Demand authentication
				if ( !this->demand_authentication() ) {
					this->print("Exiting program due to authentication failure");
					return;
				}
				
				//	Enter the main menu loop
				this->main_menu_loop();
				
				//
				this->print("User interface is terminating ...");
			}
			
			//
			bool ClientTextUI::demand_authentication()
			{
				//
				this->do_authentication();
				
				//
				if ( this->_authentication_state->isAuthSuccessful() ) {
					
					//
					this->print("Authentication credentials were valid; Success!");
					
					return true;
				}
				
				//
				this->print("Authentication credentials failed!");
				
				return false;
			}
			
			//
			void ClientTextUI::do_authentication()
			{
				//
				std::unique_ptr<Asteroids::Domain::Net::Authentication::AuthenticationInterface> authenticator
					= this->_net_factory->createNetworkAuthenticator();
				std::shared_ptr<Asteroids::Domain::Net::Messages::AUTH_STATE> auth_state;
				string username, password;
				
				//	Grab user/pass from user
				this->print("*** AUTHENTICATION REQUIRED ***");
				this->print("Enter your username: ", false);
				std::cin >> username;
				//
				this->print("Enter your password: ", false);
				std::cin >> password;
				
				//
				this->_authentication_state = authenticator->attemptLogin(username, password);
			}
			
			//
			void ClientTextUI::main_menu_loop()
			{
				//
				bool quit = false;
				Enums::MainMenuChoice choice;
				
				//
				while ( !quit )
				{
					//
					choice = this->main_menu();
					switch( choice )
					{
						//
						case Enums::MainMenuChoice::PlayGame:
							this->play_game();
							break;
						
						//
						case Enums::MainMenuChoice::ReviewGameHistory:
							this->review_game_history();
							break;
						
						//
						case Enums::MainMenuChoice::PowerUpStore:
							this->store();
							break;
						
						//
						case Enums::MainMenuChoice::FindFriendsOnSocialMedia:
							this->find_friends_on_social_media();
							break;
						
						//
						case Enums::MainMenuChoice::Quit:
							quit = true;
							this->print("Quitting ... ");
							break;
						
						//
						case Enums::MainMenuChoice::Invalid:
							this->print("Invalid choice!");
							break;
					}
				}
			}
			
			//
			Enums::MainMenuChoice ClientTextUI::main_menu()
			{
				//
				string input;
				Enums::MainMenuChoice choice;
				
				//
				this->print("");
				this->print("*** MAIN MENU ***");
				this->print("1. Play the Game");
				this->print("2. Review Game History");
				this->print("3. Purchase a PowerUp");
				this->print("4. Find Friends on Social Media");
				this->print("Q. Quit");
				this->print("Enter your selection --> ", false);
				std::cin >> input;
				
				//	Make the input lowercase
				std::transform(input.begin(), input.end(), input.begin(), ::tolower);
				
				//
				if ( input == "1" ) {
					choice =  Enums::MainMenuChoice::PlayGame;
				}
				else if ( input == "2" ) {
					choice = Enums::MainMenuChoice::ReviewGameHistory;
				}
				else if ( input == "3" ) {
					choice = Enums::MainMenuChoice::PowerUpStore;
				}
				else if ( input == "4" ) {
					choice = Enums::MainMenuChoice::FindFriendsOnSocialMedia;
				}
				else if ( input == "q" ) {
					choice =  Enums::MainMenuChoice::Quit;
				}
				else{
					choice = Enums::MainMenuChoice::Invalid;
				}
				
				return choice;
			}
			
			//
			void ClientTextUI::play_game()
			{
				//
				this->_game = this->_game_factory->createGame();
				this->initialize_display_grid();
				
				//
				this->print("Playing the game ... ");
				this->_game->start();
				this->_input->enable();
				while( this->_game->is_active() )
				{
					//
					this->handle_game_input();
					
					//
					this->_game->update();
					
					//
					this->draw_game();
				}
				this->_input->disable();
				
				//
				this->print("");
				this->print("Game has finished !!");
				this->print("Highest round reached: " + std::to_string(this->_game->get_round()));
				this->print("Final score: " + std::to_string(this->_game->get_score()));
			}
			
			//
			void ClientTextUI::handle_game_input()
			{
				//
				while ( this->_input->kbhit() )
				{
					//
					int key = this->_input->getchar();
					
					//
					if ( key == 'Q' || key == 'q' ) {
						this->print("QUITTING !!!");
						this->_game->quit();
					}
					else if ( key == Input::KEY_UP ) {
						this->_game->get_player()->clear_input();
						this->_game->get_player()->set_input_up(true);
					}
					else if ( key == Input::KEY_DOWN ) {
						this->_game->get_player()->clear_input();
						this->_game->get_player()->set_input_down(true);
					}
					else if ( key == Input::KEY_LEFT ) {
						this->_game->get_player()->clear_input();
						this->_game->get_player()->set_input_left(true);
					}
					else if ( key == Input::KEY_RIGHT ) {
						this->_game->get_player()->clear_input();
						this->_game->get_player()->set_input_right(true);
					}
					else if ( key == Input::KEY_FIRE ) {
						this->_game->get_player()->clear_input();
						this->_game->get_player()->set_input_fire(true);
					}
					
					//
					//this->print("Got key: " + std::to_string(key));
				}
			}
			
			//
			void ClientTextUI::draw_game()
			{
				//
				std::vector<std::shared_ptr<Asteroids::Domain::Game::Actors::ActorInterface>> actors;
				
				//
				std::string round = std::to_string(this->_game->get_round());
				std::string score = std::to_string(this->_game->get_score());
				
				//
				this->_display_grid->clear();
				
				//
				this->_display_grid->set_header_text("Asteroids !!! ==> Round " + round);
				this->_display_grid->set_footer_text("Score: " + score);
				
				//	Grab all actors and draw
				actors = this->_game->get_actors();
				for ( std::shared_ptr<Asteroids::Domain::Game::Actors::ActorInterface> actor : actors ) {
					this->draw_actor(actor);
				}
				
				//
				this->_display_grid->print();
			}
			
			//
			void ClientTextUI::draw_actor(std::shared_ptr<Asteroids::Domain::Game::Actors::ActorInterface> actor)
			{
				//	Draw
				this->_display_grid->draw_filled_polygon(
					actor->get_x(), actor->get_y(),
					actor->get_rotated_polygon()
				);
			}
			
			//
			void ClientTextUI::review_game_history()
			{
				//
				this->print();
				this->print("Reviewing Game History");
				
				//
				this->_game_history = this->_game_factory->createGameHistory();
				
				//	Render history
				std::vector<std::shared_ptr<Asteroids::Domain::Game::GAME_HISTORY_ENTRY_INTERFACE>> entries;
				entries = this->_game_history->get_history();
				for ( size_t i=0; i<entries.size(); i++ ) {
					std::shared_ptr<Asteroids::Domain::Game::GAME_HISTORY_ENTRY_INTERFACE> entry = entries[i];
					this->print(std::to_string(i) + "] Earned " + std::to_string(entry->get_score()) + " points: " + entry->get_date());
				}
				
				//	Ask to share history
				while(true)
				{
					//
					std::string choice_str;
					int choice_index;
					this->print("Which entry would you like to share to social media? (Enter n for none)");
					this->print("---> ", false);
					std::cin >> choice_str;
					if ( choice_str == "n" || choice_str == "N" ) {
						this->print("Won't share to social media");
						return;
					}
					choice_index = -1;
					try
					{
						choice_index = std::stoi(choice_str);
					}
					catch(...)
					{
						this->print("That choice didn't make sense");
						continue;
					}
					if ( choice_index < 0 || choice_index >= static_cast<int>(entries.size()) ) {
						this->print("Choice out of bounds");
						continue;
					}
					
					//
					this->share_game_history_entry_to_social_media(entries[choice_index]);
				}
			}
			
			//
			void ClientTextUI::share_game_history_entry_to_social_media( std::shared_ptr<Asteroids::Domain::Game::GAME_HISTORY_ENTRY_INTERFACE> entry)
			{
				//
				std::shared_ptr<Asteroids::TechnicalServices::Social::SocialMediaInterface> social_media
					= this->_technical_services_factory->createSocialMedia();
				
				//
				this->print("***** Sharing Game History to Social Media *****");
				this->print("Date: " + entry->get_date());
				this->print("Score: " + std::to_string(entry->get_score()));
				
				//	Do the sharing
				bool share_success = social_media->share_game_history_entry(
					entry->get_date(), entry->get_score()
				);
				
				//
				if ( share_success ) {
					this->print("Entry has been shared to social media");
					
					//
					std::unique_ptr<Asteroids::Domain::Net::ClientServerCommunicatorInterface> comm = this->_net_factory->createClientServerCommunicator();
					comm->notifyServerOfGameHistoryEntrySocialMediaShare(entry->get_id());
				}
				else{
					this->print("Failed to share to social media, for some reason");
				}
				
				this->print();
			}
			
			//
			void ClientTextUI::find_friends_on_social_media()
			{
				//
				std::shared_ptr<Asteroids::TechnicalServices::Social::SocialMediaInterface> social_media
					= this->_technical_services_factory->createSocialMedia();
				
				//
				while( true )
				{
					
					//
					this->print();
					this->print("***** Current Friends on Social Media *****");
					
					//
					std::vector<std::shared_ptr<Asteroids::TechnicalServices::Social::FRIEND_ON_SOCIAL_MEDIA_INTERFACE>> friends
						= social_media->get_game_friends_on_social_media();
					for ( size_t i=0; i<friends.size(); i++ ) {
						
						//
						std::shared_ptr<Asteroids::TechnicalServices::Social::FRIEND_ON_SOCIAL_MEDIA_INTERFACE> f = friends[i];
						
						//
						this->print(std::to_string(i) + "] " + f->get_friend_name() + " is on: " + f->get_social_network_name() + " as " + f->get_friend_social_media_handle());
					}
					
					//
					std::string choice_str;
					this->print("");
					this->print("Enter a number to visit your friend's social media profile, or Q to quit");
					this->print("---> ", false);
					std::cin >> choice_str;
					
					//
					if ( choice_str == "q" or choice_str == "Q" ) {
						this->print("Quitting social media section!");
						return;
					}
					
					//
					int choice_index = -1;
					try
					{
						//
						choice_index = std::stoi(choice_str);
					}
					catch(...)
					{
						//
						this->print("That answer didn't make sense");
						continue;
					}
					if ( choice_index < 0 || choice_index >= static_cast<int>(friends.size()) ) {
						this->print("That choice was out of bounds");
						continue;
					}
					
					//
					std::shared_ptr<Asteroids::TechnicalServices::Social::FRIEND_ON_SOCIAL_MEDIA_INTERFACE> friend_choice = friends[choice_index];
					
					///	@todo Actually navigate to the friend's social media account, somehow
					this->print("Now spawning window for friend's social media account: " + friend_choice->get_friend_name() + " (TODO)");
				}
			}
			
			//
			void ClientTextUI::store()
			{
				//
				this->print();
				this->print("Entering the store ... ");
				
				//
				this->_store = this->_store_factory->createStore();
				this->_payment_helper = this->_store_factory->createPaymentHelper();
				
				//
				while ( this->store_loop() ){}
				
				//
				this->print();
				this->print("Exiting the store ...");
			}
			
			//
			bool ClientTextUI::store_loop()
			{
				//
				string input;
				bool want_to_continue = true;
				
				//
				this->print();
				this->print("Welcome to the Store");
				
				//
				this->print("1. Show Currently Owned PowerUps");
				this->print("2. Show Available PowerUps");
				this->print("Q. Exit the Store");
				this->print("Enter your choice ==> ", false);
				
				//
				std::cin >> input;
				std::transform(input.begin(), input.end(), input.begin(), ::tolower);
				if ( input == "1" ) {
					
					//
					this->print("Now showing currently owned PowerUps ...");
				}
				else if ( input == "2" ) {
					this->store_offer_available_items();
				}
				else if ( input == "q" ) {
					
					//
					this->print("Goodbye!");
					want_to_continue = false;
				}
				
				return want_to_continue;
			}
			
			//
			void ClientTextUI::store_offer_available_items()
			{
				//
				std::vector<std::shared_ptr<Asteroids::Domain::Store::STORE_ITEM_INTERFACE>> store_items;
				std::shared_ptr<Asteroids::Domain::Store::STORE_ITEM_INTERFACE> item;
				string input;
				bool done;
				
				//
				store_items = this->_store->get_available_store_items();
				
				//
				done = false;
				while( !done )
				{
					
					//	Render the available items
					this->print();
					this->print("*** Select an Item to Purchase ***");
					for ( size_t i=0; i<store_items.size(); i++ ) {
						
						//
						item = store_items[i];
						
						//
						this->print();
						this->print(std::to_string( i+1 ) + ". " + item->get_name());
						this->print("===> " + item->get_description());
						this->print("($" + item->get_formatted_price() + ")");
					}
					
					//	Ask if the user wants to purchase anything
					this->print();
					this->print("Which item will you purchase? (enter L to purchase nothing, like a loser ... )");
					this->print("===> ", false);
					std::cin >> input;
					std::transform(input.begin(), input.end(), input.begin(), ::tolower);
					
					//
					if ( input == "l" ) {
						this->print("Lame, bro ... ");
						done = true;
					}
					else{
						
						//
						size_t item_index;
						try
						{
							//
							item_index = std::stoi(input) - 1;
							if ( item_index < store_items.size() ) {
								
								//	Attempt to purchase the selected item
								std::shared_ptr<Asteroids::Domain::Store::POWERUP_ADDED_INFO_INTERFACE> info
									= this->purchasing_store_item(store_items[item_index]);
								if ( info ) {
									
									//
									std::shared_ptr<Asteroids::Domain::Store::STORE_ITEM_INTERFACE> item
										= info->get_store_item();
									if ( !item ) {
										throw std::runtime_error("Store purchase seemed successful, but the POWERUP_ADDED_INFO_INTERFACE object had no store item ... ");
									}
									
									//
									this->print();
									this->print("*** THANK YOU FOR YOUR PURCHASE, BRO ***");
									this->print("You're the proud new owner of a: " + item->get_name() + " !!!");
								}
								
							}
							else{
								throw std::runtime_error("");
							}
						}
						catch(...)
						{
							//
							this->print("Invalid Selection !!!");
						}
					}
				}
			}
			
			//
			std::shared_ptr<Asteroids::Domain::Store::POWERUP_ADDED_INFO_INTERFACE>
				ClientTextUI::purchasing_store_item
				(
					std::shared_ptr<Asteroids::Domain::Store::STORE_ITEM_INTERFACE> item 
				)
			{
				//
				std::vector<Asteroids::Domain::Store::Enums::PaymentMethod> payment_methods;
				Asteroids::Domain::Store::Enums::PaymentMethod payment_method;
				std::string input;
				
				//
				payment_methods = this->_payment_helper->get_available_payment_methods();
				
				//
				this->print();
				this->print("*** Now Purchasing PowerUp Item ***");
				
				//	Show the available payment methods and ask for a selection
				this->print("You're just seconds away from owning a: \"" + item->get_name() + "\"");
				this->print("Please select your payment method below:");
				for ( size_t i=0; i<payment_methods.size(); i++ ) {
					
					//
					payment_method = payment_methods[i];
					
					//
					this->print( std::to_string(i+1) + ". " + this->_payment_helper->payment_method_to_string(payment_method));
				}
				this->print("Q. Cancel");
				this->print("===> ", false);
				std::cin >> input;
				std::transform(input.begin(), input.end(), input.begin(), ::tolower);
				
				//
				if ( input == "q" ) {
					this->print("Cancelling ... ");
				}
				else{
					
					//
					size_t method_index;
					try
					{
						//
						method_index = std::stoi(input) - 1;
						if ( method_index < payment_methods.size() ) {
							
							//	Attempt to pay, and if successful,
							//	return info about the powerup that was added to your account
							if ( this->pay_for_store_item(item, payment_methods[method_index]) ) {
								
								//
								std::shared_ptr<Asteroids::Domain::Store::POWERUP_ADDED_INFO_INTERFACE> info
									= this->_store_factory->createPowerUpAddedInfo();
								info->set_store_item(item);
								info->set_quantity(1);
								
								return info;
							}
						}
					}
					catch(...)
					{
						//
						this->print("Invalid input");
					}
				}
				
				return nullptr;
			}
			
			//
			bool ClientTextUI::pay_for_store_item(
				std::shared_ptr<Asteroids::Domain::Store::STORE_ITEM_INTERFACE> item,
				Asteroids::Domain::Store::Enums::PaymentMethod payment_method
			)
			{
				//	Payment method must be implemented
				if ( !this->_payment_helper->is_payment_method_implemented(payment_method) ) {
					this->print("That payment method isn't yet implemented, jerk");
					return false;
				}
				
				//
				this->print();
				this->print("*** Entering Payment Details ***");
				this->print("Paying for store item with method: " + this->_payment_helper->payment_method_to_string(payment_method));
				
				//
				if ( payment_method == Asteroids::Domain::Store::Enums::PaymentMethod::CreditCard ) {
					
					//
					std::shared_ptr<Asteroids::Domain::Store::PAYMENT_RESULT_DETAILS_INTERFACE> payment_result
						= this->pay_for_store_item_with_credit_card(item);
					
					//
					this->print();
					if ( payment_result->was_successful() ) {
						
						//
						this->print("*** Payment Successful ***");
						this->print("Message: " + payment_result->get_message());
						
						return true;
					}
					else{
						
						//
						this->print("*** Payment Failed! WHAT ARE YOU DOING ***");
						this->print("Message: " + payment_result->get_message());
						
						return false;
					}
				}
				else{
					
					//
					this->print("Couldn't figure out how to use that payment method ... ");
				}
				
				return false;
			}
			
			//
			std::shared_ptr<Asteroids::Domain::Store::PAYMENT_RESULT_DETAILS_INTERFACE>
				ClientTextUI::pay_for_store_item_with_credit_card
				(
					std::shared_ptr<Asteroids::Domain::Store::STORE_ITEM_INTERFACE> item
				)
			{
				//
				std::string
					cc_number,
					cc_expiration,
					cc_security_code
					;
				
				//
				this->print();
				this->print("Enter your Credit Card Number ==> ", false);
				std::cin >> cc_number;
				this->print();
				this->print("Enter the expiration in the form MM/DD/YYYY ==> ", false);
				std::cin >> cc_expiration;
				this->print();
				this->print("Enter the 3 digit security code on the back ==> ", false);
				std::cin >> cc_security_code;
				
				//
				return this->_payment_helper->pay_for_store_item_with_credit_card(item, cc_number, cc_expiration, cc_security_code);
			}
			
			
			
		}
	}
}










