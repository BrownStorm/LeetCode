class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        return dfs(0, 0, visited, m, n, k);
    }
private:
    int get(int x) {
        int res=0;
        for (; x; x /= 10) {
            res += x % 10;
        }
        return res;
    }
    int dfs(int i, int j, vector<vector<bool>> &visited, int m, int n, int k) {
        if(i >= m || j >= n || k < get(i) + get(j) || visited[i][j]) return 0;
        visited[i][j] = true;
        return 1 + dfs(i + 1, j, visited, m, n, k) +
                   dfs(i, j + 1, visited, m, n, k);
    }
};