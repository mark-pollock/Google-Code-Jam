#include "cjheader.h"


using namespace std;
int currCase = 0;
int t;

/*
 * Global variables that are needed should be declared here
 */
class Scores
{
public:


	int c_int;
	int j_int;
	int *c_array;
	int *j_array;
	int size;

	Scores(){
		c_int = 0;
		j_int = 0;
		size = 0;
	}

	Scores(int c[], int j[], int s){
		setSize(s);

		for(int i = 0; i < s; ++i){
			c_array[i] = c[i];
			j_array[i] = j[i];
		}
		refreshInts();
	}
	Scores(Scores &s){
		c_int = s.c_int;
		j_int = s.j_int;
		setSize(s.size);
		for(int i = 0; i < size; ++i){
			c_array[i] = s.c_array[i];
			j_array[i] = s.j_array[i];
		}
	}

	Scores(Scores &s, bool minusFirst){
		if(minusFirst){
			setSize(s.size - 1);
			//todo - check this line belowx2 incrememnts before the copy
			copy(s.c_array + 1, s.c_array + size, c_array);
			copy(s.j_array + 1, s.j_array + size, j_array);
			refreshInts();
		}else{
			Scores(s);
		}
	}

	void setSize(int s){
		size = s;
		c_array = new int[size];
		j_array = new int[size];

	}

	void minimizeC(){
		for(int i = 0; i < size; ++i){
			if(c_array[i] == -1)
				c_array[i] = 0;
		}
		refreshInts();
	}
	void maximizeC(){
		for(int i = 0; i < size; ++i){
			if(c_array[i] == -1)
				c_array[i] = 9;
		}
		refreshInts();
	}
	void minimizeJ(){
		for(int i = 0; i < size; ++i){
			if(j_array[i] == -1)
				j_array[i] = 0;
		}
		refreshInts();
	}
	void maximizeJ(){
		for(int i = 0; i < size; ++i){
			if(j_array[i] == -1)
				j_array[i] = 9;
		}
		refreshInts();
	}


	void refreshIntFromArray_c(){
		c_int = 0;
		for(int i = size - 1; i >= 0; --i){
			c_int = c_int + c_array[i]*pow(10, size - 1 - i);
		}
	}
	void refreshIntFromArray_j(){
		j_int = 0;
		for(int i = size - 1; i >= 0; --i){
			j_int = j_int + j_array[i]*pow(10, size - 1 - i);
		}
	}

	void refreshInts(){
		refreshIntFromArray_c();
		refreshIntFromArray_j();
	}

	void printc(){
		for(int i = 0; i < size; ++i){
			cout << c_array[i];
		}
	}
	void printj(){
			for(int i = 0; i < size; ++i){
				cout << j_array[i];
			}
	}
};

/**********************************************************/


int minimize(int n[], int size){
	int num = 0;
	for(int i = 0; i < size; ++i){
		if(n[i] == -1)
			num = num*10+0;
		else
			num = num*10+n[i];
	}
	return num;
}

int maximize(int n[], int size){
	int num = 0;
	for(int i = 0; i < size; ++i){
		if(n[i] == -1)
			num = num*10+9;
		else
			num = num*10+n[i];
	}
	return num;
}


