#pragma once
#include <cstdlib>
#include <iostream>
#ifndef valid_reg
#define valid_reg

class validRegion
{
public:
	validRegion(unsigned int);
	~validRegion();
	unsigned int getSize();
	char **visualization();
private:
	char **visImpMatrix;
	int size;
};

#endif