class Solution {
public:
    bool isPossible(int mid,vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        multiset<int>ms(workers.begin(),workers.end());
        int cnt=0,pillRequired=0;
        for(int i=mid-1;i>=0;i--){
            int w = *ms.rbegin(); 
            //no need of pills
            if(tasks[i]<=w){
                cnt++;
                ms.erase(ms.find(w));
            }
            else{
                //use pills -> 2 cases 
                //with pills possible 
                int left = tasks[i]-strength ; 
                auto pos = ms.lower_bound(left);
                if(pos==ms.end()){
                    return false;
                }
                else{
                    cnt++;pillRequired++;
                    ms.erase(ms.find(*pos));
                }
            }
        }
    return cnt>=mid&&pillRequired<=pills;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        // BINARY SEARCH  + GREEDY 
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end());
        int n=tasks.size(),m=workers.size();
        int low=0,high=min(n,m);
        while(low<=high){
            //mid number of tasks with pills possible or not
            int mid=low+(high-low)/2;
            if(isPossible(mid,tasks,workers,pills,strength)){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    return high;
    }
};
