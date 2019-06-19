

//
#include "Asteroids/Domain/Server/ServerUpdater.h"


//
#include <iostream>
#include <thread>
#include <chrono>


//
namespace Asteroids
{
	//
	namespace Domain
	{
		//
		namespace Server
		{
			//
			ServerUpdater::ServerUpdater()
			{
				//
			}
			
			//
			void ServerUpdater::update()
			{
				//
				std::cout << "OooooOOOoooo !!!" << std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				std::cout << "Aahhhhhhh !!!" << std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(2000));
				std::cout << "Oohhhhhhhh !!!" << std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(3000));
				std::cout << "Hurray, I am updated!!!!!!" << std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(5000));
			}
		}
	}
}









