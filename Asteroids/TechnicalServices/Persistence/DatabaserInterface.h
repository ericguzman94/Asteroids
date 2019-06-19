#ifndef ASTEROIDS_TECHNICALSERVICES_PERSISTENCE_DATABASERINTERFACE_H
#define ASTEROIDS_TECHNICALSERVICES_PERSISTENCE_DATABASERINTERFACE_H


//
#include "Asteroids/ForwardDeclarations.h"


//
#include <string>
#include <vector>
#include <map>


//
namespace Asteroids
{
	//
	namespace TechnicalServices
	{
		//
		namespace Persistence
		{
			///	The Databaser interface allows us to connect to and manipulate a database
			class DatabaserInterface
			{
				//
				public:
					
					//
					virtual void connect(std::string uri) = 0;
					virtual void close() = 0;
					
					//
					virtual std::vector<std::map<std::string, std::string>> query(std::string q, std::map<std::string,std::string> params=std::map<std::string,std::string>()) = 0;
			};
		}
	}
}


#endif
