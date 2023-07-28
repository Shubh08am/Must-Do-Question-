//User function template in C++

class Solution 
{
    public:
    bool isPossible(int mid,int A[],int N,int M){
        int reqPage=1,sum=0;
        for(int i=0;i<N;i++){
            if(sum+A[i]>mid){
                sum=A[i];
                reqPage++;
            }
            else sum+=A[i];
        }
    return reqPage<=M;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
      if(M>N) return -1;
      int low = *max_element(A,A+N) ; 
      int high = accumulate(A,A+N,0); 
      int ans=0;
      while(low<=high){
          int mid = low+(high-low)/2;
          
          if(isPossible(mid,A,N,M)){
              ans=mid;
              high=mid-1;
          }
          else low=mid+1;
      }
    return ans;
    }
};
