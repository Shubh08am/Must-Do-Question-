class DSU{
public:
vector<int>parent,rank,size;
DSU(int n){
    parent.resize(n+1,0);
    rank.resize(n+1,0);
    size.resize(n+1,1);
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
}
int findUltimateParent(int node){
    if(node==parent[node]) return node;
    return parent[node]=findUltimateParent(parent[node]);
}
void UnionBySize(int u,int v){
    int ulp_u=findUltimateParent(u);
    int ulp_v=findUltimateParent(v);
    if(ulp_u==ulp_v)return;
    if(size[ulp_u]<size[ulp_v]){
        parent[ulp_u]=ulp_v;
        size[ulp_v]+=size[ulp_u];
    }
    else if(size[ulp_u]>=size[ulp_v]){
        parent[ulp_v]=ulp_u;
        size[ulp_u]+=size[ulp_v];
    }
}
void UnionByRank(int u,int v){
    int ulp_u=findUltimateParent(u);
    int ulp_v=findUltimateParent(v);
    if(ulp_u==ulp_v)return;
    if(rank[ulp_u]<rank[ulp_v]){
        parent[ulp_u]=ulp_v;
    }
    else if(rank[ulp_u]>rank[ulp_v]){
        parent[ulp_v]=ulp_u;
    }
    else if(rank[ulp_u]==rank[ulp_v]){
        parent[ulp_v]=ulp_u;
        rank[ulp_u]+=1;
    }
}
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size(),provinces=0;
        DSU ds(n); 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1)  ds.UnionByRank(i,j);
            }
        }
        for(int i=0;i<n;i++){
           // if(ds.findUltimateParent(i)==i) provinces++;
           if(ds.parent[i]==i) provinces++;
        }
    return provinces;
    }
};
