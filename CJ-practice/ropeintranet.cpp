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


	int n;
	cin >> n;

	vector<pair<int, int>> wires;

	int ints = 0;
	for(int i = 0; i < n; ++i){
		int a;
		int b;
		cin >> a;
		cin >> b;

		for(int j = 0; j < wires.size(); ++j){
			if(wires[j].first > a && wires[j].second < b)
				ints++;
			else if(wires[j].first < a && wires[j].second > b)
				ints++;


		}
		pair<int, int> p(a, b);
		wires.push_back(p);

	}

	printf("%d\n", ints);

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
