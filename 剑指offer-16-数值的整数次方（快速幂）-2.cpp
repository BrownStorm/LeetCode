class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        if (n < 0) {
            x = 1 / x;
            n = -(n + 1);   // 这里不能直接 n = -n;因为-INT_MIN会导致溢出
            ans *= x;       // n向前一步，ans也同样要向前一步
        }
        while (n) {
            if (n & 1) ans *= x;
            n >>= 1;
            x *= x;
        }
        return ans;
    }
};