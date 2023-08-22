class Solution {
public:
    //[1,9,7,8,5] -> [0,3,1,1,0]
    void merge(vector<pair<int,int>>&arr,int low,int mid,int high,vector<int>&count){
        int left=low,right=mid+1;
        vector<pair<int,int>>temp;
        while(left<=mid && right<=high){
            //sort in descending to count smaller when right is smaller and left is greater
            if(arr[left].first <= arr[right].first){
                temp.push_back(arr[right]) ; 
                right++;
            }
            else{
                temp.push_back(arr[left]) ; 
                count[arr[left].second]+=high-right+1;
                left++;
            }
        }
        while(left<=mid){
            temp.push_back(arr[left]) ; 
            left++;
        }
        while(right<=high){
            temp.push_back(arr[right]) ; 
            right++;
        }
        for(int i=low;i<=high;i++) arr[i]=temp[i-low];
    }
    void mergesort(vector<pair<int,int>>&arr,int low,int high,vector<int>&count){
        if(low>=high) return;
        int mid = low + (high-low)/2; 
        mergesort(arr,low,mid,count);
        mergesort(arr,mid+1,high,count);
        merge(arr,low,mid,high,count);
    }
    vector<int> countSmaller(vector<int>& nums) {
        //sort in descending order while doing merge sort for comparison 
        int n = nums.size();
        vector<pair<int,int>>arr(n);
        vector<int>count(n,0);
        for(int i=0;i<n;i++){
            arr[i]={nums[i],i};
        }
        mergesort(arr,0,n-1,count);
        return count;
    }
};
