#ifndef ASTEROIDS_UI_CLIENTTEXTUI_DISPLAYGRID_H
#define ASTEROIDS_UI_CLIENTTEXTUI_DISPLAYGRID_H


//
#include "Asteroids/ForwardDeclarations.h"


//
#include <vector>
#include <string>
#include <memory>


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
			using std::string;
			
			///	Class to help translate and render actors and stuff from the virtual game board, to actual ASCII graphics that can be seen
			class DisplayGrid
			{
				//
				public:
					
					//
					DisplayGrid(
						double source_width, double source_height,
						int grid_width, int grid_height
					);
					
					//
					void reset();
					void clear();
					
					//
					void set_header_text(string s);
					void set_footer_text(string s);
					
					//
					void draw_filled_polygon(
						double offset_x, double offset_y,
						const std::vector<std::pair<double, double>>& points
					);
					
					//
					void draw_polygon(
						double offset_x, double offset_y,
						const std::vector<std::pair<double, double>>& points
					);
					
					//
					void set_pixel(double x, double y);
					void set_grid_pixel(int x, int y);
					
					//
					string render();
					void print();
					
				//
				private:
					
					//
					int
						_width,
						_height,
						_unused_width,
						_unused_height
						;
					double
						_source_width,
						_source_height,
						_unused_source_width,
						_unused_source_height
						;
					double _translation_ratio;
					std::vector<std::vector<bool>> grid;
					
					//
					string
						_header_text,
						_footer_text
						;
					
					//
					void init();
					
					//
					void calculate_translation();
					
					//
					void clear_grid();
					void add_border();
					
					//
					std::pair<int, int> translate_source_point(double x, double y);
			};
			
			
		}
	}
}







#endif
