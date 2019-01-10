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

pair<unsigned long long, unsigned long long> reduce(unsigned long long p, unsigned long long q){

	pair<unsigned long long, unsigned long long> frac;
	frac.first = (p / gcd(p, q));
	frac.second = (q / gcd(p, q));
	return frac;
}

bool isPowerOfTwo(unsigned long long x){
	return (x & (x - 1)) == 0;
}

void runTestCase(){
	printf("Case #%d: ", ++currCase);
	unsigned long long p;
	unsigned long long q;

	int temp = scanf("%llu/%llu", &p, &q);


	pair<unsigned long long, unsigned long long> reduced = reduce(p, q);

	p = reduced.first;
	q = reduced.second;
	//cout << "p = " << p << "  q = " << q << endl;

	if(!isPowerOfTwo(q)){
		printf("impossible\n");
		return;
	}

	int x = log2(q);

	if(x > 40){
		printf("impossible\n");
		return;
	}

	int min = x - floor(log2(p));

	printf("%d\n", min);
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
