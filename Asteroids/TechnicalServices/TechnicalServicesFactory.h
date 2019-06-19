#ifndef ASTEROIDS_TECHNICALSERVICES_TECHNICALSERVICESFACTORY_H
#define ASTEROIDS_TECHNICALSERVICES_TECHNICALSERVICESFACTORY_H


//
#include "Asteroids/ForwardDeclarations.h"
#include "Asteroids/TechnicalServices/TechnicalServicesFactoryInterface.h"


//
namespace Asteroids
{
	//
	namespace TechnicalServices
	{
		///	Implementation of TechnicalServicesFactoryInterface
		class TechnicalServicesFactory
			: public TechnicalServicesFactoryInterface
		{
			//
			public:
				
				//
				TechnicalServicesFactory();
				
				//
				std::unique_ptr<Asteroids::TechnicalServices::Persistence::DatabaserInterface> createDatabaser();
				std::unique_ptr<Asteroids::TechnicalServices::Financial::CreditCardProcessorInterface> createCreditCardProcessor();
				std::unique_ptr<Asteroids::TechnicalServices::Social::SocialMediaInterface> createSocialMedia();
				
			//
			private:
				
				//
		};
	}
}


#endif
