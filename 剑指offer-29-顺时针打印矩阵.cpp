

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int len1 = matrix.size();
        if (len1 == 0) return {};
        int len2 = matrix[0].size();
        string status = "right";
        double step = 0.5;
        int i = 0, j = 0, count = 0;
        vector<int> ans;
        while (true) {
            if (status == "right") {
                count = len2 - int(step);
                if (count <= 0) break;
                while (count-- > 0) {
                    ans.push_back(matrix[i][j++]);
                }
                i++;
                j--;
            }
            else if (status == "down") {
                count = len1 - int(step);
                if (count <= 0) break;
                while (count-- > 0) {
                    ans.push_back(matrix[i++][j]);
                }
                j--;
                i--;
            }
            else if (status == "left") {
                count = len2 - int(step);
                if (count <= 0) break;
                while (count-- > 0) {
                    ans.push_back(matrix[i][j--]);
                }
                i--;
                j++;
            }
            else {
                count = len1 - int(step);
                if (count <= 0) break;
                while (count-- > 0) {
                    ans.push_back(matrix[i--][j]);
                }
                j++;
                i++;
            }
            step += 0.5;
            if (status == "right") {
                status = "down";
                continue;
            }
            else if (status == "down") {
                status = "left";
                continue;
            }
            else if (status == "left") {
                status = "up";
                continue;
            }
            else {
                status = "right";
                continue;
            }
        }
        return ans;
    }
};