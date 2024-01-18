//User function template for C++

class Solution{   
public:
    int upperbound(vector<int> &matrix, int v){
        int cnt=0;
        int low=0,high=matrix.size()-1,ans=matrix.size();
        while(low<=high){
             int mid=low+(high-low)/2;
            if(matrix[mid]>v){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    int isPossible(int mid,vector<vector<int>> &matrix, int R, int C){
        int cnt=0;
        for(int i=0;i<R;i++){
            cnt+=upperbound(matrix[i],mid);
        }
    return cnt;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        int req = (R*C)/2; 
        int low=INT_MAX,high=INT_MIN;
        for(int i=0;i<R;i++){
            low=min(low,matrix[i][0]);
            high=max(high,matrix[i][C-1]);
        }
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(mid,matrix,R,C)<=req){
                low=mid+1;
            }
            else{
                high=mid-1;
                ans=mid;
            }
        }
        return low;//return ans;
    }
};
