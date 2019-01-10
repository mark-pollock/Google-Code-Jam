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

using namespace std;
int currCase = 0;

/*
 * Global variables that are needed should be declared here
 */


/**********************************************************/
bool findSol(int p1, int p2, char *a, int size){

	char first;
	bool firstSign = false;
	char second;
	bool secondSign = false;
	char third;
	bool thirdSign = false;



	first = a[0];
	for(int i = 1; i < p1; ++i){
		if(first == 'i' && a[i] == 'i'){
			first = '1';
			firstSign = !firstSign;
		}
		else if(first == 'i' && a[i] == 'j'){
			first = 'k';
		}else if(first == 'i' && a[i] == 'k'){
			first = 'j';
			firstSign = !firstSign;
		}


		else if(first == 'j' && a[i] == 'i'){
			first = 'k';
			firstSign = !firstSign;
		}else if(first == 'j' && a[i] == 'j'){
			first = '1';
			firstSign = !firstSign;
		}else if(first == 'j' && a[i] == 'k'){
			first = 'i';
		}


		else if(first == 'k' && a[i] == 'i'){
			first = 'j';
		}else if(first == 'k' && a[i] == 'j'){
			first = 'i';
			firstSign = !firstSign;
		}else if(first == 'k' && a[i] == 'k'){
			first = '1';
			firstSign = !firstSign;
		}

		else if(first == '1' && a[i] == 'i'){
			first = 'i';
		}else if(first == '1' && a[i] == 'j'){
			first = 'j';
		}else if(first == '1' && a[i] == 'k'){
			first = 'k';
		}
	}

	if (first != 'i' || firstSign != false){
		return false;
	}


	second = a[p1];
	for(int i = p1 + 1; i < p2; ++i){
		if(second == 'i' && a[i] == 'i'){
			second = '1';
			secondSign = !secondSign;
		}
		else if(second == 'i' && a[i] == 'j'){
			second = 'k';
		}else if(second == 'i' && a[i] == 'k'){
			second = 'j';
			secondSign = !secondSign;
		}


		else if(second == 'j' && a[i] == 'i'){
			second = 'k';
			secondSign = !secondSign;
		}else if(second == 'j' && a[i] == 'j'){
			second = '1';
			secondSign = !secondSign;
		}else if(second == 'j' && a[i] == 'k'){
			second = 'i';
		}


		else if(second == 'k' && a[i] == 'i'){
			second = 'j';
		}else if(second == 'k' && a[i] == 'j'){
			second = 'i';
			secondSign = !secondSign;
		}else if(second == 'k' && a[i] == 'k'){
			second = '1';
			secondSign = !secondSign;
		}

		else if(second == '1' && a[i] == 'i'){
			second = 'i';
		}else if(second == '1' && a[i] == 'j'){
			second = 'j';
		}else if(second == '1' && a[i] == 'k'){
			second = 'k';
		}
	}

	if (second != 'j' || secondSign != false){
		return false;
	}



	third = a[p2];
	for(int i = p2 + 1; i < size; ++i){
		if(third == 'i' && a[i] == 'i'){
			third = '1';
			thirdSign = !thirdSign;
		}
		else if(third == 'i' && a[i] == 'j'){
			third = 'k';
		}else if(third == 'i' && a[i] == 'k'){
			third = 'j';
			thirdSign = !thirdSign;
		}


		else if(third == 'j' && a[i] == 'i'){
			third = 'k';
			thirdSign = !thirdSign;
		}else if(third == 'j' && a[i] == 'j'){
			third = '1';
			thirdSign = !thirdSign;
		}else if(third == 'j' && a[i] == 'k'){
			third = 'i';
		}


		else if(third == 'k' && a[i] == 'i'){
			third = 'j';
		}else if(third == 'k' && a[i] == 'j'){
			third = 'i';
			thirdSign = !thirdSign;
		}else if(third == 'k' && a[i] == 'k'){
			third = '1';
			thirdSign = !thirdSign;
		}

		else if(third == '1' && a[i] == 'i'){
			third = 'i';
		}else if(third == '1' && a[i] == 'j'){
			third = 'j';
		}else if(third == '1' && a[i] == 'k'){
			third = 'k';
		}
	}

	if (third != 'k' || thirdSign != false){
		return false;
	}



	return true;
}

void runTestCase(){
	printf("Case #%d: ", ++currCase);



	int l;
	int x;
	assert(scanf("%d ", &l) == 1);
	assert(scanf("%d\n", &x) == 1);

	char str[x*l];

	bool li = false;
	bool lj = false;
	bool lk = false;
	for(int i = 0; i < l; ++i){
		assert(scanf("%c", &str[i]) == 1);
		if(str[i] == 'i')
			li = true;
		else if(str[i] == 'j')
			lj = true;
		else if(str[i] == 'k')
			lk = true;
	}

	int numLetters = 0;
	if(li)
		numLetters++;
	if(lj)
		numLetters++;
	if(lk)
		numLetters++;

	if(numLetters == 1){
		printf("NO\n");
		return;
	}


	for(int j = 0; j < x; ++j){
		for(int i = 0; i < l; ++i){
			str[i + j*l] = str[i];
		}
	}

	/*for(int i = 0; i < x*l; ++i){
		printf("str[%d] = %c\n", i, str[i]);
	}*/

	bool sol = false;

	int firstPos = 1;
	int secondPos = 2;

	int count = 0;
	while(firstPos < x*l - 1 && secondPos < x*l){

		count++;
		assert(firstPos < x*l);
		assert(secondPos < x*l + 1);

		sol = findSol(firstPos, secondPos, str, x*l);
		if(sol)
			break;
		else{
			if(secondPos == x*l - 1){
				if(firstPos >= x*l -2){
					break;
				}else{
					firstPos++;
					secondPos = firstPos + 1;
				}
			}else{
				secondPos++;
			}
		}
		if (count > 1000000){
			break;
		}
	}

	if(sol){
		printf("YES\n");
	}else{
		printf("NO\n");
	}

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
