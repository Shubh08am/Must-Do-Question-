class Solution {
public:
    bool isPossible(vector<int>&piles,int mid,int h){
        long time=0;
        for(auto&it:piles){
            time+=(it+mid-1)/mid;
        }
        return time<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=*max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid=low+((high-low)>>1);
            if(isPossible(piles,mid,h)) high=mid-1;
            else low=mid+1;
        }
    return low;
    }
};
