class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isPossible(int col,vector<int>&color,vector<int>adj[],int node){
        //check that adjNpde of node are not colored with same color 
        for(auto&adjNode:adj[node]){
            if(color[adjNode]==col) return false;
        }
    return true;
    }
    bool solve(int node,vector<int>adj[],int m,int n,vector<int>&color){
        //all node colored with atmost m color return true 
        if(node==n){
            return true;
        }
        //try all color on node 
        for(int i=1;i<=m;i++){
            if(isPossible(i,color,adj,node)){
                color[node]=i;
                if(solve(node+1,adj,m,n,color)) return true;
                color[node]=0;//backtrack
            }
        }
    return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int>adj[n] ; 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(graph[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
       vector<int>color(n,0);
        return solve(0,adj,m,n,color);
        
    }
};
