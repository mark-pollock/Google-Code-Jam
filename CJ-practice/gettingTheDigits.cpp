#include "cjheader.h"


using namespace std;
int currCase = 0;
int t;

/*
 * Global variables that are needed should be declared here
 */
vector<int> zero;
vector<int> one;
vector<int> two;
vector<int> three;
vector<int> four;
vector<int> five;
vector<int> six;
vector<int> seven;
vector<int> eight;
vector<int> nine;




/**********************************************************/

void runTestCase(){
	printf("Case #%d: ", ++currCase);

	string s;
	cin >> s;
	int letCounts[100] = {};

	int n[10] = {};



	int length = s.length();
	for(int i = 0; i < length; ++i){
		letCounts[s[i]]++;
	}


	while(letCounts['G'] != 0){

		n[8]++;
		for(auto it = eight.begin(); it != eight.end(); ++it){
			letCounts[*it]--;
		}
	}
	while(letCounts['Z'] != 0){
			n[0]++;
			for(auto it = zero.begin(); it != zero.end(); ++it){
				letCounts[*it]--;
			}
	}
	while(letCounts['W'] != 0){
			n[2]++;
			for(auto it = two.begin(); it != two.end(); ++it){
				letCounts[*it]--;
			}
	}
	while(letCounts['U'] != 0){
			n[4]++;
			for(auto it = four.begin(); it != four.end(); ++it){
				letCounts[*it]--;
			}
	}
	while(letCounts['X'] != 0){
			n[6]++;
			for(auto it = six.begin(); it != six.end(); ++it){
				letCounts[*it]--;
			}
	}
	while(letCounts['F'] != 0){
			n[5]++;
			for(auto it = five.begin(); it != five.end(); ++it){
				letCounts[*it]--;
			}
	}
	while(letCounts['V'] != 0){
			n[7]++;
			for(auto it = seven.begin(); it != seven.end(); ++it){
				letCounts[*it]--;
			}
	}
	while(letCounts['I'] != 0){
			n[9]++;
			for(auto it = nine.begin(); it != nine.end(); ++it){
				letCounts[*it]--;
			}
	}
	while(letCounts['H'] != 0){
			n[3]++;
			for(auto it = three.begin(); it != three.end(); ++it){
				letCounts[*it]--;
			}
	}
	while(letCounts['O'] != 0){
			n[1]++;
			for(auto it = one.begin(); it != one.end(); ++it){
				letCounts[*it]--;
			}
	}


	for(int i = 0; i < 10; ++i){
		while(n[i] != 0){
			cout << i;
			n[i]--;
		}
	}

	printf("\n");

	return;
}

void setUp(){

	zero.push_back('Z');
	zero.push_back('E');
	zero.push_back('R');
	zero.push_back('O');

	one.push_back('O');
	one.push_back('N');
	one.push_back('E');

	two.push_back('T');
	two.push_back('W');
	two.push_back('O');

	three.push_back('T');
	three.push_back('H');
	three.push_back('R');
	three.push_back('E');
	three.push_back('E');

	four.push_back('F');
	four.push_back('O');
	four.push_back('U');
	four.push_back('R');

	five.push_back('F');
	five.push_back('I');
	five.push_back('V');
	five.push_back('E');

	six.push_back('S');
	six.push_back('I');
	six.push_back('X');

	seven.push_back('S');
	seven.push_back('E');
	seven.push_back('V');
	seven.push_back('E');
	seven.push_back('N');

	eight.push_back('E');
	eight.push_back('I');
	eight.push_back('G');
	eight.push_back('H');
	eight.push_back('T');

	nine.push_back('N');
	nine.push_back('I');
	nine.push_back('N');
	nine.push_back('E');
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
