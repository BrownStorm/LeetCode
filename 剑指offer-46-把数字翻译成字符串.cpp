class Solution {
public:
    int translateNum(int num) {
        int a1 = 0, a2 = 1, ans = 1;
        if (num == 0) return 1;
        stack<int> st;
        int t;
        while (num) {
            t = num % 10;
            num /= 10;
            st.push(t);
        }
        t = 0;
        while (!st.empty()) {
            if (t * 10 + st.top() < 26 && t != 0) {
                ans = a1 + a2;
            }
            t = st.top();
            a1 = a2;
            a2 = ans;
            st.pop();
        }
        return ans;
    }
};