#include "cjheader.h"
#include "./BigIntLib/BigIntegerLibrary.hh"

using namespace std;


/*
 * Global variables that are needed should be declared here
 */


/**********************************************************/


int main(){
	BigInteger a = 674535;
	BigInteger b = 432748979;

	const BigInteger c = a * b;
	cout << (a * b);
	return 0;
}
