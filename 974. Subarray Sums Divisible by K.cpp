class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
         //prefix sum and remainder 
         unordered_map<int,int>rem;
         int cnt=0;
         for(int i=1;i<nums.size();i++) {
             nums[i]+=nums[i-1];
         }
        //take remainder 
        for(int i=0;i<nums.size();i++){
            int remainder = nums[i]%k ; 
            //-ve handle separately again add k and than take modulo
            if(remainder<0){
                int newRemainder =  (remainder + k) % k;  
                // 0 handle separately take it's freq first than cnt || [-5] -> 1
                if(newRemainder==0){
                    rem[newRemainder]++;
                  //  cout<<newRemainder << " "<<rem[newRemainder]<<"\n";
                    cnt+=rem[newRemainder];
                }
             else{ 
                cnt+=rem[newRemainder];
               // cout<<newRemainder << " "<<rem[newRemainder]<<"\n";
                 rem[newRemainder]++;
             }
            }
            if(remainder>=0) {
                // 0 handle separately take it's freq first than cnt
                if(remainder==0){
                    rem[remainder]++;
                  //  cout<<remainder << " "<<rem[remainder]<<"\n";
                    cnt+=rem[remainder];
                }
               else{
                 cnt+=rem[remainder];
                 // cout<<remainder << " "<<rem[remainder]<<"\n";
                  rem[remainder]++;  
               }             
                }
        }
        
         return cnt;
    }
};
