class SegTree{
public:
SegTree(int n){
    this->n=n;
    tree.resize(4*n,0);
}
void update(int ind,int val){
    update(ind,val,0,n-1,0);
}
int firstIndexGreaterThanPrefixSum(int x){
    return query(x,0,n-1,0);
}
private:
vector<int>tree;
int n;
void update(int ind,int val,int l,int r,int i){
    if(l==r){
        tree[i]+=val;
        return;
    }
    int m=l+(r-l)/2;
    if(m>=ind) update(ind,val,l,m,i*2+1);
    else update(ind,val,m+1,r,i*2+2);
    tree[i]=tree[i*2+1]+tree[i*2+2];
}
int query(int x,int l,int r,int i){
    if(l==r){
        if(tree[i]>=x) return l;//index found where prefix sum of freq >= x for first time
        return n; // if not possible 
    }
    int m=l+(r-l)/2;
    if(tree[i*2+1]<x) return query(x-tree[i*2+1],m+1,r,i*2+2);//go to right half by removing contribution of left half 
    else return query(x,l,m,i*2+1);
}
};

class Solution {
    SegTree*tree; 

    int valToTreeIndex(int val){
        return val+50;
    }
    int TreeIndexToVal(int ind){
        return ind-50;
    }
    void Add(int val){
        tree->update(valToTreeIndex(val),1);
    }
    void Remove(int val){
        tree->update(valToTreeIndex(val),-1);
    }
    int XthLargest(int x){
        int index = tree->firstIndexGreaterThanPrefixSum(x);
        int val = TreeIndexToVal(index);
        if(val>=0) return 0;//if xth smallest integer >=0 than 0 answer
        return val;
    }
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int>result;
        tree=new SegTree(101);

        for(int i=0;i<k-1;i++) Add(nums[i]); 
        for(int i=k-1;i<n;i++){
            Add(nums[i]);
            result.push_back(XthLargest(x));
            Remove(nums[i-k+1]);
        }
    return result;
    }
};
