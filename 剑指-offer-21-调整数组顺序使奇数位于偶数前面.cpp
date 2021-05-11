class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        auto odd = find_if(nums.begin(), nums.end(), [](int num) { return num % 2 != 0; });
        auto eve = find_if(nums.begin(), nums.end(), [](int num) { return num % 2 == 0; });
        if (odd == nums.end() || eve == nums.end()) return nums;
        if (eve == nums.begin()) {
            swap(*odd, *eve);
        }
        while (true) {
            odd = find_if(++odd, nums.end(), [](int num) { return num % 2 != 0; });
            eve = find_if(eve, odd, [](int num) { return num % 2 == 0; });
            if (odd == nums.end()) break;
            swap(*odd, *eve);
        }
        return nums;
    }
};