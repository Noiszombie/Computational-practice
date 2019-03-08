#include "validRegion.h"



validRegion::validRegion(unsigned int size)
{
	try
	{
		// Value "2" is a feature of the region
		if (size % 2 == 0)
			throw -1;
	}
	catch (int x)
	{
		std::cout << "Wrong size, value must be not multiple of 2" << std::endl;
		return;
	}
	this->size = size;
	visImpMatrix = new char*[this->size];
	for (int i = 0; i < this->size; i++) {
		visImpMatrix[i] = new char[this->size];
	}
}


validRegion::~validRegion()
{
}


unsigned int validRegion::getSize()
{
	return this->size;
}

char **validRegion::visualization()
{
	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < this->size; j++)
		{
			if ((j > (int)this->size / 2) && (i > (int)this->size / 2))
			{
				std::cout << "- ";
				visImpMatrix[i][j] = '-';
			}
			else if (((j == (int) this->size/2) && (i >= (int) this->size / 2)) || ((i == (int)this->size / 2) && (j >= (int)this->size / 2)) || (j == 0 && (i <= (int)this->size / 2)) || (i == 0 && j <= (int)this->size / 2)  || (i == this->size-1 && j <= (int)this->size / 2) || (j == this->size - 1 && i <= (int)this->size / 2) || i == 0 || j == 0)
			{
				std::cout << "* ";
				visImpMatrix[i][j] = '*';
			}
			else
			{
				std::cout << "+ ";
				visImpMatrix[i][j] = '+';
			}
		}
		std::cout << std::endl;
	}
	return visImpMatrix;
}

