#include "interiorPoints.h"
#include <iostream>
#include "data.h"

interiorPoints::interiorPoints(char **visual, unsigned int size)
{
	neighbourHood = new int *[size];
	int step = 1;
	for (int i = 0; i < size; i++)
	{
		neighbourHood[i] = new int[size];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			neighbourHood[i][j] = 0;
			if (visual[i][j] == '+')
			{
				neighbourHood[i][j] = step;
				step++;
			}
		}
	}
	std::cout << step-1 << " step" << std::endl;
	this->size = step-1;
}

double **interiorPoints::interiorSearch(char **visual,  unsigned int size)
{
	// this->size - number of interior points
	// size - number of web points
	A = new double *[this->size];
	u = new double[this->size];
	f = new double[this->size];
	for (int i = 0; i < this->size; i++)
	{
		A[i] = new double[this->size];
	}
	int step = 0;
	for(int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			if (neighbourHood[i][j] != 0)
			{
				step = neighbourHood[i][j] - 1;
				for (int k = 0; k < this->size; k++)
				{
					A[step][k] = 0.0;
					if (step == k)
					{
						A[step][step] = R;
						f[step] = f(i*h, j*h);
					}
					if (neighbourHood[i][j - 1] != 0 && j > 0)
						A[step][neighbourHood[i][j - 1] - 1] = S;
					if (neighbourHood[i][j + 1] != 0 && j < size-1)
						A[step][neighbourHood[i][j + 1] - 1] = S;
					if (neighbourHood[i - 1][j] != 0 && i > 0)
						A[step][neighbourHood[i - 1][j] - 1] = T;
					if (neighbourHood[i + 1][j] != 0 && i < size - 1)
						A[step][neighbourHood[i + 1][j] - 1] = T;
				}
			}
		}

	return A;
}


interiorPoints::~interiorPoints()
{
}
