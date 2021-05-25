class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int size1 = pushed.size(), size2 = popped.size(), p1 = 0, p2 = 0;
        stack<int> s;
        while (p1 != size1) {
            s.push(pushed[p1++]);
            while (p2 != size2 && s.size() && s.top() == popped[p2]) {
                s.pop();
                p2++;
            }
        }
        return s.size() ? false : true;
    }
};