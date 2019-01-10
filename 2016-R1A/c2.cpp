#include "cjheader.h"


using namespace std;
int currCase = 0;
int t;

/*
 * Global variables that are needed should be declared here
 */
vector<int> recip;

/**********************************************************/

void removeE(const vector<int> b, const vector<int> r){
	for(auto it = r.begin(); it != r.end(); ++it){
		b.erase((*it));
		for(int i = (*it); i < b.size(); ++i){
			b[i]--;
		}
	}
}

int findReciprocals(const vector<int> b){
	int recips = 0;
	for(int i = 0; i < b.size(); ++i){
		if(b.at(b.at(i)) == i){
			recip.push_back(i, b.at(i));
			recips++;
		}
	}
}

void runTestCase(){
	printf("Case #%d: ", ++currCase);

	recip.clear();

	int n;
	cin >> n;
	vector<int> bffs;
	for(int i = 0; i < n; ++i){
		int temp;
		cin >> temp;
		temp--; // so that we start from zero
		bffs.push_back(temp);
	}

	int recips = findReciprocals();
	while(true){
		vector<int> toRemove;
		for(int i = 0; i < bffs.size(); ++i){
			if(!(find(bffs.begin(), bffs.end(), i))){
				toRemove.push_back(i);
			}
		}
		if(toRemove.size != 0)
			removeE(bffs, toRemove);
		else
			break;
	}

	printf("%d\n", maxLength);

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
