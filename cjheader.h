#include <vector>
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
#include <limits.h>
#include <iostream>
#include <iomanip>
#include <limits.h>
#include <float.h>
#include <iterator>

using namespace std;

template <typename T>
void getNInputs(vector<T> *v, int n){

	for(int i = 0; i < n; ++i){
		T temp;
		cin >> temp;
		v->push_back(temp);
	}

	return;
}

template <typename T>
void printVector(const vector<T>& v, bool space){
	bool first = true;
	for(int i = 0; i < v.size(); ++i){
		if(!first && space)
			cout << " ";
		else
			first = false;

		cout << v[i];
	}
	cout << endl;
}

/*
 * returns the number of unique chars in a given string
 */
int nUniqueCharsInString(string &str){
	bool found[1 << CHAR_BIT] = { 0 };

	int n_distinct = 0;

	for(int i = 0; i < str.size(); ++i){
		if(!found[str[i]]){
			n_distinct++;
			found[str[i]] = true;
		}
	}
	return n_distinct;
}

void uniqueCharsInString(vector<char> &v, string &str){
	bool found[1 << CHAR_BIT] = { 0 };

	int n_distinct = 0;

	for(int i = 0; i < str.size(); ++i){
		if(!found[str[i]]){
			n_distinct++;
			v.push_back(str[i]);
			found[str[i]] = true;
		}
	}
	return;
}


int nUniqueChangesInCharsInString(string &str){
	if(str.size() == 0)
		return 0;
	char c = 0;
	int n_unique_changes = 0;
	for(int i = 0; i < str.size(); ++i){
		if (str[i] != c){
			n_unique_changes++;
			c = str[i];
		}
	}
	return n_unique_changes;
}


void uniqueChangesInCharsInString(vector<char> &v, string &str){
	if(str.size() == 0)
		return;
	char c = 0;
	for(int i = 0; i < str.size(); ++i){
		if (str[i] != c){
			v.push_back(str[i]);
			c = str[i];
		}
	}
	return;
}


/*
 * Returns the greatest common denominator
 */
template <typename T>
T gcd(T x, T y){

	T c = x % y;
	while(c != 0){
		x = y;
		y = c;
		c = x % y;
	}
	return y;
}

/*
 * Returns the reduced fraction of p, q
 */
template <typename T>
pair<T, T> reduce(T p, T q){
	pair<T, T> frac;
	frac.first = (p / gcd(p, q));
	frac.second = (q / gcd(p, q));
	return frac;
}


template <typename T>
bool isPowerOfTwo(T x){

	return (x & (x - 1)) == 0;

}

template <typename T>
bool isMultipleOfN(T x, int n){
	return x % n == 0;
}
/*
 * Returns y in x = n^y if x is a power of n,
 * else it return -1
 */
template <typename T>
T isPowerOfN(T x, int n){
	if(n == 2)
		return (x & (x - 1)) == 0;
	else{
		return -1; //FIX
	}
}


/*
 * Returns the lcm of two numbers
 */
template <typename T>
T lcm(T a, T b){
	return (a*b) / gcd(a, b);
}

template <template<class T, class All = std::allocator<T>> class A, class B>
B lcmContI(A<B> &c, typename A<B>::iterator it, typename A<B>::iterator end){
	if(it + 2 == end){
		return lcm(*it, *(it + 1));
	}else{
		return lcm(*it, lcmContI(c, it + 1, end));
	}
}


/*
 * Returns the lcm of all numbers in a container.
 */
template <template<class T, class All = std::allocator<T>> class A, class B>
B lcmCont(A<B> &c){
	typename A<B>::iterator start = c.begin();
	typename A<B>::iterator end = c.end();

	return lcmContI(c, start, end);
}


/*
 * Returns the sum of all elements in the container
 */
template <template<class T, class All = std::allocator<T>> class A, class B>
B sumCont(A<B> &c){
	B sum = 0;
	for(auto it = c.begin(); it != c.end(); ++it){
		sum += *it;
	}
	return sum;
}

/*
 * Computes the least squares of a container
 */
template <template<class T, class All = std::allocator<T>> class A, class B>
B leastSquaresC(A<B> &c){
	B C;
	C = sumCont(c) / c.size();
	return C;
}

int myCeil(double d, double eps = 10^-6){
	if(abs(round(d) - d) < eps){
		cout << "ceil7";
		return round(d);
	}else
		return ceil(d);
}

int myFloor(double d, double eps = 10^-6){
	if(abs(round(d) - d) < eps){
		cout << "floor7";
		return round(d);
	}else
		return floor(d);
}






