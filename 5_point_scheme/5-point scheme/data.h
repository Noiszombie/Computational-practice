#include <math.h>
#define steps 11
#define eps 0.000001
#define h  (double)1/(steps-1)
#define f(x, y) (sin(x)*sin(y*y)*(0.7+4.4*y*y)-2.2*sin(x)*cos(y*y))
#define phi(x, y) sin(x)*sin(y*y)
#define a 0.7
#define b 1.1
#define u(x, y) -a*(-1*sin(x)*sin(y*y))-b*(sin(x)*(-1*sin(y*y)*4*y*y+2*cos(y*y)))
#define R (double)(-2*(-a-b)/(h*h))
#define S (double)(-b/(h*h))
#define T (double)(-a/(h*h))
