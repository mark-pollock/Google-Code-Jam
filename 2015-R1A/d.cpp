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

using namespace std;
int currCase = 0;

/*
 * Global variables that are needed should be declared here
 */


/**********************************************************/


void runTestCase(){
	printf("Case #%d: ", ++currCase);


	int x;
	int r;
	int c;

	assert(scanf("%d", &x) == 1);
	assert(scanf("%d", &r) == 1);
	assert(scanf("%d", &c) == 1);

	if(x == 1){
		printf("GABRIEL");
	}else if(x == 4){
		if(r < 3){
			printf("RICHARD");
		}else if(r == 3 && c < 4){
			printf("RICHARD");
		}else if(r == 3 && c == 4){
			printf("GABRIEL");
		}else if(r == 4 && c == 1){
			printf("RICHARD");
		}else if(r == 4 && c == 2){
			printf("RICHARD");
		}else{
			assert(r == 4 && c > 2);
			printf("GABRIEL");
		}
	}else if(x == 3){
		if (r == 1){
			printf("RICHARD");
		}else if(r == 2){
			if(c < 3){
				printf("RICHARD");
			}else if(c == 3){
				printf("GABRIEL");
			}else{
				assert(c == 4);
				printf("RICHARD");
			}
		}else if(r == 3){
			if(c == 1){
				printf("RICHARD");
			}else{
				printf("GABRIEL");
			}
		}else{
			assert(r == 4);
			if(c < 3){
				printf("RICHARD");
			}else if(c == 3){
				printf("GABRIEL");
			}else{
				assert(c == 4);
				printf("RICHARD");
			}
		}
	}else{
		assert(x == 2);
		if(r == 1){
			if(c == 1 || c == 3){
				printf("RICHARD");
			}else{
				assert(c == 2 || c == 4);
				printf("GABRIEL");
			}
		}else if(r == 2){
			printf("GABRIEL");
		}else if(r == 3){
			if(c == 1 || c == 3){
				printf("RICHARD");
			}else{
				assert(c == 2 || c == 4);
				printf("GABRIEL");
			}
		}else{
			assert(r == 4);
			printf("GABRIEL");
		}
	}

	printf("\n");
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
