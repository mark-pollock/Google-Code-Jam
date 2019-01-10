#include "cjheader.h"
#include <iomanip>


using namespace std;
int currCase = 0;
int t;

/*
 * Global variables that are needed should be declared here
 */


/**********************************************************/

void runTestCase(){
	printf("Case #%d: ", ++currCase);


	int n, r, o, y, g, b, v;

	cin >> n;
	cin >> r;
	cin >> o;
	cin >> y;
	cin >> g;
	cin >> b;
	cin >> v;



	if(o > 0){
		if(n == o + b){
			if(b == o){
				while(b > 0){
					cout << "BO";
					b--;
					return;
				}
				cout << "\n";
				return;
			}else{
				cout << "IMPOSSIBLE\n";
				return;
			}
		}else{
			if(b >= o + 1){
				b++;
			}else{
				cout << "IMPOSSIBLE\n";
				return;
			}
		}
	}
	if(g > 0){
		if(n == g + r){
			if(g == r){
				while(r > 0){
					cout << "RG";
					r--;
					return;
				}
				cout << "\n";
				return;
			}else{
				cout << "IMPOSSIBLE\n";
				return;
			}
		}else{
			if(r >= g + 1){
				r++;
			}else{
				cout << "IMPOSSIBLE\n";
				return;
			}
		}
	}
	if(v > 0){
		if(n == v + y){
			if(v == y){
				while(y > 0){
					cout << "YV";
					y--;
					return;
				}
				cout << "\n";
				return;
			}else{
				cout << "IMPOSSIBLE\n";
				return;
			}
		}else{
			if(y >= v + 1){
				y++;
			}else{
				cout << "IMPOSSIBLE\n";
				return;
			}
		}
	}
	char manes[n];
	for(int i = 0; i < n; ++i){
		manes[i] = 'F';
	}

	int stablePos = 0;

	if(r + 2*g > max(y + 2*v, b + 2*o)){
		for(int i = 0; i < g; ++i){

			manes[stablePos+i] = 'R';
			manes[stablePos+i+1] = 'G';

		}
	}

	cout << result << "\n";


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