Scores iterateScores(Scores s){
	Scores newS = new Scores();

	// Size == 1 CASE
	if(s.size == 1){
		newS.setSize(1);
		if(s.c_array[0] == -1 && s.j_array[0] == -1){
			newS.c_array[0] = 0;
			newS.j_array[0] = 0;
			newS.refreshInts();
			return newS;
		}else if(s.c_array[0] == -1 && s.j_array[0] != -1){
			newS.c_array[0] = s.j_array[0];
			newS.j_array[0] = s.j_array[0];
			newS.refreshInts();
			return newS;
		}else if(s.c_array[0] != -1 && s.j_array[0] == -1){
			newS.c_array[0] = s.c_array[0];
			newS.j_array[0] = s.c_array[0];
			newS.refreshInts();
			return newS;
		}else{
			return s;
		}
	}


	/* ?-N case *******************************************************/
	if(s.c_array[0] == -1 && s.j_array[0] != -1){
		Scores newS(s, true);

		Scores itResult = iterateScores(newS);

		int t1 = s.j_array[0] - 1;
		int t2 = s.j_array[0];
		int t3 = s.j_array[0] + 1;

		int test1Dif = abs((t1*pow(10, size - 1)  + itResult.c_int) - (s.j_array[0]*pow(10, size - 1) + itResult.j_int));
		int test2Dif = abs((t2*pow(10, size - 1) + itResult.c_int) - (s.j_array[0]*pow(10, size - 1) + itResult.j_int));
		int test3Dif = abs((t3*pow(10, size - 1) + itResult.c_int) - (s.j_array[0]*pow(10, size - 1) + itResult.j_int));

		int minDif = min(test1Dif, test2Dif);
		minDif = min(minDif, test3Dif);

		if(minDif == test1Dif)
			s.c_array[0] = t1;
		else if(minDif == test2Dif)
			s.c_array[0] = t2;
		else
			s.c_array[0] = t3;

		copy(itResult.c_array.begin(), itResult.c_array.end(), ++s.c_array.begin());
		copy(itResult.j_array.begin(), itResult.j_array.end(), ++s.j_array.begin());

		return s;
	}

	/* N-? case *********************************************************/
	else if(s.c_array[0] != -1 && s.j_array[0] == -1){
		Scores newS(s, true);

		Scores itResult = iterateScores(newS);

		int t1 = s.c_array[0] - 1;
		int t2 = s.c_array[0];
		int t3 = s.c_array[0] + 1;

		int test1Dif = abs((t1*pow(10, size - 1)  + itResult.j_int) - (s.c_array[0]*pow(10, size - 1) + itResult.c_int));
		int test2Dif = abs((t2*pow(10, size - 1) + itResult.j_int) - (s.c_array[0]*pow(10, size - 1) + itResult.c_int));
		int test3Dif = abs((t3*pow(10, size - 1) + itResult.j_int) - (s.c_array[0]*pow(10, size - 1) + itResult.c_int));

		int minDif = min(test1Dif, test2Dif);
		minDif = min(minDif, test3Dif);

		if(minDif == test1Dif)
			s.j_array[0] = t1;
		else if(minDif == test2Dif)
			s.j_array[0] = t2;
		else
			s.j_array[0] = t3;

		copy(itResult.c_array.begin(), itResult.c_array.end(), ++s.c_array.begin());
		copy(itResult.j_array.begin(), itResult.j_array.end(), ++s.j_array.begin());

		return s;
	}

	/* ?-? case ************************************************************/
	else if(s.c_array[0] == -1 && s.j_array[0] == -1){
		//only ever 0's or 1's
		Scores newS(s, true);

		Scores itResult = iterateScores(newS);

		if(itResult.c_int > itResult.j_int){
			s.c_array[0] = 0;

			if(abs(itResult.j_int - itResult.c_int) < abs(itResult.j_int + 1*pow(10, s.size - 1) - itResult.c_int)){
				s.j_array[0] = 0;
			}else{
				s.j_array[0] = 1;
			}
		}else{
			s.j_array[0] = 0;
			if(abs(itResult.c_int - itResult.j_int) < abs(itResult.c_int + 1*pow(10, s.size - 1) - itResult.j_int)){
				s.c_array[0] = 0;
			}else{
				s.c_array[0] = 1;
			}
		}

		copy(itResult.c_array.begin(), itResult.c_array.end(), ++s.c_array.begin());
		copy(itResult.j_array.begin(), itResult.j_array.end(), ++s.j_array.begin());

		return s;

	}

	/* N-N case ***********************************************************/
	else if(s.c_array[0] != -1 && s.j_array[0] != -1){
		if(s.c_array[0] == s.j_array[0]){
			Scores newS(s, true);
			Scores itResult = iterateScores(newS);

			copy(itResult.c_array.begin(), itResult.c_array.end(), ++s.c_array.begin());
			copy(itResult.j_array.begin(), itResult.j_array.end(), ++s.j_array.begin());

			return s;


		}else if(s.c_array[0] < s.j_array[0]){
			s.maximizeC();
			s.minimizeJ();
			return s;
		}else if(n1[0] > n2[0]){
			s.minimizeC();
			s.maximizeJ();
			return s;
		}
	}


}

