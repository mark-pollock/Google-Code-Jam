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

unsigned long long gcd(unsigned long long x, unsigned long long y){

	unsigned long long c = x % y;
	while(c != 0){
		x = y;
		y = c;
		c = x % y;
	}
	return y;
}

unsigned long long lcmnum(unsigned long long a, unsigned long long b){
	return (a*b) / gcd(a, b);
}
unsigned long long lcm(int a[], int n, int i){

	if(n == i + 2)
		return lcmnum(a[i], a[n - 1]);
	else{
		i++;
		//printf("i = %d\n", i);
		//printf("n = %d\n", n);
		//printf("a[%d] = %d\n", i - 1, a[i - 1]);
		return lcmnum(a[i - 1], lcm(a, n, i));
	}

}


void runTestCase(){
	printf("Case #%d: ", ++currCase);

	int b;
	unsigned long long nl;

	assert(scanf("%d %llu", &b, &nl) == 2);

	int mk[b];
	for(int i = 0; i < b; ++i){
		assert(scanf("%d", &mk[i]) == 1);
	}
	if(nl <= b){
		printf("%llu\n", nl);
		return;
	}

	int barb;
	unsigned long long leastCM;
	if(b == 2){
		leastCM = lcmnum(mk[0], mk[1]);
	}else if(b == 1){
		leastCM = mk[0];
	}else{
		leastCM = lcm(&mk[0], b, 0);
	}

	int peopleInRound = 0;
	for(int i = 0; i < b; ++i){
		peopleInRound += leastCM / mk[i];
	}
	if(nl > peopleInRound)
		nl = nl % peopleInRound;

	if(nl == 0){
		nl = peopleInRound;
	}
	int n = (int)(nl);
	//printf("n = %d", n);

	if(b >= n){
		printf("%d\n", n);

		return;
	}
	int person = 1;
	person += b;

	for(int min = 1; min > 0; min++){

		int numBarbsAv = 0;
		for(int i = 0; i < b; ++i){
			//printf("min = %d    mk[%d] = %d \n", min, i, mk[i]);
			int num = mk[i];
			if(min % num == 0){
				numBarbsAv++;
			}
			if(n - person - numBarbsAv < 0){
				// we can get this barber
				barb = i + 1;
				printf("%d\n", barb);
				return;
			}
		}
		person += numBarbsAv;
	}

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
