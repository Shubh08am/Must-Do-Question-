class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        int xorr = 0 ;
        for(auto i : arr) xorr^=i;
        for(int i=1;i<=n;i++) xorr^=i;
        
        //xorr = x^y 
        int num1=0,num2=0;
        int right_set_bit = xorr&(~(xorr-1));
        
        for(auto i : arr){
             if(i&right_set_bit){
                 num1^=i;
             }
             else{
                 num2^=i;
             }
        }
         
        for(int i=1;i<=n;i++){
             if(i&right_set_bit){
                 num1^=i;
             }
             else{
                 num2^=i;
             }
        } 
        int cnt=0;
        for(auto i : arr){
            if(i==num2) cnt++;
        }
        if(cnt==2) return {num2,num1};
    return {num1,num2};    
    }
};
