

//
#include "Asteroids/TechnicalServices/TechnicalServicesFactory.h"
//
#include "Asteroids/TechnicalServices/Persistence/Databaser.h"
#include "Asteroids/TechnicalServices/Financial/CreditCardProcessorInterface.h"
#include "Asteroids/TechnicalServices/Financial/MastercardProcessor.h"
#include "Asteroids/TechnicalServices/Financial/VisaProcessor.h"
#include "Asteroids/TechnicalServices/Social/SocialMedia.h"


//
namespace Asteroids
{
	//
	namespace TechnicalServices
	{
		//
		TechnicalServicesFactory::TechnicalServicesFactory()
		{
			//
		}
		
		//
		std::unique_ptr<Asteroids::TechnicalServices::Persistence::DatabaserInterface> TechnicalServicesFactory::createDatabaser()
		{
			///	@todo Should eventually actually connect to some database during creation
			std::unique_ptr<Asteroids::TechnicalServices::Persistence::DatabaserInterface> db(
				new Asteroids::TechnicalServices::Persistence::Databaser()
			);
			
			return db;
		}
		
		//
		std::unique_ptr<Asteroids::TechnicalServices::Financial::CreditCardProcessorInterface> TechnicalServicesFactory::createCreditCardProcessor()
		{
			//
			std::unique_ptr<Asteroids::TechnicalServices::Financial::CreditCardProcessorInterface> processor;
			
			//	Use Visa if the define USE_VISA is set
			#ifdef USE_VISA
				processor = std::unique_ptr<Asteroids::TechnicalServices::Financial::CreditCardProcessorInterface>(
					new Asteroids::TechnicalServices::Financial::VisaProcessor()
				);
			//	Otherwise default to Mastercard
			#else
				processor = std::unique_ptr<Asteroids::TechnicalServices::Financial::CreditCardProcessorInterface>(
					new Asteroids::TechnicalServices::Financial::MastercardProcessor()
				);
			#endif
			
			return processor;
		}
		
		//
		std::unique_ptr<Asteroids::TechnicalServices::Social::SocialMediaInterface> TechnicalServicesFactory::createSocialMedia()
		{
			//
			std::unique_ptr<Asteroids::TechnicalServices::Social::SocialMediaInterface> socialMedia(
				new Asteroids::TechnicalServices::Social::SocialMedia
			);
			
			return socialMedia;
		}
	}
}





