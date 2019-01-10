#include "cjheader.h"

using namespace std;
int currCase = 0;
int t;

/*
 * Global variables that are needed should be declared here
 */


/**********************************************************/

int getMoves(vector<int> &motes, int a){

	int moves = 0;
	while(!motes.empty()){
		int curr = motes.back();
		///printf("start: curr = %d, moves = %d, a = %d\n", curr, moves, a);
		motes.pop_back();
		if(a > curr){
			a += curr;
		}else if(2*a - 1 > curr){
			a += a - 1 + curr;
			moves++;
		}else{
			if(motes.size() <= 0){
				//printf("a\n");
				return moves + 1;
			}
			if(a != 1){
				int movesToNext = 0;
				int a2 = a;
				while(a2 <= curr){
					a2 += a2 - 1;
					movesToNext++;
				}
				a2 += curr;
				vector<int> motes2;
				motes2 = motes;
				motes2.push_back(curr);
				motes2.erase(motes2.begin());

				int size = motes.size();
				//printf("curr = %d, a = %d, a2 = %d, size = %d, movesToNext = %d, moves = %d\n"
													//, curr, a, a2, size, movesToNext, moves);
				return moves + min(movesToNext + getMoves(motes, a2), size + 1);
			}else{
				//printf("c\n");
				return motes.size() + 1;
			}
		}
	}
	//printf("d: moves = %d\n", moves);
	return moves;
}


void runTestCase(){
	printf("Case #%d: ", ++currCase);
	int a, n;
	cin >> a;
	cin >> n;

	vector<int> motes;
	getNInputs(&motes, n);

	sort(motes.begin(), motes.end());
	reverse(motes.begin(), motes.end());

	int moves = getMoves(motes, a);
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
