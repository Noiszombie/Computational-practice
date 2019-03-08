#include "powerMethod.h"



powerMethod::powerMethod(double **matrix, unsigned int size)
{
	this->size = size;
	A = new double *[this->size];
	x = new double[this->size];
	srand(this->size);
	for (unsigned int i = 0; i < size; i++)
		A[i] = new double[this->size];
	for (unsigned int i = 0; i < this->size; i++)
		for (unsigned int j = 0; j < this->size; j++)
			A[i][j] = matrix[i][j];
}


void powerMethod::calc(unsigned int iterationNum)
{
	double normVect = 0.0;
	double normMat = 0.0;
	double **matrix = new double*[this->size];
	for (unsigned int i = 0; i < this->size; i++)
		matrix[i] = new double[this->size];
	for (unsigned int i = 0; i < this->size; i++)
	{
		for (unsigned int j = 0; j < this->size; j++)
			matrix[i][j] = 0.0;
		matrix[i][i] = 1.0;
	}

	for (unsigned int i = 0; i < this->size; i++)
	{
		x[i] = i;
	}
	/// Maximum eigenvlaue calculation///
	for (unsigned int i = 0; i < iterationNum; i++)
	{
		normVect = this->vectorEuclideanNorm(x, this->size);
		x = scalarVectorMul(x, 1.0 / normVect, this->size);
		x = matrixVectorMul(A, x, this->size);
	}
	maxEigenvalue = vectorEuclideanNorm(x, this->size);
	std::cout << maxEigenvalue << "Max eigen vlaue" << std::endl;

	double **mem = new double*[this->size];
	for (unsigned int i = 0; i < this->size; i++)
	{
		mem[i] = new double[this->size];
		x[i] = i;
	}

	normMat = matrixInfNorm(A, this->size);
	matrix = matrixSub(scalarMatrixMul(matrix, normMat, this->size), A, this->size);
	for (unsigned int i = 0; i < iterationNum; i++)
	{
		normVect = this->vectorEuclideanNorm(x, this->size);
		x = scalarVectorMul(x, 1.0 / normVect, this->size);
		x = matrixVectorMul(matrix, x, this->size);
	}
	normVect = this->vectorEuclideanNorm(x, this->size);
	minEigenvalue = normMat - normVect;
	std::cout << minEigenvalue << "Min eigen vlaue" << std::endl;
}


powerMethod::~powerMethod()
{
}


double powerMethod::vectorEuclideanNorm(double *vector, unsigned int size)
{
	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += vector[i] * vector[i]; 
	}
	return sqrt(sum);
}


double powerMethod::matrixInfNorm(double **matrix, unsigned int size)
{
	double max = 0.0;
	double mem;
	for (unsigned int i = 0; i < size; i++)
	{
		mem = 0.0;
		for (unsigned int j = 0; j < size; j++)
			mem += abs(matrix[i][j]);
		if (mem > max)
			max = mem;
	}
	return max;
}


double **powerMethod::matrixMul(double **matrix1, double **matrix2, unsigned int size)
{
	double ** result = new double*[size];

	for (unsigned int i = 0; i < size; i++)
		result[i] = new double[size];

	for (unsigned int i = 0; i < size; i++)
	{
		for (unsigned int j = 0; j < size; j++)
		{
			result[i][j] = 0.0;
			for (unsigned int k = 0; k < size; k++)
			{
				result[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
	return result;
}


double *powerMethod::matrixVectorMul(double **matrix, double *vector, unsigned int size)
{
	double *result = new double[size];
	for (unsigned int i = 0; i < size; i++)
	{
		result[i] = 0.0;
		for (unsigned int j = 0; j < size; j++)
		{
			result[i] += matrix[i][j] * vector[j];
		}
	}
	return result;
}


double **powerMethod::matrixSub(double **matrix1, double **matrix2, unsigned int size)
{
	double **result = new double*[size];
	for (unsigned int i = 0; i < size; i++)
		result[i] = new double[size];
	for (unsigned int i = 0; i < size; i++)
	{
		for (unsigned int j = 0; j < size; j++)
		{
			result[i][j] = matrix1[i][j] - matrix2[i][j];
		}
	}
	return result;
}


double **powerMethod::scalarMatrixMul(double **matrix, double scalar, unsigned int size)
{
	for (unsigned int i = 0; i < size; i++)
		for (unsigned int j = 0; j < size; j++)
			matrix[i][j] *= scalar;
	return matrix;
}


double *powerMethod::scalarVectorMul(double *vector, double scalar, unsigned int size)
{
	for (unsigned int i = 0; i < size; i++)
		vector[i] *= scalar;
	return vector;
}