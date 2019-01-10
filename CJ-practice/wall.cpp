#include "cjheader.h"


using namespace std;
int currCase = 0;
int t;

/*
 * Global variables that are needed should be declared here
 */


/**********************************************************/

class interval{
public:
	int w;
	int e;
	int h;

	int getw() { return w; };
	int gete() { return e; };
	int geth() { return h; };
	void seth(int newh) { h = newh; };
	void sete(int newe) { e = newe; };
	void setw(int neww) { w = neww; };
};

class intervalSet{
public:

};

class wall{
private:
	list<interval> intervals;
	int mostw;
	int moste;
	bool insertNew(interval);

public:
	int getmostw() { return mostw; }
	int getmoste() { return moste; }

	bool attack(int, int, int);

};

//bool wall::insertNew(interval inter){

//}

bool wall::attack(int west, int east, int strength){


	auto it = intervals.begin();
	interval prev;
	interval curr;
	for(; it != intervals.end(); ++it){
		curr = *it;
		if(curr.getw() > west){
			// we want to insert between this one and the previous
			break;
		}
		prev = curr;
	}

	if(it == intervals.end()){
		// we need to insert to the right of everything
		interval newint;
		newint.sete(east);
		newint.setw(west);
		newint.seth(strength);
		intervals.emplace_back(newint);
		return true; // attack must succeed
	}else if(it == intervals.begin() && east < curr.w){
		// need to insert before everything
		interval newint;
		newint.sete(east);
		newint.setw(west);
		newint.seth(strength);
		intervals.emplace_front(newint);
		return true; // attack must succeed
	}else if(prev.e < west && curr.w > east){
		// will fit in between prev and curr.
		interval newint;
		newint.sete(east);
		newint.setw(west);
		newint.seth(strength);
		intervals.insert(it, newint);
		return true; // attack must succeed
	}else if(prev.e >= west && curr.w > east){
		// start overlaps with prev but ends before curr

		if(prev.e >= east){
			// completely contained in prev
			if(strength < prev.h){
				return false;
			}else{
				// split prev
				interval eastPart;
				eastPart.setw(east);
				eastPart.sete(prev.e);
				eastPart.seth(prev.h);

				prev.sete(west);

				interval newint;
				newint.sete(east);
				newint.setw(west);
				newint.seth(strength);

				intervals.insert(it, newint);
				intervals.insert(it, eastPart);
				return true;
			}
		}

		if(strength > prev.h){
			prev.sete(west);
			interval newint;
			newint.sete(east);
			newint.setw(west);
			newint.seth(strength);
			intervals.insert(it, newint);
			return true;
		}else if(strength < prev.h){
			interval newint;
			newint.sete(east);
			newint.setw(prev.e);
			newint.seth(strength);
			intervals.insert(it, newint);
			return true;
		}else{
			// extend the interval
			prev.sete(east);
			return true;
		}

	}else if(prev.e < west && curr.w < east){
		// starts after prev but overlaps with ATLEAST curr
		if(curr.w <= west){
			// starts enclosed in current
			// todo think dealt with before
		}

		if(curr.e > east){
			// Doesn't go past end of curr
			if(curr.h < strength){
				curr.w = east;
				interval newint;
				newint.sete(east);
				newint.setw(west);
				newint.seth(strength);
				intervals.insert(it, newint);
				return true;
			}else if(curr.h > strength){

			}
		}




	}else{
		// overlaps with prev and overlaps with ATLEAST curr
		// todo
	}

	return true;
}

void runTestCase(){
	wall w;
	w.getmostw();

	printf("Case #%d: ", ++currCase);
	int n, l;
	cin >> n;
	cin >> l;

	vector<int> origStrings;
	vector<int> reqStrings;
	getNInputs(&origStrings, n);
	getNInputs(&reqStrings, n);




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
