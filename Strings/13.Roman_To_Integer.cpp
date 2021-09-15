class Solution {
public:
    int romanToInt(string s) {
        unordered_map<int,int>m;
        fill_values(m);
        int result = 0, SIZE = s.size();
        for(int i=SIZE-1;i>=0;i--){
            if(i==SIZE-1)result+=m[s[i]];
            else{
                if(m[s[i+1]]>m[s[i]])result-=m[s[i]];
                else result+=m[s[i]];
            }
        }
        return result;
    }
private:
    void fill_values(unordered_map<int,int>&m){
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
    }    
};
