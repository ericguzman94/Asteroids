#ifndef ASTEROIDS_TECHNICALSERVICES_FINANCIAL_FINANCIALSERVICES_H
#define ASTEROIDS_TECHNICALSERVICES_FINANCIAL_FINANCIALSERVICES_H


//
#include "Asteroids/ForwardDeclarations.h"
#include "Asteroids/TechnicalServices/Financial/FinancialServicesInterface.h"


//
namespace Asteroids
{
	//
	namespace TechnicalServices
	{
		//
		namespace Financial
		{
			///	Implementation of FinancialServicesInterface
			class FinancialServices
				: public FinancialServicesInterface
			{
				//
				public:
					
					//
					FinancialServices();
					
					//
					bool authorizePayment(std::string cc_number, std::string cc_expiration, std::string cc_security_code);
			};
		}
	}
}


#endif
