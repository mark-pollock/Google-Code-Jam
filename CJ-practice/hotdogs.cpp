#include "cjheader.h"


using namespace std;
int currCase = 0;
int t;

/*
 * Global variables that are needed should be declared here
 */
int d;
vector<double>::iterator realStart;

/**********************************************************/

void moveLeft(vector<double>::iterator start, vector<double>::iterator end, double d){
	for(auto it = start; it != end; ++it){
		//cout << "moving Left: " << *it << " to " << *it - d << endl;
		(*it) -= d;
	}
}

void moveRight(vector<double>::iterator start, vector<double>::iterator end, double d){
	for(auto it = start; it != end; ++it){
		(*it) += d;
	}
}

/**** NOTE
 * NEED TO DO IT SO THAT time does not increase for every move left / right
 * i.e. store movement of each point somewhere
 *
 *
 *
 */
double split(vector<double>::iterator start, vector<double>::iterator end){
	//vector<double>::iterator lastLeft = start;
	double time = 0;
	for(auto it = start; it != end; ++it){
		auto next = it + 1;
		if(next == end){
			break;
		}

		double dist = (*next) - (*it);
		if(dist > d){
			return time + split(next, end);
		}else{
			time += (d - dist) / 2.0;
			//cout << "time = " << time << endl;
			//cout << "it = " << *it << endl;
			moveLeft(start, it + 1, (d - dist) / 2.0);
			moveRight(next, end, (d - dist) / 2.0);
		}

	}
	return time;
}


void runTestCase(){
	printf("Case #%d: ", ++currCase);

	int c;
	cin >> c;
	cin >> d;

	vector<double> vendors;
	int total = 0;
	for(int i = 0; i < c; ++i){
		int p;
		int v;
		cin >> p;
		cin >> v;
		total += v;
		for(int j = 0; j < v; ++j){
			vendors.push_back(p);
		}
	}

	std::sort(vendors.begin(), vendors.end());
	vector<double> vendorsOrig = vendors;

	vector<double>::iterator start = vendors.begin();
	realStart = vendors.begin();
	vector<double>::iterator end = vendors.end();

	double time = split(start, end);
	//for(auto it = start; it != end; ++it){
		//cout << *it << endl;
	//}
	//cout << "time = " << time << endl;

	double time2 = 0;
	auto it = vendors.begin();

	for(auto itorig = vendorsOrig.begin(); itorig != vendorsOrig.end(); ++itorig){
		cout << "it = " << *it << " , itorig = " << *itorig << endl;
		time2 = max(time2, abs((*itorig) - (*it)));
		it++;
	}


	for(auto it = vendors.begin(); it != vendors.end(); ++it){
		auto next = it;
		next++;
		if(next == vendors.end())
			break;
		double dist = (*next) - (*it);
		if(dist < d){
			time += d - dist;
			//cout << "add time" << endl;
		}
	}


	cout << fixed;
	cout << setprecision(9);
	cout << time2 << endl;
	//printf("%f.9\n", time);

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
