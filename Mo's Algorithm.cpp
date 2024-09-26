//https://www.spoj.com/problems/DQUERY/

#include <bits/stdc++.h>
using namespace std;
#define BLOCK 555

//MO's ALGORITHM (SQRT DECOMPOSITION) - CODE N CODE 

class query{
    public: 
    int l,r,i; 
};
query Q[200001] ; 

bool comp(query a, query b){
    //sorting block by left position so that min movement of pointer 
    if(a.l / BLOCK != b.l/BLOCK) return a.l/BLOCK < b.l/BLOCK; 
    return a.r < b.r ; 
}

void add(int pos,vector<int>&a,vector<int>&freq,int &cnt){
    if(++freq[a[pos]]==1) cnt++; 
}

void remove(int pos,vector<int>&a,vector<int>&freq,int &cnt){
    if(--freq[a[pos]]==0) cnt--; 
}

int main() {
    int n;cin>>n; 
    vector<int>a(n),freq(1000001); 
    int cnt=0; 
    
    for(int i=0;i<n;i++) cin>>a[i] ; 
    
    int q;cin>>q; 
    vector<int>ans(q) ; 
    for(int i=0;i<q;i++){
        cin>>Q[i].l >> Q[i].r ; 
        Q[i].i=i; Q[i].l--; Q[i].r--; 
    }
    
    sort(Q,Q+q,comp) ; 
    
    int ML=0 , MR=-1 ; 
    for(int i=0;i<q;i++){
        int L = Q[i].l , R = Q[i].r ; 
        
        // ALL 4 CASES 
         while(ML > L){
             ML--; 
             add(ML,a,freq,cnt);
         }
        while(MR < R){
             MR++; 
             add(MR,a,freq,cnt);
         }         
         while(ML < L){
             remove(ML,a,freq,cnt);   
             ML++; 
         }        
         while(MR > R){
             remove(MR,a,freq,cnt); 
             MR--; 
         }
         
         ans[Q[i].i] = cnt ; 
    }
      
     
    for(int i=0;i<q;i++) cout<<ans[i]<<"\n" ; 
    
	return 0;
}
