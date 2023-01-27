class Solution {
public: //at Max 2 elements can occur 
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int candidate_1 = -1 ,candidate_2 = -1;
        int vote_1=0,vote_2=0;
        
        for(auto it : nums){
            if(it==candidate_1) vote_1++;
            else if(it==candidate_2) vote_2++;//first check this else candidate can be lost
            else if(vote_1==0){
                //decide candidate 
                candidate_1=it;
                vote_1=1;
            }
            else if(vote_2==0){
                //decide candidate 
                candidate_2=it;
                vote_2=1;
            }
            else{
                vote_1--;
                vote_2--;
            }
        }
    // cout<<candidate_1<<" "<<candidate_2<<" ";
    // now, candidate_1 and candidate_2 are possible ans see there occurences
    int seeFor_candidate_1 = 0 , seeFor_candidate_2=0;
    for(auto it : nums) {
        if(it==candidate_1) seeFor_candidate_1++;
       else if(it==candidate_2) seeFor_candidate_2++; 
    }
    //check,occurences now
    if(seeFor_candidate_1 > nums.size()/3 ) ans.push_back(candidate_1);
    if(seeFor_candidate_2 > nums.size()/3 ) ans.push_back(candidate_2);


    return ans;
    }
};
