#ifndef SHAPE_H
#define SHAPE_H
#include<iostream>
namespace oj
{
	class Shape3D{	
		double volume;

	public:
		double getVolume();
	
	protected:
		void setVolume(double volume);
	};

	class Sphere : public Shape3D{
		double radius;
		double pi;
	
	public:
		Sphere(double, double);
	};

	class Cone : public Shape3D{
		double radius;
		double height;
		double pi;

	public:
		Cone(double, double, double);
	};

	class Cuboid : public Shape3D{
		double length;
		double width;
		double height;
	
	public:
		Cuboid(double, double, double);
	};

	class Cube : public Cuboid{
	public:
		Cube(double);
	};
}
oj::Cone::Cone(double r, double h, double p)
{
    radius = r;
    height = h;
    pi = p;
    setVolume(1.0/3.0 * pi * r * r * h);
}
oj::Sphere::Sphere(double r, double p)
{
    radius = r;
    pi = p;
    setVolume(4.0/3.0 * pi * r * r * r);
}
oj::Cuboid::Cuboid(double l, double w, double h){
    length = l;
    width = w;
    height = h;
    setVolume(l * w * h);
}
oj::Cube::Cube(double a):Cuboid(a, a, a){
    setVolume(a * a * a);
}
#endif
