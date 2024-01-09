class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function 
	    int a=0,b=0;
	    map<int,int>m;
	    m[0]=-1;
	    for(int i=0;i<n;i++){
	        b=(b+(arr[i]%k)+k)%k;
	        if(m.find(b)==m.end()) m[b]=i;
	        else a=max(a,i-m[b]);
	    }
	   return a;
	}
};
