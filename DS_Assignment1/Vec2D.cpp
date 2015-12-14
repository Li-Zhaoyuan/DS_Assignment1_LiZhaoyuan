#include "Vec2D.h"
/****************************************************************************/
/*!
\brief
Initialize x and y value to 0.
\return
void
*/
/****************************************************************************/
Vec2D::Vec2D()
{
	x = 0;
	y = 0;
}
/****************************************************************************/
/*!
\brief
Initialize x and y based on the position of the dweller.
\param x - position x
\param y - position y
\return
void
*/
/****************************************************************************/
Vec2D::Vec2D(double x, double y)
:x(x), y(y)
{

}

