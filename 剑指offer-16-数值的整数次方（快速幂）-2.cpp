class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        if (n < 0) {
            x = 1 / x;
            n = -(n + 1);   // ���ﲻ��ֱ�� n = -n;��Ϊ-INT_MIN�ᵼ�����
            ans *= x;       // n��ǰһ����ansҲͬ��Ҫ��ǰһ��
        }
        while (n) {
            if (n & 1) ans *= x;
            n >>= 1;
            x *= x;
        }
        return ans;
    }
};