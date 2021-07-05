class Solution {
public:
    int func(int a, int b) {
        return b ? func(b, a % b) : a;
    }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int maxNum = 2;
        for (int i = 0; i < n; ++i) {
            map<pair<int, int>, int> count;
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    double dx = points[i][0] - points[j][0];
                    double dy = points[i][1] - points[j][1];
                    int t = 1;
                    if (dx == 0) {
                        dy = 1;
                    } else if (dy == 0) {
                        dx = 0;
                    } else {
                        if (dy < 0) {
                            dx = -dx;
                            dy = -dy;
                        }
                        t = func(dy, dx);
                    }
                    pair<int, int> gradient(dx / t, dy / t);
                    if (count.count(gradient)) {
                        ++count[gradient];
                    } else {
                        count[gradient] = 2;
                    }
                    if (count[gradient] > maxNum) {
                        maxNum = count[gradient];
                    }
                }
            }
        }
        return maxNum;
    }
};