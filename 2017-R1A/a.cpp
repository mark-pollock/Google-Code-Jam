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
	int r, c;
	cin >> r;
	cin >> c;

	char g[r][c];

	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			char curr;
			cin >> curr;
			g[i][j] = curr;
		}
	}


	//expand right
	for(int i = 0; i < r; ++i){
		char prev;
		prev = '!';
		for(int j = 0; j < c; ++j){
			if(g[i][j] == '?' && j != 0 && prev != '!'){
				g[i][j] = prev;
			}else{
				prev = g[i][j];
			}
		}
	}

	//expand left
	for(int i = 0; i < r; ++i){
		char prev;
		prev = '!';
		for(int j = c-1; j >= 0; --j){
			if(g[i][j] == '?' && j != c-1 && prev != '!'){
				g[i][j] = prev;
			}else{
				prev = g[i][j];
			}
		}
	}

	//expand down
	for(int j = 0; j < c; ++j){
		char prev;
		prev = '!';
		for(int i = 0; i < r; ++i){
			if(g[i][j] == '?' && i != 0 && prev != '!'){
				g[i][j] = prev;
			}else{
				prev = g[i][j];
			}
		}
	}

	//expand up
	for(int j = 0; j < c; ++j){
		char prev;
		prev = '!';
		for(int i = r - 1; i >= 0; --i){
			if(g[i][j] == '?' && i != r -1 && prev != '!'){
				g[i][j] = prev;
			}else{
				prev = g[i][j];
			}
		}
	}

	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			cout << g[i][j];
		}
		cout << "\n";
	}


	//printf("%d\n", result);

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
