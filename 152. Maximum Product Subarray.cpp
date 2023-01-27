class Solution {
public:
    int maxProduct(vector<int>& nums) {
      //prefix and suffix 
      int n = nums.size();
      vector<int>prefix(n) , suffix(n) ; 
      prefix[0] = nums[0] ; 
      suffix[n-1] = nums[n-1] ; 
      //edge case if n==1 or max product is last value of nums therefore, initially take it that only
      int maxProduct=max(prefix[0],suffix[n-1]);

     //take prefix product and see for max product 
     for(int i=1;i<n;i++){
      //if prefix[i-1] is 0 we won't consider its contribution 
      if(prefix[i-1]!=0){
          prefix[i] = prefix[i-1]*nums[i] ; 
      }
      //if prefix[i-1] is 0 take nums[i] in prefix[i-1] 
      if(prefix[i-1]==0){
          prefix[i] =nums[i] ; 
      }
      maxProduct = max(maxProduct, prefix[i]); 
     }
     
     //take suffix product and see for max product 
     for(int i=n-2;i>=0;i--){
      //if suffix[i+1] is 0 we won't consider its contribution 
      if(suffix[i+1]!=0){
          suffix[i] = suffix[i+1]*nums[i] ; 
      }
      //if suffix[i+1] is 0 take nums[i] in suffix[i+1] 
      if(suffix[i+1]==0){
          suffix[i] =nums[i] ; 
      }
      maxProduct = max(maxProduct, suffix[i]);
     }

    // for(auto it : prefix) cout<<it<<" ";
    // cout<<"\n";
    //  for(auto it : suffix) cout<<it<<" ";
    //  cout<<"\n";
   
     return maxProduct;
    }
};
