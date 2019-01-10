#include <cjheader.h>


class interval{
public:
	int left;
	int right;
	int value;

	/*
	int getw() { return left; };
	int gete() { return right; };
	int geth() { return value; };
	void seth(int newh) { h = newh; };
	void sete(int newe) { e = newe; };
	void setw(int neww) { w = neww; };*/
};

class intervalSet{
public:
	list<interval> set;
	bool insert(interval);
	int getMaxVal(int, int);
	bool mergeLeft(interval, interval);
	bool mergeRight(interval, interval);
};

bool intervalSet::mergeLeft(interval left, interval original){

}


bool intervalSet::insert(interval interv){

	auto it = set.begin();
	if(interv.right <= (*it).left){
		// insert at beginning
		set.emplace_front(interv);
		return true;
	}

	auto rit = set.rbegin();
	if(interv.left >= (*rit).right){
		// insert at end
		set.emplace_back(interv);
		return true;
	}


	/*if(interv.left <= (*it).left){
		// starts at or before beginning
		if(interv.value > (*it).value){
			(*it).left = min((*it).right, interv.right); // shrink

			while((*it).left == (*it).right){
				it = set.erase(it);
				(*it).left = min((*it).right, interv.right); // shrink
			}
			return true;
		}
		else if(interv.value < (*it).value){

		}
	}*/

	while(interv.left > (*it).left){
		++it;
	}




}

int intervalSet::getMaxVal(int left, int right){

}
