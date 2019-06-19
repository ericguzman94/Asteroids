#ifndef ASTEROIDS_TECHNICALSERVICES_FINANCIAL_CREDITCARDPROCESSORINTERFACE_H
#define ASTEROIDS_TECHNICALSERVICES_FINANCIAL_CREDITCARDPROCESSORINTERFACE_H


//
#include "Asteroids/ForwardDeclarations.h"


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
			class CreditCardProcessorInterface
			{
				//
				public:
					
					//
					virtual std::string get_processor_description() = 0;
					
					//
					virtual std::string authorizePayment(
						std::string cardholder_name,
						std::string cardholder_address,
						std::string cc_number,
						std::string cc_expiration,
						std::string cc_security_code
					) = 0;
			};
		}
	}
}



#endif
