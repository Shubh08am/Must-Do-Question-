//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    
	    int low=0,high=n-1,mini=INT_MAX,pos=0;
	    while(low<=high){
	        int mid = low+(high-low)/2;
	        if(arr[low]<=arr[high]){
	            if(mini>arr[low]){
	                mini=arr[low];
	                pos=low;
	            }
	            break;
	        }
	        else if(arr[low]<=arr[mid]){
	            if(mini>arr[low]){
	                mini=arr[low];
	                pos=low;
	            }
	            low=mid+1;
	        }
	        else if(arr[mid]<=arr[high]){
	            if(mini>arr[mid]){
	                mini=arr[mid];
	                pos=mid;
	            }
	            high=mid-1;
	        }
	    }
	 return pos;
	}

};
