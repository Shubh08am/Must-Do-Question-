class Solution {
public:
//T.C -> O(NLOGK) SC->O(N)
    vector<int>AP2(vector<int>& nums, int k) {
        multiset<int>ms;
        vector<int>ans; 
        for(int i=0;i<nums.size();i++){
            ms.insert(nums[i]) ; 
            if(i>=k-1) {
              //  ans.push_back(*(--ms.end())); //last element is the highest value
               ans.push_back(*(ms.rbegin())); //last element is the highest value
                ms.erase(ms.find(nums[i-k+1])); // remove first element of k sized window
            }
        }
    return ans;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq ; 
        int n = nums.size() ; 
        vector<int>ans; 

        // MAINTAIN DECREASING ORDER IN DEQUEUE 
        // AS AT ANY MOMENT AT nums[i] all the element smaller than it (which appears before )can't be maximum -> therefore remove them
        // T.C -> O(N) + O(N) 
        //  S.C -> O(K) -> AT MAX K ELEMENTS IN DEQUEUE
        for(int i=0;i<n;i++){
            //OUT OF BOUND CHECK
            if(!dq.empty() && i-dq.front()==k) dq.pop_front() ; 

            // MAINTAIN DECREASING ORDER IN DEQUE 
            //remove smaller elements than nums[i]
            while(!dq.empty() && nums[i]>=nums[dq.back()]) dq.pop_back() ; 
            dq.push_back(i) ; 

            //start taking maximum from k-1th position onwards for every window
            if(i>=k-1) ans.push_back(nums[dq.front()]) ; 
        }
       // return ans; // APPROACH-1 USING SLIDING WINDOW
       return AP2(nums,k) ; // APPROACH-2 USING MULTISET
    }
};
