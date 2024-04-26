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
    this->radius = r;
    this->height = h;
    this->pi = p;
	if(r<=0 || h<=0 || p<=0){
		setVolume(0);
	}else{
		setVolume(1.0/3.0 * pi * r * r * h);
	}
}
oj::Sphere::Sphere(double r, double p)
{
    this->radius = r;
    this->pi = p;
	if(r<=0 || p<=0){
		setVolume(0);
	}else{
    	setVolume(4.0/3.0 * pi * r * r * r);
	}
}
oj::Cuboid::Cuboid(double l, double w, double h){
    this->length = l;
    this->width = w;
    this->height = h;
	if(l<=0 || w<=0 || h<=0){
		setVolume(0);
	}else{
    	setVolume(l * w * h);
	}
}
oj::Cube::Cube(double a):Cuboid(a, a, a){
	//containing a cuboid with length, width, height all equal to a
    //calling a constructor of the base class with parameters a, a, a
	if(a<=0){
		setVolume(0);
	}else{
		setVolume(a * a * a);
	}
}
#endif
