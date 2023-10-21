class Solution {
public:
    void reverse(vector<int>&nums,int start,int end){
        while(start<end){
            int temp=nums[start];
            nums[start]=nums[end];
            nums[end]=temp;
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        //1-> REVERSE FIRST N-K ELEMENTS 
        //2-> REVERSE LAST K ELEMENTS 
        //3->REVERSE ALL THE ELEMENTS 
        int n = nums.size(); 
        k%=n;
        reverse(nums,0,n-k-1);
        reverse(nums,n-k,n-1); 
        reverse(nums,0,n-1);
    }
};
