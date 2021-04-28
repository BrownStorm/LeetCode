class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        vector<vector<double>> vt;
        bool flag = true;
        if (n < 0) flag = false;
        if (n == 0) return 1;
        if (x == 1) return 1;
        if (x == -1) {
            if (n % 2 == 0) return 1;
            return -1;
        }
        if (n < 0){
            x = 1 / x;
            if (n == INT_MIN) {
                n = INT_MAX;
                ans *= x;
                vt.push_back({ans, 1.0});
            }
            n = abs(n);
        }
        while (vt.empty() || n != int(vt[vt.size() - 1][1])) {
            if (vt.empty()){
                ans *= x;
                vt.push_back({ans, 1.0});
            }
            else {
                if (2 * vt[vt.size() - 1][1] < n) {
                    ans *= vt[vt.size() - 1][0];
                    vt.push_back({ans, vt[vt.size() - 1][1] * 2});
                }
                else{
                        int i = 0;
                        while (true) {
                            if (vt[i][1] + vt[vt.size() - 1][1] == n ) {
                                ans *= vt[i][0];
                                vt.push_back({ans, double(n)});
                                break;
                            } else if (vt[i][1] + vt[vt.size() - 1][1] > n) {
                                ans *= vt[i - 1][0];
                                vt.push_back({ans, vt[i - 1][1] + vt[vt.size() - 1][1]});
                                i++;
                                break;
                            }
                            i++;
                        }
                    }
            }
        }
        
        return ans;
    }
};