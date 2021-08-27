#include <iostream>
#include <vector>
#include <algorithm>

#define MAXSIZE		100

using namespace std;

void merge(vector<int> &data, int lo, int mi, int hi) {
	int* A = &data[0] + lo;
	int lb = mi - lo;
	vector<int> B(data.begin() + lo, data.begin() + mi);
	int lc = hi - mi;
	int* C = &data[0] + mi;
	for (int i = 0, j = 0, k = 0; j < lb;) {
		if (lc <= k || B[j] <= C[k])
			A[i++] = B[j++];
		if (k < lc && C[k] < B[j])
			A[i++] = C[k++];
	}
}

void MergeSort(vector<int>& data, int start, int end) {
	int lo = start, hi = end;
	if (hi - lo < 2) return;
	int mi = (lo + hi) / 2;
	MergeSort(data, lo, mi);
	MergeSort(data, mi, hi);
	merge(data, lo, mi, hi);
}

int main() {
	vector<int> data;
	srand(time(NULL));
	for (int i = 0; i < MAXSIZE; ++i) {
		data.push_back(rand() % (2 * MAXSIZE));
	}

	MergeSort(data, 0, MAXSIZE);

	for (auto num : data) {
		cout << num << " ";
	}
	cout << endl;
	for (int i = 0; i < data.size() - 1; ++i) {
		if (data[i] > data[i + 1]) {
			cout << "error" << endl;
			cout << i << endl;
			break;
		}
	}
	cout << "OK" << endl;
	return 0;
}