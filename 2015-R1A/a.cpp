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
#include <array>

using namespace std;
int currCase = 0;

/*
 * Global variables that are needed should be declared here
 */


/**********************************************************/

void runTestCase(){
	printf("Case #%d: ", ++currCase);

	int n;
	assert(scanf("%d", &n) >= 1);

	int m1 = 0;

	int prevElem = 10001;
	int mushrooms[n];
	int maxDiff = 0;
	for(int i = 0; i < n; ++i){

		int elem;
		assert(scanf("%d", &elem) >= 1);
		mushrooms[i] = elem;

		if(prevElem == 10001){
			prevElem = elem;
			continue;
		}

		int diff = prevElem - elem;
		if(diff > 0){
			m1 += diff;
			if(diff > maxDiff){
				maxDiff = diff;
			}
		}

		prevElem = elem;
	}
	int m2 = 0;
	for(int i = 0; i < n - 1; ++i){
		if(mushrooms[i] >= maxDiff)
			m2 += maxDiff;
		else
			m2 += mushrooms[i];
	}



	printf("%d %d\n", m1, m2);
	return;
}

void setUp(){

	return;
}

int main(){
	setUp();

	int t;


	assert(scanf("%d", &t) == 1);

	while(t > 0){

		runTestCase();
		t--;
	}

	return 0;
}
