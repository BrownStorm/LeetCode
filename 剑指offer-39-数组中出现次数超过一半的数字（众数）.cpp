class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        auto it1 = nums.begin();
        int count = 0;
        for (auto it2 = nums.begin(); it2 < nums.end(); it2++) {
            if (*it1 == *it2) count++;
            if (*it1 != *it2 && 2 * count == it2 - it1 + 1) {
                it1 = it2 + 1;
                count = 0;
            }
        }
        return *it1;
    }
};