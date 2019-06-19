

//
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
			HACCS_REPORT_ACTIVITY::HACCS_REPORT_ACTIVITY()
			{
				//
				this->reset();
			}
			
			//
			void HACCS_REPORT_ACTIVITY::reset()
			{
				//
				this->_when = "";
				this->_what = "";
			}
			
			//
			void HACCS_REPORT_ACTIVITY::set_when(std::string when)
			{
				//
				this->_when = when;
			}
			
			//
			std::string HACCS_REPORT_ACTIVITY::get_when()
			{
				//
				return this->_when;
			}
			
			//
			void HACCS_REPORT_ACTIVITY::set_what(std::string what)
			{
				//
				this->_what = what;
			}
			
			//
			std::string HACCS_REPORT_ACTIVITY::get_what()
			{
				//
				return this->_what;
			}
		}
	}
}






