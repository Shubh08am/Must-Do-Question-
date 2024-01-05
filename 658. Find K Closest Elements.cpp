class Solution {
public:
    class cmp{
        public:
        bool operator()(const pair<int,int>&a,const pair<int,int>&b){
            if(a.first==b.first) return a.second < b.second; 
            return a.first < b.first;
        }
    };
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //if same difference take smaller one 
      /*  vector<int>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>diff;
        for(auto&value:arr){
            int curr_diff = abs(x-value);
            diff.push({curr_diff,value});
            if(diff.size()>k) diff.pop();
        }
        while(!diff.empty()){
            int closest_number = diff.top().second;
            diff.pop();
            ans.push_back(closest_number);
        }
        sort(ans.begin(),ans.end());
    return ans;  
    */
    /*int i=0,j=arr.size()-1;
    while(j-i>=k){
        if(x-arr[i]<=arr[j]-x) j--;
        else i++;
    }
    return vector<int>(arr.begin()+i,arr.begin()+j+1);
    */
    int n=arr.size(),low=0,high=n-k; 
    //[1,1,2,2,2,2,2,3,3] k=3 , x=3 -> for why not abs difference 
    //[1] k=1 x=1 for mid+k<n 
    // O(log(n-k)+k)
    while(low<=high){
        int mid=low+(high-low)/2; 
        if(mid+k<n && x-arr[mid] > arr[mid+k] -x) low=mid+1;
        else high=mid-1;
    }
    return vector<int>(arr.begin()+low,arr.begin()+low+k);
    }
};
