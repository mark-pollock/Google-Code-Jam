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
	int r, c, n;
	cin >> r;
	cin >> c;
	cin >> n;

	int n2;
	int n3;
	int black;
	if(r % 2 != 0 && c % 2 != 0){
		n2 = 0;
		black = (int)floor((r*c) / 2) + 1;
	}else{
		black = r*c / 2;
		n2 = 2;
	}
	n3 = r + c - n2 - 2;

	int unhappiness = 0;
	int left = n - black;
	cout << "left = " << left << "\n black = " << black << "\n n = " << n << "\n n2 = " << n2 << "\n n3 = " << n3 << endl;
	if(left <= 0){
		unhappiness = 0;
	}
	if(left > 0){
		unhappiness += (min(n2, left))*2;
		left -= n2;
	}
	if(left > 0){
		unhappiness += (min(n3, left))*3;
		left -= n3;
	}
	if(left > 0){
		unhappiness += left*4;
	}

	printf("%d\n", unhappiness);

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
