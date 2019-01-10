/*
 * LessMoneyMoreProblems.cpp
 *
 *  Created on: 4 Apr 2016
 *      Author: root
 */


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

	vector<int> Porig;// = new vector<int>();
	int D;

	cin >> D;
	int maxP = 0;
	for(int i = 0; i < D; ++i){
		int temp;
		cin >> temp;
		if(temp > maxP)
			maxP = temp;
		Porig.push_back(temp);
	}


	int bestX = 0;
	int bestVal = 1002;
	for(int x = 2; x < maxP; ++x){

		vector<int> P;
		for(int i = 0; i < Porig.size(); ++i){
			P.push_back(Porig[i]);
		}

		int currVal = 0;
		for(int i = 0; i < P.size(); ++i){
			while (P[i] > x){
				P[i] = P[i] - x;
				currVal++;
			}
		}
		currVal += x;
		if(currVal < bestVal){
			bestVal = currVal;
			bestX = x;
		}
	}
	if(bestVal > maxP)
		bestVal = maxP;


	printf("%d\n", bestVal);

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

