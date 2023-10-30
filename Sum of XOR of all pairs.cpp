class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
long long ans = 0 ; 
for(int i=0;i<32;i++){
    int unset=0,set=0;
    for(int j=0;j<n;j++){
        int mask = (1<<i) ;
        if((arr[j]&mask)==0) unset++; 
        else if(arr[j]&mask) set++;
    }
    ans+=1ll*(1<<i)*unset*set;
}
return ans;
    }
};
