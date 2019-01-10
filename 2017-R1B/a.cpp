#include "cjheader.h"
#include <iomanip>


using namespace std;
int currCase = 0;
int t;

/*
 * Global variables that are needed should be declared here
 */


/**********************************************************/

void runTestCase(){
	printf("Case #%d: ", ++currCase);
	long int d, n;
	cin >> d;
	cin >> n;
	double maxTime;
	maxTime = 0;
	for(int i = 0; i < n; ++i){
		long int k, s;
		cin >> k;
		cin >> s;

		double time = ((double)(d - k)) / ((double) s);
		maxTime = max(time, maxTime);
	}

	double result;
	result = (double) d / maxTime;
	cout << fixed;
	cout << setprecision(10);

	cout << result << "\n";


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
