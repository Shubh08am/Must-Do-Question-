class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size() , i=0,j=n-1 , leftMax = 0 , rightMax = 0 , rain = 0;
        while(i<j){
            if(height[i]<height[j]){
                leftMax=max(leftMax,height[i]);
                rain+=leftMax-height[i];
                i++;
            }
            else if(height[i]>=height[j]){
                rightMax=max(rightMax,height[j]);
                rain+=rightMax-height[j];
                j--;
            }
        }
    return rain;
    }
};
