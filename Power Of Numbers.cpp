class Solution{
    public:
     long long int binExpIterative( long long int a ,  long long int b){
    long long int ans=1;
  while(b>0){
    //see if set-bit 
    if(b&1){
        ans=(ans*a*1LL)%mod;
    }
    a = (a*a*1LL)%mod;  //go to next power
    b>>=1 ; //right-shift the bit
  }
  return ans;
}
    long long power(int N,int R){
         return binExpIterative(N,R);
    }
};
