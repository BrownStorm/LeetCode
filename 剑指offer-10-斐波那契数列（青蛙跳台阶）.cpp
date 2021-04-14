class Solution {
public:
    long long fib(int n) {
        long long num1 = 1, num2 = 0, num = 0;
        if (n == 0) return 0;
        else if (n == 1) return 1;
        else {
            for (unsigned int i = 2; i <= n; i++) {
                num = (num1 + num2) % 1000000007;
                num2 = num1;
                num1 = num;
            }
            return num;
        }
    }
};