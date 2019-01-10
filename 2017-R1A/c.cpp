#include "cjheader.h"


using namespace std;
int currCase = 0;
int t;

/*
 * Global variables that are needed should be declared here
 */
/**********************************************************/

double epsilon = 10^-6;


void runTestCase(){
	printf("Case #%d: ", ++currCase);

	//cin >> s;

	int hd, ad, hk, ak, b, d, hd_max;


	cin >> hd; cin >> ad; cin >> hk; cin >> ak; cin >> b; cin >> d;
	hd_max = hd;

	int attacksNeeded;
	int numBufs = 0;
	double temp;
	if(b == 0){
		temp = 0;
	}else{
		temp = (sqrt((double)hk*(double)b) - (double)ad) / (double)b;
	}
	if(temp <= 0){
		numBufs = 0;
		attacksNeeded = myCeil((double)hk/(double)ad);
	}else{
		int numBufs1, numBufs2;
		numBufs1 = myCeil(temp);
		numBufs2 = myFloor(temp);
		int attacksNeeded1 = myCeil((double)numBufs1 + (double)hk / ((double)ad + numBufs1*(double)b));
		int attacksNeeded2 = myCeil((double)numBufs2 + (double)hk / ((double)ad + numBufs2*(double)b));
		attacksNeeded = min(attacksNeeded1, attacksNeeded2);
	}

	int attacksNByK = myCeil((double)hd / (double)ak);

	if(attacksNByK >= attacksNeeded){
		cout << attacksNeeded << "\n";
		return;
	}

	int n_deb = 0;

	int hd_startAttack; // need to set
	int totalAttacksN = attacksNeeded;






	int c2 = 0;

	int attacksNByK1 = myCeil((double)hd_startAttack / (double) (ak-n_deb*d));
	int attacksNByK2 = myCeil(((double)hd_max - (ak-n_deb*d)) / (double) (ak-n_deb*d));


	if(attacksNeeded > attacksNByK1){
		c2++;
		attacksNeeded = attacksNeeded - (attacksNByK1 - 1);
		c2 += myCeil((double)attacksNeeded / ((double)attacksNByK2 - 1));
	}else{
		// don't need to cure once started attacking
	}




	int totalMoves = totalAttacksN + c0 + c1 + c2 + n_deb;

	cout << totalMoves << "\n";



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
