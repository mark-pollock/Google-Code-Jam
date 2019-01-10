#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <utility>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstring>
#include <assert.h>
#include <math.h>
#include <random>
#include <iomanip>

using namespace std;
int currCase = 0;

/*
 * Global variables that are needed should be declared here
 */


/**********************************************************/


void runTestCase(){

}

void setUp(){

	return;
}
void swap(int *a, int k, int p){
	int temp = a[k];
	a[k] = a[p];
	a[p] = temp;
	return;
}

int main(int argc, char *argv[]){

	const int NPERMS = 1000000;
	int n = 1000;
	int bData[n][n];

	default_random_engine generator;
	uniform_int_distribution<int> baddistribution(0, n - 1);

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			bData[i][j] = 0;
		}
	}
	int bPerm[n];

	for(int count = 0; count < NPERMS; ++count){


		for(int i = 0; i < n; ++i){
			bPerm[i] = i;
		}

		for(int k = 0; k < n; ++k){
			int p = baddistribution(generator);
			swap(bPerm, k, p);
		}
		for(int i = 0; i < n; ++i){
			bData[bPerm[i]][i]++;
		}

	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			double p = ((double)bData[i][j] * (double)n)/((double)NPERMS);
			cout << setprecision(15) << p << endl;
		}
	}

	return 0;

}
