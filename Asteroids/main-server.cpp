

//
#include "Asteroids/Domain/Factory/Factory.h"
#include "Asteroids/UI/UIFactoryInterface.h"
#include "Asteroids/UI/ServerTextUI/ServerTextUIInterface.h"


//
#include <iostream>
#include <chrono>
#include <thread>


//
using std::cout;
using std::endl;
using std::cin;


//
int main()
{
	//	Instantiate Main Factory
	std::shared_ptr<Asteroids::Domain::Factory::Factory> factory(
		new Asteroids::Domain::Factory::Factory()
	);
	
	//	Instantiate ServerTextUI
	std::unique_ptr<Asteroids::UI::UIFactoryInterface> factory_ui = factory->createUIFactory();
	std::shared_ptr<Asteroids::UI::ServerTextUI::ServerTextUIInterface> ui = factory_ui->createServerTextUI();
	
	//	Run the server with user interface
	ui->run();
	
	//
	cout
		<< endl
		<< "Server program terminated; Press enter to continue"
		<< endl
		;
	cin.get();
	
	return 0;
}






