#include "cjheader.h"


using namespace std;
int currCase = 0;
int t;

/*
 * Global variables that are needed should be declared here
 */


/**********************************************************/



/*bool decreasing(unsigned long int n){
	int prev = 9;
	while(n){
		int curr = n % 10;
		n /= 10;
		if(curr > prev)
			return true;
		prev = curr;
	}
	return false;
}*/



void makeNonDecreasing(vector<int> *n){
	if(n->size() == 1)
		return;

	int prev = 0;
	for(int i = 0; i < n->size(); ++i){
		if(n->at(i) < prev){
			n->at(i - 1)--;
			for(int j = i; j < n->size(); ++j){
				n->at(j) = 9;
			}
			makeNonDecreasing(n);
		}
		prev = n->at(i);
	}
	return;
}

void runTestCase(){
	printf("Case #%d: ", ++currCase);
	string s;
	cin >> s;

	vector<int> p;

	for(int i = 0; i < s.length(); ++i){
		p.push_back((int)(s.at(i) - '0'));
	}
	makeNonDecreasing(&p);

	bool start = true;
	for(int i = 0; i < p.size(); ++i){
		if(start && p.at(i) == 0){}
		else if(start && p.at(i) != 0){
			start = false;
			cout << p.at(i);
		}else{ cout << p.at(i); }

	}
	cout << "\n";

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

