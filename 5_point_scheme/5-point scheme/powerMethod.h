#include <math.h>
#include <stdlib.h>
#include <iostream>
class powerMethod
{
public:
	powerMethod(double **, unsigned int);
	~powerMethod();
	double vectorEuclideanNorm(double *, unsigned int);
	double matrixInfNorm(double **, unsigned int);
	double **matrixMul(double **, double **, unsigned int);
	double *matrixVectorMul(double **, double *, unsigned int);
	double **matrixSub(double **, double **, unsigned int); 
	double **scalarMatrixMul(double **, double, unsigned int);
	double *scalarVectorMul(double *, double, unsigned int);
	void calc(unsigned int); 
private:
	double **A;
	double *x;
	double maxEigenvalue;
	double minEigenvalue;
	unsigned int size;
};

