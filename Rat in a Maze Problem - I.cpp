class Solution{
    public:
    void solve(int i,int j,string s,vector<vector<int>> &m, int n,vector<vector<int>>&vis,vector<string>&ans) {
        if(i==n-1 and j==n-1){
            ans.push_back(s);
            return;
        }
        string dir = "DLRU";
        int dx[] ={+1,0,0,-1};
        int dy[] = {0,-1,+1,0};
        for(int k=0;k<4;k++){
            int ni = i+dx[k] , nj = j+dy[k] ; 
            if(ni>=0&&ni<n&&nj>=0&&nj<n&&m[ni][nj]==1&&!vis[ni][nj]){
                vis[i][j]=1;
                solve(ni,nj,s+dir[k],m,n,vis,ans);
                vis[i][j]=0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
       // DFS 
       vector<string>ans;
       vector<vector<int>>vis(n,vector<int>(n,0));
       if(m[0][0]==1)solve(0,0,"",m,n,vis,ans);
       return ans;
    }
};
