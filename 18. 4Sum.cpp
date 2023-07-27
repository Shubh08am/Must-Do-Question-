class Solution {
public:
    vector<vector<int>> Approach1(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end()) ; 
        set<vector<int>>ans;
        vector<vector<int>>res;

        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    for(int l=k+1;l<nums.size();l++){
                        if(nums[i]+nums[j]+nums[k]+nums[l]==target){
                            ans.insert({nums[i],nums[j],nums[k],nums[l]});
                        }
                    }
                }
            }
        }
        for(auto&i:ans) res.push_back(i);
    return res;
    }

    vector<vector<int>> Approach2(vector<int>& nums, int target) {
        vector<vector<int>>res;
        set<vector<int>>ans;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0) cnt++;
        }
         for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                set<int>hash;
                for(int k=j+1;k<nums.size();k++){
                    long long s = nums[i]+nums[j];
                    s+=nums[k] ; 
                    int fourth = target-s; 
                     if(hash.count(fourth)){
                         cout<<"here\n";
                         vector<int>temp = {nums[i],nums[j],nums[k],fourth};
                         sort(temp.begin(),temp.end()) ; 
                         ans.insert(temp);
                     }
                    hash.insert(nums[k]);
                }
            }
        }
        for(auto&i:ans) res.push_back(i);
    return res;
    }

    vector<vector<int>> Approach3(vector<int>& nums, int target) {
        //3 pointer :- 2 pointer fixed i and j than k and l moved
        int n = nums.size() ; 
        sort(nums.begin(),nums.end()) ;
        vector<vector<int>>ans; 
        for(int i=0;i<n;i++){
             if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                    if(j>i+1 && nums[j]==nums[j-1]) continue;
                    int k = j+1; 
                    int l = n-1; 

                    while(k<l){
                        long long sum = nums[i]  ;
                        sum+=nums[j] ;
                         sum +=nums[k] ;
                         sum += nums[l] ; 

                        if(sum<target){
                            k++;
                        }
                        else if(sum>target){
                            l--;
                        }
                        else if(sum==target){
                            ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                            k++;
                            l--;

                            while(k<l&&nums[k]==nums[k-1]) k++;
                            while(k<l&&nums[l]==nums[l+1]) l--;
                        }
                    }
            }
        }
    return ans;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
     //   return Approach1(nums,target);
    //      return Approach2(nums,target);
          return Approach3(nums,target);
    } 
};
