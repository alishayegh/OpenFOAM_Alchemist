// Library
// .H files
#include<iostream>
class circle
{
   double d_;
   public:
   double area();
   double per();
   circle (double);
};

// .C files
circle::circle (double x)
:
d_(x)
{}

double circle::area()
{
		return 3.14 * d_* d_/4;
}

double circle::per()
{
		return 3.14 * d_;
}

// Application/ executable
int main()
{
    circle c1(1);
	std::cout << c1.area() << std::endl;
	std::cout << c1.per() << std::endl;
}