/*
#define ROW b_len
#define COL a_len+b_len+2


int getCarry(int num) {
    int carry = 0;
    if(num>=10) {
        while(num!=0) {
            carry = num %10;
            num = num/10;
        }
    }
    else carry = 0;
    return carry;
}

int num(char a) {
    return int(a)-48;
}


string mulLarge(string &a, string &b){
    string ret;
    int a_len = a.length();
    int b_len = b.length();
    int mat[ROW][COL];
    for(int i =0; i<ROW; ++i) {
        for(int j=0; j<COL; ++j) {
            mat[i][j] = 0;

        }
    }

    int carry=0, n,x=a_len-1,y=b_len-1;
    for(int i=0; i<ROW; ++i) {
        x=a_len-1;
        carry = 0;
        for(int j=(COL-1)-i; j>=0; --j) {
            if((x>=0)&&(y>=0))  {
                n = (num(a[x])*num(b[y]))+carry;
                mat[i][j] = n%10;
                carry = getCarry(n);
            }
            else if((x>=-1)&&(y>=-1)) mat[i][j] = carry;
            x=x-1;
        }
        y=y-1;
    }

    carry = 0;
    int sum_arr[COL];
    for(int i =0; i<COL; ++i) sum_arr[i] = 0;
    for(int i=0; i<ROW; ++i) {
        for(int j=COL-1; j>=0; --j) {
            sum_arr[j] += (mat[i][j]);
        }
    }
    int temp;
    for(int i=COL-1; i>=0; --i) {
        sum_arr[i] += carry;
        temp = sum_arr[i];
        sum_arr[i] = sum_arr[i]%10;
        carry = getCarry(temp);
    }

    for(int i=0; i<COL; ++i) {
        ret.push_back(char(sum_arr[i]+48));
    }

    while(ret[0]=='0'){
        ret = ret.substr(1,ret.length()-1);
    }
    return ret;
}


string powLarge(string &a, int p){
	string temp = a;
	for(int i = 1; i < p; ++i){
		temp = mulLarge(temp, a);
	}
	return temp;
}

#define toDigit(c) (c-'0')

string addLarge(string &a, string &b){
	int aDigit = a.length();
	int bDigit = b.length();
	int carry = 0;
	string result;
	aDigit--;
	bDigit--;
	while(aDigit >= 0 || bDigit >= 0){
		if(aDigit < 0){
			int d = toDigit(b[bDigit]) + carry;
			carry = 0;
			while(d > 9){
				d -= 10;
				carry++;
			}
			bDigit--;
			result.push_back(char(d + '0'));
		}else if(bDigit < 0){
			int d = toDigit(a[aDigit]) + carry;
			carry = 0;
			while(d > 9){
				d -= 10;
				carry++;
			}
			aDigit--;
			result.push_back(char(d + '0'));
		}else{
			int d = toDigit(a[aDigit]) + toDigit(b[bDigit]) + carry;
			carry = 0;
			while(d > 9){
				d -= 10;
				carry++;
			}
			aDigit--;
			bDigit--;
			result.push_back(char(d + '0'));
		}
	}
	if(carry > 0){
		int count = 0;
		while(carry > 9){
			carry -= 10;
			count++;
		}
		result.push_back(char(carry + '0'));
		if(count > 0)
			result.push_back(char(count + '0'));
	}

	string resultRightWay;
	for(int i = result.size() - 1; i > -1; --i){
		resultRightWay.push_back(result[i]);
	}
	return resultRightWay;
}


string minusLarge(string &ag, string &bg){
	string a;
	string b;
	if(ag.length() > bg.length()){
		int numZeros = ag.length() - bg.length();
		int i = 0;
		while(numZeros > 0){
			b.push_back('0');
			numZeros--;
			a.push_back(ag[i]);
			i++;
		}
		for(int j = 0; j < bg.length(); ++j){
			a.push_back(ag[j + i]);
			b.push_back(bg[j]);
		}
	}else if(ag.length() < bg.length()){
		int numZeros = bg.length() - ag.length();
		int i = 0;
		while(numZeros > 0){
			a.push_back('0');
			numZeros--;
			b.push_back(bg[i]);
			i++;
		}
		for(int j = 0; j < bg.length(); ++j){
			b.push_back(bg[j + i]);
			a.push_back(ag[j]);
		}
	}

	// now a and b are the same length
	int carry = 0;
	string result;
	for(int digit = 0; digit < a.length(); ++digit){
		int d = toDigit(a[digit]) -
	}

	int carry = 0;
	string result;
	while(a.length() + )


	while(aDigit >= 0 || bDigit >= 0){
		if(aDigit < 0){
			int d = toDigit(b[bDigit]) + carry;
			carry = 0;
			while(d > 9){
				d -= 10;
				carry++;
			}
			bDigit--;
			result.push_back(char(d + '0'));
		}else if(bDigit < 0){
			int d = toDigit(a[aDigit]) + carry;
			carry = 0;
			while(d > 9){
				d -= 10;
				carry++;
			}
			aDigit--;
			result.push_back(char(d + '0'));
		}else{
			int d = toDigit(a[aDigit]) + toDigit(b[bDigit]) + carry;
			carry = 0;
			while(d > 9){
				d -= 10;
				carry++;
			}
			aDigit--;
			bDigit--;
			result.push_back(char(d + '0'));
		}
	}
	if(carry > 0){
		int count = 0;
		while(carry > 9){
			carry -= 10;
			count++;
		}
		result.push_back(char(carry + '0'));
		if(count > 0)
			result.push_back(char(count + '0'));
	}

	string resultRightWay;
	for(int i = result.size() - 1; i > -1; --i){
		resultRightWay.push_back(result[i]);
	}
	return resultRightWay;*/
//}
