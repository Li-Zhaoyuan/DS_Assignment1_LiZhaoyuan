/****************************************************************************/
/*!
\file Vec2D.h
\author Li Zhaoyuan
\par email: 150592K@mymail.nyp.edu.sg
\brief
Struct to define position coordinates x and y.
*/
/****************************************************************************/

#ifndef VEC2D_H_
#define VEC2D_H_
/****************************************************************************/
/*!
Class Vec2D:
\brief Defines position x and y.
*/
/****************************************************************************/
struct Vec2D
{
public:
	Vec2D();
	Vec2D(double x, double y ) ;
	//virtual ~Vec2D();

	
	double x;
	double y;

	
};

#endif