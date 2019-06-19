#ifndef ASTEROIDS_UI_CLIENTTEXTUI_INPUT_H
#define ASTEROIDS_UI_CLIENTTEXTUI_INPUT_H


//
#include <vector>


#ifdef __linux__
	
	#include <stdlib.h>
	#include <string.h>
	#include <unistd.h>
	#include <sys/select.h>
	#include <termios.h>
	
#else
	#include <conio.h>
#endif


//
namespace Asteroids
{
	//
	namespace UI
	{
		//
		namespace ClientTextUI
		{
			///	Thank you very much: https://stackoverflow.com/questions/448944/c-non-blocking-keyboard-input
			class Input
			{
				//
				public:
					
					//
					Input();
					~Input();
					
					//
					void enable();
					void disable();
					
					//
					int kbhit();
					int getchar();
					
					//
					#ifdef __linux__
						static constexpr int KEY_UP = 65;
						static constexpr int KEY_DOWN = 66;
						static constexpr int KEY_LEFT = 68;
						static constexpr int KEY_RIGHT = 67;
					#else
						static constexpr int KEY_UP = 72;
						static constexpr int KEY_DOWN = 80;
						static constexpr int KEY_LEFT = 75;
						static constexpr int KEY_RIGHT = 77;
					#endif
					static constexpr int KEY_FIRE = 32;
					
				//
				private:
					
					//
					bool _is_enabled;
					
					//
					#ifdef __linux__
						struct termios _original_linux_termio_settings;
					#else
						//	Nada
					#endif
					
					//
					void init();
			};
		}
	}
}








#endif
