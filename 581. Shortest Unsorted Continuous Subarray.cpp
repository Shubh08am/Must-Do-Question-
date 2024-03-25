class Solution {
public:
    int nextMaximum(vector<int>& nums){
        stack<int>s; 
        s.push(-1) ;
        int n=nums.size();
        int next=-1e9; 
        for(int i=n-1;i>=0;i--){
            while(s.top()!=-1 && nums[s.top()]< nums[i]) {
                next=max(next,s.top());
                s.pop(); 
            } 
            s.push(i);
        }
    return next;
    }
    int prevMinimum(vector<int>& nums){
        stack<int>s; 
        s.push(-1) ; 
        int n=nums.size();
        int prev=1e9; 
        for(int i=0;i<n;i++){
            while(s.top()!=-1 && nums[s.top()]> nums[i]) {
                prev=min(prev,s.top());
                s.pop(); 
            }
            s.push(i);
        }
    return prev;
    }
    
    int findUnsortedSubarray(vector<int>& nums) {
        int prev = prevMinimum(nums) ; 
        int next = nextMaximum(nums) ; 
        int n=nums.size(); 
       
        if(prev==1e9 && next==-1e9) return 0; 
        
    return next-prev+1;
    }
};

/*
[1,3,2,3,3]
[2,3,3,2,4]
[2,4,6,8,10,9,15]
[2,4,6,8,10,90,15]
[1,2,300,4]
[-1,-11,1,2,-2,-56]
*/
