class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
       //cyclci sort 
        //nums[i] shounld be at the position = nums[i]-1 
        //if not there swap it to correct place 
        int i=0,n=nums.size();
        while(i<n){
            int pos = nums[i]-1 ; 
            if(nums[i]!=nums[pos]) swap(nums[i],nums[pos]); 
            else i++; //when nums[i] is at its correct place go ahead 
        }
        vector<int>duplicates ; 
      //  for(auto&it:nums) cout<<it<<" ";
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1) duplicates.push_back(nums[i]);
        }
        return duplicates;
    }
};
