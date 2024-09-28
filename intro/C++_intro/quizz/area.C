// Library
// .H files
#include<iostream>
class rect
{
   double l_;
   double h_;
   public:
   double area();
   double per();
   rect (double, double);
};

class square : public rect
{
   public:
   square(double); 
};

square::square(double a): 
rect(a,a)
{}

// .C files
rect::rect (double x, double y)
:
l_(x),
h_(y)
{}

double rect::area()
{
		return l_ * h_;
}

double rect::per()
{
		return 2 * (l_ + h_);
}

// Application/ executable
int main()
{
    rect r1(1,2);
	std::cout << "Rectangle area = "<< r1.area() << std::endl;
	std::cout << "Rectangle per = " << r1.per() << std::endl;

    square s1(2);
	std::cout << "square area = " << s1.area() << std::endl;
	std::cout << "square per = " << s1.per() << std::endl;
}
