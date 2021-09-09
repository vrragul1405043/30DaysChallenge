class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if(dividend == INT_MIN && divisor == 1)return INT_MIN;
        if(dividend == INT_MIN && divisor == -1)return INT_MAX;
        
        bool isNegative = ((divisor<0)^(dividend<0))?true:false;
        long result = 0, n = abs(dividend), m = abs(divisor);
        
        for(int i=31;i>=0;i--){
            if((m<<i)<=n){
                n-=(m<<i);
                result = result | (1<<i);
            }
        }
        
        result = (isNegative)?result*-1:result;
        result = (result<=INT_MIN || result>=INT_MAX)?INT_MAX:result;
        return result;
    }
};
