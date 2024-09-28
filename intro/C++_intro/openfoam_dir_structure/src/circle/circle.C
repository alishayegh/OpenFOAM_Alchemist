#include"circle.H"
double circle::area()
{
    return 3.14 * d_ * d_ / 4;
}

circle::circle(double d)
{
    d_ = d;
}
