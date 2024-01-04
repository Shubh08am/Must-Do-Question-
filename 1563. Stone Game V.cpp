class Solution {
public:
    int subarraySum(int i,int j,vector<int>& stoneValue){
        int sum=0;
        for(int k=i;k<=j;k++) sum+=stoneValue[k]; 
    return sum;
    }
    int solve(int i,int j,vector<int>& stoneValue,vector<vector<int>>&dp) {
        //one stone remaining -> Game ends 
        if(i>=j) return 0;
        int &val=dp[i][j];
        if(val!=-1) return val;
        int result=-1e9; 

        //i to j calculate sum and than try to partition 
        int total_sum_of_partition=subarraySum(i,j,stoneValue); 
        int sum_before_partition=0,sum_after_partition=0; 

        for(int partition=i;partition<j;partition++){
            sum_before_partition+=stoneValue[partition];
            sum_after_partition=total_sum_of_partition-sum_before_partition;

            //take smaller one and give to alice 

            if(sum_before_partition>sum_after_partition){
                //i -> partition+1 but j->j go right 
                result=max(result,sum_after_partition+solve(partition+1,j,stoneValue,dp));
            }
            else if(sum_before_partition<sum_after_partition){
                //i -> i but j->partition stay left 
                result=max(result,sum_before_partition+solve(i,partition,stoneValue,dp));
            }
            else if(sum_before_partition==sum_after_partition){
                //try both way left and right 
                int right_way = sum_after_partition+solve(partition+1,j,stoneValue,dp);
                int left_way = sum_before_partition+solve(i,partition,stoneValue,dp) ;
                result=max({result,right_way,left_way});
            }
        }
    return val=result; 
    }
    int stoneGameV(vector<int>& stoneValue) {
        // Partition Dp -> MCM  
        //i -> 0 j-> n-1 
        int n = stoneValue.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,n-1,stoneValue,dp);
    }
};
