class Solution {
public:
    int minArray(vector<int>& numbers) {
        if (numbers.size() == 0) return -1;
        else if (numbers.size() == 1) return numbers[0];
        int lo = 0, hi = numbers.size() - 1;
        while(abs(lo - hi) != 1){
            int mid = (lo + hi) / 2;
            if (numbers[lo] < numbers[hi]) {
                lo = mid;
            } else if (numbers[lo] > numbers[mid]){
                hi = mid;
            } else lo++;
        }
        return min(numbers[lo], numbers[hi]);
    }
};