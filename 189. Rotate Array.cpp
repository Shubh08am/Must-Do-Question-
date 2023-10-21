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
      /*
        //1->REVERSE FIRST N-K ELEMENTS I.E N-K-1
        //2->REVERSE LAST K ELEMENTS I.E FROM N-KTH TO N-1TH
        //3->REVERSE ALL THE ELEMENTS 
        int n = nums.size(); 
        k%=n;
        reverse(nums,0,n-k-1);
        reverse(nums,n-k,n-1); 
        reverse(nums,0,n-1);
        */

        //1->REVERSE ALL THE ELEMENTS
        //2->REVERSE FIRST K ELEMENTS I.E K-1
        //3->REVERSE REMAINING ELEMENTS I.E FROM KTH TO N-1TH
        int n = nums.size(); 
        k%=n;
        reverse(nums,0,n-1);
        reverse(nums,0,k-1); 
        reverse(nums,k,n-1);
    }
};
