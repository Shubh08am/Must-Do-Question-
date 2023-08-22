#include<bits/stdc++.h>
using namespace std ; 

int merge(vector<int>&v,int low,int mid,int high){
    int left=low , right=mid+1 , inversion=0; 
    vector<int>temp; 

    while(left<=mid && right<=high){
        if(v[left]<=v[right]){
            temp.push_back(v[left]) ;
            left++;
        }
        else{
            //right part smaller 
            inversion+=(mid-left+1) ; 
            temp.push_back(v[right]) ;
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(v[left]) ;
        left++;
    }
     while(right<=high){
        temp.push_back(v[right]) ;
        right++;
    }
    for(int i=low;i<=high;i++) v[i]=temp[i-low];
    return inversion;
}
int mergesort(vector<int>&v,int low,int high){
    int inversion=0;
    if(low>=high) return inversion;
    int mid = low + (high-low)/2;
    inversion+=mergesort(v,low,mid);
    inversion+=mergesort(v,mid+1,high);
    inversion+=merge(v,low,mid,high);
    return inversion;
}
int main(){
    int n;cin>>n;
    vector<int>v(n) ; 
    for(int i=0;i<n;i++) cin>>v[i] ; 
    cout<< mergesort(v,0,n-1) ; 
}
