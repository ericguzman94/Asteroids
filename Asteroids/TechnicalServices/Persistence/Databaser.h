#ifndef ASTEROIDS_TECHNICALSERVICES_PERSISTENCE_DATABASER_H
#define ASTEROIDS_TECHNICALSERVICES_PERSISTENCE_DATABASER_H


//
#include "Asteroids/ForwardDeclarations.h"
#include "Asteroids/TechnicalServices/Persistence/DatabaserInterface.h"


//
namespace Asteroids
{
	//
	namespace TechnicalServices
	{
		//
		namespace Persistence
		{
			///	Implementation of Databaser
			class Databaser
				: public DatabaserInterface
			{
				//
				public:
					
					//
					Databaser();
					
					//
					void connect(std::string uri);
					void close();
					
					//
					std::vector<std::map<std::string, std::string>> query(std::string q, std::map<std::string,std::string> params=std::map<std::string,std::string>());
			};
		}
	}
}


#endif
