#include "cjheader.h"


using namespace std;
int currCase = 0;
int t;

/*
 * Global variables that are needed should be declared here
 */


/**********************************************************/

bool decreasing(unsigned long int n){
	int prev = 9;
	while(n){
		int curr = n % 10;
		n /= 10;
		if(curr > prev)
			return true;
		prev = curr;
	}
	return false;
}

void runTestCase(){
	printf("Case #%d: ", ++currCase);

	unsigned long int n;
	cin >> n;

	while(decreasing(n)){
		n--;
	}
	cout << n << "\n";
	//printf("%d\n", n);
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
