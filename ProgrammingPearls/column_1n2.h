#include <process.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>

using namespace std;

#define MAX_NUM			100000 // �ִ� ���� ����
#define MAX_RAND_NUM	10000 // ���� ����
int randNum[MAX_NUM];


void swap(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

void createRandNum() {
	for (int i = 0; i < MAX_NUM; ++i) {
		randNum[i] = i;
	}
	srand((unsigned int)_getpid() + (unsigned int)time(NULL));

	// ���� 100������ 1000���� ���� ������ ������ ���ڷ� ������
	for (int i = 0; i < MAX_RAND_NUM; ++i) {
		swap(randNum[i], randNum[rand()% MAX_NUM]);
	}
}

int qsortArr[MAX_RAND_NUM];

int compareNum(const void* x, const void* y) {
	return *(int *)x - *(int *)y;
}

void setQsortArr() {
	for (int i = 0; i < MAX_RAND_NUM; ++i) {
		qsortArr[i] = randNum[i];
	}
}

void testQsort() {
	qsort(qsortArr, MAX_RAND_NUM, sizeof(int), compareNum);
}

void testSet() {
	set<int> setArr;

	for (int i = 0; i < MAX_RAND_NUM; ++i) {
		setArr.insert(randNum[i]);
	}
}

#define SHIFT5 5 // int�� bit�� �ٲٱ� ����(32 == 2���� 100000) shift >> 5 == 1

class BitVector {
public:
	BitVector() {
		int maxSize = size(m_bitArr);
		for (int i = 0; i < maxSize; ++i) {
			m_bitArr[i] = 0;
		}
	}

private:
	void setNum(int n) {
		m_bitArr[n >> SHIFT5] |= 1 << (n % 32);
	}

	void clearNum(int n) {
		m_bitArr[n >> SHIFT5] &= ~(1 << (n % 32));
	}

	bool exist(int n) {
		return m_bitArr[n >> SHIFT5] & 1 << (n % 32);
	}

public:
	void testBitSort() {
		for (int i = 0; i < MAX_RAND_NUM; ++i) {
			setNum(randNum[i]);
		}
	}

private:
	int m_bitArr[(MAX_NUM >> SHIFT5) + 1];
};

#define MAX_LENGTH 10000000
int list[MAX_LENGTH];

void init(int *pList) {
	for (int i = 0; i < MAX_LENGTH; ++i) {
		pList[i] = i;
	}
}

int gcd(int x, int y) {
	if (y == 0) {
		return x;
	}
	return gcd(y, x%y);
}

void swap_(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

void swapArr(int *pList, const int x, const int y, const int m) {
	
	for (int i = 0; i < m; ++i) {
		swap_(pList[x + i], pList[y + i]);
	}
}

void jugglingAction(int n) {

	init(list);
	int temp;
	const int g = gcd(MAX_LENGTH, n);
	for (int i = 0; i < g; ++i) {
		temp = list[i];
		int j = i;
		while (1) {
			int k = j + n;
			if (k >= MAX_LENGTH) {
				k -= MAX_LENGTH;
			}
			if (k == i) {
				break;
			}
			list[j] = list[k];
			j = k;
		}

		list[j] = temp;
	}
}

void change(int n) {

	init(list);
	int i = n;
	int p = n;
	int j = MAX_LENGTH - p;
	while (i != j) {
		if (i > j) {
			swapArr(list, p - i, p, j);
			i -= j;
		}
		else {
			swapArr(list, p - i, p + j - i, i);
			j -= i;
		}
	}
	swapArr(list, p - i, p, i);
}

void column_1() {

	clock_t start, end;

	start = clock();
	createRandNum();
	end = clock();

	cout << "���� ���� �ð�           : " << (double)(end - start) / CLOCKS_PER_SEC << "\n";

	BitVector bV;

	start = clock();
	bV.testBitSort();
	end = clock();

	cout << "��Ʈ ���� ���� ���� �ð� : " << (double)(end - start) / CLOCKS_PER_SEC << "\n";

	start = clock();
	testSet();
	end = clock();

	cout << "set ���� ���� �ð�       : " << (double)(end - start) / CLOCKS_PER_SEC << "\n";

	setQsortArr();
	start = clock();
	testQsort();
	end = clock();

	cout << "qsort ���� �ð�          : " << (double)(end - start) / CLOCKS_PER_SEC << "\n";

}

void column_2() {

	clock_t start, end;

	start = clock();
	change(1);
	end = clock();

	cout << "���۸� �ð�           : " << (double)(end - start) / CLOCKS_PER_SEC << "\n";
}