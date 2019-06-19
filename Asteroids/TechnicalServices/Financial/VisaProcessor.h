#ifndef ASTEROIDS_TECHNICALSERVICES_FINANCIAL_VISAPROCESSOR_H
#define ASTEROIDS_TECHNICALSERVICES_FINANCIAL_VISAPROCESSOR_H


//
#include "Asteroids/ForwardDeclarations.h"
//
#include "Asteroids/TechnicalServices/Financial/CreditCardProcessorInterface.h"


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
			class VisaProcessor
				: public CreditCardProcessorInterface
			{
				//
				public:
					
					//
					VisaProcessor();
					
					//
					std::string get_processor_description();
					
					//
					std::string authorizePayment(
						std::string cardholder_name,
						std::string cardholder_address,
						std::string cc_number,
						std::string cc_expiration,
						std::string cc_security_code
					);
			};
		}
	}
}



#endif
