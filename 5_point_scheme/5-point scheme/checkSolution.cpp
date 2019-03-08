#include "checkSolution.h"




checkSolution::checkSolution(double x, double y, double epsilon)
{
	this->epsilon = epsilon;
	if (abs(u(x, y) - f(x, y)) < this->epsilon)
	{
		std::cout << "Function u(x, y) is a solution of differential equation" << std::endl;
	}
	else
	{
		std::cout << "Fucntion u(x, y) isn't a solution of differential equation" << std::endl;
	}
}


checkSolution::~checkSolution()
{
}
