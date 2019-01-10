#include "cjheader.h"


using namespace std;
int currCase = 0;
int t;

/*
 * Global variables that are needed should be declared here
 */


/**********************************************************/

void flipPancakes(vector<char> *v, int startPos, int endPos){
	for(int i = startPos; i <= endPos; ++i){
		if(v->at(i) == '+')
			v->at(i) = '-';
		else
			v->at(i) = '+';
	}
}

int findFirstMinus(vector<char> *v){
	int i = 0;
	for(auto iter = v->begin(); iter != v->end(); ++iter){
		if(*iter == '-'){
			return i;
		}
		++i;
	}

	return -1;
}


void runTestCase(){
	printf("Case #%d: ", ++currCase);

	string s;
	cin >> s;

	int k;
	cin >> k;

	vector<char> p;

	for(int i = 0; i < s.length(); ++i){
		p.push_back(s.at(i));
	}
	int flips = 0;
	int startPos = findFirstMinus(&p);

	while(startPos != -1 && startPos + k <= s.size()){
		flipPancakes(&p, startPos, startPos+k - 1);
		flips++;
		startPos = findFirstMinus(&p);
	}
	if(startPos == -1)
		printf("%d\n", flips);
	else if(startPos + k > s.size())
		printf("IMPOSSIBLE\n");

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
