#include <iostream>

using namespace std;

#define PROBLEM_2

#ifdef PROBLEM_2

#define MAX_NUM 10000000
#define SHIFT5 5 // int를 bit로 바꾸기 위해(32 == 2진수 100000) shift >> 5 == 1

int arr[(MAX_NUM + 1)>>SHIFT5];

void set(int n) {

}
#endif // PROBLEM_2
int main() {
	cout << size(arr);

	return 0;
}