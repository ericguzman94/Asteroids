

//
#include "Asteroids/Domain/Server/HACCS_REPORT.h"
#include "Asteroids/Domain/Server/HACCS_REPORT_ACTIVITY.h"


//
namespace Asteroids
{
	//
	namespace Domain
	{
		//
		namespace Server
		{
			//
			HACCS_REPORT::HACCS_REPORT()
			{
				//
				this->reset();
			}
			
			//
			void HACCS_REPORT::reset()
			{
				//
				this->_id = "";
				this->_username = "";
				this->_nickname = "";
				this->_email = "";
				
				//
				this->_suspicious_activities.clear();
			}
			
			//
			void HACCS_REPORT::set_id( std::string id )
			{
				//
				this->_id = id;
			}
			
			//
			std::string HACCS_REPORT::get_id()
			{
				//
				return this->_id;
			}
			
			//
			void HACCS_REPORT::set_user_details(std::string username, std::string nickname, std::string email)
			{
				//
				this->_username =username;
				this->_nickname = nickname;
				this->_email = email;
			}
			
			//
			std::string HACCS_REPORT::get_username()
			{
				//
				return this->_username;
			}
			
			//
			std::string HACCS_REPORT::get_nickname()
			{
				//
				return this->_nickname;
			}
			
			//
			std::string HACCS_REPORT::get_email()
			{
				//
				return this->_email;
			}
			
			///	Creates a HACCS_REPORT_ACTIVITY, because nobody else will need
			///	to create the activity, but the report
			void HACCS_REPORT::add_suspicious_activity(std::string when, std::string what)
			{
				//
				std::shared_ptr<HACCS_REPORT_ACTIVITY_INTERFACE> activity(
					new HACCS_REPORT_ACTIVITY()
				);
				
				//
				activity->set_when(when);
				activity->set_what(what);
				
				//
				this->_suspicious_activities.push_back(activity);
			}
			
			//
			std::vector<std::shared_ptr<HACCS_REPORT_ACTIVITY_INTERFACE>> HACCS_REPORT::get_suspicious_activities()
			{
				//
				return this->_suspicious_activities;
			}
			
			
			
		}
	}
}












