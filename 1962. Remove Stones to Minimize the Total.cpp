

class Solution {
public:
static bool comp(int a , int b){
  return a>b;
    }

    int minStoneSum(vector<int>& piles, int k) {
        int duplicateK=k,size;
        int totalStone = 0;
        sort(piles.begin(),piles.end(),comp);
     //   for(auto it: piles) cout<<it<<" ";

     priority_queue<int>removedStone;
     //push first k elements in removedStone where they are stored in decreasing order if(K<piles.size()) else all elements are pushed

if(k>=piles.size()){
    size=piles.size(); //than take all elements from piles
}
else if(k<piles.size()){
    size=k;
}
     for(int i=0;i<size;i++){
         removedStone.push(piles[i]);
     }

     /*while(!removedStone.empty()) {
         cout<<removedStone.top()<<" ";
         removedStone.pop();
     }*/

     //Apply,the operation to top element always
     while(k--){
         int maxStone = (removedStone.top()+1)>>1;
         removedStone.pop();
         removedStone.push(maxStone);
     }

     //push the remaining element of piles in removedStone than take total sum
     k=duplicateK;
     while(k<piles.size()){
         removedStone.push(piles[k]);
         k++;
     } 

     while(!removedStone.empty()) {
         totalStone+=removedStone.top();
         removedStone.pop();
     }
        return totalStone;
    }
};
