class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        /*for(auto x : points){
            for(auto i : x) cout<<i<<" ";
            cout<<"   ";
        }*/
        int arrows=0,n=points.size();
        for(int i=0;i<n;i++){
            int j=i+1,pt=points[i][1];
            while(j<n && pt>=points[j][0]){
                pt=min(pt,points[j][1]);
                j++;
            }
            arrows++;
            i=j-1;
        }
    return arrows;
    }
};
