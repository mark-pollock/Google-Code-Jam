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
	string r, t;
	cin >> r;
	cin >> t;

	string two = "2";
	BigInteger a;

	string n = mulLarge(tw

	long long n = ((1 - 2*r) + sqrt(pow(2*r - 1, 2) + 8*t)) / 4;
	//n += sqrt(pow(2*r - 1, 2) + 8*t);
	//n /= 4;


	long long tCheck = 2 * pow(n, 2) + (2*r - 1)*n;
	if (tCheck > t)
		n--;
	printf("%llu\n", n);

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
