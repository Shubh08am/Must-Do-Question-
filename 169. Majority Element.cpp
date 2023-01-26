class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //moore voting algorithm
        int candidates=0,votes=0;
        for(int i=0;i<nums.size();i++){
            if(votes==0){
                //decide candidates
                candidates=nums[i];
            }
            if(candidates==nums[i]) {
                votes++;
            }
            else if(candidates!=nums[i]){
                votes--;
            }
        }
        return candidates;
    }
};
