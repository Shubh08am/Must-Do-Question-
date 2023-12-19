class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //find the next greater element position 
        // if nextGreater= -1 -> ans[i]=0 
        // else ans[i]= nextGreater[i] - i 
        int n=temperatures.size();
        vector<int>nextGreater(n,0);
        stack<int>s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && temperatures[s.top()]<=temperatures[i]) s.pop();
            if(!s.empty()) nextGreater[i]=s.top()-i;
            s.push(i);
        }
    return nextGreater;
    }
};
