class Solution {
public:
    int minFlipsMonoIncr(string s) {
int n = s.size();
vector<int>ones(n,0);
vector<int>zeros(n,0);

int ones_cnt = 0 , zeros_cnt=0 , flips = 1e9;
//suffix sum for 0 i.e no of 0 in right
for(int i=n-1;i>=0;i--)   {
       if(s[i]=='0') zeros_cnt++;
            zeros[i] = zeros_cnt;
}
//for(auto it : zeros) cout<<it<<" ";
//cout<<"\n";


//prefix sum for 1 i.e no of 1 in left
for(int i=0;i<n;i++) {
            if(s[i]=='1')  ones_cnt++;
            ones[i] = ones_cnt;
}
//for(auto it : ones) cout<<it<<" ";
//cout<<"\n";

for(int i=0;i<n-1;i++){
            int flip_left = ones[i];
            int flip_right = zeros[i+1];
            flips = min(flips,flip_left+flip_right);
        //    cout<<i<<" "<<flips<<"\n";
}
        
// edge case :- flip all 0 -> 1
     flips = min(flips,zeros[0]);

 // edge case :- flip all 1 -> 0 
     flips = min(flips,ones[n-1]);
        
return flips;        
    }
};
 
