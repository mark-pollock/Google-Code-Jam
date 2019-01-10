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

	unsigned int n;
	cin >> n;

	bool digits[10];
	for(int i = 0; i < 10; ++i){
		digits[i] = false;
	}


	int count = 0;

	if(n == 0){
		printf("INSOMNIA\n");
		return;
	}


	unsigned int num;

	for(num = n; num < n*(1000000); num += n){
		unsigned int tempNum = num;
		while(tempNum >= 1){
			int tempD = tempNum % 10;
			if(digits[tempD] == false){
				digits[tempD] = true;
				count++;
			}
			tempNum = tempNum / 10;
		}
		if(count >= 10){
			break;
		}
	}

	if(num >= n*(1000000)){
		printf("INSOMNIA\n");
		printf("num = %d\n n = %d\n", num, n);
	}else{
		printf("%d\n", num);
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
