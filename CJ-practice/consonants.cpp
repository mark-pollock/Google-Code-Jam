#include "cjheader.h"


using namespace std;
int currCase = 0;
int t;

/*
 * Global variables that are needed should be declared here
 */


/**********************************************************/
bool isConsonant(char c){
	if(c=='a'||c=='A'||c=='e'||c=='E'||c=='i'||c=='I'||c=='o'||c=='O'||c=='u'||c=='U')
		return false;
	else
		return true;
}


void runTestCase(){
	printf("Case #%d: ", ++currCase);



	string s;
	cin >> s;

	unsigned long long n;
	cin >> n;


	unsigned long long left = 0;
	unsigned long long total = 0;
	unsigned long long pos = 0;


	bool haveNCons = false;
	while(pos <= s.length() - n){

		if(haveNCons){
			if(isConsonant(s[pos + n - 1]))
				haveNCons = true;
			else{
				haveNCons = false;
			}
		}

		unsigned long long offset = 0;

		if(!haveNCons){
			haveNCons = true;
			for(unsigned long long i = 0; i < n; ++i){
				if(!isConsonant(s[pos + i])){
					offset = i;
					haveNCons = false;
					break;
				}
			}

		}else{
			// we have it from last time

		}

		if(haveNCons){
			unsigned long long L = pos - left;
			unsigned long long R = s.length() - (pos + n);
			total += (L + 1)*(R + 1);
			left = pos + 1;
		}

		pos += offset + 1;
	}

	printf("%llu\n", total);
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
