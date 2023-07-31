class Solution {
public:
    //FLOYD CYCLE DETECTION -> T.C -> O(N) SC -> O(1)
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0] ; 
        int fast = nums[0] ; 
        bool ok = 1 ; 

        //TILL COLLISION FAST AND SLOW MOVED
        while(ok || fast!=slow){
            ok=0;
            slow = nums[slow] ; //moved once
            fast = nums[nums[fast]] ; //moved twice
           // cout<<slow<<" "<<fast<<"\n";
        }
        fast = nums[0] ; 
        while(slow!=fast){
            slow=nums[slow];//moved once
            fast=nums[fast] ;//moved once
          //  cout<<slow<<" "<<fast<<"\n";
        }
    return slow;
    }
};
