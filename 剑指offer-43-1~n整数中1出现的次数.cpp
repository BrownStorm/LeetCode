class Solution {
public:
    int countDigitOne(int n) {
        // 返回结果初始化为0
        int res = 0;
        // 先对最低位进行初始化
        int cur = n % 10, high = n / 10, low = 0;
        long digital = 1;
        while(high != 0 || cur != 0){
            if(cur == 0){
                res += int(high * digital);
            }else if(cur == 1){
                res += int(high * digital + low + 1);
            }else{
                res += int((high+1) * digital);
            }
            low = int(low + digital*cur);
            cur = high % 10;
            high = high / 10;
            digital *= 10;
        }
        return res;
    }
};