class Solution{
    private:
    void swapArrayElement(long long arr1[], long long arr2[],int left,int right){
            if(arr1[left]>arr2[right]){
                       swap(arr1[left],arr2[right]);
            }
    }
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
          /* int left=n-1,right=0;
           while(left>=0 && right<m){
               if(arr1[left]>arr2[right]){
                   swap(arr1[left],arr2[right]);
               }
               else break;
               left--;right++;
           }
           sort(arr1,arr1+n);
           sort(arr2,arr2+m);
           */
           int len=n+m;
           int gap=(len+1)/2;
           while(gap>0){
               int left=0,right=gap;
               while(right<len){
                   if(left<n && right>=n){
                       swapArrayElement(arr1,arr2,left,right-n);
                   }
                   else if(left>=n && right>=n){
                       swapArrayElement(arr2,arr2,left-n,right-n);
                   }
                  else if(left<n && right<n){
                       swapArrayElement(arr1,arr1,left,right);
                   }
                   left++;right++;
               }
               if(gap==1) break;
               gap=(gap+1)/2;
           }
        } 
};
