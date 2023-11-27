class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int>curr_subsequence; 
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(!curr_subsequence.empty() && curr_subsequence.top()>nums[i] && n-i>k-curr_subsequence.size()){
                curr_subsequence.pop();
            }
           if(curr_subsequence.size()<k) curr_subsequence.push(nums[i]);
        }
        vector<int>subsequence;
        while(!curr_subsequence.empty()){
            subsequence.push_back(curr_subsequence.top());
            curr_subsequence.pop();
        }
    reverse(subsequence.begin(),subsequence.end());
    return subsequence;
    }
};
