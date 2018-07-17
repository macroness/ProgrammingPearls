#include <iostream>
#include "column_4.h"

using namespace std;

static int bSearch(const int x[], const int& n, const int& t) {
	if (n == 0) return -1;

	const int m = n / 2;
	if (x[m] == t) {
		return m;
	}
	else if (x[m] < t) {
		const int ret = bSearch(&x[m + 1], n - m - 1, t);
		if (ret == -1)
			return ret;
		else
			return ret + m + 1; 
	}
	else {// x[m] > t 
		return bSearch(x, m, t);
	}
}

static void initArr(int x[], const int& n) {
	
}

void testColumn_4() {
	int x[] = { 0,1,2,3,4,5,6,7 };

	const int pos = bSearch(x, 8, 6);

	if (pos == -1) {
		cout << "search fail !\n";
	}
	else {
		cout << "position : " << pos << "\n";
	}
}