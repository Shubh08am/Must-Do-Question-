class Solution {
public:
    bool palindrome(int median){
        int rev=0,prev=median;
        while(median){
            rev=rev*10+median%10;
            median/=10;
        }
    return rev==prev;
    }
    long long reqCost(long long median,vector<int>&nums){
        long long cost=0;
        if(median==1e15) return 1e15;
        for(auto&it:nums) cost+=abs(it-median);
        return cost;
    }
    int nextPalindrome(int median){
        while(median){
            if(palindrome(median)) return median;
            median++;
        }
     return 0;
    }
    int prevPalindrome(int median){
        while(median){
            if(palindrome(median)) return median;
            median--;
        }
     return 0;
    }
    long long minimumCost(vector<int>& nums) {
        long long cost=0;
        sort(nums.begin(),nums.end()) ; 
        //find the median and see 2 closest palindrome to median one greater and second less than or equal to 
        //and than see the cost 
        int n=nums.size() ; 
        long long median = 0 ,median1=0;
        long long pal1 = 1e15 ,pal2=1e15, pal3=1e15,pal4=1e15  ;
        if(n&1){
            median = nums[n/2] ; 
            pal1=nextPalindrome(median);
            pal2=prevPalindrome(median);
        }
        else{
            median1=nums[n/2] ; 
            pal3=nextPalindrome(median1);
            pal4=prevPalindrome(median1);
        }
        long long ans1 = min(1ll*reqCost(pal1,nums) , 1ll*reqCost(pal2,nums)); 
        long long ans2 = min(1ll*reqCost(pal3,nums) , 1ll*reqCost(pal4,nums)); 
        long long ans = min(ans1,1ll*ans2);
        return ans; 
    }
};
