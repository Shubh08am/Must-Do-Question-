#include <bits/stdc++.h> 
vector<int>merge(vector<int>&nums1,vector<int>&nums2){
    vector<int>nums3;
    int n1=nums1.size(),n2=nums2.size(),i=0,j=0;
    while(i<n1&&j<n2){
        if(nums1[i]<nums2[j]) {nums3.push_back(nums1[i]);i++;}
        else {nums3.push_back(nums2[j]);j++;}
    }
    while(i<n1) {nums3.push_back(nums1[i]);i++;}
    while(j<n2) {nums3.push_back(nums2[j]);j++;}
return nums3;
} 
vector<int> mergeSort(int low,int high,vector<vector<int>>&kArrays, int k){
    if(low>high) return {};
    if(low==high) return kArrays[low];
    int mid=low+(high-low)/2;

    vector<int>left = mergeSort(low,mid,kArrays,k);
    vector<int>right = mergeSort(mid+1,high,kArrays,k);
    return merge(left,right);
}
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    return mergeSort(0,k-1,kArrays,k);
}
