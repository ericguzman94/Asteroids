

//
#include "Asteroids/Domain/Game/Actors/Rect.h"


//
#include <sstream>


///	@todo remove me
#include <iostream>


//
namespace Asteroids
{
	//
	namespace Domain
	{
		//
		namespace Game
		{
			//
			namespace Actors
			{
				//
				Rect::Rect()
				{
					//
					this->reset();
				}
				
				//
				void Rect::reset()
				{
					//
					this->x1
						= this->y1
						= this->x2
						= this->y2
						= 0
						;
				}
				
				//
				Rect Rect::consume_polygon(const std::vector<std::pair<double,double>>& points)
				{
					//
					Rect r;
					bool did_first = false;
					
					//
					for ( std::pair<double,double> point : points ) {
						
						//
						double x = point.first;
						double y = point.second;
						
						//
						if ( !did_first ) {
							did_first = true;
							r.x1 = r.x2 = x;
							r.y1 = r.y2 = y;
						}
						else{
							
							//
							if ( x < r.x1 ) {
								r.x1 = x;
							}
							if ( x > r.x2 ) {
								r.x2 = x;
							}
							if ( y < r.y1 ) {
								r.y1 = y;
							}
							if ( y > r.y2 ) {
								r.y2 = y;
							}
						}
					}
					
					//
					r.update_dimensions();
					
					//
					return r;
				}
				
				//
				void Rect::add_offset(double x, double y)
				{
					//
					this->x1 += x;
					this->x2 += x;
					this->y1 += y;
					this->y2 += y;
					
					//
					this->update_dimensions();
				}
				
				//
				void Rect::update_dimensions()
				{
					//
					this->width = this->x2 - this->x1;
					this->height = this->y2 - this->y1;
				}
				
				//
				bool Rect::collides_with_rect(const Rect& other)
				{
					//
					if (
						
						//	If any of their points are within our rect
						this->is_point_within(other.x1, other.y1)
						|| this->is_point_within(other.x2, other.y1)
						|| this->is_point_within(other.x1, other.y2)
						|| this->is_point_within(other.x2, other.y2)
						
						//	If any of our points are within their rect
						|| other.is_point_within(this->x1, this->y1)
						|| other.is_point_within(this->x2, this->y1)
						|| other.is_point_within(this->x1, this->y2)
						|| other.is_point_within(this->x2, this->y2)
					)
					{
						//
						return true;
					}
					
					//
					//std::cout << "Not within: " << this->to_string() << " && " << other.to_string() << std::endl;
					
					return false;
				}
				
				//
				bool Rect::is_point_within(double x, double y) const
				{
					//
					if (
						x >= this->x1
						&& x <= this->x2
						&& y >= this->y1
						&& y <= this->y2
					)
					{
						return true;
					}
					
					return false;
				}
				
				//
				std::string Rect::to_string() const
				{
					//
					std::stringstream ss;
					
					//
					ss
						<< "{"
						<< this->x1 << ":" << this->y1
						<< " "
						<< this->x2 << ":" << this->y2
						<< "}"
						;
					
					return ss.str();
				}
			}
		}
	}
}






