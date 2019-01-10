#include "cjheader.h"


using namespace std;
int currCase = 0;
int t;

/*
 * Global variables that are needed should be declared here
 */


/**********************************************************/

void runTestCase(){
	printf("Case #%d:\n", ++currCase);
	double d;
	int n, A;
	cin >> d;
	cin >> n;
	cin >> A;

	double t[n];
	double x[n];
	for(int i = 0; i < n; ++i){
		cin >> t[i];
		cin >> x[i];
	}
	double avals[A];
	for(int i = 0; i < A; ++i)
		cin >> avals[i];


	double timeCar;
	if(x[0] >= d){
		timeCar = 0; // car doesn't effect
	}else{
		int i;
		for(i = 1; i < n; ++i){
			if(x[i] >= d){
				break;
			}
		}

		if(x[i] == d){
			timeCar = t[i];
		}else{
		// will reach d between t[i - 1], t[i]
			printf("t[%d] = %f\nt[%d] = %f\nx[%d] = %f\nx[%d] = %f\n", i - 1, t[i - 1], i, t[i], i - 1, x[i - 1], i, x[i]);
			cout << "d = " << d << endl;
			timeCar = t[i - 1] + ((d - x[i - 1]) / ((x[i] - x[i - 1]) / (t[i] - t[i - 1])));
		}
	}



	for(int acount = 0; acount < A; ++acount){
		// If no car:
		double a = avals[acount];
		double timeNoCar = (sqrt(2*a*d)) / a;
		cout << "timeCar = " << timeCar << "   ;   timeNoCar = " << timeNoCar << endl;
		double result = max(timeCar, timeNoCar);
		printf("%f\n", result);
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
