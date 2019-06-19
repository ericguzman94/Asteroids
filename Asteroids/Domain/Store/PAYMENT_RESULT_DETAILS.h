#ifndef ASTEROIDS_DOMAIN_STORE_PAYMENT_RESULT_DETAILS_H
#define ASTEROIDS_DOMAIN_STORE_PAYMENT_RESULT_DETAILS_H


//
#include "Asteroids/ForwardDeclarations.h"
#include "Asteroids/Domain/Store/PAYMENT_RESULT_DETAILS_INTERFACE.h"


//
namespace Asteroids
{
	//
	namespace Domain
	{
		//
		namespace Store
		{
			///	Implementation of PATMENT_RESULTS_DETAILS_INTERFACE
			class PAYMENT_RESULT_DETAILS
				: public PAYMENT_RESULT_DETAILS_INTERFACE
			{
				//
				public:
					
					//
					PAYMENT_RESULT_DETAILS();
					
					//
					void set_was_successful(bool b);
					bool was_successful();
					
					//
					void set_message(std::string m);
					std::string get_message();
					
				//
				private:
					
					//
					bool _was_successful;
					
					//
					std::string _message;
			};
		}
	}
}








#endif
