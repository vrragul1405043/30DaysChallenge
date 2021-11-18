class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int SIZE = nums.size();
        if(SIZE==1)return to_string(nums[0]);
        
        string result = "";
        
        auto comparator = [](string& s1, string& s2){
            return s1+s2 > s2+s1;
        };
        
        vector<string>stringNums(SIZE);
        
        for(int i=0;i<SIZE;i++) stringNums[i] = to_string(nums[i]);
        
        
        sort(stringNums.begin(), stringNums.end(),comparator);
        
        for(string& s : stringNums)result+=s;
        
        return (result[0] == '0')?"0":result;
        
    }
};
