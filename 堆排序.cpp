#include <iostream>
#include <vector>
#include <algorithm>

#define HEAPSIZE		100

using namespace std;

class m_Heap {
public:
	vector<int> m_heap;
	int m_size;
public:
	m_Heap(vector<int> &v) {
		for (auto num : v) {
			insert(num);
		}
	}
	
	int getLChild(int i) {
		int j = 2 * i + 1;
		return j < m_size ? j : -1;
	}

	int getRChild(int i) {
		int j = 2 * i + 2;
		return j < m_size ? j : -1;
	}

	int getParent(int i) {
		return i ? (i - 1) / 2 : -1;
	}

	void insert(int num) {
		m_heap.push_back(num);
		m_size++;
		up();
	}

	int up() {
		int i = m_size - 1;
		int j = getParent(i);
		while (j != -1 && j != properParent(j)) {
			swap(m_heap[i], m_heap[j]);
			i = j;
			j = getParent(i);
		}
		return i;
	}

	int down() {
		int i = 0;
		bool t = true;
		int j;
		while (i != (j = properParent(i))) {
			swap(m_heap[i], m_heap[j]);
			i = j;
		}
		return i;
	}

	void delMax() {
		swap(m_heap[0], m_heap[m_size - 1]);
		--m_size;
		down();
	}

	void m_heap_sort() {
		while (m_size) {
			swap(m_heap[0], m_heap[--m_size]);
			down();
		}
	}

private:
	int properParent(int i) {
		int a = getLChild(i), b = getRChild(i);
		if (a == -1 && b == -1) return i;
		else if (a == -1) {
			if (m_heap[b] > m_heap[i]) return b;
			else return i;
		}
		else if (b == -1) {
			if (m_heap[a] > m_heap[i]) return a;
			else return i;
		}
		else {
			if (max(max(m_heap[a], m_heap[b]), m_heap[i]) == m_heap[i]) return i;
			else if (m_heap[a] > m_heap[b]) return a;
			else return b;
		}
	}
};



int main() {
	srand(time(NULL));
	vector<int> arr;
	for (int i = 0, num = 0; i < HEAPSIZE; ++i) {
		arr.push_back(rand() % (HEAPSIZE * 2));
	}
	m_Heap h1(arr);
	for (auto num : h1.m_heap) cout << num << " ";
	cout << endl << "----------------------------" << endl;;
	h1.m_heap_sort();
	for (auto num : h1.m_heap) cout << num << " ";
	cout << endl;
}