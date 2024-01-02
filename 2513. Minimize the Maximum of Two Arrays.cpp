class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long long low=uniqueCnt1+uniqueCnt2,high=1e18; 
        //divisibe by both -> counted twice count 1 therfore mid-mid/lcm >= uniqueCnt1+uniqueCnt2
        long long lcm = (1ll*divisor1*divisor2)/__gcd(divisor1,divisor2);
        while(low<=high){
            long long mid = low+(high-low)/2; 
           // cout << low << " "<< mid << " " << high << " "<<ans<<"\n" ; 
            if((mid-mid/lcm)>=(uniqueCnt1+uniqueCnt2) && (mid-(mid/divisor1) >= uniqueCnt1)&& (mid-(mid/divisor2) >= uniqueCnt2)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
    return low;
    }
};
