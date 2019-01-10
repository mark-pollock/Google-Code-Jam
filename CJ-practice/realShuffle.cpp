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

		double bProb[n][n];
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				bProb[i][j] = 0;
			}
		}
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				assert(scanf("%lf", &bProb[i][j]) >= 1);
			}
		}


		int t;
		assert(scanf("%d", &t) >= 1);
		assert(t == 120);


		int bad_c = 0;
		for(int i = 0; i < t; ++i){
			assert(scanf("%d", &n) >= 1);
			assert(n == 1000);
			double s = 1;
			for(int j = 0; j < n; ++j){
				int elem;
				assert(scanf("%d", &elem) >= 1);
				if(bProb[elem][j] == 0){
					bProb[elem][j] = 0.00000001;
				}
				s *= bProb[elem][j];
			}

			if(s > 1){
				printf("Case #%d: BAD\n", i + 1);
				bad_c++;
			}else
				printf("Case #%d: GOOD\n", i + 1);
		}
		cerr << "bad_c = " << bad_c << endl;
	return 0;

}
