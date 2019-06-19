#ifndef ASTEROIDS_TECHNICALSERVICES_TECHNICALSERVICESFACTORYINTERFACE_H
#define ASTEROIDS_TECHNICALSERVICES_TECHNICALSERVICESFACTORYINTERFACE_H


//
#include "Asteroids/ForwardDeclarations.h"


//
#include <memory>


//
namespace Asteroids
{
	//
	namespace TechnicalServices
	{
		///	Creates objects that belong to the TechnicalServices package
		class TechnicalServicesFactoryInterface
		{
			//
			public:
				
				//
				virtual std::unique_ptr<Asteroids::TechnicalServices::Persistence::DatabaserInterface> createDatabaser() = 0;
				virtual std::unique_ptr<Asteroids::TechnicalServices::Financial::CreditCardProcessorInterface> createCreditCardProcessor() = 0;
				virtual std::unique_ptr<Asteroids::TechnicalServices::Social::SocialMediaInterface> createSocialMedia() = 0;
		};
	}
}


#endif
