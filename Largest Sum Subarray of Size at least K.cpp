class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        long long sum=0,i=0,j=0,max_sum=-1e9,prev_sum=0;
        while(j<n){
            sum+=a[j];
            if(j-i+1==k){
                max_sum=max(max_sum,sum);
            }
            else if(j-i+1>k){
                //if -ve contribution from i remove it 
                //else keep taking it 
                prev_sum+=a[i];
                i++;
                if(prev_sum<0){
                    sum-=prev_sum;
                    prev_sum=0;
                }
                max_sum=max(max_sum,sum);
            }
        j++;
        }
    return max_sum;
    }
};
