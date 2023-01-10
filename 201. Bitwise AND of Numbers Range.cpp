class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
    int ans=0; 
    //match left and right only 
    for(int bit=30;bit>=0;bit--){
    //when mis-match break as after that all 0 in and
     if((left&(1<<bit)) !=  (right&(1<<bit))) break;

     else{  //cout<< (left&(1<<bit)) <<" ";  5&4 -> 4 , here when bit=2 
            //cout<<ans<<" ";
         ans|=(left&(1<<bit)); // i.e ans+=(left&(1<<bit));
     }
    }   
    return ans;
    }
};
