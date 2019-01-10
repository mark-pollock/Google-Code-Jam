#include "cjheader.h"


using namespace std;
int currCase = 0;
int t;

/*
 * Global variables that are needed should be declared here
 */


/**********************************************************/
int nChoosek(int n, int k)
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

bool liesInPyramid(int x, int y, int k){
	if(!(x > -k && x < k && y < k))
		return false;

	if(y > (k - 1 - abs(x)))
		return false;

	return true;
}
void runTestCase(){
	printf("Case #%d: ", ++currCase);
	int n, x, y;
	cin >> n;
	cin >> x;
	cin >> y;


	int k = floor((-1.0 + sqrt(1 + 8*n)) / 2.0);
	int kCeil = ceil((-1.0 + sqrt(1 + 8*n)) / 2.0);
	if(k % 2 == 0)
		k--;
	if(kCeil % 2 == 0)
		kCeil++;
	if (kCeil == k){
		// perfect pyramid

		if(liesInPyramid(x, y, k)){
			printf("1.0\n");
			return;
		}else{
			printf("0.0\n");
			return;
		}
	}
	assert(kCeil == k + 2);

	if(!liesInPyramid(x, y, kCeil)){
		// Doesn't lie in next pyramid
		printf("0.0\n");
		return;
	}
	if(y >= (kCeil - 1)){
		printf("0.0\n");
		return;
	}

	if(liesInPyramid(x, y, k)){
		printf("1.0\n");
		return;
	}
	int diams = n - (k*(k + 1)) / 2;


	int diamsNeededToFallOnOneSide = y + 1;

	double prob = 0;
	for(int i = 0; i < diamsNeededToFallOnOneSide; ++i){
		prob += nChoosek(diams, i) * pow(0.5, i) * pow(0.5, diams - i);
	}
	prob = 1- prob;
	//double prob = nChoosek(diams, diamsNeededToFallOnOneSide) * pow(0.5, diams);

	//cout << "n = " << n << ", diams = " << diams << ", k = " << k << ", diamsNeededToFallOnOneSide = " << diamsNeededToFallOnOneSide << ", prob = " << prob << endl;

	//cout << "k = " << k << endl;
	printf("%f\n", prob);

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
