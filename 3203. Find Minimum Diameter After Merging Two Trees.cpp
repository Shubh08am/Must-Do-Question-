class Solution {
public:
    void dfs1(int node, vector<int>& vis, vector<int> adj1[], int depth, int& d, int& farthestNode) {
        if (depth > d) {
            farthestNode = node;
            d = depth;
        }
        for (auto& it : adj1[node]) {
            if (vis[it] == 0) {
                vis[it] = 1;
                dfs1(it, vis, adj1, depth + 1, d, farthestNode);
            }
        }
    }
    void dfs2(int node, vector<int>& vis, vector<int> adj2[], int depth, int& d) {
        if (depth > d) {
            d = depth;
        }
        for (auto& it : adj2[node]) {
            if (vis[it] == 0) {
                vis[it] = 1;
                dfs2(it, vis, adj2, depth + 1, d);
            }
        }
    }

    int getTreeDiameter(vector<int> adj[], int n) {
        vector<int> vis(n, 0);
        int farthestNode = 0, d = 0;

        // First DFS to find the farthest node from node 0
        vis[0] = 1;
        dfs1(0, vis, adj, 0, d, farthestNode);

        // Second DFS to find the diameter
        fill(vis.begin(), vis.end(), 0);
        d = 0;
        vis[farthestNode] = 1;
        dfs2(farthestNode, vis, adj, 0, d);

        return d;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<int> adj1[n], adj2[m];

        for (auto& it : edges1) {
            int u = it[0], v = it[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }

        for (auto& it : edges2) {
            int u = it[0], v = it[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
        //min diamaeter after merging = max(d1,d2,(d1+1)/2+(d2+1)/2+1) 
        //connect at center of tree 
        //to find dfs -> run dfs 2 times 
        //first dfs -> find the farthest node 
        //second dfs -> from the farthest node again find the farthest node 
        int d1 = getTreeDiameter(adj1, n);
        int d2 = getTreeDiameter(adj2, m);
        int d3 = (d1 + 1) / 2 + (d2 + 1) / 2 + 1;

        return max({d1, d2, d3});
    }
};
