

//
#include "Asteroids/TechnicalServices/Financial/MastercardProcessor.h"


//
#include <string>


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
			MastercardProcessor::MastercardProcessor()
			{
				//
			}
			
			//
			std::string MastercardProcessor::get_processor_description()
			{
				//
				return "Mastercard Payment Processor";
			}
			
			//
			std::string MastercardProcessor::authorizePayment(
				std::string cardholder_name,
				std::string cardholder_address,
				std::string cc_number,
				std::string cc_expiration,
				std::string cc_security_code
			)
			{
				//	Mute warnings, lulz
				cardholder_name = cardholder_name;
				cardholder_address = cardholder_address;
				cc_number = cc_number;
				cc_expiration = cc_expiration;
				cc_security_code = cc_security_code;
				
				//
				return "Payment successfully processed through Mastercard";
			}
		}
	}
}




