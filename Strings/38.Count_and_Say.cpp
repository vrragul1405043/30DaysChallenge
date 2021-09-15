class Solution {
public:
    string countAndSay(int n) {
        if(n<=0)return "";
        if(n==1)return "1";
        string result = "1";
        while(n>1){
            int count = 1;
            string temp = "";
            for(int i=0;i<result.size();i++){
                if(i+1<result.size() && result[i] == result[i+1])count++;
                else{
                    temp+=to_string(count)+result[i];
                    count = 1;
                }
            }
            result = temp;
            n--;
        }
        return result;
    }
};
