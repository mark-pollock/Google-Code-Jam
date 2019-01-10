#include "cjheader.h"


using namespace std;
int currCase = 0;
int t;

/*
 * Global variables that are needed should be declared here
 */


/**********************************************************/

int findOcc(vector<int> &v, int e){
	int count = 0;
	for(auto iter = v.begin(); iter != v.end(); ++iter){
		if((*iter) == e)
			count++;
	}

	return count;
}


void runTestCase(){
	printf("Case #%d: ", ++currCase);

	vector<int> possibleCards1;
	vector<int> possibleCards2;

	int row1, row2;

	cin >> row1;
	row1--;

	for(int i = 0; i < 4; ++i){
		for(int j = 0; j < 4; ++j){
			int temp;
			cin >> temp;
			if(i == row1){
				possibleCards1.push_back(temp);
			}
		}
	}


	cin >> row2;
	row2--;

	for(int i = 0; i < 4; ++i){
		for(int j = 0; j < 4; ++j){
			int temp;
			cin >> temp;
			if(i == row2){
				if(findOcc(possibleCards1, temp) > 0){
					possibleCards2.push_back(temp);
				}
			}
		}
	}

	if(possibleCards2.size() == 0){
		printf("Volunteer cheated!\n");
	}else if(possibleCards2.size() > 1){
		printf("Bad magician!\n");
	}else{
		printf("%d\n", possibleCards2[0]);
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
