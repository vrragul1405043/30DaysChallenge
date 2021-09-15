/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int candidate;
        stack<int>s;
        for(int i=0;i<n;i++)s.push(i);
        while(s.size()>1){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            if(knows(a,b))s.push(b);
            else s.push(a);
        }
        
        candidate = s.top();
        s.pop();
        
        for(int i=0;i<n;i++){
            if(i==candidate)continue;
            else{
                if(!knows(i,candidate) || knows(candidate,i))return -1;
            }
        }
        return candidate;
    }
};
