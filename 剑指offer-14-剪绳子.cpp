class Solution {
public:
    int cuttingRope(int n) {
        int dp[n];
        switch (n){
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 2;
        default:
            break;
        }
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i < n; ++i) {
            int maxNum = 0;
            for (int j = 0;j < i / 2 + 1; ++j) {
                maxNum = max(maxNum, max(j + 1, dp[j]) * max(i - j, dp[i - j - 1]));
            }
            dp[i] = maxNum;
        }
        return dp[n - 1];
    }
};