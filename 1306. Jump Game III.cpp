class Solution {
public:
    bool isValid(int pos,int val,int n,int sign){
       if(sign==1) return pos + val >=0 && pos + val < n ;
       else  return pos - val >=0 && pos - val < n ;
    }
    bool canReach(vector<int>& arr, int start) {
        //bfs 
        int n=arr.size();
        queue<pair<int,int>>allJumps; 
        allJumps.push({start,arr[start]});
        vector<int>vis(n,0);
        vis[start]=1;
        while(!allJumps.empty()){
            auto it = allJumps.front();
            allJumps.pop();
            int val = it.second;
            int pos = it.first ; 
          //  cout << pos << " " << val << "\n";
            if(arr[pos]==0) return true;
            if(isValid(pos,arr[pos],n,1) && !vis[pos+arr[pos]]){
                vis[pos+arr[pos]]=1;
                allJumps.push({pos+arr[pos],pos+arr[pos]});
            }
            if(isValid(pos,arr[pos],n,0) && !vis[pos-arr[pos]]){
                vis[pos-arr[pos]]=1;
                allJumps.push({pos-arr[pos],pos-arr[pos]});
            }
        }
    return false;
    }
};
