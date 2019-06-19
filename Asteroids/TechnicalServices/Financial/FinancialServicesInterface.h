#ifndef ASTEROIDS_TECHNICALSERVICES_FINANCIAL_FINANCIALSERVICESINTERFACE_H
#define ASTEROIDS_TECHNICALSERVICES_FINANCIAL_FINANCIALSERVICESINTERFACE_H


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
			///	Provides an interface to external financial services, such as external banking systems
			/**
				This class isn't connected to anything yet, because the client
				still doesn't connect to the server, which means there's no need for the server daemon
				to actually call this method yet
			*/
			class FinancialServicesInterface
			{
				//
				public:
					
					//
					virtual bool authorizePayment(std::string cc_number, std::string cc_expiration, std::string cc_security_code) = 0;
			};
		}
	}
}


#endif
