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
	int n, k;
	cin >> n;
	cin >> k;
	int r[n];
	int h[n];
	int order[n];
	for(int i = 0; i < n; ++i){
		order[i] = i;
	}
	for(int i = 0; i < n; ++i){
		cin >> r[i];
		cin >> h[i];
	}
	double pi = 3.1415926535897932384626433832795028841971693993751058;


	double SA = 0;
	do{
		int lastR = 10^6;
		bool possible = true;
		for(int i = 0; i < k; ++i){
			int index = order[i];
			if(r[index] > lastR){
				possible = false;
			}
		}
		if(possible){
			double currSA = pi*r[order[0]]*r[order[0]];

			for(int i = 0; i < k; ++i){
				int index = order[i];
				currSA += 2*pi*r[index]*h[index];
			}

			if(currSA > SA){
				SA = currSA;
			}
		}


	}while(next_permutation(order, order + n));


	cout << SA << endl;

	//printf("%d\n", result);

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
