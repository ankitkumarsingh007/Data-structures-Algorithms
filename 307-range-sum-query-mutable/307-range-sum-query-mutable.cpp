class NumArray {
public:
    vector<int> tree;
    vector<int> arr;
    
    void generateTree(int ss,int se,int si){
        if(ss==se){
            tree[si]=arr[ss];
            return;
        }
        int mid=(ss+se)/2;
        
        generateTree(ss,mid,2*si+1);
        generateTree(mid+1,se,2*si+2);
        tree[si]=tree[si*2+1]+tree[si*2+2];
        return;
    }
    
    NumArray(vector<int>& nums) {
        arr=nums;
        int n=arr.size();
        tree.clear();
        tree.resize(4*n,0);
        
        generateTree(0,n-1,0);
    }
    
    void helperUpdate(int ss,int se,int si,int &qi,int &diff){
        if(ss>qi || se<qi)
            return;
        
        tree[si]+=diff;
        
        if(ss<se){
            int mid=(ss+se)/2;

            if(qi<=mid)
            helperUpdate(ss,mid,2*si+1,qi,diff);
            else
            helperUpdate(mid+1,se,2*si+2,qi,diff);
        }
    }
    
    void update(int index, int val) {
        int diff=val-arr[index];
        arr[index]=val;
        helperUpdate(0,arr.size()-1,0,index,diff);
    }
    
    int helperSum(int ss,int se,int si,int qs,int qe){
        if(ss>qe || se<qs)
            return 0;
        //this line 
        if(qs<=ss && qe>=se)
            return tree[si];
        
        int mid=(ss+se)/2;
        
        return helperSum(ss,mid,2*si+1,qs,qe)+helperSum(mid+1,se,2*si+2,qs,qe);
    }
    
    int sumRange(int left, int right) {
        return helperSum(0,arr.size()-1,0,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */