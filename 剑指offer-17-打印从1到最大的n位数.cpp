class Solution {
public:
    vector<int> ans;

    vector<int> printNumbers(int n) {
        if (n <= 0) return ans;
        string number(n, '0');

        for (int i = 0; i < 10; ++i) {
            number[0] = i + '0';
            func(number, n, 0);
        }

        return ans;
    }

    void func(string number, int length, int index) {
        if (length - 1 == index) {
            print(number);
            return;
        }
        for (int i = 0; i < 10; ++i) {
            number[index + 1] = i + '0';
            func(number, length, index + 1);
        }
    }

    void print(string number) {
        for (int i = 0; i < number.length(); ++i)
            if (number[i] != '0') {
                ans.push_back(stoi(number.substr(i)));
                return;
            }
    }


};