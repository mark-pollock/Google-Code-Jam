#include "cjheader.h"


using namespace std;
int currCase = 0;
int t;

/*
 * Global variables that are needed should be declared here
 */


/**********************************************************/

void runTestCase(){
	printf("Case #%d: ", ++currCase);
	double t = 100000000000;
	double t1 = 0;
	double t2 = 0;

	double c, f, x;
	cin >> c;
	cin >> f;
	cin >> x;

	int bestN = -1;


	for(int n = 0; n < 100000; ++n){
		if(n == 0)
			t1 = 0;
		else if(n == 1){
			t1 += c / 2.0;
		}else{
			t1 += c / (2.0 + (n-1)*f);
		}

		t2 = x / (2 + n*f);
		if(t1 + t2 < t){
			bestN = n;
			t = t1 + t2;
		}else{
			break;
		}


	}



	printf("%f\n", t);

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
