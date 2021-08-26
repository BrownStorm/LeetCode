#include <iostream>
#include <vector>
#include <algorithm>

#define MAXSIZE		100

using namespace std;

int partition(vector<int>& data, int length, int start, int end) {
	if (length <= 0 || start < 0 || end >= length) cerr << "error" << endl;
	int index = start - 1;
	for (int i = start; i < end; ++i) {
		if (data[i] < data[end]) {
			swap(data[i], data[++index]);
		}
	}
	swap(data[++index], data[end]);
	return index;
}

void QuickSort(vector<int> &data, int length, int start, int end) {
	if (start == end) return;
	int index = partition(data, length, start, end);
	if (start < index) QuickSort(data, length, start, index - 1);
	if (index < end) QuickSort(data, length, index + 1, end);
}


int main() {
	vector<int> data;
	srand(time(NULL));
	for (int i = 0; i < MAXSIZE; ++i) {
		data.push_back(rand() % (2 * MAXSIZE));
	}
	QuickSort(data, data.size(), 0, MAXSIZE - 1);
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