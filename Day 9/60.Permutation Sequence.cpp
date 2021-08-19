class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>temp(n,0);
        int fact = 1;
        string ans = "";
        k-=1;
        for(int i=1;i<n;i++){
            temp[i-1] = i;
            fact*=i;
        }
        temp[n-1]=n;
        while(true){
            int ind = k/fact;
            ans = ans + to_string(temp[ind]);
            temp.erase(temp.begin()+ind);
            if(temp.size()==0)break;
            k = k%fact;
            fact = fact/temp.size(); 
        }
        return ans;
    }
};