//returns integer arrays and size of arrays
/*pair<pair<int*, int*>, int> iterateFun(int n1[], int n2[], int size){
	int n1Result, n2Result;

	if(size == 1){
		if(n1[0] == -1 && n2[0] == -1){
			int newN1[1];
			int newN2[1];
			newN1[0] = 0;
			newN2[0] = 0;
			pair<int*, int*> p1(newN1, newN2);
			return pair<pair<int*, int*>, int>(p1, 1);
		}else if(n1[0] == -1 && n2[0] != -1){
			int newN1[1];
			int newN2[1];
			newN1[0] = n2[0];
			newN2[0] = n2[0];
			return pair<int*, int*>(newN1, newN2, 1);
		}else if(n1[0] != -1 && n2[0] == -1){
			int newN1[1];
			int newN2[1];
			newN1[0] = n1[0];
			newN2[0] = n1[0];
			return pair<int*, int*>(newN1, newN2);
		}else{
			return pair<int, int>(newN1, newN2);
		}
	}

	if(n1[0] == -1 && n2[0] != -1){
		int n1New[size - 1];
		copy(++begin(n1), end(n1), n1New.begin());
		int n2New[size - 1];
		copy(++begin(n2), end(n2), n2New.begin());

		pair<int, int> itResult = iterateFun(n1New, n2New, size - 1);

		int t1 = n2[0] - 1;
		int t2 = n2[0];
		int t3 = n2[0] + 1;

		int test1Dif = abs(t1*pow(10, size - 1)  + itResult.first - n2[0]*pow(10, size - 1) + itResult.second);
		int test2Dif = abs(t2*pow(10, size - 1) + itResult.first - n2[0]*pow(10, size - 1) + itResult.second);
		int test3Dif = abs(t3*pow(10, size - 1) + itResult.first - n2[0]*pow(10, size - 1) + itResult.second);

		int minDif = min(test1Dif, test2Dif);
		minDif = min(minDif, test3Dif);

		if(minDif == test1Dif)
			n1Result = t1*pow(10, size - 1) + itResult.first;
		else if(minDif == test2Dif)
			n1Result = t2*pow(10, size - 1) + itResult.first;
		else
			n1Result = t3*pow(10, size - 1) + itResult.first;

		n2Result = n2[0]*pow(10, size - 1) + itResult.second;

	}else if(n1[0] != -1 && n2[0] == -1){
		int n1New[size - 1];
		copy(++begin(n1), end(n1), n1New.begin());
		int n2New[size - 1];
		copy(++begin(n2), end(n2), n2New.begin());

		pair<int, int> itResult = iterateFun(n1New, n2New, size - 1);

		int t1 = n1[0] - 1;
		int t2 = n1[0];
		int t3 = n1[0] + 1;

		int test1Dif = abs(t1*pow(10, size - 1)  + itResult.second - n1[0]*pow(10, size - 1) + itResult.first);
		int test2Dif = abs(t2*pow(10, size - 1) + itResult.second - n1[0]*pow(10, size - 1) + itResult.first);
		int test3Dif = abs(t3*pow(10, size - 1) + itResult.second - n1[0]*pow(10, size - 1) + itResult.first);

		int minDif = min(test1Dif, test2Dif);
		minDif = min(minDif, test3Dif);

		if(minDif == test1Dif)
			n2Result = t1*pow(10, size - 1) + itResult.second;
		else if(minDif == test2Dif)
			n2Result = t2*pow(10, size - 1) + itResult.second;
		else
			n2Result = t3*pow(10, size - 1) + itResult.second;

		n1Result = n1[0]*pow(10, size - 1) + itResult.first;


	}else if(n1[0] == -1 && n2[0] == -1){
		//only ever 0's or 1's
		int n1New[size - 1];
		copy(++begin(n1), end(n1), n1New.begin());
		int n2New[size - 1];
		copy(++begin(n2), end(n2), n2New.begin());

		pair<int, int> itResult = iterateFun(n1New, n2New, size - 1);

		if(itResult.first > itResult.second){
			n1Result = itResult.first;
			if(abs(n1Result - itResult.second < itResult.second+1*pow(10, size - 1))){
				n2Result = itResult.second;
			}else
				n2Result = itResult.second + 1*pow(10, size - 1);
		}


	}else if(n1[0] != -1 && n2[0] != -1){
		if(n1[0] == n2[0]){
			int n1New[size - 1];
			copy(++begin(n1), end(n1), n1New.begin());
			int n2New[size - 1];
			copy(++begin(n2), end(n2), n2New.begin());

			pair<int, int> itResult = iterateFun(n1New, n2New, size - 1);

			n1Result = n1[0]*pow(10, size - 1) + itResult.first;
			n2Result = n2[0]*pow(10, size - 1) + itResult.second;

		}else if(n1[0] < n2[0]){
			n1Result = maximize(n1, size);
			n2Result = minimize(n2, size);

		}else if(n1[0] > n2[0]){
			n1Result = minimize(n1, size);
			n2Result = maximize(n2, size);
		}
	}

	/*int leadingZeros1 = size - (int)log10(n1Result) + 1;
	int leadingZeros2 = size - (int)log10(n2Result) + 1;

	int i1 = 0;
	for(; i1 < leadingZeros1; ++i1){
		resultToReturn1[i1] = 0;
	}
	int i2 = 0;
	for(; i2 < leadingZeros2; ++i2){
		resultToReturn2[i2] = 0;
	}

	while (n1Result > 0){
		resultToReturn1[i1] = n1Result % 10;
		n1Result = n1Result / 10;
		i1++;
	}
	while (n2Result > 0){
			resultToReturn2[i2] = n2Result % 10;
			n2Result = n2Result / 10;
			i1++;
	}

	int resultToReturn1[size];
	int resultToReturn2[size];

	return pair<int, int>(n1Result, n2Result);



}*/

