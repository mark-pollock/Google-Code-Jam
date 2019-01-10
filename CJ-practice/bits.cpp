#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <utility>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstring>
#include <assert.h>
#include <math.h>
#include <array>

using namespace std;
int currCase = 0;

/*
 * Global variables that are needed should be declared here
 */

int l;
int n;


/**********************************************************/
template<class ForwardIteratorType>
bool solved(ForwardIteratorType curr_begin, ForwardIteratorType curr_end,
		ForwardIteratorType req_begin, ForwardIteratorType req_end){
	
	
	for(auto it = curr_begin; it != curr_end; ++it){
		bool foundMatch = false;
		for(auto it2 = req_begin; it2 != req_end; ++it2){
			if(*it == *it2){
				foundMatch = true;
				break;
			}
		}
		if(foundMatch == false){
			return false;
		}
	}
	
	

	return true;
}


template<class ForwardIteratorType>
void flip(ForwardIteratorType curr_begin, ForwardIteratorType curr_end, int b){
	for(auto it = curr_begin; it != curr_end; ++it){
		(*it)[b] = !(*it)[b];
		//(*it)[l - 1 -b] = !(*it)[l - 1 -b];
	}

}

template<class ForwardIteratorType>
void printArray(ForwardIteratorType curr_begin, ForwardIteratorType curr_end){
	int i = 0;
	for(auto it = curr_begin; it != curr_end; ++it){
		if(*it)
			printf("1");
		else
			printf("0");
	}

}

template<class ForwardIteratorType>
void print2DArray(ForwardIteratorType curr_begin, ForwardIteratorType curr_end){
	int i = 0;
	for(auto it = curr_begin; it != curr_end; ++it){
		printf("%d : ", i);
		++i;
		printArray((*it).begin(), (*it).end());
		printf("\n");
	}

}

void runTestCase(){
	printf("Case #%d: ", ++currCase);

	assert(scanf("%d %d", &n, &l) == 2);
	
	vector<vector<bool>> curr;
	vector<vector<bool>> req;

	int c_curr[l];
	int c_req[l];
	
	for(int i = 0; i < l; ++i){
		c_curr[i] = 0;
		c_req[i] = 0;
	}
	


	for(int i = 0; i < n; ++i){
		vector<bool> temp;
		for(int j = 0; j < l; ++j){
			int b;
			assert(scanf("%1d", &b) == 1);
			if(b == 1){
				//temp.insert(temp.end(), true);
				temp.push_back(true);
				c_curr[j]++;
			}else
				//temp.insert(temp.begin(), false);
				temp.push_back(false);
		}
		curr.insert(curr.begin(), temp);
	}
	for(int i = 0; i < n; ++i){
		vector<bool> temp;
		for(int j = 0; j < l; ++j){
			int b;
			assert(scanf("%1d", &b) == 1);
			if(b == 1){
				//temp.insert(temp.begin(), true);
				temp.push_back(true);
				c_req[j]++;
			}else
				temp.push_back(false);
				//temp.insert(temp.begin(), false);
		}
		req.insert(req.begin(), temp);
	}
	

	//for(int i = 0; i < l; ++i){
		//printf("c_curr[%d] = %d     ;;   c_req[%d] = %d\n", i, c_curr[i], i, c_req[i]);
	//}
	if(solved(curr.begin(), curr.end(), req.begin(), req.end())){
		printf("0\n");
		return;
	}


	bool maybeFlip[l];
	for(int i = 0; i < l; ++i)
		maybeFlip[i] = false;
	int c_maybeFlip = 0;



	int flipped = 0;

	for(int i = 0; i < l; ++i){
		if(c_curr[i] == c_req[i] && c_curr[i] == n/2){
			c_maybeFlip++;
			maybeFlip[i] = true;
		}else if(c_curr[i] == c_req[i]){
			// DO NOTHING
		}else if(c_req[i] == n - c_curr[i]){
			//FLIP
			flipped++;
			//printf("bit = %d\n", i);
			//print2DArray(curr.begin(), curr.end());
			c_curr[i] = c_req[i];
			flip(curr.begin(), curr.end(), i);
			//print2DArray(curr.begin(), curr.end());
		}else{
			// CANNOT FIND SOLUTION
			//printf("c_curr[%d] = %d  ;  c_req[%d] = %d", i, c_curr[i], i, c_req[i]);
			printf("NOT POSSIBLE\n");
			return;
		}
	}
	
	if(solved(curr.begin(), curr.end(), req.begin(), req.end())){
		printf("%d\n", flipped);
		return;
	}
	
	if(c_maybeFlip == 0){
		printf("NOT POSSIBLE\n");
		return;
	}
	printf("c-maybeFlip = %d\n", c_maybeFlip);
	int bitsMaybe[c_maybeFlip];

	int j = 0;
	for(int i = 0; i < l; ++i){
		if(maybeFlip[i]){
			bitsMaybe[j] = i;
			j++;
		}
	}
	
	bool bitsToFlip[c_maybeFlip];
	for(int i = 1; i < c_maybeFlip ; ++i){
		bitsToFlip[i] = false;
	}
	bitsToFlip[0] = true;


	int numToFlipThisPass = 1;
	while(true){
		/*for(int i = 0; i < c_maybeFlip; ++i){
			printf("%d: ", i);
			if(bitsToFlip[i])
				printf("1\n");
			else
				printf("0\n");
		}*/
		for(int i = 0; i < c_maybeFlip; ++i){
			if(bitsToFlip[i]){
				//printf("bitsMaybe[%d] = %d\n", i, bitsMaybe[i]);
				flip(curr.begin(), curr.end(), bitsMaybe[i]);
				flipped++;
			}
		}


		if(solved(curr.begin(), curr.end(), req.begin(), req.end())){
			printf("%d\n", flipped);
			return;
		}else{
			for(int i = 0; i < c_maybeFlip; ++i){
				if(bitsToFlip[i]){
					flip(curr.begin(), curr.end(), bitsMaybe[i]);
					flipped--;
				}
			}
		}
		if(!prev_permutation(bitsToFlip, bitsToFlip + c_maybeFlip)){
			if(numToFlipThisPass == c_maybeFlip){
				printf("NOT POSSIBLE\n");
				return;
			}
			for(int i = 1; i < c_maybeFlip ; ++i){
				bitsToFlip[i] = false;
			}
			numToFlipThisPass++;
			for(int i = 0; i < numToFlipThisPass; ++i){
				bitsToFlip[i] = true;
			}
		}

	}



	//printf("%d\n", answer);
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
