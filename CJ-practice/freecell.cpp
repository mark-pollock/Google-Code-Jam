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
	int pd;
	int pg;
	long n;

	cin >> n;
	cin >> pd;
	cin >> pg;

	pair<int, int> redFrac = reduce(pg, 100);

	long x;
	int A = redFrac.first;
	int B = redFrac.second;

	bool found = false;
	int MAXA = 10000000;
	for(int a = 1; a < MAXA; ++a){
		for(long d = 1; d <= n; ++d){
			double factor = pd*0.01*d;
			int factorint = (int)factor;
			if(factor - factorint > 0.000000000000001 || factor - factorint < -0.000000000000001){
				continue;
			}
			//cout << "a = " << a << endl;
			//cout << "d = " << d << endl;
			long x = a*A - pd*0.01*d;
			//cout << "x = " << x << endl;
			long y = a*B;
			//cout << "y = " << y << endl;
			if(x <= y && x >= 0 && y >= d && ((x / y) == (A / B))){
				found = true;
				break;
			}
		}
		if(found)
			break;
	}

	if(found)
		printf("Possible\n");
	else
		printf("Broken\n");

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
