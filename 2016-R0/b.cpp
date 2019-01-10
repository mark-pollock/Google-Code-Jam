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

	string s;
	cin >> s;

	int changes = nUniqueChangesInCharsInString(s);
	changes--;
	int plus = 0;
	int minus = 0;
	bool lastPlus = false;
	bool lastMinus = false;

	for(int i = 0; i < s.length(); ++i){
		if(s.at(i) == '+'){
			plus++;
			lastPlus = true;
			lastMinus = false;
		}else{
			minus++;
			lastMinus = true;
			lastPlus = false;
		}
	}


	//cout << "minus = " << minus << ", plus = " << plus << endl;
	//cout << "changes = " << changes << endl;

	if(lastMinus)
		changes++;



	printf("%d\n", changes);

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
