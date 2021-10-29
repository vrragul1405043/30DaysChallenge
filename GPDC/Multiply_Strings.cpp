class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")return "0";
        
        int M = num1.size();
        int N = num2.size();
           
        vector<int>result(M+N,0);
        int result_ptr = M+N-1, idx = 0;
        string answer = "";
        
        for(int i = N-1; i>=0; i--){
            int S = 0;
            int temp_ptr = result_ptr; // storing it in temp_ptr to iterate in inner variable
            for(int j=M-1;j>=0;j--){
                S+= ((num2[i]-'0') * (num1[j]-'0')) + result[temp_ptr];
                result[temp_ptr] = S%10;
                S/=10;
                temp_ptr--;
            }
            if(S>0)result[temp_ptr] = S;//if carry exists put it in vector at the index
            result_ptr--; //decrement the result_ptr
        }
        
        //skip first non_zero elements
        while(idx<result.size() && result[idx]==0)++idx;  
        
        //appending it as a string
        for(int i=idx;i<result.size();i++) answer = answer + to_string(result[i]);
        
        return answer;
    }
};
