#include "data.h"
#ifndef interior_points
#define interior_points
class interiorPoints
{
public:
	interiorPoints(char **, unsigned int);
	~interiorPoints();
	double **interiorSearch(char **, unsigned int);
	unsigned int getSize();
private:
	double **A;
	int **neighbourHood;
	double *u;
	double *f;
	unsigned int size;
};

#endif