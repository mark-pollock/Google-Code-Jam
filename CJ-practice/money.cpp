#include "cjheader.h"


using namespace std;
int currCase = 0;
int t;

/*
 * Global variables that are needed should be declared here
 */
map<long, long> DPmap;
bool reversedOnLast;
/**********************************************************/


long P(long n){
	cout << "P(" << n << ") being calculated" << endl;
	if(n < 10)
		return n;

	if(DPmap.find(n) != DPmap.end())
		return (*DPmap.find(n)).second;



	long nextDigit;
	if(n >= 100000000000000)
		nextDigit = 1000000000000000;
	else if(n >= 10000000000000)
		nextDigit = 100000000000000;
	else if(n >= 1000000000000)
		nextDigit = 10000000000000;
	else if(n >= 100000000000)
		nextDigit = 1000000000000;
	else if(n >= 10000000000)
		nextDigit = 100000000000;
	else if(n >= 1000000000)
		nextDigit = 10000000000;
	else if(n >= 100000000)
		nextDigit = 1000000000;
	else if(n >= 10000000)
		nextDigit = 100000000;
	else if(n >= 1000000)
		nextDigit = 10000000;
	else if(n >= 100000)
		nextDigit = 1000000;
	else if(n >= 10000)
		nextDigit = 100000;
	else if(n >= 1000)
		nextDigit = 10000;
	else if(n >= 100)
		nextDigit = 1000;
	else
		nextDigit = 100;


	bool cantUseReverse = false;
	string s = to_string(n);
	reverse(s.begin(), s.end());

	if(s[0] == '0')
		cantUseReverse = true;

	long reversed = stol(s, NULL, 10);

	long temp = LONG_MAX;
	if((!reversedOnLast) && (!cantUseReverse)){
		if(reversed < nextDigit && reversed != n){
			reversedOnLast = true;
			temp = P(reversed);
		}
	}else{
		reversedOnLast = false;
	}

	long temp2 = P(n - 1);

	long result = min(temp, temp2) + 1;
	DPmap.emplace(n, result);
	return result;

}

void runTestCase(){
	printf("Case #%d: ", ++currCase);
	long n;
	cin >> n;
	reversedOnLast = false;


	printf("%ld\n", P(n));

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
