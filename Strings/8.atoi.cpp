class Solution {
public:
    int myAtoi(string s) {
        int current_ptr = 0, SIZE = s.size();
        long result = 0;
        while(s[current_ptr]==' ')current_ptr++;
        bool isPositive = true;
        
        if(s[current_ptr]=='-' || s[current_ptr] == '+'){
            isPositive = s[current_ptr]!='-';
            current_ptr+=1;
        }
        
        while(current_ptr<SIZE){
            if(s[current_ptr]>='0' && s[current_ptr]<='9'){
                result = (result*10)+(s[current_ptr]-'0');
                if(result>INT_MAX){
                    if(!isPositive)return INT_MIN;
                    else return INT_MAX;
                }
                current_ptr++;
            }
            else break; 
        }
        
        return (!isPositive)?result*-1:result; 
    }
};
