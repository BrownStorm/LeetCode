#include <iostream>
#include <vector>
#include <algorithm>

#define MAXSIZE		1000000

using namespace std;

class prority_queue {
public:
	vector<int> m_queue;
	int m_size;

public:
	prority_queue(vector<int>& v) {
		m_size = v.size();
		m_queue = v;
		for (int i = m_size / 2 - 1, j; i >= 0; --i) {
			down(i);
		}
	}

	void push(int num) {
		insert(num);
	}

	int pop() {
		return delMax();
	}

	void heap_sort() {
		while (m_size) {
			swap(m_queue[0], m_queue[--m_size]);
			down(0);
		}
	}

	bool verify_sort() {
		int flag = true;
		for (int i = 0; i < MAXSIZE - 1; ++i) {
			if (m_queue[i] > m_queue[i + 1]) {
				cout << i << endl;
				cout << "sort_ERROR" << endl;
				flag = false;
				break;
			}
		}
		return flag;
	}

	bool verify_heap() {
		int flag = true;
		for (int i = 0, a, b; i < m_size / 2 - 1; ++i) {
			a = getLChild(i);
			b = getRChild(i);
			if (m_queue[i] < m_queue[a] && m_queue[i] < m_queue[b]) {
				flag = false;
				cout << i << endl;
				cout << "heap_ERROR" << endl;
			}
		}
		return flag;
	}

	void print() {
		for_each(m_queue.begin(), m_queue.end(), [](int a) { cout << a << " "; });
		cout << endl;
	}

private:
	int getLChild(int i) {
		int j = 2 * i + 1;
		return j >= m_size ? -1 : j;
	}

	int getRChild(int i) {
		int j = 2 * i + 2;
		return j >= m_size ? -1 : j;
	}

	int getParent(int i) {
		return i ? (i - 1) / 2 : -1;
	}

	int delMax() {
		int max = m_queue[0];
		m_queue[0] = m_queue[--m_size];
		m_queue.erase(m_queue.begin() + m_size);
		down(0);
		return max;
	}

	void down(int start) {
		int i = start, j;
		while (i != (j = properParent(i))) {
			swap(m_queue[i], m_queue[j]);
			i = j;
		}
	}

	void up() {
		int i = m_size - 1;
		int j = getParent(i);
		while (j != -1 && j != properParent(j)) {
			swap(m_queue[i], m_queue[j]);
			i = j;
			j = getParent(i);
		}
	}

	int properParent(int i) {
		int a = getLChild(i), b = getRChild(i);
		if (a == -1 && b == -1) return i;
		else if (a == -1) {
			if (m_queue[i] < m_queue[b]) return b;
			else return i;
		}
		else if (b == -1) {
			if (m_queue[i] < m_queue[a]) return a;
			else return i;
		}
		else {
			if (max(max(m_queue[a], m_queue[b]), m_queue[i]) == m_queue[i]) return i;
			else if (m_queue[a] > m_queue[b]) return a;
			else return b;
		}
	}

	void insert(int i) {
		m_size++;
		m_queue.push_back(i);
		up();
	}
};

int main() {
	vector<int> data;
	srand(time(NULL));
	for (int i = 0; i < MAXSIZE; ++i) {
		data.push_back(rand() % (2 * MAXSIZE));
	}

	prority_queue pq(data);
	//pq.print();
	if (pq.verify_heap()) {
		cout << "heap_OK" << endl;
	}

	pq.heap_sort();

	//pq.print();
	pq.verify_sort();
	if (pq.verify_heap()) {
		cout << "sort_OK" << endl;
	}

	return 0;
}