void runTestCase(){
	printf("Case #%d: ", ++currCase);
	string c1, j1;
	cin >> c1;
	cin >> j1;

	int c[c1.length()] = {};
	int j[j1.length()] = {};

	for(int i = 0; i < c1.length(); ++i){
		if(c1[i] == '?')
			c[i] = -1;
		else
			c[i] = (int)c1[i] - '0';
		if(j1[i] == '?')
			j[i] = -1;
		else
			j[i] = (int)j1[i] - '0';
	}
	int countQsAtStart = 0;
	bool numberFound = false;

	int i = 0;
	while(!numberFound){
		if(c[i] == -1 && j[i] == -1){
			countQsAtStart++;
			i++;
		}else
			numberFound = true;
	}

	int cNew[size - countQsAtStart];
	auto cStart = c.begin();
	auto jStart = j.begin();
	for(int j = 0; j < countQsAtStart; ++j){
		cStart++;
		jStart++;
	}
	copy(cStart, end(c), cNew.begin());
	int jNew[size - countQsAtStart];
	copy(jStart, end(j), jNew.begin());


	Scores sStart(cNew, jNew, size - countQsAtStart);

	Scores results = iterateFun(sStart);


	for(int j = 0; j < countQsAtStart; ++j){
		cout << "0";
	}
	results.printc();
	for(int j = 0; j < countQsAtStart; ++j){
		cout << "0";
	}
	results.printj();
	cout << "\n";

	//printf("%d %d\n", results.first, results.second);


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
