class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans ; 
        int n = intervals.size() , i=0 ; 
        while(i<n){
            if(newInterval[0]>intervals[i][1]){
                ans.push_back(intervals[i]);
            }
            else if(intervals[i][0]>newInterval[1]){
                break;
            }
            //ex: interval[i]=[1,3] & newInterval=[2,4]
            //both condition works for overlapping 
            // else if(intervals[i][1]>=newInterval[0]){
            else if(intervals[i][0]<=newInterval[1]){
                newInterval[0]=min(newInterval[0],intervals[i][0]);
                newInterval[1]=max(newInterval[1],intervals[i][1]);
            }
            i++;
        }
        ans.push_back(newInterval);
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
    return ans;
    }
};
