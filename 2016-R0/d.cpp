#include "cjheader.h"


using namespace std;
int currCase = 0;
int t;

/*
 * Global variables that are needed should be declared here
 */


/**********************************************************/

void runTestCase(){
	printf("Case #%d:", ++currCase);
	unsigned long long k;
	unsigned long long c;
	unsigned long long s;
	cin >> k;
	cin >> c;
	cin >> s;

	for(int i = 0; i < k; ++i){
		cout << " " << (unsigned long long)(1 + i*pow(k, c-1));
		//printf(" %u", (unsigned long long)(1 + i*pow(k, c-1)));
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
