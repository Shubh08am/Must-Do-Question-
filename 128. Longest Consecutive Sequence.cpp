class DisjointSet{
public:
vector<int>parent , rank , size ; 
//constructor created 
DisjointSet(int n){
    //declare size for vector 
    parent.resize(n+1) ;  //n+1 as it covers both 0 & 1 based indexing
    rank.resize(n+1,0) ;  //initially, every node rank is marked as 0
    size.resize(n+1,1) ;  //initially, every node size is marked as 1

    //initially,every node is a parent of itself 
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
}

//find Ultimate Parent  
int findUltimateParent(int node){
       if(node==parent[node]) return node ; 
       //doing,path compression by assigning value to parent[node] and making T.C  as O(4*alpha) --> O(1)
       return parent[node] = findUltimateParent(parent[node]) ;
}

//Disjoint Set -> [1] finding Union By Rank 
void UnionByRank(int u , int v){
    int ulp_u = findUltimateParent(u) ; //UltimateParent of u 
    int ulp_v = findUltimateParent(v) ; //UltimateParent of v

    //if belonging to same components 
    if(ulp_u == ulp_v) return;

    //if not belonging to same components 
    if(rank[ulp_u]<rank[ulp_v]){
        //smaller guy gets connected to larger guy and no change in rank of ulp_u or ulp_v 
        //update parent of smaller guy
        parent[ulp_u]=ulp_v;
    }
    else if(rank[ulp_u]>rank[ulp_v]){
        //smaller guy gets connected to larger guy and no change in rank of ulp_u or ulp_v 
        //update parent of smaller guy
        parent[ulp_v]=ulp_u;
    }
    else if(rank[ulp_u]==rank[ulp_v]){
        //Anyone can get connected to other node and change in rank of node to which connected
        //update parent of node which gets connected
        parent[ulp_v]=ulp_u; //connecting ulp_v to ulp_u 
        rank[ulp_u]++;
    }
}

//Disjoint Set -> [2] finding Union By Size 
void UnionBySize(int u , int v){
    int ulp_u = findUltimateParent(u) ; //UltimateParent of u 
    int ulp_v = findUltimateParent(v) ; //UltimateParent of v

    //if belonging to same components 
    if(ulp_u == ulp_v) return;

    //if not belonging to same components 
    if(size[ulp_u]<size[ulp_v]){
        //smaller guy gets connected to larger guy and change in size to which connected
        //update parent of smaller guy
        parent[ulp_u]=ulp_v;
        size[ulp_v]+=size[ulp_u];
    }
    else if(size[ulp_u]>size[ulp_v]){
        parent[ulp_v]=ulp_u;
        size[ulp_u]+=size[ulp_v];
    }
    else if(size[ulp_u]==size[ulp_v]){
        //Anyone can get connected to other node and change in size of node to which connected
        //update parent of node which gets connected
        parent[ulp_v]=ulp_u; //connecting ulp_v to ulp_u 
        size[ulp_u]+=size[ulp_v];
    }
}
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) { 
  /*     //APPROACH - 3
   //INDEX CONSIDERED NODE -> PATTERN 
        // FINDING LARGEST COMPONENT SIZE 
        int n = nums.size() ,maxi=0;
        DisjointSet ds(n) ;  
        unordered_map<int,int>pos ; 

        for(int i=0;i<n;i++){
            //if ith node element already considered don't consider again 
            //ex:- 1,2,1 -> ans-2 not 3 as last 1 not counted again
            if(pos.count(nums[i])) {
                continue;
            }
            pos[nums[i]] = i ; 

            if(pos.count(nums[i]-1)){
                 ds.UnionBySize(i,pos[nums[i]-1]) ;
            }

            if(pos.count(nums[i]+1)){
                 ds.UnionBySize(i,pos[nums[i]+1]) ;
            }
        }

        for(int i=0;i<n;i++){
        //    cout<<ds.size[i] << " " <<ds.parent[i] << "\n"; 
            maxi=max(maxi,ds.size[i]) ; 
        }
    return maxi;
    */

/*  //APPROACH - 1 
    int n = nums.size();
    sort(nums.begin(),nums.end()) ; 
    int lastSmaller = INT_MIN; 
    int lcs = 0 , cnt = 1 ; 

    for(int i=0;i<n;i++){
        // 1,1,2,100 -> lastSmaller = 1  nums[i] = 2 -> so lastSmaller = 2 now and cnt increase
        if(nums[i]-1 == lastSmaller) {
            cnt++;
            lastSmaller=nums[i] ; 
        }
        // 1,1,2,100 -> lastSmaller = 2 nums[i] = 100 -> so lastSmaller = 100 now and cnt = 1
        if(nums[i] != lastSmaller){
            cnt=1;
            lastSmaller=nums[i] ; 
        }
        lcs=max(lcs,cnt);
    }
    return lcs;
    */

    //APPROACH - 2 T.C ->  O(N) + O(2N)  // ASSUMING SET TAKES 0(1)
     int n = nums.size();
     int lcs = 0; 
     unordered_set<int>s(nums.begin(),nums.end()) ; 
    for(auto&it:s){
        //2 4 -> it = 4 so 3 not present 
        //i.e for every sequence start iterating from first element of that sequence 
        // ex:- 1 2 3 4 100 101 102 
        // start from 1 and 100 respectively in total 4+3 iterations 
        //as for 1 and 100 -> 0 and 99 not present 

        if(s.find(it-1) == s.end()){
            int x=it,cnt=1;
            while(s.find(x+1)!=s.end()){
                x++;
                cnt++;
            }
            lcs=max(lcs,cnt);
        }
    }
    return lcs;
    }
};
