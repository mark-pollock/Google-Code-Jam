#include "cjheader.h"
using namespace std;
int currCase = 0;

/*
 * Global variables that are needed should be declared here
 */


/**********************************************************/

void runTestCase(){
	printf("Case #%d: ", ++currCase);
	int n;
	cin >> n;

	vector<string> strings;

	getNInputs(&strings, n);


	auto it = strings.begin();



	int numOfDiffLetters = nUniqueChangesInCharsInString(*it);
	vector<char> uniqueChars;
	uniqueChangesInCharsInString(uniqueChars, *it);

	vector<vector<int>> data;
	//cout << "strings.size = " << strings.size() << "." << endl;

	for(auto it = strings.begin(); it != strings.end(); ++it){
		vector<int> temp;
		char prevC = '-';
		int charCount = 0;
		auto it2 = uniqueChars.begin();

		for(int i = 0; i < (*it).size(); ++i){
			char c = (*it)[i];
			if(c != prevC){

				if(prevC != '-'){
					temp.push_back(charCount + 1);
					it2++;
				}
				if(c != *it2){
					printf("Fegla Won\n");
					return;
				}

				charCount = 0;
				prevC = c;


			}else{
				charCount++;
			}
		}
		it2++;
		if(it2 != uniqueChars.end()){
			printf("Fegla Won\n");
			return;
		}
		temp.push_back(charCount + 1);
		data.push_back(temp);
	}


	int moves = 0;
	for(int i = 0; i < numOfDiffLetters; ++i){
		int max = 0;
		int min = INT_MAX;
		for(int j = 0; j < data.size(); ++j){
			if(max < data[j][i])
				max = data[j][i];
			if(min > data[j][i])
				min = data[j][i];
		}

		int movesMin = INT_MAX;
		for(int c = min; c <= max; ++c){
			int movesTemp = 0;
			for(int j = 0; j < data.size(); ++j){
				movesTemp += abs(data[j][i] - c);
			}
			if(movesTemp < movesMin)
				movesMin = movesTemp;
		}
		moves += movesMin;
	}

	printf("%d\n", moves);

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
