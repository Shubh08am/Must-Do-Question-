class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
         sort(A.rbegin(),A.rend());
         sort(B.rbegin(),B.rend());
         priority_queue<pair<int,pair<int,int>>>pq;
         set<pair<int,int>>vis;
          vis.insert({0,0});
         vector<int>ans;
         pq.push({A[0]+B[0],{0,0}});
         while(K-- && !pq.empty()){
             auto it = pq.top();
             pq.pop();
             ans.push_back(it.first);
             int i=it.second.first,j=it.second.second;
             if(i+1<N && vis.find({i+1,j})==vis.end()){
                 pq.push({A[i+1]+B[j],{i+1,j}});
                 vis.insert({i+1,j});
             }
             if(j+1<N && vis.find({i,j+1})==vis.end()){
                 pq.push({A[i]+B[j+1],{i,j+1}});
                 vis.insert({i,j+1});
             }
         }
        return ans;
    }
};
