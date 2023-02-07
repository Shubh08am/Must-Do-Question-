class Solution {
public:
    int getMaxLen(vector<int>& nums) {
    int i=0,j=0,n=nums.size(); 
    int maxiProductLen = n , currLen=0 , len=0;
    long long int product=1;

    while(j<n){
    product*=nums[j]*1LL;

    //3 cases :- 
    //1 product == 0 || 2 product>0 || 3 product<0 
    if(product==0){
        i=j+1;
        maxiProductLen=n; // [-4,0,0,-9,-10]
        product=1;
    }
    else if(product>0){
        currLen = j-i+1;
        len=max(len,currLen);
         product=1; //so, that no overflow 
    } 
    else if(product<0){
        maxiProductLen=min(maxiProductLen,j);
        int newLen = j-maxiProductLen; 
    //    cout<<j<<" "<<newLen<<"\n";
        len=max(len,newLen); 
          product=-1; //so, that no overflow 
    }
    j++;
    }
    return len;
    }
};
