return;
}
void mergesort(int l,int r){
if(l>=r)
return;
int mid=(l+r)/2;
mergesort(l,mid);
mergesort(mid+1,r);
merge(l,mid,r);
}
vector<int> countSmaller(vector<int>& nums) {
arr.clear();
n=nums.size();
for(int i=0;i<n;i++){
arr.push_back({nums[i],i});
}
res.clear();
res.resize(n,0);
mergesort(0,n-1);
return res;
}
```