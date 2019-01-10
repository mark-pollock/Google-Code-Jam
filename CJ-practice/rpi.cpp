#include "cjheader.h"


using namespace std;
int currCase = 0;
int t;

/*
 * Global variables that are needed should be declared here
 */


/**********************************************************/

void runTestCase(){
	printf("Case #%d:\n", ++currCase);
	int n;
	cin >> n;
	string mat[n];
	for(int i = 0; i < n; ++i){
		string s;
		cin >> s;
		mat[i] = s;
	}
	int numMatches[n] = {};
	int wins[n] = {};

	double WP[n] = {};
	double OWP[n] = {};
	double OOWP[n] = {};
	double RPI[n] = {};

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(mat[i][j] != '.')
				numMatches[i]++;
			if(mat[i][j] == '1')
				wins[i]++;
		}
		if(numMatches[i] == 0)
			WP[i] = 0;
		else
			WP[i] = (double)wins[i] / (double)numMatches[i];
	}

	for(int i = 0; i < n; ++i){
		int numOpponents = 0;
		for(int j = 0; j < n; ++j){
			if(i == j || mat[j][i] == '.')
				continue;

			numOpponents++;
			int winsj = wins[j];
			int numMatchesj = numMatches[j] - 1;
			if(mat[j][i] == '1')
				winsj--;
			OWP[i] += (double)winsj / (double)numMatchesj;
		}
		OWP[i] = OWP[i] / (double)numOpponents;
	}


	for(int i = 0; i < n; ++i){
		int numOpponents = 0;
		for(int j = 0; j < n; ++j){
			if(i == j || mat[j][i] == '.')
				continue;

			numOpponents++;
			OOWP[i] += OWP[j];

		}
		OOWP[i] = OOWP[i] / (double)numOpponents;
	}

	for(int i = 0; i < n; ++i){
		RPI[i] = 0.25 * WP[i] + 0.50 * OWP[i] + 0.25 * OOWP[i];
		cout << RPI[i] << endl;
	}

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
