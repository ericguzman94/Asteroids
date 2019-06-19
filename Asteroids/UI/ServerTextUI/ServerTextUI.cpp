

//
#include "Asteroids/UI/ServerTextUI/ServerTextUI.h"
//
#include "Asteroids/Domain/Factory/FactoryInterface.h"
#include "Asteroids/TechnicalServices/TechnicalServicesFactoryInterface.h"
#include "Asteroids/TechnicalServices/Financial/CreditCardProcessorInterface.h"
#include "Asteroids/Domain/Server/ServerFactoryInterface.h"
#include "Asteroids/Domain/Server/ServerDaemonInterface.h"
#include "Asteroids/Domain/Server/HACCS_REPORT_INTERFACE.h"
#include "Asteroids/Domain/Server/HACCS_REPORT_ACTIVITY_INTERFACE.h"


//
#include <iostream>
#include <algorithm>


//
namespace Asteroids
{
	//
	namespace UI
	{
		//
		namespace ServerTextUI
		{
			//
			ServerTextUI::ServerTextUI( std::shared_ptr<Asteroids::Domain::Factory::FactoryInterface> factory )
			{
				//
				this->_factory = factory;
				
				//
				this->init();
			}
			
			///	It is assumed that if you're sitting at the Admin console interface,
			///	You already have permission to Administer the server,
			///	Since to get to that point you'd need to be able to login to the computer's main server account anyway
			void ServerTextUI::run()
			{
				//
				this->main_menu_loop();
			}
			
			//
			void ServerTextUI::main_menu_loop()
			{
				//
				Enums::MainMenuChoice choice;
				
				//
				do
				{
					//
					choice = this->main_menu();
					
					//
					switch ( choice )
					{
						//
						case Enums::MainMenuChoice::ApplyUpdates:
							this->do_apply_updates();
							break;
						
						//
						case Enums::MainMenuChoice::ReviewFlaggedUsers:
							this->do_review_flagged_users();
							break;
						
						//
						case Enums::MainMenuChoice::ProcessCreditCardPayment:
							this->do_process_credit_card_payment();
							break;
						
						//
						case Enums::MainMenuChoice::Invalid:
							std::cout << "Invalid choice!" << std::endl;
							break;
						
						//
						case Enums::MainMenuChoice::Shutdown:
							std::cout << "OK; Shutting down ... " << std::endl;
							break;
					}
				}
				while ( choice != Enums::MainMenuChoice::Shutdown );
			}
			
			//
			Enums::MainMenuChoice ServerTextUI::main_menu()
			{
				//
				std::cout
					<< std::endl
					<< std::endl
					<< "*** Server Main Menu ***" << std::endl
					<< "1. Review Flagged Users" << std::endl
					<< "2. Download and Apply Updates" << std::endl
					<< "3. Process a Credit Card Payment" << std::endl
					<< "4. Shutdown" << std::endl
					;
				if ( this->_daemon->is_restart_required() ) {
					std::cout << "***** RESTART REQUIRED *****" << std::endl;
				}
				std::cout
					<< "Enter your choice ==> "
					;
				std::string input;
				std::cin >> input;
				
				//
				Enums::MainMenuChoice choice;
				if ( input == "1" ) {
					choice = Enums::MainMenuChoice::ReviewFlaggedUsers;
				}
				else if ( input == "2" ) {
					choice = Enums::MainMenuChoice::ApplyUpdates;
				}
				else if ( input == "3" ) {
					choice = Enums::MainMenuChoice::ProcessCreditCardPayment;
				}
				else if ( input == "4" ) {
					choice = Enums::MainMenuChoice::Shutdown;
				}
				else{
					choice = Enums::MainMenuChoice::Invalid;
				}
				
				return choice;
			}
			
			//
			void ServerTextUI::init()
			{
				//
				this->_factory_server = this->_factory->createServerFactory();
				this->_factory_technical_services = this->_factory->createTechnicalServicesFactory();
				
				//
				this->_daemon = this->_factory_server->createDaemon();
			}
			
