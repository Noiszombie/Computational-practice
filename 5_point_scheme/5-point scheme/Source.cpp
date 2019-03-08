#include <iostream>
#include <cstdlib>
#include "validRegion.h"
#include "checkSolution.h"
#include "interiorPoints.h"
#include "powerMethod.h"
#include <math.h>
#include "data.h"

using namespace std;

int main() {
	validRegion check(steps);
	char **plot = check.visualization();
	interiorPoints inter(plot, steps);
	double **matrix = inter.interiorSearch(plot, steps);
	powerMethod powMeth(matrix, steps);
	powMeth.calc(15);
	system("pause>0");
	return 0;
}