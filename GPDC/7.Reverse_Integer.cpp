class Solution {
public:
    int reverse(int x) {
        if(!x)return x;
        bool isPositive = (x>0)?true:false;
        long result = 0;
        while(x){
            result = (result * 10) + (x%10);
            x/=10;
        }
        return (result>INT_MAX || result<INT_MIN)?0:result;
    }
};
