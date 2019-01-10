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
	int m;
	int p;
	assert(scanf("%d %d %d", &n, &m, &p) > 1);

	int s = 0;

	if(p < 5){
		printf("%d\n", p);
		return;
	}else if(n == 1 || m == 1){
		printf("%d\n", p);
		return;
	}else if(n == 2 || m == 2){
		printf("%d\n", p);
		return;
	}

	if(p >= n*m - 4){
		s = 2*(n-2) + 2*(m-2) + p - (n*m - 4);
		printf("%d\n", s);
		return;
	}

	int h = 0;
	int w = 0;
	while(p > s + h + w + h*w){
		if(h < (n - 2)){
			h++;
			s++;
		}
		if(p <= s + h + w + h*w){
			break;
		}

		if(w < (m - 2)){
			w++;
			s++;
		}
	}


	int diff = (s + h + w + h*w) - p;
	//printf("diff = %d\n", diff);
	diff = diff / 2;
	//printf("diff2 = %d\n", diff);
	//assert(diff <= 4);
	//if(diff > 4)
		//diff = 4;
	s = 2*s;
	s -= diff;
	printf("%d\n", s);
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
