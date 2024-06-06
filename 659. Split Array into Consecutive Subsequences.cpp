class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int>starting,ending; 
        for(auto&val:nums) starting[val]++;
        for(auto&val:nums){
            if(starting[val]==0) continue; 
            starting[val]--; 
            //can we increase length from 3 of the current ending subsequence 
            if(ending[val-1]>0){
                ending[val-1]--;
                ending[val]++; //now ends at val
            }
            else if(starting[val+1]>0 && starting[val+2]){
                starting[val+1]--;
                starting[val+2]--;
                ending[val+2]++;//one subsequence end here
            }
            else return false;
        }
    return true;
    }
};
