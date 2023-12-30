class SegTree{
public:
SegTree(int _n,vector<int>&arr){
    n=_n;
    tree.resize(4*n,0);
    build(0,n-1,0,arr);
}
int query(int x,int y){
return query(x,y,0,n-1,0);
}
void update(int ind,int val){
update(ind,val,0,n-1,0);
}
private:
vector<int>tree; 
int n;
void build(int l,int r,int i,vector<int>&arr){
    if(l==r){
        tree[i]=arr[l];
        return;
    }
    int m= l+(r-l)/2;
    build(l,m,i*2+1,arr);
    build(m+1,r,i*2+2,arr);
    tree[i]=tree[i*2+1]+tree[i*2+2] ; 
}
int query(int x,int y,int l,int r,int i){
    //no overlap
    if(r<x || l>y) return 0; 
    //complete overlap 
    if(l>=x && r<=y) return tree[i]; 
    //partial overlap 
    int m=l+(r-l)/2; 
    return query(x,y,l,m,i*2+1)+query(x,y,m+1,r,i*2+2) ; 
}
void update(int ind,int val,int l,int r,int i){
    if(l==r){
        tree[i]=val;
        return;
    }
    int m= l+(r-l)/2;
    if(m>=ind) update(ind,val,l,m,i*2+1) ; 
    else update(ind,val,m+1,r,i*2+2);
    tree[i]=tree[i*2+1]+tree[i*2+2] ;
}
};
class NumArray {
public:
    SegTree * tree;
    NumArray(vector<int>& nums) {
        int n =nums.size();
        tree= new SegTree(n,nums);
    }
    void update(int index, int val) {
        tree->update(index,val);
    }
    
    int sumRange(int left, int right) {
        return tree->query(left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
