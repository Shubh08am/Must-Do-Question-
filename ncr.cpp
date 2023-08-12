#include<bits/stdc++.h>
using namespace std; 
int main(){
    int t;cin>>t;while(t--){
    long long int r,n;cin>>n>>r; 
    long long int num=1;
    for(int i=0;i<r;i++){
        num=num*(n-i);
        num=num/(i+1);
    }
    cout<<num<<"\n";
    }
}
