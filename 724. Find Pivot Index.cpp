class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
    /*    int prefix[n],suffix[n];
        memset(prefix,0,sizeof(prefix));
        memset(suffix,0,sizeof(suffix));
        for(int i=1;i<n;i++){
            prefix[i]+=prefix[i-1]+nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            suffix[i]+=suffix[i+1]+nums[i+1];
        }
        for(int i=0;i<n;i++){
            if(prefix[i]==suffix[i]) return i;
        }
    return -1;*/
    int right_sum=accumulate(nums.begin(),nums.end(),0),left_sum=0;
    for(int i=0;i<n;i++){
        right_sum-=nums[i];
        cout<< left_sum << " "<< right_sum << "\n";
        if(left_sum==right_sum) return i;
        left_sum+=nums[i];
    }
    return -1;
    }
};
