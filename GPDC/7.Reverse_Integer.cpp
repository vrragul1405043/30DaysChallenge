class Solution {
public:
    int reverse(int x) {
        if(!x)return x;
        bool isPositive = (x>0)?true:false;
        long result = 0;
        x = abs(x);
        while(x){
            result = (result * 10) + (x%10);
            x/=10;
        }
        result = (isPositive)?result:-1 * result;
        return (result>INT_MAX || result<INT_MIN)?0:result;
    }
};