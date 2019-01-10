#include "cjheader.h"

#include <bitset>



using namespace std;
int currCase = 0;
int t;

const int LENGTH = 32;

/*
 * Global variables that are needed should be declared here
 */


/**********************************************************/


int getFactor(unsigned long long a, int b, int length){
	string s = bitset< LENGTH >( a ).to_string();
	unsigned long long num = 0;
	for(int pos = 0; pos < length; ++pos){
		if(s.at(length - pos - 1) == '1'){
			num += pow(b, pos);
		}
	}

	if(num % 2 == 0)
		return 2;
	for(int i = 3; i <= sqrt(num); i = i+2){
		if(num % i == 0){
			return i;
		}

	}
	return 0;
}


unsigned long long increaseNum(unsigned long long n2){
	int pos = 0;

	string s1 = bitset< LENGTH >( n2 ).to_string();
	unsigned long long n = stoull(s1);
	unsigned long long num = 0;
	while(n >= 1){
		int temp = n % 10;
		if(temp == 1){
			num += pow(2, pos);
		}
		n = n / 10;
		pos++;
	}


	// we now have the number in base 2.
	num += 2;
	// need to convert back to base 10.

	return num;

}

void runTestCase(){
	printf("Case #%d:\n", ++currCase);


	int j, n;
	cin >> n;
	cin >> j;

	int count = 0;

	int factors[11] = {0};

	bool found = true;

	int num = pow(2, n - 1) + 1; // = 100...001


	//num = 49;
	while(num < pow(2, n)){ // = 111111..11
		//cout << "num = " << num << endl;
		for(int i = 2; i < 11; ++i){
			int factor = getFactor(num, i, n);
			if(factor > 1){
				factors[i] = factor;
			}else{
				found = false;
				break;
			}
		}
		if(found == true){
			string s = bitset< LENGTH >( num ).to_string();

			cout << s;
			for(int i = 2; i < 11; ++i){
				printf(" %d", factors[i]);
			}
			printf("\n");
			count++;
			if(count >= j)
				break;
		}else{
			found = true;
		}

		//return;
		num = increaseNum(num);


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
