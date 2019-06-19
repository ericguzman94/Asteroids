

//
#include "Asteroids/Domain/Store/PAYMENT_RESULT_DETAILS.h"


//
namespace Asteroids
{
	//
	namespace Domain
	{
		//
		namespace Store
		{
			//
			PAYMENT_RESULT_DETAILS::PAYMENT_RESULT_DETAILS()
			{
				//
				this->set_was_successful(false);
			}
			
			//
			void PAYMENT_RESULT_DETAILS::set_was_successful(bool b)
			{
				//
				this->_was_successful = b;
			}
			
			//
			bool PAYMENT_RESULT_DETAILS::was_successful()
			{
				//
				return this->_was_successful;
			}
			
			//
			void PAYMENT_RESULT_DETAILS::set_message(std::string m)
			{
				//
				this->_message = m;
			}
			
			//
			std::string PAYMENT_RESULT_DETAILS::get_message()
			{
				//
				return this->_message;
			}
		}
	}
}







