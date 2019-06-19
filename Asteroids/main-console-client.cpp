

//
#include "Asteroids/Domain/Factory/Factory.h"
#include "Asteroids/UI/UIFactoryInterface.h"
#include "Asteroids/UI/ClientTextUI/ClientTextUIInterface.h"

//
#include <iostream>


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
	
	//	Instantiate Text User Interface
	std::unique_ptr<Asteroids::UI::UIFactoryInterface> factory_ui = factory->createUIFactory();
	std::unique_ptr<Asteroids::UI::ClientTextUI::ClientTextUIInterface> ui = factory_ui->createClientTextUI();
	
	//
	ui->run();
	
	//
	cout
		<< endl
		<< "Client program terminated; Press enter to continue"
		<< endl
		;
	cin.get();
	
	return 0;
}


