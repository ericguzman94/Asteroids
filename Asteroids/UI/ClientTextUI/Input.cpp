

//
#include "Asteroids/UI/ClientTextUI/Input.h"


//
namespace Asteroids
{
	//
	namespace UI
	{
		//
		namespace ClientTextUI
		{
			//
			Input::Input()
			{
				//
				this->init();
			}
			
			//
			Input::~Input()
			{
				//
				this->disable();
			}
			
			//
			void Input::enable()
			{
				//
				if ( this->_is_enabled ) {
					return;
				}
				
				//
				#ifdef __linux__
					
					//
					struct termios termio_settings_new;
					
					/* take two copies - one for now, one for later */
					tcgetattr(0, &this->_original_linux_termio_settings);
					memcpy(&termio_settings_new, &this->_original_linux_termio_settings, sizeof(termio_settings_new));
					
					//	Set the new terminal mode
					cfmakeraw(&termio_settings_new);
					tcsetattr(0, TCSANOW, &termio_settings_new);
					
				#else
					//	Nothing needed for windows
				#endif
				
				//
				this->_is_enabled = true;
			}
			
			//
			void Input::disable()
			{
				//
				if ( !this->_is_enabled ) {
					return;
				}
				
				//
				#ifdef __linux__
					tcsetattr(0, TCSANOW, &this->_original_linux_termio_settings);
				#else
					//	Nothing needed for windows
				#endif
				
				//
				this->_is_enabled = false;
			}
			
			//
			int Input::kbhit()
			{
				//
				int result;
				
				//
				if ( !this->_is_enabled ) {
					return 0;
				}
				//this->enable();
				
				//
				#ifdef __linux__
					
					//
					struct timeval tv = { 0L, 0L };
					
					fd_set fds;
					FD_ZERO(&fds);
					FD_SET(0, &fds);
					
					result = select(1, &fds, NULL, NULL, &tv);
					
				#else
					result = _kbhit();
				#endif
				
				//
				//this->disable();
				
				return result;
			}
			
			//
			int Input::getchar()
			{
				//
				int key = 0;
				
				//
				if ( !this->_is_enabled ) {
					return 0;
				}
				
				//
				//this->enable();
				
				//
				#ifdef __linux__
					
					int r;
					unsigned char c;
					if ((r = read(0, &c, sizeof(c))) < 0) {
						key = r;
					}
					else {
						key = c;
					}
				#else
					key = _getch();
				#endif
				
				//
				//this->disable();
				
				return key;
			}
			
			//
			void Input::init()
			{
				//
				this->_is_enabled = false;
			}
			
			
			
		}
	}
}






