#include "cjheader.h"


using namespace std;
int currCase = 0;
int t;

/*
 * Global variables that are needed should be declared here
 */


/**********************************************************/

bool matches(int min1, int max1, int min2, int max2){
	for(int i = min2; i <= max2; ++i){
		if(i >= min1 && i <= max1)
			return true;
	}
	return false;
}

class Package{
public:
	int min;
	int max;
	bool valid;
	Package(int minimum, int maximum)
	{
		min = minimum;
		max = maximum;
		if(min != 0 || max != 0)
			valid = true;
		else
			valid = false;
	}

	int getMin(){return min;}
	int getMax(){return max;}

	void setVals(int m1, int m2){
		min = m1;
		max = m2;
		if(m1 != 0 || m2 != 0)
			valid = true;
		else
			valid = false;
	}

	void remove(){
		min = 0;
		max = 0;
		valid = false;
	}

	bool isValid(){return valid;}



	string toString(){
		return to_string(min) + "-" + to_string(max);
	}
};


bool comparePack(Package const &p1, Package const &p2){
	if(p1.min == p2.min){
		return (p1.max < p2.max);
	}else{
		return (p1.min < p2.min);
	}
}


/*int numpackages(int **s_min, int **s_max, int n, int p, int *curPack, int size_curPack){

	int packages = 0;
	for(int k = 0; k < p; ++k){
		int min_s = s_min[0][k];
		int max_s = s_max[0][k];

		vector<int> toUse;
		bool found2 = true;
		if(min_s != 0 && max_s != 0){
			for(int i = 1; i < n; ++i){
				bool found = false;
				for(int j = 0; j < p; ++j){
					if(s_min[i][j] != 0 && s_max[i][j] != 0){
						if(matches(min_s, max_s, s_min[i][j], s_max[i][j])){
							toUse.push_back(j);
							found = true;
							break;
						}
					}
				}
				if(!found){
					found2 = false;
					break;
				}
			}
			if(found2){
				packages++;
				for(int i = 1; i < n; ++i){
					s_min[i][toUse[i-1]] = 0;
					s_max[i][toUse[i-1]] = 0;
				}
				s_min[0][k] = 0;
				s_max[0][k] = 0;
			}
		}
	}
	return packages;
}*/


void runTestCase(){

	printf("Case #%d: ", ++currCase);

	int n, p;

	cin >> n;
	cin >> p;

	int r[n];




	for(int i = 0; i < n; ++i){
		cin >> r[i];
	}

	int **s_min, **s_max;
	s_min = new int*[n];
	s_max = new int*[n];

	for(int i = 0; i < n; ++i){
		s_min[i] = new int[p];
		s_max[i] = new int[p];
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < p; ++j){
			double curr;
			cin >> curr;
			double minv_temp, maxv_temp;
			int minv, maxv;
			minv_temp = curr / (r[i]*1.1);
			maxv_temp = curr / (r[i]*0.9);
			if(abs(round(minv_temp) - minv_temp) < 10^-6){
				minv = round(minv_temp);
			}else{
				minv = ceil(curr / (r[i]*1.1));
			}
			if(abs(round(maxv_temp) - maxv_temp) < 10^-6){
				maxv = round(maxv_temp);
			}else{
				maxv = floor(curr / (r[i]*0.9));
			}
			while(curr > minv*r[i]*1.1)
				minv++;
			while(curr < maxv*r[i]*0.9)
				maxv--;
			if(minv > maxv){
				s_min[i][j] = 0;
				s_max[i][j] = 0;
			}else{
				s_min[i][j] = minv;
				s_max[i][j] = maxv;
			}
		}
	}

	vector<vector<Package>> allServings;
	for(int i = 0; i < n; ++i){
		vector<Package> currIng;
		for(int j = 0; j < p; ++j){
			Package currPackage = Package(s_min[i][j], s_max[i][j]);
			currIng.push_back(currPackage);
		}
		if(currIng.size() != 0){
			allServings.push_back(currIng);
		}
	}

	for(auto iter1 = allServings.begin(); iter1 != allServings.end(); ++iter1){
		sort(iter1->begin(), iter1->end(), comparePack);
	}


	for(auto iter = allServings.begin(); iter != allServings.end(); ++iter){
		while(!iter->begin()->isValid() && iter->size() != 0)
			iter->erase(iter->begin());
	}


	int result = 0;

	while(true){
		int highest_min = -1;
		auto indexOflowestMax = allServings.begin();
		int lowest_max = 10000000;
		for(auto iter1 = allServings.begin(); iter1 != allServings.end(); ++iter1){
			if(iter1->size() == 0){
				goto finished;
			}
			if(iter1->begin()->getMax() < lowest_max){
				lowest_max = iter1->begin()->getMax();
				indexOflowestMax = iter1;

			}if(iter1->begin()->getMin() > highest_min){
				highest_min = iter1->begin()->getMin();
			}
		}
		if(lowest_max < highest_min && lowest_max != 10000000 && highest_min != -1){
			// remove worst
			indexOflowestMax->erase(indexOflowestMax->begin());
		}else{
			// remove all and make package.
			result++;
			for(auto iter = allServings.begin(); iter != allServings.end(); ++iter){
				iter->erase(iter->begin());
				if(iter->size() == 0)
					goto finished;
			}
		}
	}





	//cout << packages << "\n";


	//printf("%d\n", result);
finished:
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
