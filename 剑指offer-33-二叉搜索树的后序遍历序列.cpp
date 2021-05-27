class Solution {
public:
    bool func(vector<int>& postorder, int i, int j) {
        if (i >= j) return true;
        int t = i;
        while (postorder[j] > postorder[t]) t++;
        int m = t;
        while (postorder[j] < postorder[t]) t++;
        return t == j && func(postorder, i, m - 1) && func(postorder, m, j - 1);

    }
    bool verifyPostorder(vector<int>& postorder) {
        return func(postorder, 0, postorder.size() - 1);
    }
};