#include "cjheader.h"


using namespace std;
int currCase = 0;
int t;

/*
 * Global variables that are needed should be declared here
 */
int vecHas(vector<char>& v, char k){
	for(int i = 0; i < v.size(); ++i){
		if(v[i] == k)
			return i;
	}
	return -1;
}

/**********************************************************/

void runTestCase(){
	printf("Case #%d: ", ++currCase);
	int k, l, s;
	cin >> k;
	cin >> l;
	cin >> s;

	string monkey;
	cin >> monkey;

	string target;
	cin >> target;

	vector<char> monk;
	vector<int> occurences;
	for(int i = 0; i < k; ++i){
		if(vecHas(monk, monkey[i]) == -1){
			monk.push_back(monkey[i]);
			occurences.push_back(1);
		}else{
			occurences[vecHas(monk, monkey[i])]++;
		}
	}

	vector<int> letterProbs;
	for(int i = 0; i < occurences.size(); ++i){
		letterProbs.push_back(occurences[i] / k);
	}



	printf("%d\n", result);

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
