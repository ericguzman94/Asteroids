

//
#include "Asteroids/TechnicalServices/Persistence/Databaser.h"


//
namespace Asteroids
{
	//
	namespace TechnicalServices
	{
		//
		namespace Persistence
		{
			//
			Databaser::Databaser()
			{
				//
			}
			
			//
			void Databaser::connect(std::string uri)
			{
				//	Mute silly warnings
				uri = uri;
			}
			
			//
			void Databaser::close()
			{
				//
				
			}
			
			//
			std::vector<std::map<std::string, std::string>> Databaser::query(std::string q, std::map<std::string,std::string> params)
			{
				//
				std::vector<std::map<std::string, std::string>> rows;
				
				//	Mute silly warnings
				q = q;
				params = params;
				
				return rows;
			}
		}
	}
}



