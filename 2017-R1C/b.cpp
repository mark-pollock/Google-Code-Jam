#include "cjheader.h"


using namespace std;
int currCase = 0;
int t;

/*
 * Global variables that are needed should be declared here
 */
int C[1440];
int J[1440];
int Csmallest, Jsmallest;
int CsmallestEnd, CsmallestStart, JsmallestEnd, JsmallestStart;

/**********************************************************/
void findCsmallest(){
	// Finding Smallest in C

	Csmallest = 1500;

	int last = -1;
	int lastEnd, lastStart;
	lastEnd = -1;
	int smallestEnd, smallestStart;
	smallestEnd = 1500;
	smallestStart = 1500;
	for(int i = 0; i < 1440; ++i){
		if(C[i] != last && last != -1 && C[i] == 0){
			lastEnd = i;
		}else if(C[i] != last && last != -1 && C[i] == 1 && lastEnd != -1){
			// found start
			int distance = i - lastEnd;
			bool allowed = true;
			for(int j = lastEnd; j < i; ++j){
				if(J[j] == 1){
					allowed = false;
					break;
				}
			}
			if (distance < Csmallest && allowed){
				Csmallest = distance;
				CsmallestEnd = lastEnd;
				CsmallestStart = i;
			}
		}
		last = C[i];
	}
	int Cfirst, Clast;
	Cfirst = -1;
	Clast = -1;
	for(int i = 0; i < 1440; ++i){
		if(Cfirst == -1 && C[i] == 1){
			Cfirst = i;
		}
		if(C[i] == 1)
			Clast = i;
	}
	int distance = (1439 - Clast) + Cfirst;

	bool allowed = true;
	for(int j = Clast; j < 1440; ++j){
		if(J[j] == 1){
			allowed = false;
			break;
		}
	}
	for(int j = 0; j < Cfirst; ++j){
		if(J[j] == 1){
			allowed = false;
			break;
		}
	}
	if (distance < Csmallest && allowed && distance > 0){
		Csmallest = distance;
		CsmallestEnd = Clast;
		CsmallestStart = Cfirst;
	}
}

void findJsmallest(){
	// Finding Smallest in C

	Jsmallest = 1500;

	int last = -1;
	int lastEnd, lastStart;
	lastEnd = -1;
	int smallestEnd, smallestStart;
	smallestEnd = 1500;
	smallestStart = 1500;
	for(int i = 0; i < 1440; ++i){
		if(J[i] != last && last != -1 && J[i] == 0){
			lastEnd = i;
		}else if(J[i] != last && last != -1 && J[i] == 1 && lastEnd != -1){
			// found start
			int distance = i - lastEnd;
			bool allowed = true;
			for(int j = lastEnd; j < i; ++j){
				if(C[j] == 1){
					allowed = false;
					break;
				}
			}
			if (distance < Jsmallest && allowed){
				Jsmallest = distance;
				JsmallestEnd = lastEnd;
				JsmallestStart = i;
			}
		}
		last = J[i];
	}
	int Jfirst, Jlast;
	Jfirst = -1;
	Jlast = -1;
	for(int i = 0; i < 1440; ++i){
		if(Jfirst == -1 && J[i] == 1){
			Jfirst = i;
		}
		if(J[i] == 1)
			Jlast = i;
	}
	int distance = (1439 - Jlast) + Jfirst;

	bool allowed = true;
	for(int j = Jlast; j < 1440; ++j){
		if(C[j] == 1){
			allowed = false;
			break;
		}
	}
	for(int j = 0; j < Jfirst; ++j){
		if(C[j] == 1){
			allowed = false;
			break;
		}
	}
	if (distance < Jsmallest && allowed && distance > 0){
		Jsmallest = distance;
		JsmallestEnd = Jlast;
		JsmallestStart = Jfirst;
	}
}

int sumC(){
	int sum = 0;
	for(int i = 0; i < 1440; ++i){
		sum += C[i];
	}
	return sum;
}
int sumJ(){
	int sum = 0;
	for(int i = 0; i < 1440; ++i){
		sum += J[i];
	}
	return sum;
}

void joinCSmallest(){
	if(CsmallestEnd < CsmallestStart){
		for(int i = CsmallestEnd; i <= CsmallestStart; ++i){
			C[i] = 1;
		}
	}else{
		for(int i = CsmallestEnd; i < 1440; ++i){
			C[i] = 1;
		}
		for(int i = 0; i <= CsmallestStart; ++i){
			C[i] = 1;
		}
	}
}

void joinJSmallest(){
	if(JsmallestEnd < JsmallestStart){
		for(int i = JsmallestEnd; i <= JsmallestStart; ++i){
			J[i] = 1;
		}
	}else{
		for(int i = JsmallestEnd; i < 1440; ++i){
			J[i] = 1;
		}
		for(int i = 0; i <= JsmallestStart; ++i){
			J[i] = 1;
		}
	}
}

void runTestCase(){
	printf("Case #%d: ", ++currCase);
	int Ac, Aj;
	cin >> Ac;
	cin >> Aj;

	for(int i = 0; i < 1440; ++i){
		C[i] = 0;
		J[i] = 0;
	}

	for(int i = 0; i < Ac; ++i){
		int Ci, Di;
		cin >> Ci;
		cin >> Di;
		for(int j = Ci; j < Di; ++j){
			C[j] = 1;
		}
	}
	for(int i = 0; i < Aj; ++i){
		int Ji, Ki;
		cin >> Ji;
		cin >> Ki;
		for(int j = Ji; j < Ki; ++j){
			J[j] = 1;
		}
	}

	bool operated = true;
	while(operated){


		findCsmallest();
		findJsmallest();

		/*cout << "Csmallest = " << Csmallest << endl;
		cout << "CsmallestStart = " << CsmallestStart << endl;
		cout << "CsmallestEnd = " << CsmallestEnd << endl;

		cout << "Jsmallest = " << Jsmallest << endl;
		cout << "jsmallestStart = " << JsmallestStart << endl;
		cout << "jsmallestEnd = " << JsmallestEnd << endl;*/

		operated = false;
		if(Csmallest <= Jsmallest && sumC() + Csmallest <= 720){
			joinCSmallest();
			operated = true;
		}else if(sumJ() + Jsmallest <=720){
			joinJSmallest();
			operated = true;
		}
	}
	int changesC = 0;
	int changesJ = 0;
	int lastC, lastJ;
	lastC = C[0];
	lastJ = J[0];
	for(int i = 1; i < 1440; ++i){
		if(C[i] != lastC){
			//cout << "C[" << i-1 << "] = " << C[i-1] << ", C[" << i << "] = " << C[i] << endl;
			changesC++;
			lastC = C[i];
		}
		if(J[i] != lastJ){
			//cout << "J[" << i-1 << "] = " << J[i-1] << ", J[" << i << "] = " << J[i] << endl;
			changesJ++;
			lastJ = J[i];
		}
	}

	if(C[1439] != C[0])
		changesC++;
	if(J[1439] != J[0])
		changesJ++;

	//cout << "changesC = " << changesC << endl;
	//cout << "changesJ = " << changesJ << endl;



	cout << max(max(changesC, changesJ), 2) << endl;





	//printf("%d\n", result);

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
