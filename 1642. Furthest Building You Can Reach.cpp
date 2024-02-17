class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size(); 
        priority_queue<int,vector<int>,greater<int>>pq; 
        for(int i=0;i<n-1;i++){
            if(heights[i+1]>heights[i]) {
               pq.push({heights[i+1]-heights[i]}); 
               if(pq.size()>ladders){
                   //on min diff use bricks and on max diff use ladder 
                   //but first see range as well 
                   int bricksReq = pq.top();
                   pq.pop(); 
                   if(bricks<bricksReq) return i; 
                   else bricks-=bricksReq;
               }
            }
        }
        return n-1;   
    }
};
