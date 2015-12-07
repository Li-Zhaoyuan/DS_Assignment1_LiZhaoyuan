#ifndef VEC_2_D_H_
#define VEC_2_D_H_

class Vec2D
{
public:
	Vec2D();
	Vec2D(double x = 0, double y = 0) : x(x), y(y){};
	virtual ~Vec2D();

	double x;
	double y;

	
};

#endif