#include <iostream>
#include <time.h>

using namespace std;

void Swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int RangeInRange(int start, int end) {
	srand((unsigned)time(NULL));
	return start + rand() % (end - start);
}

int partition(int data[], int length, int start, int end) {
	//for (int i = 0; i < length; i++) {
	//	cout << data[i] << " ";
	//}
	//cout << endl;
	if (length <= 0 || start < 0 || end >= length || data == nullptr) cerr << "error" << endl;
	int index = RangeInRange(start, end);
	swap(data[index], data[end]);

	int small = start - 1;
	for (int i = start; i < end; ++i) {
		if (data[i] < data[end]) {
			swap(data[i], data[++small]);
		}
	}
	swap(data[++small], data[end]);
	return small;
}

void QuickSort(int data[], int length, int start, int end) {
	if (start == end) return;
	int index = partition(data, length, start, end);
	//cout << index << endl;
	if (start < index) QuickSort(data, length, start, index - 1);
	if (index < end) QuickSort(data, length, index + 1, end);
}



int main() {
	int data[] = { 5, 8, 50, -98, 74, 22, 66, 43, 46, 21 };
	QuickSort(data, 10, 0, 9);
	for (auto num : data) {
		cout << num << " ";
	}
	cout << endl;
	return 0;
}