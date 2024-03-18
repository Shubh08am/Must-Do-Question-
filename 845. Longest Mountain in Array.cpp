class Solution {
public: 
    int longestMountain(vector<int>& arr) {
        //2 pointer  
        int n=arr.size(),i=1,ans=0;
        while(i<n-1){
            //if mountain 
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                int j=i-1,k=i+1; 
                //try to maximize the window till possible 
                
                while(j>0){
                    if(arr[j]>arr[j-1]){
                        j--;
                    }
                    else break;
                }
                while(k<n-1){
                    if(arr[k]>arr[k+1]){
                        k++;
                    }
                    else break;
                }
                ans=max(ans,k-j+1);
            }
            i++;
        }
    return ans;
    }
};