			//
			void ServerTextUI::do_process_credit_card_payment()
			{
				//
				std::unique_ptr<Asteroids::TechnicalServices::Financial::CreditCardProcessorInterface> processor
					= this->_factory_technical_services->createCreditCardProcessor();
				std::string
					cardholder_name,
					cardholder_address,
					cc_number,
					cc_expiration,
					cc_security_code,
					payment_result_message
					;
				
				//
				std::cout
					<< std::endl
					<< "--> Processing a Credit Card Payment with: "
						<< processor->get_processor_description() << std::endl
					;
				
				//
				std::cout << "Enter the cardholder's name: ";
				std::cin >> cardholder_name;
				std::cout << "Enter the cardholder's address: ";
				std::cin >> cardholder_address;
				std::cout << "Enter the card number: ";
				std::cin >> cc_number;
				std::cout << "Enter the card expiration: ";
				std::cin >> cc_expiration;
				std::cout << "Enter the card security code: ";
				std::cin >> cc_security_code;
				
				//
				payment_result_message = processor->authorizePayment(
					cardholder_name,
					cardholder_address,
					cc_number,
					cc_expiration,
					cc_security_code
				);
				std::cout
					<< std::endl
					<< "Payment result: " << payment_result_message
					;
			}
			
			//
			void ServerTextUI::do_apply_updates()
			{
				//
				std::cout << "--> Applying updates" << std::endl;
				
				//
				this->_daemon->apply_updates();
				
				//
				std::cout << "--> Updates have finished" << std::endl;
			}
			
			//
			void ServerTextUI::do_review_flagged_users()
			{
				//
				while( this->do_review_flagged_user() )
				{
					//	nada
				}
			}
			
			//
			bool ServerTextUI::do_review_flagged_user()
			{
				//
				std::shared_ptr<Asteroids::Domain::Server::HACCS_REPORT_INTERFACE> report;
				std::string input;
				bool review_another = false;
				
				//	Grab and show a report of the next case
				report = this->_daemon->get_next_haccs_report();
				std::cout
					<< std::endl
					<< "*** Reviewing Flagged User ***" << std::endl
					<< "Username: " << report->get_username() << std::endl
					<< "Nickname: " << report->get_nickname() << std::endl
					<< "Email: " << report->get_email() << std::endl
					<< std::endl
					<< "** Recent Suspicious Activity **" << std::endl
					;
				for ( std::shared_ptr<Asteroids::Domain::Server::HACCS_REPORT_ACTIVITY_INTERFACE> activity : report->get_suspicious_activities() ) {
					std::cout << activity->get_when() << " : " << activity->get_what() << std::endl;
				}
				
				//	Ask for and apply judgment
				std::cout
					<< std::endl
					<< "1. Forgive this User" << std::endl
					<< "2. Ban this User" << std::endl
					<< "Enter judgment ==> "
					;
				std::cin >> input;
				if ( input == "1" ) {
					std::cout << "Forgiving the user ... " << std::endl;
					this->_daemon->forgive_haccs_report( report );
				}
				else if ( input == "2" ) {
					std::cout << "OK; Banning the user ... " << std::endl;
					this->_daemon->ban_user( report->get_username() );
				}
				else{
					std::cout << "Invalid selection ..." << std::endl;
				}
				
				//	Ask if we'd like to review another user
				std::cout
					<< std::endl
					<< "Review another user?" << std::endl
					<< "(Y/N) ==> "
					;
				std::cin >> input;
				std::transform(input.begin(), input.end(), input.begin(), ::tolower);
				if ( input == "y" ) {
					std::cout << "Okay; Reviewing another user ... " << std::endl;
					review_another = true;
				}
				else if ( input == "n" ) {
					std::cout << "Okay; Won't review any more users right now" << std::endl;
					review_another = false;
				}
				else{
					std::cout << "INVALID INPUT" << std::endl;
					review_another = false;
				}
				
				return review_another;
			}
		}
	}
}















