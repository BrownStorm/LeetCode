class Solution {
public:
    int findNthDigit(int n) {
        long long start = 1;
        int digit = 1;
        long long count = 9;
        while(n > count){
            n -= count;
            start *= 10;
            digit ++;
            count = start * digit * 9;  
        }
        int num = start + (n - 1) / digit;
        string s = to_string(num);
        return s[(n - 1) % digit] -'0';
    }
};