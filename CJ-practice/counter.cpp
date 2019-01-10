#include "cjheader.h"


using namespace std;
int currCase = 0;
int t;

/*
 * Global variables that are needed should be declared here
 */
long n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14;

/**********************************************************/
long findN(long n, long num){
	long count = 1;
	while(num != n){
		++count;
		string s = to_string(num);
		reverse(s.begin(), s.end());
		long rev = stol(s, NULL, 10);
		long maxnum = max(rev, num + 1);
		if(maxnum > n){
			return count + min(findN(n, num + 1), findN(n, rev));
		}else{
			num = maxnum;
		}
	}
	return count;
}

void runTestCase(){
	printf("Case #%d: ", ++currCase);
	long n;
	cin >> n;


	if(n <= 10){
		printf("%ld\n", n);
		return;
	}

	long count = 0;

	string s = to_string(n);
	int halfLength = s.size() / 2;
	if(s.size() % 2 != 0)
		halfLength++;
	string firstHalf = s.substr(0, halfLength);
	string secondHalf = s.substr(halfLength, s.size() - halfLength);

	reverse(firstHalf.begin(), firstHalf.end());

	long firstH = stol(firstHalf, NULL, 10);
	long secondH = stol(secondHalf, NULL, 10);


	if(n == 100000000000000)
		count = n14;
	else if(n == 10000000000000)
		count = n13;
	else if(n == 1000000000000)
		count = n12;
	else if(n == 100000000000)
		count = n11;
	else if(n == 10000000000)
		count = n10;
	else if(n == 1000000000)
		count = n9;
	else if(n == 100000000)
		count = n8;
	else if(n == 10000000)
		count = n7;
	else if(n == 1000000)
		count = n6;
	else if(n == 100000)
		count = n5;
	else if(n == 10000)
		count = n4;
	else if(n == 1000)
		count = n3;
	else if(n == 100)
		count = n2;
	else if(n == 10)
		count = n1;

	if(count != 0){
		printf("%ld\n", count);
		return;
	}

	int plus = 0;
	if(secondH == 0){
		n--;
		plus = 1;
		s = to_string(n);
		halfLength = s.size() / 2;
		if(s.size() % 2 != 0)
			halfLength++;
		firstHalf = s.substr(0, halfLength);
		secondHalf = s.substr(halfLength, s.size() - halfLength);

		reverse(firstHalf.begin(), firstHalf.end());

		firstH = stol(firstHalf, NULL, 10);
		secondH = stol(secondHalf, NULL, 10);
	}

	long factor;
	long size;
	if(n > 100000000000000){
		factor = n14;
		size = 100000000000000;
	}else if(n > 10000000000000){
		factor = n13;
		size = 10000000000000;
	}else if(n > 1000000000000){
		factor = n12;
		size = 1000000000000;
	}else if(n > 100000000000){
		factor = n11;
		size = 100000000000;
	}else if(n > 10000000000){
		factor = n10;
		size = 10000000000;
	}else if(n > 1000000000){
		factor = n9;
		size = 1000000000;
	}else if(n > 100000000){
		factor = n8;
		size = 100000000;
	}else if(n > 10000000){
		factor = n7;
		size = 10000000;
	}else if(n > 1000000){
		factor = n6;
		size = 1000000;
	}else if(n > 100000){
		factor = n5;
		size = 100000;
	}else if(n > 10000){
		factor = n4;
		size = 10000;
	}else if(n > 1000){
		factor = n3;
		size = 1000;
	}else if(n > 100){
		factor = n2;
		size = 100;
	}else{
		factor = n1;
		size = 10;
	}



	count = factor + plus + firstH + secondH;
	if(factor + n - size + plus < count)
		count = factor + n - size + plus;

	printf("%ld\n", count);
	return;
}

void setUp(){

	return;
}

int main(){
	setUp();

	int t;
	n1 = 10;
	n2 = 29;
	n3 = 138;
	n4 = 337;
	n5 = 1436;
	n6 = 3435;
	n7 = 14434;
	n8 = 34433;
	n9 = 144432;
	n10 = 344431;
	n11 = 1444430;
	n12 = 3444429;
	n13 = 14444428;
	n14 = 34444427;

	assert(scanf("%d", &t) == 1);

	while(t > 0){

		runTestCase();
		t--;
	}

	return 0;
}
