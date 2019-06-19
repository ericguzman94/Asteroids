

//
#include "Asteroids/TechnicalServices/Financial/FinancialServices.h"


//
namespace Asteroids
{
	//
	namespace TechnicalServices
	{
		//
		namespace Financial
		{
			//
			FinancialServices::FinancialServices()
			{
				//
			}
			
			//
			bool FinancialServices::authorizePayment(std::string cc_number, std::string cc_expiration, std::string cc_security_code)
			{
				//	Mute warnings, lulz
				cc_number = cc_number;
				cc_expiration = cc_expiration;
				cc_security_code = cc_security_code;
				
				return true;
			}
		}
	}
}



