

//
#include "Asteroids/UI/ClientTextUI/DisplayGrid.h"


//
#include <iostream>
#include <sstream>
#include <math.h>


//
using std::cout;
using std::endl;
using std::stringstream;


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
			DisplayGrid::DisplayGrid(
				double source_width, double source_height,
				int grid_width, int grid_height
			)
			{
				//
				this->_source_width = source_width;
				this->_source_height = source_height;
				
				//
				this->_width = grid_width;
				this->_height = grid_height;
				
				//
				this->init();
			}
			
			//
			void DisplayGrid::init()
			{
				//
				this->reset();
			}
			
			//
			void DisplayGrid::calculate_translation()
			{
				//	Calculate the translation ratio
				double ratio_width = this->_width / this->_source_width;
				double ratio_height = this->_height / this->_source_height;
				double ratio;
				if ( ratio_width < ratio_height ) {
					ratio = ratio_width;
				}
				else{
					ratio = ratio_height;
				}
				this->_translation_ratio = ratio;
				
				//	Calculate unused source
				this->_unused_source_width = this->_source_width - (this->_translation_ratio * this->_width);
				this->_unused_source_height = this->_source_height - (this->_translation_ratio * this->_height);
				
				//	Determine unused local grid space
				this->_unused_width = this->_width - (this->_source_width * this->_translation_ratio);
				this->_unused_height = this->_height - (this->_source_height * this->_translation_ratio);
			}
			
			//
			void DisplayGrid::clear_grid()
			{
				//
				this->grid.clear();
				
				//
				for ( int y = 0; y < this->_height; y++ ) {
					
					//
					this->grid.push_back(std::vector<bool>());
					
					//
					for ( int x = 0; x < this->_width; x++ ) {
						
						//
						this->grid[y].push_back(false);
					}
				}
				
				//
				this->add_border();
			}
			
			//
			void DisplayGrid::add_border()
			{
				//
				for ( size_t y=0; y<this->_source_height; y++ ) {
					
					//	Left and right vertical sides
					this->set_pixel(0, y);
					this->set_pixel( this->_source_width - 1, y );
					
					//	A horizonal line, if we're at the very top or bottom
					if ( y == 0 || y == static_cast<size_t> (this->_source_height - 1) ) {
						for ( size_t x=0; x < this->_source_width; x++ ) {
							this->set_pixel(x, y);
						}
					}
				}
			}
			
			//
			void DisplayGrid::reset()
			{
				//
				this->_header_text = "";
				this->_footer_text = "";
				
				//
				this->clear_grid();
				
				//
				this->calculate_translation();
			}
			
			//
			void DisplayGrid::clear()
			{
				//
				for ( size_t y = 0; y < this->grid.size(); y++ ) {
					for ( size_t x = 0; x < this->grid[y].size(); x++ ) {
						this->grid[y][x] = false;
					}
				}
				
				//
				this->add_border();
			}
			
			//
			void DisplayGrid::set_header_text(string s)
			{
				//
				this->_header_text = s;
			}
			
			//
			void DisplayGrid::set_footer_text(string s)
			{
				//
				this->_footer_text = s;
			}
			
			//
			void DisplayGrid::draw_filled_polygon(
				double offset_x, double offset_y,
				const std::vector<std::pair<double, double>>& points
			)
			{
				//
				std::vector<std::pair<double, double>> points_temp;
				double step_size;
				double ratio;
				
				//
				step_size = 0.99;
				
				//	Draw+Shrink a maximum of 100 times
				for ( int i=0; i<100; i++) {
					
					//
					bool anything_large_enough = false;
					
					//
					ratio = pow( step_size, i );
					
					//	Shrink this polygon
					points_temp = points;
					for ( size_t i=0; i<points_temp.size(); i++ ) {
						
						//
						std::pair<double,double> * point = &points_temp[i];
						
						//
						//cout << point->first << " (" << ratio << ") ==> ";
						point->first *= ratio;
						//cout << point->first << "\r\n";
						point->second *= ratio;
						
						//
						if ( fabs(point->first) >= 1  || fabs(point->second)>=1 ) {
							anything_large_enough = true;
						}
					}
					
					//	Render its outline
					this->draw_polygon(
						offset_x, offset_y,
						points_temp
					);
					
					//	If no points were "large enough",
					//	we can break
					if ( !anything_large_enough ) {
						break;
					}
				}
			}
			
			//
			void DisplayGrid::draw_polygon(
				double offset_x, double offset_y,
				const std::vector<std::pair<double, double>>& points
			)
			{
				//
				const std::pair<double,double> * point;
				//const std::pair<double,double> * point_last = &points[ points.size() - 1 ];
				
				//
				for ( size_t i=0; i<points.size(); i++ ) {
					
					//
					point = &points[i];
					
					//
					this->set_pixel(
						point->first + offset_x,
						point->second + offset_y
					);
				}
				
				///	@todo It'd be nice if we could finish connecting the polygon points
				///	with a line
				/*
				//
				for ( size_t i=0; i<points.size(); i++ ) {
					
					//
					point = &points[i];
					
					//	Draw at this point
					this->set_pixel(
						point->first + offset_x,
						point->second + offset_y
					);
					
					//	Draw line from the last point
					double distance_x = point->first - point_last->first;
					double distance_y = point->second - point_last->second;
					double step_x, step_y;
					if ( fabs(distance_x) > fabs(distance_y) ) {
						step_x = 1;
						step_y = (fabs(distance_y) / fabs(distance_x));
					}
					else{
						step_x = (fabs(distance_x) / fabs(distance_y));
						step_y = 1;
					}
					for (
						double x = point_last->first, y = point_last->second;
						fmin(fabs(x - point->first), fabs(y - point->second)) > 2;
						x += step_x, y += step_y
					)
					{
						//
						this->set_pixel(
							x + offset_x,
							y + offset_y
						);
					}
					
					//
					point_last = point;
				}
				* */
			}
			
			//
			void DisplayGrid::set_pixel(double x, double y)
			{
				//
				std::pair<int, int> point_translated = this->translate_source_point(x, y);
				int translated_x = point_translated.first;
				int translated_y = point_translated.second;
				
				//
				this->set_grid_pixel(translated_x, translated_y);
			}
			
			//
			void DisplayGrid::set_grid_pixel(int x, int y)
			{
				//	Refuse to print anything out of bounds
				if
				(
					x >= 0
					&& x < this->_width
					&& y >= 0
					&& y < this->_height
				)
				{
					//
					this->grid[y][x] = true;
				}
			}
			
			//
			void DisplayGrid::print()
			{
				//
				stringstream ss;
				
				//
				ss << "\r\n\r\n\r\n\r\n";
				
				//
				ss << this->render();
				
				//
				cout << ss.str();
			}
			
			//
			string DisplayGrid::render()
			{
				//
				stringstream ss;
				stringstream padding_x;
				
				//	Create padding to center Xwise
				int half_unused_x = this->_unused_width / 2;
				for ( int i = 0; i<half_unused_x; i++ ) {
					padding_x << " ";
				}
				
				//	Render the header text
				ss << "\r\n" << this->_header_text;
				
				//	Render the grid
				for ( size_t y = 0; y < this->grid.size(); y++ ) {
					
					//
					ss << "\r\n";
					
					//
					ss << padding_x.str();
					
					//
					for ( size_t x = 0; x < this->grid[y].size(); x++ ) {
						
						//
						if ( this->grid[y][x] ) {
							ss << "*";
						}
						else{
							ss << " ";
						}
					}
				}
				
				//	Render the footer text
				ss << "\r\n" << this->_footer_text;
				
				//
				ss << "\r\n";
				
				return ss.str();
			}
			
			//
			std::pair<int, int> DisplayGrid::translate_source_point(double x, double y)
			{
				//
				int point_x = static_cast<int> (x * this->_translation_ratio);
				int point_y = static_cast<int> (y * this->_translation_ratio);
				std::pair<int, int> point(point_x, point_y);
				
				return point;
			}
			
			
		}
	}
}







